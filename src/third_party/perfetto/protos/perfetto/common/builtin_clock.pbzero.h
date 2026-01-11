// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_COMMON_BUILTIN_CLOCK_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_COMMON_BUILTIN_CLOCK_PBZERO_H_

#include <stdint.h>

namespace perfetto {
namespace protos {
namespace pbzero {

// BuiltinClock enum values
enum BuiltinClock : int32_t {
  BUILTIN_CLOCK_UNKNOWN = 0,
  BUILTIN_CLOCK_REALTIME = 1,
  BUILTIN_CLOCK_REALTIME_COARSE = 2,
  BUILTIN_CLOCK_MONOTONIC = 3,
  BUILTIN_CLOCK_MONOTONIC_COARSE = 4,
  BUILTIN_CLOCK_MONOTONIC_RAW = 5,
  BUILTIN_CLOCK_BOOTTIME = 6,
  BUILTIN_CLOCK_MAX_ID = 63,
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_COMMON_BUILTIN_CLOCK_PBZERO_H_
