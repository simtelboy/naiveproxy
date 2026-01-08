// Copyright 2025 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies
#ifndef THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_MOJO_EVENT_INFO_PBZERO_H_
#define THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_MOJO_EVENT_INFO_PBZERO_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub implementation of ChromeMojoEventInfo
class ChromeMojoEventInfo {
 public:
  ChromeMojoEventInfo() = default;
  ~ChromeMojoEventInfo() = default;

  // Stub methods
  void set_mojo_interface_tag(const char* value) {}
  const char* mojo_interface_tag() const { return ""; }

  void set_ipc_hash(uint32_t value) {}
  uint32_t ipc_hash() const { return 0; }

  void set_is_reply(bool value) {}
  bool is_reply() const { return false; }

  void set_mojo_interface_method_iid(uint64_t value) {}
  uint64_t mojo_interface_method_iid() const { return 0; }
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_CHROME_MOJO_EVENT_INFO_PBZERO_H_
