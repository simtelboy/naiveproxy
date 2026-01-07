// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_TRACING_TRACED_VALUE_FORWARD_H_
#define INCLUDE_PERFETTO_TRACING_TRACED_VALUE_FORWARD_H_

#include <utility>

namespace perfetto {

// Forward declaration
class TracedValue;

// Stub for traced value support check
template <typename T>
struct check_traced_value_support {
  static constexpr bool value = false;
  using type = void;  // Add type member for SFINAE
};

// Stub function for writing values into traced context
// This must be declared here so it's available when strong_alias.h includes this file
template <typename T>
inline void WriteIntoTracedValue(TracedValue&& context, const T& value) {
  // Empty stub - does nothing
}

}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_TRACING_TRACED_VALUE_FORWARD_H_
