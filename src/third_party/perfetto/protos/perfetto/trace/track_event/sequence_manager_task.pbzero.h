// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_SEQUENCE_MANAGER_TASK_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_SEQUENCE_MANAGER_TASK_PBZERO_H_

#include <stdint.h>

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub SequenceManagerTask protobuf message
class SequenceManagerTask {
 public:
  // Stub enum for QueueName
  enum QueueName {
    QUEUE_NAME_UNKNOWN = 0,
    QUEUE_NAME_DEFAULT = 1,
    QUEUE_NAME_CONTROL = 2,
  };

  // Stub enum for Priority
  enum Priority {
    PRIORITY_UNKNOWN = 0,
    PRIORITY_CONTROL = 1,
    PRIORITY_HIGHEST = 2,
    PRIORITY_VERY_HIGH = 3,
    PRIORITY_HIGH = 4,
    PRIORITY_NORMAL = 5,
    PRIORITY_LOW = 6,
    PRIORITY_BEST_EFFORT = 7,
  };

  SequenceManagerTask() = default;
  ~SequenceManagerTask() = default;

  void set_queue_name(QueueName value) {}
  void set_priority(Priority value) {}
  void set_task_type(int32_t value) {}
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_SEQUENCE_MANAGER_TASK_PBZERO_H_
