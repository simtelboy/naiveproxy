// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PBZERO_CHROME_TRACK_EVENT_H_
#define PERFETTO_PROTOS_PBZERO_CHROME_TRACK_EVENT_H_

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub for ChromeMemoryPressureNotification
class ChromeMemoryPressureNotification {
 public:
  ChromeMemoryPressureNotification() = default;
  ~ChromeMemoryPressureNotification() = default;
  
  void set_level(int32_t) {}
  void set_creation_location_iid(uint64_t) {}
};

// Stub for ChromeTrackEvent
class ChromeTrackEvent {
 public:
  ChromeTrackEvent() = default;
  ~ChromeTrackEvent() = default;
  
  ChromeMemoryPressureNotification* set_chrome_memory_pressure_notification() {
    return &notification_;
  }
  
 private:
  ChromeMemoryPressureNotification notification_;
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PBZERO_CHROME_TRACK_EVENT_H_
