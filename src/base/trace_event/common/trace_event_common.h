// Copyright 2015 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_TRACE_EVENT_COMMON_TRACE_EVENT_COMMON_H_
#define BASE_TRACE_EVENT_COMMON_TRACE_EVENT_COMMON_H_

#include "base/threading/platform_thread.h"
#include "base/time/time.h"
#include "base/tracing_buildflags.h"
#include "build/build_config.h"

// Macros for reading the current trace time (bypassing any virtual time
// overrides).
#define TRACE_TIME_TICKS_NOW() ::base::subtle::TimeTicksNowIgnoringOverride()
#define TRACE_TIME_NOW() ::base::subtle::TimeNowIgnoringOverride()

// Implementation detail: trace event macros create temporary variables
// to keep instrumentation overhead low. These macros give each temporary
// variable a unique name based on the line number to prevent name collisions.
#define INTERNAL_TRACE_EVENT_UID(name_prefix) name_prefix##__LINE__

// Category name macro for disabled-by-default categories
#define TRACE_DISABLED_BY_DEFAULT(name) "disabled-by-default-" name

// Trace ID macros
#define TRACE_ID_LOCAL(id) (id)

#if BUILDFLAG(ENABLE_BASE_TRACING)
// When tracing is enabled, include the real Perfetto implementation
// The actual macros and types come from Perfetto headers
#else
// Stub implementation for when Perfetto tracing is disabled (e.g., cronet builds)

// Disable Perfetto tracing
#define PERFETTO_ENABLE_LEGACY_TRACE_EVENTS 0

// Stub macros to replace Perfetto trace event macros
#define PERFETTO_UID(name_prefix) name_prefix##__LINE__
#define PERFETTO_DEFINE_TEST_CATEGORY_PREFIXES(...)
#define PERFETTO_DEFINE_CATEGORIES_IN_NAMESPACE_WITH_ATTRS(ns, attrs, ...)
#define PERFETTO_USE_CATEGORIES_FROM_NAMESPACE(ns)
#define PERFETTO_TRACK_EVENT_STATIC_STORAGE_IN_NAMESPACE_WITH_ATTRS(ns, attrs)

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
#define TRACE_EVENT_BEGIN1(category, name, arg1_name, arg1_val)
#define TRACE_EVENT_BEGIN2(category, name, arg1_name, arg1_val, arg2_name, arg2_val)
#define TRACE_EVENT_END0(category, name)
#define TRACE_EVENT_END1(category, name, arg1_name, arg1_val)
#define TRACE_EVENT_END2(category, name, arg1_name, arg1_val, arg2_name, arg2_val)
// Support both 1 and 2+ arguments
#define TRACE_EVENT_BEGIN(...) do { } while (0)
#define TRACE_EVENT_END(...) do { } while (0)
#define TRACE_EVENT_ASYNC_BEGIN0(category, name, id)
#define TRACE_EVENT_ASYNC_END0(category, name, id)
#define TRACE_EVENT_OBJECT_CREATED_WITH_ID(category, name, id)
#define TRACE_EVENT_OBJECT_SNAPSHOT_WITH_ID(category, name, id, snapshot)
#define TRACE_EVENT_OBJECT_DELETED_WITH_ID(category, name, id)
#define TRACE_EVENT_WITH_FLOW0(category, name, id, flags)
#define TRACE_COUNTER_ID1(category, name, id, value) do { (void)(category); (void)(name); (void)(id); (void)(value); } while (0)
#define TRACE_COUNTER(category, name, value) do { (void)(category); (void)(name); (void)(value); } while (0)

