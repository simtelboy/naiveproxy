// Copyright 2025 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies

#ifndef THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_TRACK_DESCRIPTOR_GEN_H_
#define THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_TRACK_DESCRIPTOR_GEN_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {

// Forward declarations
class ProcessDescriptor;
class ThreadDescriptor;
class CounterDescriptor;

// Stub implementation of TrackDescriptor
class TrackDescriptor {
 public:
  // SiblingMergeBehavior enum
  enum SiblingMergeBehavior {
    SIBLING_MERGE_BEHAVIOR_UNSPECIFIED = 0,
    SIBLING_MERGE_BEHAVIOR_NONE = 0,
    SIBLING_MERGE_BEHAVIOR_BY_SIBLING_MERGE_KEY = 1,
    SIBLING_MERGE_BEHAVIOR_MERGE_BY_KEY = 1,
  };

  TrackDescriptor() = default;
  ~TrackDescriptor() = default;

  // Stub methods
  void set_uuid(uint64_t value) {}
  void set_parent_uuid(uint64_t value) {}
  void set_name(const std::string& value) {}
  ProcessDescriptor* mutable_process() { static ProcessDescriptor p; return &p; }
  ThreadDescriptor* mutable_thread() { static ThreadDescriptor t; return &t; }
  CounterDescriptor* mutable_counter() { static CounterDescriptor c; return &c; }

  uint64_t uuid() const { return 0; }
  uint64_t parent_uuid() const { return 0; }
  const std::string& name() const { static std::string s; return s; }
  const ProcessDescriptor& process() const { static ProcessDescriptor p; return p; }
  const ThreadDescriptor& thread() const { static ThreadDescriptor t; return t; }
  const CounterDescriptor& counter() const { static CounterDescriptor c; return c; }
};

// Create gen namespace alias for compatibility
namespace gen {
using TrackDescriptor = ::perfetto::protos::TrackDescriptor;
using ProcessDescriptor = ::perfetto::protos::ProcessDescriptor;
using ThreadDescriptor = ::perfetto::protos::ThreadDescriptor;
using CounterDescriptor = ::perfetto::protos::CounterDescriptor;
}  // namespace gen

}  // namespace protos
}  // namespace perfetto

#endif  // THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACK_EVENT_TRACK_DESCRIPTOR_GEN_H_
