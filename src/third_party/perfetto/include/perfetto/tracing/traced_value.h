// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_TRACING_TRACED_VALUE_H_
#define INCLUDE_PERFETTO_TRACING_TRACED_VALUE_H_

#include <stdint.h>
#include <string>

namespace perfetto {

// Stub Dictionary class
class TracedDictionary {
 public:
  TracedDictionary() = default;
  ~TracedDictionary() = default;
  
  void Add(const char* key, int64_t value) {}
  void Add(const char* key, const char* value) {}
  void Add(const char* key, const std::string& value) {}
};

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
  
  // Add WriteDictionary method
  TracedDictionary WriteDictionary() { return TracedDictionary(); }
};

// Forward declaration for internal types
namespace internal {
struct TrackEventIncrementalState;
}

// Stub EventContext class
class EventContext {
 public:
  EventContext() = default;
  ~EventContext() = default;

  internal::TrackEventIncrementalState* incremental_state_ = nullptr;
};

// Note: WriteIntoTracedValue and other functions are defined in traced_value_forward.h
// to avoid redefinition errors

}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_TRACING_TRACED_VALUE_H_