// Trace event flags
#define TRACE_EVENT_FLAG_NONE 0
#define TRACE_EVENT_FLAG_COPY (1u << 0)
#define TRACE_EVENT_FLAG_HAS_ID (1u << 1)
#define TRACE_EVENT_FLAG_SCOPE_OFFSET (1u << 2)
#define TRACE_EVENT_FLAG_SCOPE_EXTRA (1u << 3)
#define TRACE_EVENT_FLAG_EXPLICIT_TIMESTAMP (1u << 4)
#define TRACE_EVENT_FLAG_ASYNC_TTS (1u << 5)
#define TRACE_EVENT_FLAG_BIND_TO_ENCLOSING (1u << 6)
#define TRACE_EVENT_FLAG_FLOW_IN (1u << 7)
#define TRACE_EVENT_FLAG_FLOW_OUT (1u << 8)
#define TRACE_EVENT_FLAG_HAS_CONTEXT_ID (1u << 9)
#define TRACE_EVENT_FLAG_HAS_PROCESS_ID (1u << 10)
#define TRACE_EVENT_FLAG_HAS_LOCAL_ID (1u << 11)
#define TRACE_EVENT_FLAG_HAS_GLOBAL_ID (1u << 12)
#define TRACE_EVENT_FLAG_TYPED_PROTO_ARGS (1u << 15)
#define TRACE_EVENT_FLAG_JAVA_STRING_LITERALS (1u << 16)

// Scope mask for extracting scope from flags
#define TRACE_EVENT_FLAG_SCOPE_MASK \
  (static_cast<unsigned int>(TRACE_EVENT_FLAG_SCOPE_OFFSET | \
                             TRACE_EVENT_FLAG_SCOPE_EXTRA))

// Trace event scope
#define TRACE_EVENT_SCOPE_THREAD 0
#define TRACE_EVENT_SCOPE_PROCESS 1
#define TRACE_EVENT_SCOPE_GLOBAL 2

// Trace event scope names
#define TRACE_EVENT_SCOPE_NAME_GLOBAL "g"
#define TRACE_EVENT_SCOPE_NAME_PROCESS "p"
#define TRACE_EVENT_SCOPE_NAME_THREAD "t"

// Trace event API macros
#define TRACE_EVENT_API_GET_CATEGORY_GROUP_ENABLED(category) \
  (static_cast<const unsigned char*>(nullptr))
#define TRACE_EVENT_CATEGORY_GROUP_ENABLED(category, ret) \
  do { *(ret) = false; } while (0)
#define TRACE_EVENT_CATEGORY_ENABLED(category) (false)
#define TRACE_EVENT_API_GET_CATEGORY_GROUP_NAME(category) ""

// Typed tracing macros (with lambda support) - all disabled
#define TRACE_EVENT(category, name, ...) do { (void)(category); (void)(name); } while (0)
#define TRACE_EVENT_INSTANT(category, name, ...) do { (void)(category); (void)(name); } while (0)
#define TRACE_EVENT_INSTANT1(category, name, scope, arg1_name, arg1_val) do { (void)(category); (void)(name); (void)(scope); (void)(arg1_name); (void)(arg1_val); } while (0)
#define TRACE_COUNTER1(category, name, value) do { (void)(category); (void)(name); (void)(value); } while (0)

// String copy macro for trace arguments
#define TRACE_STR_COPY(str) (str)

// Async event macros
#define TRACE_EVENT_NESTABLE_ASYNC_BEGIN0(category, name, id) do { (void)(category); (void)(name); (void)(id); } while (0)
#define TRACE_EVENT_NESTABLE_ASYNC_BEGIN1(category, name, id, arg1_name, arg1_val) do { (void)(category); (void)(name); (void)(id); (void)(arg1_name); (void)(arg1_val); } while (0)
#define TRACE_EVENT_NESTABLE_ASYNC_END0(category, name, id) do { (void)(category); (void)(name); (void)(id); } while (0)

// Stub namespace declarations for compatibility
namespace perfetto {

// Forward declarations
namespace protos {
namespace pbzero {
class DebugAnnotation;
}  // namespace pbzero

namespace gen {
class DataSourceConfig;
class TrackEventConfig;
}  // namespace gen
}  // namespace protos

// Main DebugAnnotation in perfetto namespace (for inheritance)
using DebugAnnotation = protos::pbzero::DebugAnnotation;

// Use the gen namespace types
using DataSourceConfig = protos::gen::DataSourceConfig;
using TrackEventConfig = protos::gen::TrackEventConfig;

// DataSourceBase stub with SetupArgs and StopArgs
class DataSourceBase {
 public:
  virtual ~DataSourceBase() = default;

  struct SetupArgs {
    const DataSourceConfig* config = nullptr;
    uint32_t internal_instance_index = 0;
  };

  struct StartArgs {
    uint32_t internal_instance_index = 0;
  };

