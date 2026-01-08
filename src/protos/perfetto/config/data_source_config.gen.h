// Copyright 2025 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies

#ifndef PERFETTO_PROTOS_PERFETTO_CONFIG_DATA_SOURCE_CONFIG_GEN_H_
#define PERFETTO_PROTOS_PERFETTO_CONFIG_DATA_SOURCE_CONFIG_GEN_H_

#include <string>
#include <vector>

namespace perfetto {
namespace protos {
namespace gen {

// Stub DataSourceConfig class
class DataSourceConfig {
 public:
  DataSourceConfig() = default;
  ~DataSourceConfig() = default;

  // Basic getters/setters
  const std::string& name() const { return name_; }
  void set_name(const std::string& value) { name_ = value; }

  uint32_t target_buffer() const { return target_buffer_; }
  void set_target_buffer(uint32_t value) { target_buffer_ = value; }

  uint32_t trace_duration_ms() const { return trace_duration_ms_; }
  void set_trace_duration_ms(uint32_t value) { trace_duration_ms_ = value; }

  bool enable_extra_guardrails() const { return enable_extra_guardrails_; }
  void set_enable_extra_guardrails(bool value) { enable_extra_guardrails_ = value; }

  const std::string& legacy_config() const { return legacy_config_; }
  void set_legacy_config(const std::string& value) { legacy_config_ = value; }

 private:
  std::string name_;
  uint32_t target_buffer_ = 0;
  uint32_t trace_duration_ms_ = 0;
  bool enable_extra_guardrails_ = false;
  std::string legacy_config_;
};

}  // namespace gen
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_CONFIG_DATA_SOURCE_CONFIG_GEN_H_
