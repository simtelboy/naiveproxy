// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_DEBUG_ANNOTATION_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_DEBUG_ANNOTATION_PBZERO_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub protobuf zero-copy message
class DebugAnnotation {
 public:
  DebugAnnotation() = default;
  virtual ~DebugAnnotation() = default;  // Virtual destructor for inheritance

  // Name setters
  void set_name(const char* data) {}
  void set_name(const char* data, size_t size) {}
  void set_name(const std::string& value) {}
  void set_name_iid(uint64_t value) {}

  // Value setters
  void set_bool_value(bool value) {}
  void set_uint_value(uint64_t value) {}
  void set_int_value(int64_t value) {}
  void set_double_value(double value) {}
  void set_string_value(const char* data) {}
  void set_string_value(const char* data, size_t size) {}
  void set_string_value(const std::string& value) {}
  void set_string_value_iid(uint64_t value) {}
  void set_pointer_value(uint64_t value) {}
  void set_legacy_json_value(const char* data) {}
  void set_legacy_json_value(const char* data, size_t size) {}
  void set_legacy_json_value(const std::string& value) {}

  // Nested value support
  DebugAnnotation* add_dict_entries() { return nullptr; }
  DebugAnnotation* add_array_values() { return nullptr; }
  DebugAnnotation* set_nested_value() { return nullptr; }

  // Proto type name
  void set_proto_type_name(const char* data) {}
  void set_proto_type_name(const char* data, size_t size) {}
  void set_proto_type_name(const std::string& value) {}
  void set_proto_type_name_iid(uint64_t value) {}

  // Proto value
  void set_proto_value(const void* data, size_t size) {}

  // Scattered bytes support for protozero - returns size_t (bytes written)
  template <typename T>
  size_t AppendScatteredBytes(uint32_t field_id, const T* ranges, size_t num_ranges) {
    return 0;
  }

  // Virtual method for derived classes
  virtual void Add(DebugAnnotation*) const {}
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_DEBUG_ANNOTATION_PBZERO_H_
