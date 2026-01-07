// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_TRACING_TRACED_PROTO_H_
#define INCLUDE_PERFETTO_TRACING_TRACED_PROTO_H_

namespace perfetto {

// Stub TracedProto class
template <typename T>
class TracedProto {
 public:
  TracedProto() = default;
  ~TracedProto() = default;

  T* operator->() { return &message_; }
  const T* operator->() const { return &message_; }

 private:
  T message_;
};

}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_TRACING_TRACED_PROTO_H_
