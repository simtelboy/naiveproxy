// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_TRACING_INTERNAL_TRACK_EVENT_INTERNAL_H_
#define INCLUDE_PERFETTO_TRACING_INTERNAL_TRACK_EVENT_INTERNAL_H_

#include <memory>
#include <utility>

// Forward declarations to avoid circular dependencies
namespace perfetto {
namespace protos {
namespace pbzero {
class InternedData;
}  // namespace pbzero
}  // namespace protos

namespace protozero {
template <typename T>
class HeapBuffered;
}  // namespace protozero

namespace internal {

// Stub for BaseTrackEventInternedDataIndex
class BaseTrackEventInternedDataIndex {
 public:
  virtual ~BaseTrackEventInternedDataIndex() = default;
  
#if PERFETTO_DCHECK_IS_ON()
  const char* type_id_ = nullptr;
  void* add_function_ptr_ = nullptr;
#endif
};

// Stub for TrackEventIncrementalState
struct TrackEventIncrementalState {
  // Serialized interned data
  std::unique_ptr<protozero::HeapBuffered<protos::pbzero::InternedData>> 
      serialized_interned_data;
  
  // Index for interned data - array of (field_number, index) pairs
  // Using a fixed size array to avoid dynamic allocation
  static constexpr size_t kMaxInternedDataFields = 32;
  std::pair<size_t, std::unique_ptr<BaseTrackEventInternedDataIndex>> 
      interned_data_indices[kMaxInternedDataFields];
  
  TrackEventIncrementalState() {
    // Initialize all field numbers to 0 (unused)
    for (auto& entry : interned_data_indices) {
      entry.first = 0;
    }
  }
};

}  // namespace internal
}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_TRACING_INTERNAL_TRACK_EVENT_INTERNAL_H_
