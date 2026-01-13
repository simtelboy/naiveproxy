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
#include "base/json/json_reader.h"
#include "base/logging.h"
#include "base/run_loop.h"
#include "base/task/single_thread_task_executor.h"
#include "base/task/thread_pool/thread_pool_instance.h"

// 全局状态
static std::atomic<bool> g_running{false};
static std::atomic<bool> g_initialized{false};
static std::string g_last_error;
static NaiveLogCallback g_log_callback = nullptr;
static std::unique_ptr<std::thread> g_proxy_thread;
static std::unique_ptr<base::RunLoop> g_run_loop;

// 内部日志函数
static void InternalLog(int level, const char* message) {
  if (g_log_callback) {
    g_log_callback(level, message);
  }
}

extern "C" {

int naive_get_version(void) {
  return NAIVE_API_VERSION;
}

void naive_set_log_callback(NaiveLogCallback callback) {
  g_log_callback = callback;
}

int naive_start(const char* config_json) {
  if (g_running.load()) {
    g_last_error = "Proxy is already running";
    return NAIVE_ERROR_ALREADY_RUNNING;
  }

  if (config_json == nullptr || config_json[0] == '\0') {
    g_last_error = "Invalid config: empty or null";
    return NAIVE_ERROR_INVALID_CONFIG;
  }

  // 解析 JSON 配置
  auto value = base::JSONReader::Read(config_json);
  if (!value || !value->is_dict()) {
    g_last_error = "Invalid config: not a valid JSON object";
    return NAIVE_ERROR_INVALID_CONFIG;
  }

  InternalLog(NAIVE_LOG_INFO, "Starting NaiveProxy with JSON config");

  // TODO: 实现完整的启动逻辑
  // 这里需要将 naive_proxy_bin.cc 中的 main() 逻辑重构为可调用的函数

  g_running.store(true);
  return NAIVE_OK;
}

int naive_start_with_file(const char* config_path) {
  if (g_running.load()) {
    g_last_error = "Proxy is already running";
    return NAIVE_ERROR_ALREADY_RUNNING;
  }

  if (config_path == nullptr || config_path[0] == '\0') {
    g_last_error = "Invalid config path: empty or null";
    return NAIVE_ERROR_INVALID_CONFIG;
  }

  InternalLog(NAIVE_LOG_INFO, "Starting NaiveProxy with config file");

  // 构造命令行参数并调用 naive_main
  char* argv[] = {(char*)"naive", (char*)config_path};
  return naive_main(2, argv);
}

int naive_stop(void) {
  if (!g_running.load()) {
    g_last_error = "Proxy is not running";
    return NAIVE_ERROR_NOT_RUNNING;
  }

  InternalLog(NAIVE_LOG_INFO, "Stopping NaiveProxy");

  if (g_run_loop) {
    g_run_loop->Quit();
  }

  if (g_proxy_thread && g_proxy_thread->joinable()) {
    g_proxy_thread->join();
    g_proxy_thread.reset();
  }

  g_running.store(false);
  return NAIVE_OK;
}

int naive_is_running(void) {
  return g_running.load() ? 1 : 0;
}

const char* naive_get_last_error(void) {
  return g_last_error.c_str();
}

// 声明原始的 main 函数（在 naive_proxy_bin.cc 中定义）
// 我们将其重命名以避免符号冲突
int naive_main(int argc, char* argv[]) {
  if (g_running.load()) {
    g_last_error = "Proxy is already running";
    return NAIVE_ERROR_ALREADY_RUNNING;
  }

  g_running.store(true);

  // 在新线程中运行代理
  g_proxy_thread = std::make_unique<std::thread>([argc, argv]() {
    // 初始化 Chromium 基础设施
    base::AtExitManager exit_manager;
    base::CommandLine::Init(argc, argv);
    base::FeatureList::InitInstance("", "");

    base::SingleThreadTaskExecutor io_task_executor(base::MessagePumpType::IO);
    base::ThreadPoolInstance::CreateAndStartWithDefaultParams("naive");

    g_run_loop = std::make_unique<base::RunLoop>();

    InternalLog(NAIVE_LOG_INFO, "NaiveProxy thread started");

    // 运行事件循环
    g_run_loop->Run();

    InternalLog(NAIVE_LOG_INFO, "NaiveProxy thread stopped");

    g_running.store(false);
  });

  return NAIVE_OK;
}

}  // extern "C"
