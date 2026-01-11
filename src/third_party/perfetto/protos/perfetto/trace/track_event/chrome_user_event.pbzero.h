// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_USER_EVENT_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_USER_EVENT_PBZERO_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub ChromeUserEvent protobuf message
class ChromeUserEvent {
 public:
  ChromeUserEvent() = default;
  ~ChromeUserEvent() = default;

  void set_action(const char* value) {}
  void set_action(const std::string& value) {}
  void set_action_hash(uint64_t value) {}
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_USER_EVENT_PBZERO_H_
