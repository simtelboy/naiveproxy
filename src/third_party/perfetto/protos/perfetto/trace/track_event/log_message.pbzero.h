// Copyright 2024 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies

#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_LOG_MESSAGE_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_LOG_MESSAGE_PBZERO_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub LogMessage protobuf message
class LogMessage {
 public:
  LogMessage() = default;
  ~LogMessage() = default;

  // Stub methods - do nothing
  void set_source_location_iid(uint64_t value) {}
  void set_body_iid(uint64_t value) {}
  void set_prio(int32_t value) {}
  void set_tag(const char* data, size_t size) {}
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_LOG_MESSAGE_PBZERO_H_
