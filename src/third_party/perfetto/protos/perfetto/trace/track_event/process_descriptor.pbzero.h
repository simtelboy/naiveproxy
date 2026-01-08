// Copyright 2025 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies

#ifndef THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_PROCESS_DESCRIPTOR_PBZERO_H_
#define THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_PROCESS_DESCRIPTOR_PBZERO_H_

#include <stdint.h>
#include <string>
#include <vector>

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub implementation of ProcessDescriptor
class ProcessDescriptor {
 public:
  ProcessDescriptor() = default;
  ~ProcessDescriptor() = default;

  // Stub methods
  void set_pid(int32_t value) {}
  void set_process_name(const char* data, size_t size) {}
  void add_cmdline(const char* data, size_t size) {}
  void set_process_priority(int32_t value) {}

  int32_t pid() const { return 0; }
  const std::string& process_name() const { static std::string s; return s; }
  const std::vector<std::string>& cmdline() const { static std::vector<std::string> v; return v; }
  int32_t process_priority() const { return 0; }
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_PROCESS_DESCRIPTOR_PBZERO_H_
