// Copyright 2015 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_TRACE_EVENT_COMMON_TRACE_EVENT_COMMON_H_
#define BASE_TRACE_EVENT_COMMON_TRACE_EVENT_COMMON_H_

// Stub implementation for OpenHarmony - Perfetto tracing disabled

////////////////////////////////////////////////////////////////////////////////
// Stub trace macros

#include "base/threading/platform_thread.h"
#include "base/time/time.h"
#include "build/build_config.h"

// Disable Perfetto tracing for OpenHarmony
#define PERFETTO_ENABLE_LEGACY_TRACE_EVENTS 0

// Macros for reading the current trace time (bypassing any virtual time
// overrides).
#define TRACE_TIME_TICKS_NOW() ::base::subtle::TimeTicksNowIgnoringOverride()
#define TRACE_TIME_NOW() ::base::subtle::TimeNowIgnoringOverride()

// Implementation detail: trace event macros create temporary variables
// to keep instrumentation overhead low. These macros give each temporary
// variable a unique name based on the line number to prevent name collisions.
#define INTERNAL_TRACE_EVENT_UID(name_prefix) name_prefix##__LINE__

// Stub macros to replace Perfetto trace event macros
#define PERFETTO_UID(name_prefix) name_prefix##__LINE__
#define PERFETTO_DEFINE_TEST_CATEGORY_PREFIXES(...)
#define PERFETTO_DEFINE_CATEGORIES_IN_NAMESPACE_WITH_ATTRS(ns, attrs, ...)
#define PERFETTO_USE_CATEGORIES_FROM_NAMESPACE(ns)

// Category name macro for disabled-by-default categories
#define TRACE_DISABLED_BY_DEFAULT(name) "disabled-by-default-" name

// Trace value type constants
#define TRACE_VALUE_TYPE_BOOL 1
#define TRACE_VALUE_TYPE_UINT 2
#define TRACE_VALUE_TYPE_INT 3
#define TRACE_VALUE_TYPE_DOUBLE 4
#define TRACE_VALUE_TYPE_POINTER 5
#define TRACE_VALUE_TYPE_STRING 6
#define TRACE_VALUE_TYPE_COPY_STRING 7
#define TRACE_VALUE_TYPE_CONVERTABLE 8
#define TRACE_VALUE_TYPE_PROTO 9

// Trace event phase constants
#define TRACE_EVENT_PHASE_BEGIN 'B'
#define TRACE_EVENT_PHASE_END 'E'
#define TRACE_EVENT_PHASE_COMPLETE 'X'
#define TRACE_EVENT_PHASE_INSTANT 'I'
#define TRACE_EVENT_PHASE_ASYNC_BEGIN 'S'
#define TRACE_EVENT_PHASE_ASYNC_STEP_INTO 'T'
#define TRACE_EVENT_PHASE_ASYNC_STEP_PAST 'p'
#define TRACE_EVENT_PHASE_ASYNC_END 'F'
#define TRACE_EVENT_PHASE_NESTABLE_ASYNC_BEGIN 'b'
#define TRACE_EVENT_PHASE_NESTABLE_ASYNC_END 'e'
#define TRACE_EVENT_PHASE_NESTABLE_ASYNC_INSTANT 'n'
#define TRACE_EVENT_PHASE_FLOW_BEGIN 's'
#define TRACE_EVENT_PHASE_FLOW_STEP 't'
#define TRACE_EVENT_PHASE_FLOW_END 'f'
#define TRACE_EVENT_PHASE_METADATA 'M'
#define TRACE_EVENT_PHASE_COUNTER 'C'
#define TRACE_EVENT_PHASE_SAMPLE 'P'
#define TRACE_EVENT_PHASE_CREATE_OBJECT 'N'
#define TRACE_EVENT_PHASE_SNAPSHOT_OBJECT 'O'
#define TRACE_EVENT_PHASE_DELETE_OBJECT 'D'
#define TRACE_EVENT_PHASE_MEMORY_DUMP 'v'
#define TRACE_EVENT_PHASE_MARK 'R'
#define TRACE_EVENT_PHASE_CLOCK_SYNC 'c'
#define TRACE_EVENT_PHASE_ENTER_CONTEXT '('
#define TRACE_EVENT_PHASE_LEAVE_CONTEXT ')'
#define TRACE_EVENT_PHASE_LINK_IDS '='

// Legacy trace event macros - all disabled
#define TRACE_EVENT0(category, name)
#define TRACE_EVENT1(category, name, arg1_name, arg1_val)
#define TRACE_EVENT2(category, name, arg1_name, arg1_val, arg2_name, arg2_val)
#define TRACE_EVENT_INSTANT0(category, name, scope)
#define TRACE_EVENT_BEGIN0(category, name)
#define TRACE_EVENT_END0(category, name)
#define TRACE_EVENT_ASYNC_BEGIN0(category, name, id)
#define TRACE_EVENT_ASYNC_END0(category, name, id)
#define TRACE_EVENT_OBJECT_CREATED_WITH_ID(category, name, id)
#define TRACE_EVENT_OBJECT_SNAPSHOT_WITH_ID(category, name, id, snapshot)
#define TRACE_EVENT_OBJECT_DELETED_WITH_ID(category, name, id)

// Typed tracing macros (with lambda support) - all disabled
#define TRACE_EVENT(category, name, ...) do { (void)(category); (void)(name); } while (0)
#define TRACE_EVENT_INSTANT(category, name, ...) do { (void)(category); (void)(name); } while (0)

// Stub namespace declarations for compatibility
namespace perfetto {

// Forward declarations
namespace protos {
namespace pbzero {
class DebugAnnotation;
}  // namespace pbzero
}  // namespace protos

// Main DebugAnnotation in perfetto namespace (for inheritance)
using DebugAnnotation = protos::pbzero::DebugAnnotation;

class Category {
 public:
  explicit Category(const char*) {}
  Category& SetDescription(const char*) { return *this; }
  template<typename... Args>
  Category& SetTags(Args&&...) { return *this; }
  class Group {
   public:
    explicit Group(const char*) {}
  };
};

// Note: Tracing class is defined in perfetto/tracing/tracing.h
// We don't define it here to avoid conflicts

class ThreadTrack {};

namespace legacy {
template <typename T>
ThreadTrack ConvertThreadId(const T&) { return ThreadTrack(); }
}  // namespace legacy

struct TraceTimestamp {};

template <typename T>
struct TraceTimestampTraits {
  static TraceTimestamp ConvertTimestampToTraceTimeNs(const T&) {
    return TraceTimestamp();
  }
};

namespace internal {
inline void WriteDebugAnnotation(protos::pbzero::DebugAnnotation*, ...) {}

// Stub for traced value support
template <typename T>
struct has_traced_value_support {
  static constexpr bool value = false;
};

// Stub function
template <typename T>
inline void* CreateTracedValueFromProto(T*) { return nullptr; }

}  // namespace internal

// Import protozero namespace for convenience
namespace protozero {}
using namespace protozero;

}  // namespace perfetto

namespace base {
class TrackEvent {
 public:
  template <typename T, typename D>
  static void SetTrackDescriptor(const T&, const D&) {}
  template <typename T>
  static void EraseTrackDescriptor(const T&) {}
};
}  // namespace base

#endif  // BASE_TRACE_EVENT_COMMON_TRACE_EVENT_COMMON_H_