  struct StopArgs {
    virtual ~StopArgs() = default;
    virtual std::function<void()> HandleStopAsynchronously() const { return nullptr; }
    uint32_t internal_instance_index = 0;
  };

  virtual void OnSetup(const SetupArgs&) {}
  virtual void OnStart(const StartArgs&) {}
  virtual void OnStop(const StopArgs&) {}
};

// TrackEventSessionObserver stub
class TrackEventSessionObserver {
 public:
  virtual ~TrackEventSessionObserver() = default;
  virtual void OnSetup(const DataSourceBase::SetupArgs&) {}
  virtual void OnStart(const DataSourceBase::StartArgs&) {}
  virtual void OnStop(const DataSourceBase::StopArgs&) {}
};

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

// Track base class
struct Track {
  uint64_t uuid = 0;
  uint64_t parent_uuid = 0;

  constexpr Track() = default;
  explicit constexpr Track(uint64_t uuid_, uint64_t parent_uuid_ = 0)
      : uuid(uuid_), parent_uuid(parent_uuid_) {}

  explicit operator bool() const { return uuid != 0; }

  template <typename T>
  static Track FromPointer(const T* ptr) {
    return Track(reinterpret_cast<uint64_t>(ptr));
  }

  template <typename T>
  static Track FromPointer(const T* ptr, Track parent) {
    return Track(reinterpret_cast<uint64_t>(ptr), parent.uuid);
  }

  static Track Global(uint64_t id) { return Track(id); }
};

// ThreadTrack stub
struct ThreadTrack : public Track {
  static ThreadTrack Current() { return ThreadTrack(); }
  static ThreadTrack ForThread(uint64_t) { return ThreadTrack(); }
};

// ProcessTrack stub
struct ProcessTrack : public Track {
  static ProcessTrack Current() { return ProcessTrack(); }
  static ProcessTrack ForProcess(uint64_t) { return ProcessTrack(); }
};

// CounterTrack stub
struct CounterTrack : public Track {
  explicit CounterTrack(const char*) {}
  CounterTrack(const char*, Track) {}

  static CounterTrack Global(const char*) { return CounterTrack(""); }

  CounterTrack& set_unit(int) { return *this; }
  CounterTrack& set_unit_name(const char*) { return *this; }
  CounterTrack& set_unit_multiplier(uint64_t) { return *this; }
  CounterTrack& set_is_incremental(bool) { return *this; }
};

// NamedTrack stub - complete definition needed for std::optional<NamedTrack>
class NamedTrack : public Track {
 public:
  NamedTrack() = default;
  ~NamedTrack() = default;

  // Copy and move constructors
  NamedTrack(const NamedTrack&) = default;
  NamedTrack(NamedTrack&&) = default;
  NamedTrack& operator=(const NamedTrack&) = default;
  NamedTrack& operator=(NamedTrack&&) = default;

  // Constructor with name
  explicit NamedTrack(const char* name, uint64_t id = 0, Track parent = Track())
      : Track(id, parent.uuid), name_(name) {}

  // Static factory methods
  static NamedTrack ThreadScoped(const char* name, uint64_t id = 0) {
    return NamedTrack(name, id, ThreadTrack::Current());
  }

  template <typename T>
  static NamedTrack FromPointer(const char* name, const T* ptr, Track parent = Track()) {
    return NamedTrack(name, reinterpret_cast<uint64_t>(ptr), parent);
  }

  static NamedTrack Global(const char* name, uint64_t id = 0) {
    return NamedTrack(name, id, Track());
  }

 private:
  const char* name_ = nullptr;
};

// Mark NamedTrack as fully defined
#define PERFETTO_NAMED_TRACK_DEFINED 1

namespace legacy {
enum PerfettoLegacyCurrentThreadId { kCurrentThreadId };

template <typename T>
ThreadTrack ConvertThreadId(const T&) { return ThreadTrack(); }
}  // namespace legacy

struct TraceTimestamp {
  uint32_t clock_id = 0;
  uint64_t value = 0;
};

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

// TrackEventTlsStateUserData base class
class TrackEventTlsStateUserData {
 public:
  virtual ~TrackEventTlsStateUserData() = default;
};

// TrackEventInternal stub
class TrackEventInternal {
 public:
  static uint32_t GetClockId() { return 0; }
};

}  // namespace internal

