// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_TRACING_CORE_FORWARD_DECLS_H_
#define INCLUDE_PERFETTO_TRACING_CORE_FORWARD_DECLS_H_

#include <stdint.h>
#include <memory>

namespace perfetto {

// Forward declarations for core tracing types
class TraceConfig;
class TraceStats;
class ObservableEvents;

namespace protos {
namespace gen {
class TraceConfig;
class TraceStats;
class ObservableEvents;
}  // namespace gen
}  // namespace protos

}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_TRACING_CORE_FORWARD_DECLS_H_
