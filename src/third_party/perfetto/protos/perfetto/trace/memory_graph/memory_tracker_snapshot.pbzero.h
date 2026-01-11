// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_MEMORY_GRAPH_MEMORY_TRACKER_SNAPSHOT_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_MEMORY_GRAPH_MEMORY_TRACKER_SNAPSHOT_PBZERO_H_

#include <stdint.h>
#include <string>

namespace perfetto {
namespace protos {
namespace pbzero {

// Forward declarations
class MemoryTrackerSnapshot_ProcessSnapshot;
class MemoryTrackerSnapshot_ProcessSnapshot_MemoryNode;
class MemoryTrackerSnapshot_ProcessSnapshot_MemoryEdge;

// Stub MemoryTrackerSnapshot message
class MemoryTrackerSnapshot {
 public:
  // Type aliases for nested classes
  using ProcessSnapshot = MemoryTrackerSnapshot_ProcessSnapshot;

  // LevelOfDetail enum
  enum LevelOfDetail : int32_t {
    DETAIL_FULL = 0,
    DETAIL_LIGHT = 1,
    DETAIL_BACKGROUND = 2,
  };

  MemoryTrackerSnapshot() = default;
  ~MemoryTrackerSnapshot() = default;

  void set_global_dump_id(uint64_t value) {}
  void set_level_of_detail(LevelOfDetail value) {}

  ProcessSnapshot* add_process_memory_dumps() { return nullptr; }
};

// Stub ProcessSnapshot message
class MemoryTrackerSnapshot_ProcessSnapshot {
 public:
  // Type aliases for nested classes
  using MemoryNode = MemoryTrackerSnapshot_ProcessSnapshot_MemoryNode;
  using MemoryEdge = MemoryTrackerSnapshot_ProcessSnapshot_MemoryEdge;

  MemoryTrackerSnapshot_ProcessSnapshot() = default;
  ~MemoryTrackerSnapshot_ProcessSnapshot() = default;

  void set_pid(int32_t value) {}

  MemoryNode* add_allocator_dumps() { return nullptr; }
  MemoryEdge* add_memory_edges() { return nullptr; }
};

// Stub MemoryNodeEntry message (nested in MemoryNode)
class MemoryTrackerSnapshot_ProcessSnapshot_MemoryNode_MemoryNodeEntry {
 public:
  // Units enum
  enum Units : int32_t {
    UNSPECIFIED = 0,
    BYTES = 1,
    COUNT = 2,
  };

  MemoryTrackerSnapshot_ProcessSnapshot_MemoryNode_MemoryNodeEntry() = default;
  ~MemoryTrackerSnapshot_ProcessSnapshot_MemoryNode_MemoryNodeEntry() = default;

  void set_name(const char* value) {}
  void set_name(const std::string& value) {}
  void set_units(Units value) {}
  void set_value_uint64(uint64_t value) {}
  void set_value_string(const char* value) {}
  void set_value_string(const std::string& value) {}
};

// Stub MemoryNode message
class MemoryTrackerSnapshot_ProcessSnapshot_MemoryNode {
 public:
  // Type alias for nested entry class
  using MemoryNodeEntry = MemoryTrackerSnapshot_ProcessSnapshot_MemoryNode_MemoryNodeEntry;

  // Flags enum
  enum Flags : int32_t {
    FLAG_NONE = 0,
    FLAG_WEAK = 1,
  };

  MemoryTrackerSnapshot_ProcessSnapshot_MemoryNode() = default;
  ~MemoryTrackerSnapshot_ProcessSnapshot_MemoryNode() = default;

  void set_id(uint64_t value) {}
  void set_absolute_name(const char* value) {}
  void set_absolute_name(const std::string& value) {}
  void set_weak(bool value) {}
  void set_size_bytes(uint64_t value) {}
  void set_flags(Flags value) {}

  MemoryNodeEntry* add_entries() { return nullptr; }
};

// Stub MemoryEdge message
class MemoryTrackerSnapshot_ProcessSnapshot_MemoryEdge {
 public:
  MemoryTrackerSnapshot_ProcessSnapshot_MemoryEdge() = default;
  ~MemoryTrackerSnapshot_ProcessSnapshot_MemoryEdge() = default;

  void set_source_id(uint64_t value) {}
  void set_target_id(uint64_t value) {}
  void set_importance(int32_t value) {}
  void set_overridable(bool value) {}
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_MEMORY_GRAPH_MEMORY_TRACKER_SNAPSHOT_PBZERO_H_
