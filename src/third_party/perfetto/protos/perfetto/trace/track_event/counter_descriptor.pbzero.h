// Copyright 2025 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies

#ifndef THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_COUNTER_DESCRIPTOR_PBZERO_H_
#define THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_COUNTER_DESCRIPTOR_PBZERO_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub implementation of CounterDescriptor
class CounterDescriptor {
 public:
  // Unit enum
  enum Unit {
    UNIT_UNSPECIFIED = 0,
    UNIT_TIME_NS = 1,
    UNIT_COUNT = 2,
    UNIT_SIZE_BYTES = 3,
  };

  // BuiltinCounterType enum
  enum BuiltinCounterType {
    COUNTER_UNSPECIFIED = 0,
    COUNTER_THREAD_TIME_NS = 1,
    COUNTER_THREAD_INSTRUCTION_COUNT = 2,
  };

  CounterDescriptor() = default;
  ~CounterDescriptor() = default;

  // Stub methods
  void set_unit(int32_t value) {}
  void set_unit_name(const char* data, size_t size) {}
  void set_unit_multiplier(int64_t value) {}
  void set_is_incremental(bool value) {}

  int32_t unit() const { return 0; }
  const std::string& unit_name() const { static std::string s; return s; }
  int64_t unit_multiplier() const { return 0; }
  bool is_incremental() const { return false; }
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_COUNTER_DESCRIPTOR_PBZERO_H_
