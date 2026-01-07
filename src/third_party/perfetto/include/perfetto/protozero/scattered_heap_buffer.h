// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_PROTOZERO_SCATTERED_HEAP_BUFFER_H_
#define INCLUDE_PERFETTO_PROTOZERO_SCATTERED_HEAP_BUFFER_H_

#include <stddef.h>
#include <stdint.h>
#include <memory>

namespace perfetto {
namespace protozero {

// Stub implementation
class ScatteredHeapBuffer {
 public:
  class Slice {
   public:
    uint8_t* start() { return nullptr; }
    size_t size() { return 0; }
  };

  ScatteredHeapBuffer(size_t initial_size = 0, size_t maximum_size = 0) {}
  ~ScatteredHeapBuffer() = default;

  Slice GetNewBuffer() { return Slice(); }
  void AdjustUsedSizeOfCurrentSlice(size_t used_size) {}
  
  const Slice* slices() const { return nullptr; }
  size_t slice_count() const { return 0; }
};

// Stub HeapBuffered template
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

// Import protozero into global namespace for convenience
// This allows code to use protozero::HeapBuffered without perfetto:: prefix
using namespace perfetto::protozero;

#endif  // INCLUDE_PERFETTO_PROTOZERO_SCATTERED_HEAP_BUFFER_H_
