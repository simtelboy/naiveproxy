// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_TRACING_TRACED_VALUE_H_
#define INCLUDE_PERFETTO_TRACING_TRACED_VALUE_H_

#include <stdint.h>
#include <string>

namespace perfetto {

// Stub implementation
class TracedValue {
 public:
  TracedValue() = default;
  ~TracedValue() = default;

  void WriteInt64(int64_t value) {}
  void WriteUInt64(uint64_t value) {}
  void WriteDouble(double value) {}
  void WriteBoolean(bool value) {}
  void WriteString(const char* value) {}
  void WriteString(const std::string& value) {}
  void WritePointer(const void* value) {}
};

}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_TRACING_TRACED_VALUE_H_