// Tracing class stub
class Tracing {
 public:
  struct InitArgs {
    uint32_t backends = 0;
  };

  static void Initialize(const InitArgs&) {}
  static void ResetForTesting() {}
  static bool IsInitialized() { return false; }
};

// Backend types
enum BackendType : uint32_t {
  kUnspecifiedBackend = 0,
  kInProcessBackend = 1 << 0,
  kSystemBackend = 1 << 1,
  kCustomBackend = 1 << 2,
};

// Import protozero namespace for convenience
namespace protozero {}
using namespace protozero;

// Forward declarations
class TracedArray;
class TracedDictionary;

// TracedValue stub for tracing support
class TracedValue {
 public:
  TracedValue() = default;
  ~TracedValue() = default;

  // Allow move
  TracedValue(TracedValue&&) = default;
  TracedValue& operator=(TracedValue&&) = default;

  // Disable copy
  TracedValue(const TracedValue&) = delete;
  TracedValue& operator=(const TracedValue&) = delete;

  // Convert to dictionary
  TracedDictionary WriteDictionary() &&;
};

// TracedDictionary stub
class TracedDictionary {
 public:
  TracedDictionary() = default;
  ~TracedDictionary() = default;

  TracedDictionary(TracedDictionary&&) = default;
  TracedDictionary& operator=(TracedDictionary&&) = default;

  template <typename T>
  void Add(const char*, T&&) {}

  TracedArray AddArray(const char*);

  TracedDictionary AddDictionary(const char*) { return TracedDictionary(); }
};

// TracedArray stub
class TracedArray {
 public:
  TracedArray() = default;
  ~TracedArray() = default;

  TracedArray(TracedArray&&) = default;
  TracedArray& operator=(TracedArray&&) = default;

  template <typename T>
  void Append(T&&) {}

  TracedDictionary AppendDictionary() { return TracedDictionary(); }
};

// Define methods after all classes are complete
inline TracedArray TracedDictionary::AddArray(const char*) { return TracedArray(); }
inline TracedDictionary TracedValue::WriteDictionary() && { return TracedDictionary(); }

// StaticString stub
class StaticString {
 public:
  const char* value = nullptr;
  constexpr StaticString() = default;
  constexpr StaticString(const char* str) : value(str) {}
  constexpr operator const char*() const { return value; }
};

// EventContext stub for trace event callbacks
class EventContext {
 public:
  template <typename T>
  T* event() { return nullptr; }
};

// Flow stub for trace event flow
class Flow {
 public:
  constexpr Flow() = default;
  explicit constexpr Flow(uint64_t) {}

  static Flow Global(uint64_t) { return Flow(); }
  static Flow ProcessScoped(uint64_t) { return Flow(); }

  template <typename T>
  static Flow FromPointer(const T*) { return Flow(); }

  void operator()(EventContext&) const {}
};

// TerminatingFlow stub
class TerminatingFlow {
 public:
  constexpr TerminatingFlow() = default;
  explicit constexpr TerminatingFlow(uint64_t) {}

  static TerminatingFlow Global(uint64_t) { return TerminatingFlow(); }
  static TerminatingFlow ProcessScoped(uint64_t) { return TerminatingFlow(); }

  template <typename T>
  static TerminatingFlow FromPointer(const T*) { return TerminatingFlow(); }

  void operator()(EventContext&) const {}
};

}  // namespace perfetto

namespace base {
class TrackEvent {
 public:
  template <typename T, typename D>
  static void SetTrackDescriptor(const T&, const D&) {}
  template <typename T>
  static void EraseTrackDescriptor(const T&) {}
  static void AddSessionObserver(perfetto::TrackEventSessionObserver*) {}
  static void RemoveSessionObserver(perfetto::TrackEventSessionObserver*) {}
  static void Register() {}
  static uint32_t GetTraceClockId() { return 0; }
};
}  // namespace base

#endif  // !BUILDFLAG(ENABLE_BASE_TRACING)

#endif  // BASE_TRACE_EVENT_COMMON_TRACE_EVENT_COMMON_H_
