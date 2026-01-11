// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_TRACING_CORE_FORWARD_DECLS_H_
#define INCLUDE_PERFETTO_TRACING_CORE_FORWARD_DECLS_H_

#include <stdint.h>
#include <string>
#include <memory>

// Include the actual class definitions
#include "protos/perfetto/config/data_source_config.gen.h"
#include "protos/perfetto/common/data_source_descriptor.gen.h"
#include "protos/perfetto/config/interceptor_config.gen.h"

namespace perfetto {

// Create aliases in the perfetto namespace
// This is the standard pattern used by Perfetto to expose proto types
using DataSourceConfig = ::perfetto::protos::gen::DataSourceConfig;
using DataSourceDescriptor = ::perfetto::protos::gen::DataSourceDescriptor;
using InterceptorDescriptor = ::perfetto::protos::gen::InterceptorDescriptor;

}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_TRACING_CORE_FORWARD_DECLS_H_
