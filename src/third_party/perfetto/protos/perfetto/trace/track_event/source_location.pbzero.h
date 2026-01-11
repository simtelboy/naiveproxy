// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_SOURCE_LOCATION_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_SOURCE_LOCATION_PBZERO_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {
namespace pbzero {

// Only define if not already defined by interned_data.pbzero.h
#ifndef PERFETTO_PBZERO_SOURCE_LOCATION_DEFINED
#define PERFETTO_PBZERO_SOURCE_LOCATION_DEFINED

// Stub SourceLocation protobuf message
class SourceLocation {
 public:
  SourceLocation() = default;
  ~SourceLocation() = default;

  void set_iid(uint64_t value) {}
  void set_file_name(const char* value) {}
  void set_file_name(const std::string& value) {}
  void set_function_name(const char* value) {}
  void set_function_name(const std::string& value) {}
  void set_line_number(uint32_t value) {}

  uint64_t iid() const { return 0; }
  const std::string& file_name() const { static std::string s; return s; }
  const std::string& function_name() const { static std::string s; return s; }
  uint32_t line_number() const { return 0; }
};

#endif  // PERFETTO_PBZERO_SOURCE_LOCATION_DEFINED

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_SOURCE_LOCATION_PBZERO_H_
