// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_TRACING_EVENT_CONTEXT_H_
#define INCLUDE_PERFETTO_TRACING_EVENT_CONTEXT_H_

#include <memory>

namespace perfetto {

// Forward declarations
namespace protos {
namespace pbzero {
class InternedData;
}
}

namespace protozero {
template <typename T>
class HeapBuffered;
}

namespace internal {
struct TrackEventIncrementalState;
}

// Stub EventContext class
class EventContext {
 public:
  EventContext() = default;
  ~EventContext() = default;
  
  // Stub member - pointer to incremental state
  internal::TrackEventIncrementalState* incremental_state_ = nullptr;
};

}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_TRACING_EVENT_CONTEXT_H_
