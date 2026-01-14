// Copyright 2024 aspect
// NaiveProxy C API implementation for HarmonyOS

#include "net/tools/naive/naive_api.h"

#include <atomic>
#include <memory>
#include <string>
#include <thread>

#include "base/at_exit.h"
#include "base/command_line.h"
#include "base/feature_list.h"
#include "base/files/file_path.h"
#include "base/json/json_file_value_serializer.h"
#include "base/json/json_reader.h"
#include "base/logging.h"
#include "base/run_loop.h"
#include "base/strings/string_number_conversions.h"
#include "base/task/single_thread_task_executor.h"
#include "base/task/thread_pool/thread_pool_instance.h"
#include "base/values.h"
#include "net/tools/naive/naive_config.h"
#include "net/tools/naive/naive_proxy.h"
#include "net/http/http_network_session.h"
#include "net/http/http_transaction_factory.h"
#include "net/log/net_log.h"
#include "net/proxy_resolution/configured_proxy_resolution_service.h"
#include "net/proxy_resolution/proxy_config.h"
#include "net/proxy_resolution/proxy_config_service_fixed.h"
#include "net/proxy_resolution/proxy_config_with_annotation.h"
#include "net/socket/client_socket_pool_manager.h"
#include "net/socket/tcp_server_socket.h"
#include "net/traffic_annotation/network_traffic_annotation.h"
#include "net/url_request/url_request_context.h"
#include "net/url_request/url_request_context_builder.h"
#include "url/url_util.h"

