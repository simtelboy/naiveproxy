// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_APPLICATION_STATE_INFO_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_APPLICATION_STATE_INFO_PBZERO_H_

#include <stdint.h>

namespace perfetto {
namespace protos {
namespace pbzero {

// ChromeApplicationStateInfo stub
class ChromeApplicationStateInfo {
 public:
  // ApplicationState enum
  enum ApplicationState : int32_t {
    APPLICATION_STATE_UNKNOWN = 0,
    APPLICATION_STATE_HAS_RUNNING_ACTIVITIES = 1,
    APPLICATION_STATE_HAS_PAUSED_ACTIVITIES = 2,
    APPLICATION_STATE_HAS_STOPPED_ACTIVITIES = 3,
    APPLICATION_STATE_HAS_DESTROYED_ACTIVITIES = 4,
  };

  ChromeApplicationStateInfo() = default;
  ~ChromeApplicationStateInfo() = default;

  void set_application_state(ApplicationState value) {}
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_APPLICATION_STATE_INFO_PBZERO_H_
