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
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // BASE_TRACING_PROTOS_CHROME_TRACK_EVENT_PBZERO_H_
