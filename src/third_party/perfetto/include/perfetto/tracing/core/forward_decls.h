// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_TRACING_CORE_FORWARD_DECLS_H_
#define INCLUDE_PERFETTO_TRACING_CORE_FORWARD_DECLS_H_

// If trace_event_common.h has already been included, skip this file
// to avoid redefinition errors
#ifdef BASE_TRACE_EVENT_COMMON_TRACE_EVENT_COMMON_H_
// Types already defined in trace_event_common.h
#else

#include <stdint.h>
#include <string>
#include <memory>

// Include the actual class definitions
#include "protos/perfetto/config/data_source_config.gen.h"
#include "protos/perfetto/common/data_source_descriptor.gen.h"
#include "protos/perfetto/config/interceptor_config.gen.h"
#include "protos/perfetto/config/trace_config.gen.h"

namespace perfetto {

// Create aliases in the perfetto namespace
// This is the standard pattern used by Perfetto to expose proto types
using DataSourceConfig = ::perfetto::protos::gen::DataSourceConfig;
using DataSourceDescriptor = ::perfetto::protos::gen::DataSourceDescriptor;
using InterceptorDescriptor = ::perfetto::protos::gen::InterceptorDescriptor;
using TraceConfig = ::perfetto::protos::gen::TraceConfig;

}  // namespace perfetto

#endif  // BASE_TRACE_EVENT_COMMON_TRACE_EVENT_COMMON_H_

#endif  // INCLUDE_PERFETTO_TRACING_CORE_FORWARD_DECLS_H_
