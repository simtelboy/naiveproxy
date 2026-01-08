// Copyright 2025 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies

#ifndef THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_THREAD_DESCRIPTOR_GEN_H_
#define THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_THREAD_DESCRIPTOR_GEN_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {

// Stub implementation of ThreadDescriptor
class ThreadDescriptor {
 public:
  ThreadDescriptor() = default;
  ~ThreadDescriptor() = default;

  // Stub methods
  void set_pid(int32_t value) {}
  void set_tid(int32_t value) {}
  void set_thread_name(const std::string& value) {}
  void set_thread_priority(int32_t value) {}

  int32_t pid() const { return 0; }
  int32_t tid() const { return 0; }
  const std::string& thread_name() const { static std::string s; return s; }
  int32_t thread_priority() const { return 0; }
};

}  // namespace protos
}  // namespace perfetto

#endif  // THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_THREAD_DESCRIPTOR_GEN_H_
