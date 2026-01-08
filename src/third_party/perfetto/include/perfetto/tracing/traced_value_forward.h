// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_TRACING_TRACED_VALUE_FORWARD_H_
#define INCLUDE_PERFETTO_TRACING_TRACED_VALUE_FORWARD_H_

#include <utility>

namespace perfetto {

// Forward declaration
class TracedValue;
class EventContext;

// Stub for traced value support check
template <typename T>
struct check_traced_value_support {
  static constexpr bool value = false;
  using type = void;  // Add type member for SFINAE
};

// Type alias for convenience
template <typename T>
using check_traced_value_support_t = typename check_traced_value_support<T>::type;

// Base template for TraceFormatTraits (needed for specializations)
template <typename T, typename Enable = void>
struct TraceFormatTraits;

// Stub function for writing values into traced context
template <typename T>
inline void WriteIntoTracedValue(TracedValue&& context, const T& value) {
  // Empty stub - does nothing
}

// Stub function for writing into traced proto
template <typename T>
inline void WriteIntoTracedProto(TracedValue&& context, const T& value) {
  // Empty stub - does nothing
}

// Stub StaticString class - matches string_helpers.h definition
class StaticString {
 public:
  template <size_t N>
  constexpr StaticString(const char (&str)[N]) : value(str) {}
  constexpr StaticString(std::nullptr_t) : value(nullptr) {}
  constexpr explicit StaticString(const char* str) : value(str) {}
  operator bool() const { return !!value; }
  const char* value;
};

// Stub NamedTrack class (remove unused field warning)
class NamedTrack {
 public:
  NamedTrack() = default;
  explicit NamedTrack(const char*) {}
};

}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_TRACING_TRACED_VALUE_FORWARD_H_
