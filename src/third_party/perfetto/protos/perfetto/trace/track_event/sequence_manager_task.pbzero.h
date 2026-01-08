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
    DEFAULT_TQ = 1,  // Alias for QUEUE_NAME_DEFAULT
    QUEUE_NAME_CONTROL = 2,
  };

  // Stub enum for Priority
  enum Priority {
    PRIORITY_UNKNOWN = 0,
    PRIORITY_CONTROL = 1,
    PRIORITY_HIGHEST = 2,
    PRIORITY_VERY_HIGH = 3,
    PRIORITY_HIGH = 4,
    NORMAL_PRIORITY = 5,  // Alias for PRIORITY_NORMAL
    PRIORITY_NORMAL = 5,
    PRIORITY_LOW = 6,
    PRIORITY_BEST_EFFORT = 7,
  };

  SequenceManagerTask() = default;
  ~SequenceManagerTask() = default;

  void set_queue_name(QueueName value) {}
  void set_priority(Priority value) {}
  void set_task_type(int32_t value) {}

  // Static method to convert QueueName enum to string
  static const char* QueueName_Name(QueueName value) {
    switch (value) {
      case QUEUE_NAME_UNKNOWN: return "QUEUE_NAME_UNKNOWN";
      case QUEUE_NAME_DEFAULT: return "QUEUE_NAME_DEFAULT";
      case QUEUE_NAME_CONTROL: return "QUEUE_NAME_CONTROL";
      default: return "UNKNOWN";
    }
  }
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_SEQUENCE_MANAGER_TASK_PBZERO_H_
