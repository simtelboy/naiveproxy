// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_BASE_TEMPLATE_UTIL_H_
#define INCLUDE_PERFETTO_BASE_TEMPLATE_UTIL_H_

#include <type_traits>

namespace perfetto {
namespace base {

// Stub template utilities
template <typename T>
struct remove_cvref {
  using type = std::remove_cv_t<std::remove_reference_t<T>>;
};

template <typename T>
using remove_cvref_t = typename remove_cvref<T>::type;

}  // namespace base
}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_BASE_TEMPLATE_UTIL_H_
