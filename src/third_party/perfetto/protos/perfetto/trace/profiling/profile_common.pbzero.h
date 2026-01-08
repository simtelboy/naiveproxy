// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_PROFILING_PROFILE_COMMON_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_PROFILING_PROFILE_COMMON_PBZERO_H_

#include <stdint.h>
#include <string>
#include <vector>

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub InternedString protobuf message
class InternedString {
 public:
  InternedString() = default;
  ~InternedString() = default;

  void set_iid(uint64_t value) {}
  void set_str(const std::string& value) {}

  uint64_t iid() const { return 0; }
  const std::string& str() const { static std::string s; return s; }
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_PROFILING_PROFILE_COMMON_PBZERO_H_
