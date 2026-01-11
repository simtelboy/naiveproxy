// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_TRACING_TRACED_VALUE_FORWARD_H_
#define INCLUDE_PERFETTO_TRACING_TRACED_VALUE_FORWARD_H_

#include <cstddef>
#include <cstring>
#include <string>
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

// DynamicString class - for runtime strings
class DynamicString {
 public:
  explicit DynamicString(const std::string& str)
      : value(str.data()), length(str.length()) {}
  explicit DynamicString(const char* str) : value(str) {
    length = str ? strlen(str) : 0;
  }
  DynamicString(const char* str, size_t len) : value(str), length(len) {}
  constexpr DynamicString() : value(nullptr), length(0) {}

  operator bool() const { return !!value; }

  const char* value;
  size_t length;
};

// Stub TracedArray class
class TracedArray {
 public:
  TracedArray() = default;
  ~TracedArray() = default;

  template <typename T>
  void Append(const T& value) {}
};

// Stub TracedDictionary class
class TracedDictionary {
 public:
  TracedDictionary() = default;
  ~TracedDictionary() = default;

  template <typename T>
  void Add(const char* key, const T& value) {}

  template <typename T>
  void Add(DynamicString key, const T& value) {}

  void Add(const char* key, int64_t value) {}
  void Add(const char* key, const char* value) {}
  void Add(const char* key, const std::string& value) {}
  void Add(DynamicString key, int64_t value) {}
  void Add(DynamicString key, const char* value) {}
  void Add(DynamicString key, const std::string& value) {}
};

// Stub TracedValue class - main traced value type
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

  // Add WriteDictionary method
  TracedDictionary WriteDictionary() { return TracedDictionary(); }

  // Add WriteArray method
  TracedArray WriteArray() { return TracedArray(); }
};

// Forward declaration of NamedTrack
// Full definition is in trace_event_common.h or perfetto/tracing/track.h
#ifndef PERFETTO_NAMED_TRACK_DEFINED
#ifndef PERFETTO_NAMED_TRACK_DECLARED
#define PERFETTO_NAMED_TRACK_DECLARED
class NamedTrack;
#endif
#endif

}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_TRACING_TRACED_VALUE_FORWARD_H_
