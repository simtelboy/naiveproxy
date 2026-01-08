// Copyright 2025 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies
#ifndef THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACE_PACKET_PBZERO_H_
#define THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACE_PACKET_PBZERO_H_

#include <stdint.h>

namespace perfetto {
namespace protos {
namespace pbzero {

// Forward declaration
class TrackDescriptor;

// Stub for TracePacket
class TracePacket {
 public:
  TracePacket() = default;
  ~TracePacket() = default;

  // Stub methods
  void set_timestamp(uint64_t value) {}
  uint64_t timestamp() const { return 0; }

  void set_timestamp_clock_id(uint32_t value) {}
  uint32_t timestamp_clock_id() const { return 0; }

  TrackDescriptor* set_track_descriptor() { static TrackDescriptor t; return &t; }
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // THIRD_PARTY_PERFETTO_PROTOS_PERFETTO_TRACE_TRACE_PACKET_PBZERO_H_
