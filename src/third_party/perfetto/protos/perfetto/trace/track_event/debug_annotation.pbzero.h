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

  void set_name(const char* data, size_t size) {}
  void set_bool_value(bool value) {}
  void set_uint_value(uint64_t value) {}
  void set_int_value(int64_t value) {}
  void set_double_value(double value) {}
  void set_string_value(const char* data, size_t size) {}
  void set_pointer_value(uint64_t value) {}
  void set_legacy_json_value(const std::string& value) {}

  // Scattered bytes support
  struct ScatteredBytes {
    const void* data;
    size_t size;
  };

  void AppendScatteredBytes(uint32_t field_id, const ScatteredBytes* ranges, size_t num_ranges) {}

  // Virtual method for derived classes
  virtual void Add(DebugAnnotation*) const {}
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_DEBUG_ANNOTATION_PBZERO_H_
