// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_CONFIG_TRACK_EVENT_TRACK_EVENT_CONFIG_GEN_H_
#define PERFETTO_PROTOS_PERFETTO_CONFIG_TRACK_EVENT_TRACK_EVENT_CONFIG_GEN_H_

#include <string>
#include <vector>

namespace perfetto {
namespace protos {
namespace gen {

// Stub TrackEventConfig class
class TrackEventConfig {
 public:
  TrackEventConfig() = default;
  ~TrackEventConfig() = default;

  // Disabled categories
  const std::vector<std::string>& disabled_categories() const {
    static std::vector<std::string> v;
    return v;
  }

  void add_disabled_categories(const std::string& value) {}

  // Enabled categories
  const std::vector<std::string>& enabled_categories() const {
    static std::vector<std::string> v;
    return v;
  }

  void add_enabled_categories(const std::string& value) {}

  // Disabled tags
  const std::vector<std::string>& disabled_tags() const {
    static std::vector<std::string> v;
    return v;
  }

  void add_disabled_tags(const std::string& value) {}

  // Enabled tags
  const std::vector<std::string>& enabled_tags() const {
    static std::vector<std::string> v;
    return v;
  }

  void add_enabled_tags(const std::string& value) {}

  // Filter debug annotations
  bool filter_debug_annotations() const { return false; }
  void set_filter_debug_annotations(bool value) {}

  // Enable thread time sampling
  bool enable_thread_time_sampling() const { return false; }
  void set_enable_thread_time_sampling(bool value) {}

  // Timestamp unit multiplier
  uint64_t timestamp_unit_multiplier() const { return 1; }
  void set_timestamp_unit_multiplier(uint64_t value) {}
};

}  // namespace gen
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_CONFIG_TRACK_EVENT_TRACK_EVENT_CONFIG_GEN_H_
