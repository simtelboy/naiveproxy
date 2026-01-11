// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_EXT_BASE_LOCK_FREE_TASK_RUNNER_H_
#define INCLUDE_PERFETTO_EXT_BASE_LOCK_FREE_TASK_RUNNER_H_

#include <functional>

namespace perfetto {
namespace base {

// Stub LockFreeTaskRunner
class LockFreeTaskRunner {
 public:
  LockFreeTaskRunner() = default;
  ~LockFreeTaskRunner() = default;

  void PostTask(std::function<void()> task) {}
};

}  // namespace base
}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_EXT_BASE_LOCK_FREE_TASK_RUNNER_H_
