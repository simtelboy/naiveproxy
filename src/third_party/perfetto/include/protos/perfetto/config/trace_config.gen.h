// Copyright 2024 The Chromium Authors
// Stub implementation for HarmonyOS build

#ifndef THIRD_PARTY_PERFETTO_INCLUDE_PROTOS_PERFETTO_CONFIG_TRACE_CONFIG_GEN_H_
#define THIRD_PARTY_PERFETTO_INCLUDE_PROTOS_PERFETTO_CONFIG_TRACE_CONFIG_GEN_H_

#include <string>
#include <vector>

namespace perfetto {
namespace protos {
namespace gen {

// Stub TraceConfig class
class TraceConfig {
 public:
  // Nested TriggerConfig class
  class TriggerConfig {
   public:
    enum TriggerMode {
      UNSPECIFIED = 0,
      START_TRACING = 1,
      STOP_TRACING = 2,
      CLONE_SNAPSHOT = 3,
    };

    TriggerMode trigger_mode() const { return UNSPECIFIED; }
    bool use_clone_snapshot_if_available() const { return false; }
  };

  // Nested BufferConfig class
  class BufferConfig {
   public:
    uint32_t size_kb() const { return 0; }
  };

  // Nested DataSource class
  class DataSource {
   public:
    class Config {
     public:
      const std::string& name() const { static std::string s; return s; }
    };
    const Config& config() const { static Config c; return c; }
  };

  // Methods
  const TriggerConfig& trigger_config() const { static TriggerConfig tc; return tc; }
  const std::vector<BufferConfig>& buffers() const { static std::vector<BufferConfig> v; return v; }
  const std::vector<DataSource>& data_sources() const { static std::vector<DataSource> v; return v; }
  uint32_t duration_ms() const { return 0; }
};

}  // namespace gen
}  // namespace protos
}  // namespace perfetto

#endif  // THIRD_PARTY_PERFETTO_INCLUDE_PROTOS_PERFETTO_CONFIG_TRACE_CONFIG_GEN_H_
