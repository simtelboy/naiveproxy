// Copyright 2025 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies

#ifndef PERFETTO_PROTOS_PERFETTO_CONFIG_TRACE_CONFIG_GEN_H_
#define PERFETTO_PROTOS_PERFETTO_CONFIG_TRACE_CONFIG_GEN_H_

#include <string>
#include <vector>
#include <cstdint>

namespace perfetto {
namespace protos {
namespace gen {

// Stub TraceConfig class
class TraceConfig {
 public:
  TraceConfig() = default;
  ~TraceConfig() = default;

  // Basic getters/setters
  uint32_t duration_ms() const { return duration_ms_; }
  void set_duration_ms(uint32_t value) { duration_ms_ = value; }

  uint32_t max_file_size_bytes() const { return max_file_size_bytes_; }
  void set_max_file_size_bytes(uint32_t value) { max_file_size_bytes_ = value; }

  bool write_into_file() const { return write_into_file_; }
  void set_write_into_file(bool value) { write_into_file_ = value; }

  uint32_t file_write_period_ms() const { return file_write_period_ms_; }
  void set_file_write_period_ms(uint32_t value) { file_write_period_ms_ = value; }

  uint32_t flush_period_ms() const { return flush_period_ms_; }
  void set_flush_period_ms(uint32_t value) { flush_period_ms_ = value; }

  bool deferred_start() const { return deferred_start_; }
  void set_deferred_start(bool value) { deferred_start_ = value; }

 private:
  uint32_t duration_ms_ = 0;
  uint32_t max_file_size_bytes_ = 0;
  bool write_into_file_ = false;
  uint32_t file_write_period_ms_ = 0;
  uint32_t flush_period_ms_ = 0;
  bool deferred_start_ = false;
};

}  // namespace gen
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_CONFIG_TRACE_CONFIG_GEN_H_
