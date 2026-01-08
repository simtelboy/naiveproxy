// Copyright 2025 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies

#ifndef THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_THREAD_DESCRIPTOR_PBZERO_H_
#define THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_THREAD_DESCRIPTOR_PBZERO_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub implementation of ThreadDescriptor
class ThreadDescriptor {
 public:
  ThreadDescriptor() = default;
  ~ThreadDescriptor() = default;

  // Stub methods
  void set_pid(int32_t value) {}
  void set_tid(int32_t value) {}
  void set_thread_name(const char* data, size_t size) {}
  void set_thread_priority(int32_t value) {}

  int32_t pid() const { return 0; }
  int32_t tid() const { return 0; }
  const std::string& thread_name() const { static std::string s; return s; }
  int32_t thread_priority() const { return 0; }
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_THREAD_DESCRIPTOR_PBZERO_H_
