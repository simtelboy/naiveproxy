// Copyright 2024 Stub implementation for OpenHarmony
// Minimal stub to avoid Perfetto dependency

#ifndef THIRD_PARTY_PERFETTO_INCLUDE_PERFETTO_PROTOZERO_SCATTERED_HEAP_BUFFER_H_
#define THIRD_PARTY_PERFETTO_INCLUDE_PERFETTO_PROTOZERO_SCATTERED_HEAP_BUFFER_H_

namespace perfetto {
namespace protozero {

// Stub for HeapBuffered template
template <typename T>
class HeapBuffered {
 public:
  HeapBuffered() = default;
  ~HeapBuffered() = default;
  
  T* get() { return &message_; }
  const T* get() const { return &message_; }
  T* operator->() { return &message_; }
  const T* operator->() const { return &message_; }
  
 private:
  T message_;
};

}  // namespace protozero
}  // namespace perfetto

// Export protozero to global namespace for compatibility
namespace protozero = perfetto::protozero;

#endif  // THIRD_PARTY_PERFETTO_INCLUDE_PERFETTO_PROTOZERO_SCATTERED_HEAP_BUFFER_H_
