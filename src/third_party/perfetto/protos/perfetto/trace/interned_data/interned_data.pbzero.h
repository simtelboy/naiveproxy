// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_INTERNED_DATA_INTERNED_DATA_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_INTERNED_DATA_INTERNED_DATA_PBZERO_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {
namespace pbzero {

// Forward declarations - these are defined in their own headers
// Do NOT define them here to avoid redefinition errors
class SourceLocation;
class LogMessageBody;
class InternedString;
class Mapping;
class Frame;
class Callstack;
class UnsymbolizedSourceLocation;

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

  // Non-template add methods that return pointers to stub types
  SourceLocation* add_source_locations();
  LogMessageBody* add_log_message_body();
  InternedString* add_build_ids();
  InternedString* add_mapping_paths();
  InternedString* add_function_names();
  Mapping* add_mappings();
  Frame* add_frames();
  Callstack* add_callstacks();
  UnsymbolizedSourceLocation* add_unsymbolized_source_locations();

  // Stub EventCategory for interning
  class EventCategory {
   public:
    void set_iid(uint64_t) {}
    void set_name(const char*) {}
    void set_name(const char*, size_t) {}
    void set_name(const std::string&) {}
  };
  EventCategory* add_event_categories() { return nullptr; }

  // Stub EventName for interning
  class EventName {
   public:
    void set_iid(uint64_t) {}
    void set_name(const char*) {}
    void set_name(const std::string&) {}
  };
  EventName* add_event_names() { return nullptr; }

  // Stub DebugAnnotationName for interning
  class DebugAnnotationName {
   public:
    void set_iid(uint64_t) {}
    void set_name(const char*) {}
    void set_name(const std::string&) {}
  };
  DebugAnnotationName* add_debug_annotation_names() { return nullptr; }

  // Stub DebugAnnotationValueTypeName for interning
  class DebugAnnotationValueTypeName {
   public:
    void set_iid(uint64_t) {}
    void set_name(const char*) {}
    void set_name(const std::string&) {}
  };
  DebugAnnotationValueTypeName* add_debug_annotation_value_type_names() { return nullptr; }

  // Stub HistogramName for interning
  class HistogramName {
   public:
    void set_iid(uint64_t) {}
    void set_name(const char*) {}
    void set_name(const std::string&) {}
  };
  HistogramName* add_histogram_names() { return nullptr; }

  // Stub methods - do nothing
  void set_iid(uint64_t) {}
  void set_value(const char*) {}
};

// Inline implementations - return nullptr for all
inline SourceLocation* InternedData::add_source_locations() { return nullptr; }
inline LogMessageBody* InternedData::add_log_message_body() { return nullptr; }
inline InternedString* InternedData::add_build_ids() { return nullptr; }
inline InternedString* InternedData::add_mapping_paths() { return nullptr; }
inline InternedString* InternedData::add_function_names() { return nullptr; }
inline Mapping* InternedData::add_mappings() { return nullptr; }
inline Frame* InternedData::add_frames() { return nullptr; }
inline Callstack* InternedData::add_callstacks() { return nullptr; }
inline UnsymbolizedSourceLocation* InternedData::add_unsymbolized_source_locations() { return nullptr; }

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_INTERNED_DATA_INTERNED_DATA_PBZERO_H_
