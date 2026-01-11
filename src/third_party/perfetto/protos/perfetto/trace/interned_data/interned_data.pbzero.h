// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_INTERNED_DATA_INTERNED_DATA_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_INTERNED_DATA_INTERNED_DATA_PBZERO_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {
namespace pbzero {

// Forward declarations for nested message types
class SourceLocation;
class LogMessageBody;
class InternedString;
class Mapping;
class Frame;
class Callstack;
class EventCategory;
class EventName;
class DebugAnnotationName;
class DebugAnnotationValueTypeName;
class HistogramName;

// Stub for InternedData protobuf message
class InternedData {
 public:
  InternedData() = default;
  ~InternedData() = default;

  // Field numbers for protobuf fields
  static constexpr int kEventCategoriesFieldNumber = 1;
  static constexpr int kEventNamesFieldNumber = 2;
  static constexpr int kDebugAnnotationNamesFieldNumber = 3;
  static constexpr int kSourceLocationsFieldNumber = 4;
  static constexpr int kDebugAnnotationValueTypeNamesFieldNumber = 5;
  static constexpr int kUnsymbolizedSourceLocationsFieldNumber = 6;
  static constexpr int kLogMessageBodyFieldNumber = 20;
  static constexpr int kBuildIdsFieldNumber = 16;
  static constexpr int kMappingPathsFieldNumber = 17;
  static constexpr int kFunctionNamesFieldNumber = 18;
  static constexpr int kMappingsFieldNumber = 19;
  static constexpr int kFramesFieldNumber = 6;
  static constexpr int kCallstacksFieldNumber = 7;
  static constexpr int kHistogramNamesFieldNumber = 25;

  // Stub methods - return dummy nested message pointers
  template <typename T>
  T* add_source_locations() { return nullptr; }

  template <typename T>
  T* add_log_message_body() { return nullptr; }

  template <typename T>
  T* add_build_ids() { return nullptr; }

  template <typename T>
  T* add_mapping_paths() { return nullptr; }

  template <typename T>
  T* add_function_names() { return nullptr; }

  template <typename T>
  T* add_mappings() { return nullptr; }

  template <typename T>
  T* add_frames() { return nullptr; }

  template <typename T>
  T* add_callstacks() { return nullptr; }

  template <typename T>
  T* add_event_categories() { return nullptr; }

  template <typename T>
  T* add_event_names() { return nullptr; }

  template <typename T>
  T* add_debug_annotation_names() { return nullptr; }

  template <typename T>
  T* add_debug_annotation_value_type_names() { return nullptr; }

  template <typename T>
  T* add_histogram_names() { return nullptr; }

  // Stub methods - do nothing
  void set_iid(uint64_t) {}
  void set_value(const char*) {}
};

// Stub SourceLocation message
class SourceLocation {
 public:
  void set_iid(uint64_t) {}
  void set_file_name(const char*) {}
  void set_file_name(const std::string&) {}
  void set_function_name(const char*) {}
  void set_function_name(const std::string&) {}
  void set_line_number(uint32_t) {}
};

// Stub LogMessageBody message
class LogMessageBody {
 public:
  void set_iid(uint64_t) {}
  void set_body(const char*) {}
  void set_body(const std::string&) {}
};

// Stub InternedString message
class InternedString {
 public:
  void set_iid(uint64_t) {}
  void set_str(const char*) {}
  void set_str(const char*, size_t) {}
  void set_str(const std::string&) {}
};

// Stub EventCategory message
class EventCategory {
 public:
  void set_iid(uint64_t) {}
  void set_name(const char*) {}
  void set_name(const char*, size_t) {}
  void set_name(const std::string&) {}
};

// Stub EventName message
class EventName {
 public:
  void set_iid(uint64_t) {}
  void set_name(const char*) {}
  void set_name(const std::string&) {}
};

// Stub DebugAnnotationName message
class DebugAnnotationName {
 public:
  void set_iid(uint64_t) {}
  void set_name(const char*) {}
  void set_name(const std::string&) {}
};

// Stub DebugAnnotationValueTypeName message
class DebugAnnotationValueTypeName {
 public:
  void set_iid(uint64_t) {}
  void set_name(const char*) {}
  void set_name(const std::string&) {}
};

// Stub HistogramName message
class HistogramName {
 public:
  void set_iid(uint64_t) {}
  void set_name(const char*) {}
  void set_name(const std::string&) {}
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_INTERNED_DATA_INTERNED_DATA_PBZERO_H_
