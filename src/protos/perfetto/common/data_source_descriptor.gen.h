// Copyright 2025 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies

#ifndef PERFETTO_PROTOS_PERFETTO_COMMON_DATA_SOURCE_DESCRIPTOR_GEN_H_
#define PERFETTO_PROTOS_PERFETTO_COMMON_DATA_SOURCE_DESCRIPTOR_GEN_H_

#include <string>
#include <vector>

namespace perfetto {
namespace protos {
namespace gen {

// Stub DataSourceDescriptor class
class DataSourceDescriptor {
 public:
  DataSourceDescriptor() = default;
  ~DataSourceDescriptor() = default;

  // Basic getters/setters
  const std::string& name() const { return name_; }
  void set_name(const std::string& value) { name_ = value; }

  bool will_notify_on_start() const { return will_notify_on_start_; }
  void set_will_notify_on_start(bool value) { will_notify_on_start_ = value; }

  bool will_notify_on_stop() const { return will_notify_on_stop_; }
  void set_will_notify_on_stop(bool value) { will_notify_on_stop_ = value; }

  bool handles_incremental_state_clear() const { return handles_incremental_state_clear_; }
  void set_handles_incremental_state_clear(bool value) { handles_incremental_state_clear_ = value; }

  bool no_flush() const { return no_flush_; }
  void set_no_flush(bool value) { no_flush_ = value; }

  uint64_t id() const { return id_; }
  void set_id(uint64_t value) { id_ = value; }

 private:
  std::string name_;
  bool will_notify_on_start_ = false;
  bool will_notify_on_stop_ = false;
  bool handles_incremental_state_clear_ = false;
  bool no_flush_ = false;
  uint64_t id_ = 0;
};

}  // namespace gen
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_COMMON_DATA_SOURCE_DESCRIPTOR_GEN_H_
