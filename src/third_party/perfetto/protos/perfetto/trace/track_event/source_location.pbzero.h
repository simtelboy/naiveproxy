// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_SOURCE_LOCATION_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_SOURCE_LOCATION_PBZERO_H_

#include <string>

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub SourceLocation protobuf message
class SourceLocation {
 public:
  SourceLocation() = default;
  ~SourceLocation() = default;

  void set_file_name(const std::string& value) {}
  void set_function_name(const std::string& value) {}
  void set_line_number(uint32_t value) {}

  const std::string& file_name() const { static std::string s; return s; }
  const std::string& function_name() const { static std::string s; return s; }
  uint32_t line_number() const { return 0; }
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_SOURCE_LOCATION_PBZERO_H_
