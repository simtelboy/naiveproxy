// Copyright 2024 Stub implementation for OpenHarmony
#ifndef BASE_TRACING_PROTOS_CHROME_TRACK_EVENT_PBZERO_H_
#define BASE_TRACING_PROTOS_CHROME_TRACK_EVENT_PBZERO_H_

#include <stdint.h>

#include "base/tracing_buildflags.h"

#if BUILDFLAG(ENABLE_BASE_TRACING)
// Include real Perfetto headers when tracing is enabled
#include "third_party/perfetto/protos/perfetto/trace/track_event/sequence_manager_task.pbzero.h"
#include "third_party/perfetto/protos/perfetto/trace/track_event/chrome_track_event.pbzero.h"
#else

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub SequenceManagerTask
class SequenceManagerTask {
 public:
  enum class Priority : int32_t {
    UNKNOWN = 0,
    CONTROL_PRIORITY = 1,
    HIGHEST_PRIORITY = 2,
    VERY_HIGH_PRIORITY = 3,
    HIGH_PRIORITY = 4,
    NORMAL_PRIORITY = 5,
    LOW_PRIORITY = 6,
    BEST_EFFORT_PRIORITY = 7,
  };

  enum class QueueName : int32_t {
    UNKNOWN = 0,
  };

  SequenceManagerTask() = default;
  ~SequenceManagerTask() = default;

  void set_priority(Priority) {}
  void set_queue_name(QueueName) {}
};

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

// Stub DebugAnnotation for trace events
class DebugAnnotation {
 public:
  DebugAnnotation() = default;
  ~DebugAnnotation() = default;

  void set_name(const char*) {}
  void set_string_value(const char*) {}
  void set_int_value(int64_t) {}
  void set_uint_value(uint64_t) {}
  void set_double_value(double) {}
  void set_bool_value(bool) {}
  void set_pointer_value(uint64_t) {}
};

// Stub ChromeTrackEvent - the main track event class
class ChromeTrackEvent {
 public:
  ChromeTrackEvent() = default;
  ~ChromeTrackEvent() = default;

  DebugAnnotation* add_debug_annotations() {
    static DebugAnnotation dummy;
    return &dummy;
  }

  ChromeMemoryPressureNotification* set_chrome_memory_pressure_notification() {
    static ChromeMemoryPressureNotification dummy;
    return &dummy;
  }

  SequenceManagerTask* set_sequence_manager_task() {
    static SequenceManagerTask dummy;
    return &dummy;
  }
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // BUILDFLAG(ENABLE_BASE_TRACING)

#endif  // BASE_TRACING_PROTOS_CHROME_TRACK_EVENT_PBZERO_H_
