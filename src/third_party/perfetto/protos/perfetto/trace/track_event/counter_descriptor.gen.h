// Copyright 2025 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies
#ifndef THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_COUNTER_DESCRIPTOR_GEN_H_
#define THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_COUNTER_DESCRIPTOR_GEN_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {

// Stub for CounterDescriptor
class CounterDescriptor {
 public:
  // BuiltinCounterType enum
  enum BuiltinCounterType {
    COUNTER_UNSPECIFIED = 0,
    COUNTER_THREAD_TIME_NS = 1,
    COUNTER_THREAD_INSTRUCTION_COUNT = 2,
  };

  CounterDescriptor() = default;
  ~CounterDescriptor() = default;

  // Stub methods
  void set_type(int32_t value) {}
  int32_t type() const { return 0; }

  void set_unit(int32_t value) {}
  int32_t unit() const { return 0; }

  void set_unit_name(const std::string& value) {}
  const std::string& unit_name() const { static std::string s; return s; }

  void set_unit_multiplier(int64_t value) {}
  int64_t unit_multiplier() const { return 0; }

  void set_is_incremental(bool value) {}
  bool is_incremental() const { return false; }
};

}  // namespace protos
}  // namespace perfetto

#endif  // THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_COUNTER_DESCRIPTOR_GEN_H_
