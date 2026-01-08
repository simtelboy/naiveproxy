// Copyright 2024 Stub implementation for OpenHarmony
#ifndef PERFETTO_PROTOS_PERFETTO_TRACE_MEMORY_GRAPH_PBZERO_H_
#define PERFETTO_PROTOS_PERFETTO_TRACE_MEMORY_GRAPH_PBZERO_H_

#include <stdint.h>
#include <string>
#include <vector>

namespace perfetto {
namespace protos {
namespace pbzero {

// Stub MemoryTrackerSnapshot protobuf message
class MemoryTrackerSnapshot {
 public:
  class ProcessSnapshot {
   public:
    class MemoryNode {
     public:
      class MemoryNodeEntry {
       public:
        void set_name(const std::string& value) {}
        void set_units(int32_t value) {}
        void set_value_uint64(uint64_t value) {}
        void set_value_string(const std::string& value) {}
      };

      void set_id(uint64_t value) {}
      void set_absolute_name(const std::string& value) {}
      MemoryNodeEntry* add_entries() { return nullptr; }
    };

    class MemoryEdge {
     public:
      void set_source_id(uint64_t value) {}
      void set_target_id(uint64_t value) {}
      void set_importance(uint32_t value) {}
      void set_overridable(bool value) {}
    };

    void set_pid(int32_t value) {}
    MemoryNode* add_allocator_dumps() { return nullptr; }
    MemoryEdge* add_memory_edges() { return nullptr; }
  };

  void set_global_dump_id(uint64_t value) {}
  void set_level_of_detail(int32_t value) {}
  ProcessSnapshot* add_process_memory_dumps() { return nullptr; }
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_TRACE_MEMORY_GRAPH_PBZERO_H_
