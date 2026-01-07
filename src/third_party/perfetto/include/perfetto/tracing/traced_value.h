// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_TRACING_TRACED_VALUE_H_
#define INCLUDE_PERFETTO_TRACING_TRACED_VALUE_H_

#include <stdint.h>
#include <string>
#include <utility>

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

// Stub function for writing values into traced context
template <typename T>
inline void WriteIntoTracedValue(TracedValue&& context, const T& value) {
  // Empty stub - does nothing
}

}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_TRACING_TRACED_VALUE_H_
