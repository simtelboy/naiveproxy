// Copyright 2024 Stub implementation for OpenHarmony
#ifndef BASE_TRACING_PROTOS_CHROME_TRACK_EVENT_PBZERO_H_
#define BASE_TRACING_PROTOS_CHROME_TRACK_EVENT_PBZERO_H_

#include <stdint.h>

// Include SequenceManagerTask
#include "third_party/perfetto/protos/perfetto/trace/track_event/sequence_manager_task.pbzero.h"

namespace perfetto {
namespace protos {
namespace pbzero {

// Re-export SequenceManagerTask for convenience
using SequenceManagerTask = ::perfetto::protos::pbzero::SequenceManagerTask;

// Stub MemoryPressureLevel enum
enum MemoryPressureLevel {
  MEMORY_PRESSURE_LEVEL_NONE = 0,
  MEMORY_PRESSURE_LEVEL_MODERATE = 1,
  MEMORY_PRESSURE_LEVEL_CRITICAL = 2,
};

// Stub ChromeMemoryPressureNotification message
class ChromeMemoryPressureNotification {
 public:
  ChromeMemoryPressureNotification() = default;
  ~ChromeMemoryPressureNotification() = default;

  void set_level(int32_t value) {}
  void set_creation_location_iid(uint64_t value) {}
};

// Stub Chrome track event protobuf message
class ChromeTrackEvent {
 public:
  ChromeTrackEvent() = default;
  ~ChromeTrackEvent() = default;

  // Stub methods
  void set_name(const char* data, size_t size) {}
  void set_category(const char* data, size_t size) {}
  void set_type(int32_t value) {}
  void set_id(uint64_t value) {}

  // Memory pressure notification support
  ChromeMemoryPressureNotification* set_chrome_memory_pressure_notification() {
    return &notification_;
  }

 private:
  ChromeMemoryPressureNotification notification_;
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // BASE_TRACING_PROTOS_CHROME_TRACK_EVENT_PBZERO_H_
