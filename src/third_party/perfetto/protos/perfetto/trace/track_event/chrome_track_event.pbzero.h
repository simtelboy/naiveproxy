// Copyright 2025 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies
#ifndef THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_TRACK_EVENT_PBZERO_H_
#define THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_TRACK_EVENT_PBZERO_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {
namespace pbzero {

// Forward declarations
class ChromeTaskAnnotator;
class ChromeMojoEventInfo;
class TaskExecution;
class CurrentTask;

// Stub implementation of ChromeTrackEvent
class ChromeTrackEvent {
 public:
  ChromeTrackEvent() = default;
  ~ChromeTrackEvent() = default;

  // Stub methods
  ChromeTaskAnnotator* set_chrome_task_annotator() { return nullptr; }
  ChromeMojoEventInfo* set_chrome_mojo_event_info() { return nullptr; }
  TaskExecution* set_task_execution() { return nullptr; }
  CurrentTask* set_current_task() { return nullptr; }
};

// Stub implementation of ChromeTaskAnnotator
class ChromeTaskAnnotator {
 public:
  enum DelayPolicy {
    FLEXIBLE_NO_SOONER = 0,
    FLEXIBLE_PREFER_EARLY = 1,
    PRECISE = 2,
  };

  ChromeTaskAnnotator() = default;
  ~ChromeTaskAnnotator() = default;

  void set_ipc_hash(uint32_t value) {}
  uint32_t ipc_hash() const { return 0; }

  void set_delay_policy(DelayPolicy value) {}
  DelayPolicy delay_policy() const { return FLEXIBLE_NO_SOONER; }

  void set_task_delay_us(uint64_t value) {}
  uint64_t task_delay_us() const { return 0; }
};

// Stub implementation of CurrentTask
class CurrentTask {
 public:
  CurrentTask() = default;
  ~CurrentTask() = default;

  void set_posted_from_iid(uint64_t value) {}
  uint64_t posted_from_iid() const { return 0; }

  void set_task_queueing_time_us(uint64_t value) {}
  uint64_t task_queueing_time_us() const { return 0; }

  void set_task_queued_time_us(uint64_t value) {}
  uint64_t task_queued_time_us() const { return 0; }

  void set_event_offset_from_task_start_time_us(uint64_t value) {}
  uint64_t event_offset_from_task_start_time_us() const { return 0; }

  void set_task_start_time_us(uint64_t value) {}
  uint64_t task_start_time_us() const { return 0; }
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_TRACK_EVENT_PBZERO_H_
