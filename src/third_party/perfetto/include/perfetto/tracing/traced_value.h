// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_TRACING_TRACED_VALUE_H_
#define INCLUDE_PERFETTO_TRACING_TRACED_VALUE_H_

#include <stdint.h>
#include <string>

// Include forward declarations - use relative path
#include "third_party/perfetto/include/perfetto/tracing/traced_value_forward.h"

namespace perfetto {

// Forward declarations for pbzero types
namespace protos {
namespace pbzero {
class ChromeTrackEvent;
}
}

// TracedDictionary and TracedArray are already defined in traced_value_forward.h
// TracedValue is also defined there

// Forward declaration for internal types
namespace internal {
struct TrackEventIncrementalState;
}

// Forward declare ChromeTrackEvent to avoid include issues
namespace protos {
namespace pbzero {
class ChromeTrackEvent;
class ChromeMemoryPressureNotification;
}
}

// Stub EventContext class
class EventContext {
 public:
  EventContext() = default;
  ~EventContext() = default;

  // Template method to get event
  template <typename T>
  T* event() { return nullptr; }

  // Specialization for ChromeTrackEvent (default when no template arg)
  protos::pbzero::ChromeTrackEvent* event() { return nullptr; }

  internal::TrackEventIncrementalState* incremental_state_ = nullptr;
};

// Stub Flow class for flow tracking
class Flow {
 public:
  // ProcessScoped flow
  static Flow ProcessScoped(uint64_t id) { return Flow(); }

  // Apply flow to context (no-op)
  void operator()(EventContext& ctx) const {}
};

// Stub TerminatingFlow class for terminating flow tracking
class TerminatingFlow {
 public:
  // ProcessScoped terminating flow
  static TerminatingFlow ProcessScoped(uint64_t id) { return TerminatingFlow(); }

  // Apply terminating flow to context (no-op)
  void operator()(EventContext& ctx) const {}
};

// Note: WriteIntoTracedValue and other functions are defined in traced_value_forward.h
// to avoid redefinition errors

}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_TRACING_TRACED_VALUE_H_
