// Copyright 2025 Stub implementation for OpenHarmony
// This is a stub file to satisfy build dependencies

#ifndef PERFETTO_PROTOS_PERFETTO_CONFIG_INTERCEPTOR_CONFIG_GEN_H_
#define PERFETTO_PROTOS_PERFETTO_CONFIG_INTERCEPTOR_CONFIG_GEN_H_

#include <string>

namespace perfetto {
namespace protos {
namespace gen {

// Stub InterceptorDescriptor class
class InterceptorDescriptor {
 public:
  InterceptorDescriptor() = default;
  ~InterceptorDescriptor() = default;

  // Basic getters/setters
  const std::string& name() const { return name_; }
  void set_name(const std::string& value) { name_ = value; }

 private:
  std::string name_;
};

}  // namespace gen
}  // namespace protos
}  // namespace perfetto

#endif  // PERFETTO_PROTOS_PERFETTO_CONFIG_INTERCEPTOR_CONFIG_GEN_H_
