// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_PROFILING_PROFILE_COMMON_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_PROFILING_PROFILE_COMMON_PBZERO_H_

#include <stdint.h>
#include <string>
#include <vector>

namespace perfetto {
namespace protos {
namespace pbzero {

// Only define if not already defined
#ifndef PERFETTO_PBZERO_INTERNED_STRING_DEFINED
#define PERFETTO_PBZERO_INTERNED_STRING_DEFINED

// Stub InternedString protobuf message
class InternedString {
 public:
  InternedString() = default;
  ~InternedString() = default;

  void set_iid(uint64_t value) {}
  void set_str(const char* value) {}
  void set_str(const char* value, size_t len) {}
  void set_str(const std::string& value) {}

  uint64_t iid() const { return 0; }
  const std::string& str() const { static std::string s; return s; }
};

#endif  // PERFETTO_PBZERO_INTERNED_STRING_DEFINED

// Stub Mapping protobuf message
#ifndef PERFETTO_PBZERO_MAPPING_DEFINED
#define PERFETTO_PBZERO_MAPPING_DEFINED

class Mapping {
 public:
  Mapping() = default;
  ~Mapping() = default;

  void set_iid(uint64_t value) {}
  void set_build_id(uint64_t value) {}
  void add_path_string_ids(uint64_t value) {}
  void set_exact_offset(uint64_t value) {}
  void set_start_offset(uint64_t value) {}
  void set_start(uint64_t value) {}
  void set_end(uint64_t value) {}
  void set_load_bias(uint64_t value) {}
};

#endif  // PERFETTO_PBZERO_MAPPING_DEFINED

// Stub Frame protobuf message
#ifndef PERFETTO_PBZERO_FRAME_DEFINED
#define PERFETTO_PBZERO_FRAME_DEFINED

class Frame {
 public:
  Frame() = default;
  ~Frame() = default;

  void set_iid(uint64_t value) {}
  void set_function_name_id(uint64_t value) {}
  void set_mapping_id(uint64_t value) {}
  void set_rel_pc(uint64_t value) {}
};

#endif  // PERFETTO_PBZERO_FRAME_DEFINED

// Stub Callstack protobuf message
#ifndef PERFETTO_PBZERO_CALLSTACK_DEFINED
#define PERFETTO_PBZERO_CALLSTACK_DEFINED

class Callstack {
 public:
  Callstack() = default;
  ~Callstack() = default;

  void set_iid(uint64_t value) {}
  void add_frame_ids(uint64_t value) {}
};

#endif  // PERFETTO_PBZERO_CALLSTACK_DEFINED

// Stub LogMessageBody protobuf message
#ifndef PERFETTO_PBZERO_LOG_MESSAGE_BODY_DEFINED
#define PERFETTO_PBZERO_LOG_MESSAGE_BODY_DEFINED

class LogMessageBody {
 public:
  LogMessageBody() = default;
  ~LogMessageBody() = default;

  void set_iid(uint64_t value) {}
  void set_body(const char* value) {}
  void set_body(const std::string& value) {}
};

#endif  // PERFETTO_PBZERO_LOG_MESSAGE_BODY_DEFINED

// Stub UnsymbolizedSourceLocation protobuf message
#ifndef PERFETTO_PBZERO_UNSYMBOLIZED_SOURCE_LOCATION_DEFINED
#define PERFETTO_PBZERO_UNSYMBOLIZED_SOURCE_LOCATION_DEFINED

class UnsymbolizedSourceLocation {
 public:
  UnsymbolizedSourceLocation() = default;
  ~UnsymbolizedSourceLocation() = default;

  void set_iid(uint64_t value) {}
  void set_mapping_id(uint64_t value) {}
  void set_rel_pc(uint64_t value) {}
};

#endif  // PERFETTO_PBZERO_UNSYMBOLIZED_SOURCE_LOCATION_DEFINED

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_PROFILING_PROFILE_COMMON_PBZERO_H_
