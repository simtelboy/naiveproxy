// Copyright 2024 aspect
// NaiveProxy C API for HarmonyOS integration

#ifndef NET_TOOLS_NAIVE_NAIVE_API_H_
#define NET_TOOLS_NAIVE_NAIVE_API_H_

#ifdef __cplusplus
extern "C" {
#endif

// API 版本
#define NAIVE_API_VERSION 1

// 错误码
#define NAIVE_OK 0
#define NAIVE_ERROR_INVALID_CONFIG -1
#define NAIVE_ERROR_ALREADY_RUNNING -2
#define NAIVE_ERROR_NOT_RUNNING -3
#define NAIVE_ERROR_BIND_FAILED -4
#define NAIVE_ERROR_INIT_FAILED -5

// 日志级别
#define NAIVE_LOG_NONE 0
#define NAIVE_LOG_ERROR 1
#define NAIVE_LOG_WARNING 2
#define NAIVE_LOG_INFO 3
#define NAIVE_LOG_DEBUG 4

// 日志回调函数类型
typedef void (*NaiveLogCallback)(int level, const char* message);

// 获取 API 版本
int naive_get_version(void);

// 设置日志回调
void naive_set_log_callback(NaiveLogCallback callback);

// 使用 JSON 配置字符串启动代理
// config_json: JSON 格式的配置字符串
// 返回: NAIVE_OK 成功，其他为错误码
int naive_start(const char* config_json);

// 使用配置文件路径启动代理
// config_path: 配置文件路径
// 返回: NAIVE_OK 成功，其他为错误码
int naive_start_with_file(const char* config_path);

// 停止代理
// 返回: NAIVE_OK 成功，其他为错误码
int naive_stop(void);

// 检查代理是否正在运行
// 返回: 1 正在运行，0 未运行
int naive_is_running(void);

// 获取最后一次错误信息
const char* naive_get_last_error(void);

// 使用命令行参数启动（兼容原有 main 函数）
// argc: 参数数量
// argv: 参数数组
// 返回: 退出码
int naive_main(int argc, char* argv[]);

#ifdef __cplusplus
}
#endif

#endif  // NET_TOOLS_NAIVE_NAIVE_API_H_