namespace {

constexpr int kListenBackLog = 512;
constexpr int kDefaultMaxSocketsPerPool = 256;
constexpr int kDefaultMaxSocketsPerGroup = 255;
constexpr int kExpectedMaxUsers = 8;

constexpr net::NetworkTrafficAnnotationTag kTrafficAnnotation =
    net::DefineNetworkTrafficAnnotation("naive", "");

// 全局状态
std::atomic<bool> g_running{false};
std::atomic<bool> g_stop_requested{false};
std::string g_last_error;
NaiveLogCallback g_log_callback = nullptr;
std::unique_ptr<std::thread> g_proxy_thread;

// 内部日志函数
void InternalLog(int level, const char* message) {
  if (g_log_callback) {
    g_log_callback(level, message);
  }
}

void InternalLogString(int level, const std::string& message) {
  InternalLog(level, message.c_str());
}

// 构建 URLRequestContext
std::unique_ptr<net::URLRequestContext> BuildURLRequestContext(
    const net::NaiveConfig& config,
    net::NetLog* net_log) {
  net::URLRequestContextBuilder builder;

  builder.DisableHttpCache();
  builder.set_net_log(net_log);

  net::ProxyConfig proxy_config;
  auto proxy_service =
      net::ConfiguredProxyResolutionService::CreateWithoutProxyResolver(
          std::make_unique<net::ProxyConfigServiceFixed>(
              net::ProxyConfigWithAnnotation(proxy_config, kTrafficAnnotation)),
          net_log);
  proxy_service->ForceReloadProxyConfig();
  builder.set_proxy_resolution_service(std::move(proxy_service));

  return builder.Build();
}

// 代理运行线程函数
void ProxyThreadFunc(const std::string& config_json) {
  InternalLog(NAIVE_LOG_INFO, "NaiveProxy thread starting...");

  // 初始化 Chromium 基础设施
  base::AtExitManager exit_manager;

  // 初始化命令行（必须）
  int argc = 1;
  const char* argv[] = {"naive"};
  base::CommandLine::Init(argc, const_cast<char**>(argv));

  // 初始化 FeatureList
  base::FeatureList::InitInstance("", "");

  // 创建任务执行器
  base::SingleThreadTaskExecutor io_task_executor(base::MessagePumpType::IO);
  base::ThreadPoolInstance::CreateAndStartWithDefaultParams("naive");

  // 注册 URL schemes
  url::AddStandardScheme("quic",
                         url::SCHEME_WITH_HOST_PORT_AND_USER_INFORMATION);
  url::AddStandardScheme("socks",
                         url::SCHEME_WITH_HOST_PORT_AND_USER_INFORMATION);

  // 设置 socket pool 参数
  net::ClientSocketPoolManager::set_max_sockets_per_pool(
      net::HttpNetworkSession::NORMAL_SOCKET_POOL,
      kDefaultMaxSocketsPerPool * kExpectedMaxUsers);
  net::ClientSocketPoolManager::set_max_sockets_per_group(
      net::HttpNetworkSession::NORMAL_SOCKET_POOL,
      kDefaultMaxSocketsPerGroup * kExpectedMaxUsers);

  // 解析配置
  auto json_value = base::JSONReader::Read(config_json, base::JSON_PARSE_RFC);
  if (!json_value || !json_value->is_dict()) {
    g_last_error = "Invalid JSON config";
    InternalLog(NAIVE_LOG_ERROR, g_last_error.c_str());
    g_running.store(false);
    return;
  }

  net::NaiveConfig config;
  if (!config.Parse(json_value->GetDict())) {
    g_last_error = "Failed to parse config";
    InternalLog(NAIVE_LOG_ERROR, g_last_error.c_str());
    g_running.store(false);
    return;
  }

  // 获取 NetLog
  net::NetLog* net_log = net::NetLog::Get();

  // 创建 URLRequestContext
  auto context = BuildURLRequestContext(config, net_log);
  auto* session = context->http_transaction_factory()->GetSession();

  // 创建监听 socket
  std::vector<std::unique_ptr<net::NaiveProxy>> naive_proxies;

  for (const auto& listen_config : config.listen) {
    auto listen_socket =
        std::make_unique<net::TCPServerSocket>(net_log, net::NetLogSource());

    int result = listen_socket->ListenWithAddressAndPort(
        listen_config.addr, listen_config.port, kListenBackLog);
    if (result != net::OK) {
      g_last_error = "Failed to listen on " + listen_config.addr + ":" +
                     base::NumberToString(listen_config.port);
      InternalLog(NAIVE_LOG_ERROR, g_last_error.c_str());
      g_running.store(false);
      return;
    }

    std::string listen_msg = "Listening on " + listen_config.addr + ":" +
                             base::NumberToString(listen_config.port);
    InternalLog(NAIVE_LOG_INFO, listen_msg.c_str());

    auto naive_proxy = std::make_unique<net::NaiveProxy>(
        std::move(listen_socket), listen_config.protocol, listen_config.user,
        listen_config.pass, config.insecure_concurrency, nullptr,
        session, kTrafficAnnotation,
        std::vector<net::PaddingType>{net::PaddingType::kVariant1,
                                      net::PaddingType::kNone});
    naive_proxies.push_back(std::move(naive_proxy));
  }

  InternalLog(NAIVE_LOG_INFO, "NaiveProxy started successfully");

  // 运行事件循环
  base::RunLoop run_loop;
  while (!g_stop_requested.load()) {
    run_loop.RunUntilIdle();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  InternalLog(NAIVE_LOG_INFO, "NaiveProxy stopped");
  g_running.store(false);
}

}  // namespace

extern "C" {

NAIVE_EXPORT int naive_get_version(void) {
  return NAIVE_API_VERSION;
}

NAIVE_EXPORT void naive_set_log_callback(NaiveLogCallback callback) {
  g_log_callback = callback;
}

NAIVE_EXPORT int naive_start(const char* config_json) {
  if (g_running.load()) {
    g_last_error = "Proxy is already running";
    return NAIVE_ERROR_ALREADY_RUNNING;
  }

  if (config_json == nullptr || config_json[0] == '\0') {
    g_last_error = "Invalid config: empty or null";
    return NAIVE_ERROR_INVALID_CONFIG;
  }

  g_running.store(true);
  g_stop_requested.store(false);

  // 在新线程中运行代理
  std::string config_copy(config_json);
  g_proxy_thread = std::make_unique<std::thread>(ProxyThreadFunc, config_copy);

  return NAIVE_OK;
}

NAIVE_EXPORT int naive_stop(void) {
  if (!g_running.load()) {
    g_last_error = "Proxy is not running";
    return NAIVE_ERROR_NOT_RUNNING;
  }

  InternalLog(NAIVE_LOG_INFO, "Stopping NaiveProxy...");
  g_stop_requested.store(true);

  if (g_proxy_thread && g_proxy_thread->joinable()) {
    g_proxy_thread->join();
    g_proxy_thread.reset();
  }

  return NAIVE_OK;
}

NAIVE_EXPORT int naive_is_running(void) {
  return g_running.load() ? 1 : 0;
}

NAIVE_EXPORT const char* naive_get_last_error(void) {
  return g_last_error.c_str();
}

}  // extern "C"
