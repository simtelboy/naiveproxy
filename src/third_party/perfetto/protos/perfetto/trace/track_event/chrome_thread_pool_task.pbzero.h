// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_THREAD_POOL_TASK_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_THREAD_POOL_TASK_PBZERO_H_

#include <stdint.h>

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub ChromeThreadPoolTask protobuf message
class ChromeThreadPoolTask {
 public:
  // Priority enum
  enum Priority {
    PRIORITY_UNKNOWN = 0,
    PRIORITY_BEST_EFFORT = 1,
    PRIORITY_USER_VISIBLE = 2,
    PRIORITY_USER_BLOCKING = 3,
  };

  // ExecutionMode enum
  enum ExecutionMode {
    EXECUTION_MODE_UNKNOWN = 0,
    EXECUTION_MODE_PARALLEL = 1,
    EXECUTION_MODE_SEQUENCED = 2,
    EXECUTION_MODE_SINGLE_THREAD = 3,
    EXECUTION_MODE_JOB = 4,
  };

  // ShutdownBehavior enum
  enum ShutdownBehavior {
    SHUTDOWN_BEHAVIOR_UNKNOWN = 0,
    SHUTDOWN_BEHAVIOR_CONTINUE_ON_SHUTDOWN = 1,
    SHUTDOWN_BEHAVIOR_SKIP_ON_SHUTDOWN = 2,
    SHUTDOWN_BEHAVIOR_BLOCK_SHUTDOWN = 3,
  };

  ChromeThreadPoolTask() = default;
  ~ChromeThreadPoolTask() = default;

  void set_task_priority(Priority value) {}
  void set_priority(Priority value) {}
  void set_execution_mode(ExecutionMode value) {}
  void set_shutdown_behavior(ShutdownBehavior value) {}
  void set_sequence_token(int64_t value) {}
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_THREAD_POOL_TASK_PBZERO_H_
