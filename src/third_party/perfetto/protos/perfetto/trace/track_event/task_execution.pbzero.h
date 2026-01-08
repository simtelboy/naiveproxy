// Copyright 2025 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies
#ifndef THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_TASK_EXECUTION_PBZERO_H_
#define THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_TASK_EXECUTION_PBZERO_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub implementation of TaskExecution
class TaskExecution {
 public:
  TaskExecution() = default;
  ~TaskExecution() = default;

  // Stub methods
  void set_posted_from_ipc(bool value) {}
  bool posted_from_ipc() const { return false; }

  void set_source_location_iid(uint64_t value) {}
  uint64_t source_location_iid() const { return 0; }

  void set_task_type(uint32_t value) {}
  uint32_t task_type() const { return 0; }
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_TASK_EXECUTION_PBZERO_H_
