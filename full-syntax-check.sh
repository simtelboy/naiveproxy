#!/bin/bash
# 全项目语法检查 - 使用 clang 的 -fsyntax-only 模式
# 这个模式只检查语法,不生成目标文件,速度比完整编译快10倍以上

set -e

cd "$(dirname "$0")/src"

echo "==================================="
echo "Full Project Syntax Check"
echo "==================================="

# 颜色定义
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# 确保有编译器
if [ ! -d "third_party/llvm-build/Release+Asserts" ]; then
    echo "Downloading clang..."
    ./get-clang.sh
    EXTRA_FLAGS='target_os="android"' ./get-clang.sh
fi

# 生成编译配置
echo "Generating build configuration..."
if [ ! -d "out/SyntaxCheck" ]; then
    gn gen out/SyntaxCheck --args='target_os="android" target_cpu="arm64" is_official_build=true is_debug=false'
fi

# 获取编译命令
echo "Extracting compilation commands..."
ninja -C out/SyntaxCheck -t commands > compile_commands.txt

# 统计变量
TOTAL_FILES=0
ERROR_FILES=0
SUCCESS_FILES=0

# 创建错误日志
ERROR_LOG="syntax_errors.log"
> $ERROR_LOG

# 提取所有 .cc 文件的编译命令
echo "Checking C++ files..."
grep "\.cc" compile_commands.txt | while read -r cmd; do
    # 提取源文件名
    SOURCE_FILE=$(echo "$cmd" | grep -oP '../../[^ ]+\.cc' | head -1)

    if [ -z "$SOURCE_FILE" ]; then
        continue
    fi

    TOTAL_FILES=$((TOTAL_FILES + 1))

    # 修改命令:添加 -fsyntax-only 标志,移除 -o 输出
    SYNTAX_CMD=$(echo "$cmd" | sed 's/-o [^ ]*//' | sed 's/clang++/clang++ -fsyntax-only/')

    # 执行语法检查
    echo -n "Checking [$TOTAL_FILES]: $SOURCE_FILE ... "

    if eval "$SYNTAX_CMD" 2>&1 | tee -a $ERROR_LOG | grep -q "error:"; then
        echo -e "${RED}FAILED${NC}"
        ERROR_FILES=$((ERROR_FILES + 1))
        echo "----------------------------------------" >> $ERROR_LOG
    else
        echo -e "${GREEN}OK${NC}"
        SUCCESS_FILES=$((SUCCESS_FILES + 1))
    fi

    # 每检查10个文件显示进度
    if [ $((TOTAL_FILES % 10)) -eq 0 ]; then
        echo -e "${YELLOW}Progress: $TOTAL_FILES files checked, $ERROR_FILES errors${NC}"
    fi
done

# 显示摘要
echo ""
echo "==================================="
echo "Syntax Check Summary"
echo "==================================="
echo "Total files checked: $TOTAL_FILES"
echo -e "Success: ${GREEN}$SUCCESS_FILES${NC}"
echo -e "Failed: ${RED}$ERROR_FILES${NC}"
echo "==================================="

# 显示错误详情
if [ $ERROR_FILES -gt 0 ]; then
    echo ""
    echo "Error details saved to: $ERROR_LOG"
    echo ""
    echo "Top 20 errors:"
    grep "error:" $ERROR_LOG | head -20
    echo ""
    echo -e "${RED}❌ Syntax check failed!${NC}"
    exit 1
else
    echo ""
    echo -e "${GREEN}✅ All syntax checks passed!${NC}"
fi
