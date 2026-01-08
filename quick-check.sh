#!/bin/bash
# 快速语法检查脚本 - 不进行完整编译,只检查语法错误

set -e

cd "$(dirname "$0")/src"

echo "==================================="
echo "Fast Syntax Check Tool"
echo "==================================="

# 确保有编译器
if [ ! -d "third_party/llvm-build/Release+Asserts" ]; then
    echo "Downloading clang..."
    ./get-clang.sh
    EXTRA_FLAGS='target_os="android"' ./get-clang.sh
fi

# 生成编译数据库
echo "Generating compilation database..."
if [ ! -d "out/Syntax" ]; then
    gn gen out/Syntax --args='target_os="android" target_cpu="arm64" is_official_build=true is_debug=false'
fi

# 导出编译命令
gn desc out/Syntax "//*" --format=json > out/Syntax/compile_commands.json

# 查找所有修改过的文件
echo "Finding modified files..."
MODIFIED_FILES=$(git diff --name-only HEAD~1 HEAD | grep -E '\.(cc|cpp|h)$' || echo "")

if [ -z "$MODIFIED_FILES" ]; then
    echo "No C++ files modified, checking all base files..."
    MODIFIED_FILES=$(find base -name "*.cc" -o -name "*.h" | head -100)
fi

echo "Files to check:"
echo "$MODIFIED_FILES"
echo ""

# 使用 clang-check 进行快速检查
CLANG_CHECK="third_party/llvm-build/Release+Asserts/bin/clang-check"
ERROR_COUNT=0

echo "Running syntax check..."
for file in $MODIFIED_FILES; do
    if [ -f "$file" ]; then
        echo "Checking: $file"
        if ! $CLANG_CHECK -p out/Syntax "$file" 2>&1 | tee -a syntax_check.log; then
            ERROR_COUNT=$((ERROR_COUNT + 1))
        fi
    fi
done

echo ""
echo "==================================="
echo "Check Summary:"
echo "Files checked: $(echo "$MODIFIED_FILES" | wc -l)"
echo "Errors found: $ERROR_COUNT"
echo "==================================="

if [ $ERROR_COUNT -gt 0 ]; then
    echo "❌ Syntax check failed!"
    echo "See syntax_check.log for details"
    exit 1
else
    echo "✅ All checks passed!"
fi
