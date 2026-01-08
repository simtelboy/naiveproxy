// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_INTERNED_DATA_INTERNED_DATA_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_INTERNED_DATA_INTERNED_DATA_PBZERO_H_

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub for InternedData protobuf message
class InternedData {
 public:
  InternedData() = default;
  ~InternedData() = default;

  // Field numbers for protobuf fields
  static constexpr int kSourceLocationsFieldNumber = 4;
  static constexpr int kLogMessageBodyFieldNumber = 20;
  static constexpr int kBuildIdsFieldNumber = 16;
  static constexpr int kMappingPathsFieldNumber = 17;
  static constexpr int kMappingsFieldNumber = 19;
  static constexpr int kUnsymbolizedSourceLocationsFieldNumber = 6;

  // Stub methods - do nothing
  void set_iid(uint64_t) {}
  void set_value(const char*) {}
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_INTERNED_DATA_INTERNED_DATA_PBZERO_H_
