# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 语言规则

**重要：在此仓库中工作时，必须始终使用中文。** 这包括：
- 所有对话和回复
- 代码注释
- Git commit 消息
- 生成的文档
- 错误说明和日志输出

## Project Overview

This is a fork of [NaiveProxy](https://github.com/klzgrad/naiveproxy) adding HarmonyOS NEXT (OpenHarmony/OHOS) platform support. NaiveProxy uses Chromium's network stack to create a censorship-resistant proxy that mimics regular Chrome browser traffic.

The codebase is a minimal subset (~0.3%) of Chromium, focused on the network stack components needed for the proxy functionality.

## Build System

### Primary Build Method (GitHub Actions)
The main build workflow is `build-ohos-docker.yml` which uses a Docker container with HarmonyOS NDK:
- Triggers on push to master/ohos-* branches
- Uses `simtelboyhotyi/ohos-build:latest` Docker image
- Supports arm64 and x64 architectures

### Local Build Commands
```bash
cd src

# Get toolchain (clang compiler)
./get-clang.sh

# For Android cross-compilation
EXTRA_FLAGS='target_os="android"' ./get-clang.sh

# Build (release)
./build.sh

# Build (debug)
./build.sh debug

# Build with specific target
EXTRA_FLAGS='target_os="ohos" target_cpu="arm64"' ./build.sh
```

### GN Build System
The project uses Chromium's GN meta-build system:
```bash
# Generate build files
./gn/out/gn gen out/Release --args="<flags>"

# Build the naive target
ninja -C out/Release naive
```

Key GN flags for cronet/OHOS builds (set in build.sh):
- `is_cronet_build=true` - Enables cronet build mode
- `enable_base_tracing=false` - Disables Perfetto tracing (critical for OHOS)
- `use_sysroot=false` - Don't use Chromium sysroot

## Architecture

### Source Structure
- `src/` - Main Chromium-derived source code
  - `net/` - Network stack (HTTP, QUIC, DNS, SSL, sockets)
  - `net/tools/naive/` - NaiveProxy-specific code (proxy implementation)
  - `base/` - Chromium base library (threading, memory, tracing stubs)
  - `crypto/` - Cryptographic primitives
  - `url/` - URL parsing
  - `components/` - Chromium components
  - `third_party/` - Dependencies (boringssl, protobuf, etc.)

### Key NaiveProxy Components
Located in `src/net/tools/naive/`:
- `naive_proxy_bin.cc` - Main entry point
- `naive_proxy.cc/h` - Core proxy logic
- `naive_connection.cc/h` - Connection handling
- `naive_padding_*.cc/h` - Traffic padding for anti-fingerprinting
- `socks5_server_socket.cc/h` - SOCKS5 protocol
- `http_proxy_server_socket.cc/h` - HTTP CONNECT proxy

### Build Targets
- `naive` - Main executable (defined in `src/net/BUILD.gn`)
- For OHOS: builds as shared library `libnaive.so`

## OHOS/Cronet Build Considerations

### Perfetto Tracing Disabled
When `enable_base_tracing=false` (required for cronet/OHOS builds), Perfetto tracing is disabled. This requires:

1. **Stub implementations** in `src/base/trace_event/common/trace_event_common.h`:
   - `perfetto::TracedValue`, `TracedDictionary`, `TracedArray`
   - `perfetto::EventContext`, `StaticString`
   - `perfetto::Flow`, `TerminatingFlow`
   - `perfetto::Track`, `ThreadTrack`, `ProcessTrack`

2. **Conditional compilation** using `#if BUILDFLAG(ENABLE_BASE_TRACING)`:
   - `WriteIntoTrace()` methods in various classes
   - Perfetto proto includes (`chrome_track_event.pbzero.h`)
   - Proto-dependent code in task scheduler files

3. **Stub enums** like `QueueName` in `src/base/task/sequence_manager/task_queue.h`

### Common Compilation Issues
When porting to OHOS, watch for:
- Missing `#include "base/tracing_buildflags.h"`
- Unconditional use of `perfetto::` types
- Proto types like `ChromeTaskAnnotator`, `ChromeThreadPoolTask`
- `WriteIntoTrace` methods without conditional guards

## Environment Variables

For OHOS builds in Docker:
- `OHOS_NDK_HOME` - HarmonyOS NDK path
- `OHOS_SYSROOT` - Sysroot for cross-compilation
- `COMMAND_LINE_TOOLS_HOME` - HarmonyOS command line tools

## Chromium Version

Current base: `143.0.7499.109` (see `CHROMIUM_VERSION` file)

Note: The master branch rebases from a new root commit for each Chrome release. Use tags for stable versions.
