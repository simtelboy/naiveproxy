// Copyright 2024 Stub implementation for OpenHarmony
#ifndef BASE_TRACING_PROTOS_CHROME_TRACK_EVENT_PBZERO_H_
#define BASE_TRACING_PROTOS_CHROME_TRACK_EVENT_PBZERO_H_

#include <stdint.h>

// Include SequenceManagerTask
#include "third_party/perfetto/protos/perfetto/trace/track_event/sequence_manager_task.pbzero.h"
// Include the perfetto chrome_track_event
#include "third_party/perfetto/protos/perfetto/trace/track_event/chrome_track_event.pbzero.h"

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

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // BASE_TRACING_PROTOS_CHROME_TRACK_EVENT_PBZERO_H_
