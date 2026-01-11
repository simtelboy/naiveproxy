// Copyright 2024 Stub implementation for OpenHarmony
#ifndef INCLUDE_PERFETTO_EXT_TRACE_PROCESSOR_EXPORT_JSON_H_
#define INCLUDE_PERFETTO_EXT_TRACE_PROCESSOR_EXPORT_JSON_H_

#include "third_party/perfetto/include/perfetto/base/export.h"

#include <functional>
#include <string>

namespace perfetto {
namespace trace_processor {
namespace json {

// Stub OutputWriter for JSON export
class PERFETTO_EXPORT_COMPONENT OutputWriter {
 public:
  virtual ~OutputWriter() = default;
  virtual void Write(const std::string& str) = 0;
};

// Stub function for exporting trace to JSON
inline int ExportJson(void* tp,
                      OutputWriter* output,
                      std::function<bool(const char*)> argument_filter = nullptr,
                      std::function<bool(const char*)> metadata_filter = nullptr,
                      std::function<bool(const char*)> label_filter = nullptr) {
  return 0;
}

}  // namespace json
}  // namespace trace_processor
}  // namespace perfetto

#endif  // INCLUDE_PERFETTO_EXT_TRACE_PROCESSOR_EXPORT_JSON_H_
