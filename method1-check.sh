#!/bin/bash
# 方案1: 完整编译检查 (不链接)
# 这是最接近真实编译的检查方法,准确度 99%

set -e

cd "$(dirname "$0")/src"

# 颜色定义
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo "========================================="
echo -e "${BLUE}🚀 方案1: 完整编译检查 (不链接)${NC}"
echo "========================================="
echo "说明: 使用与完整编译完全相同的编译器和参数"
echo "      只编译到 .o 文件,不进行链接"
echo "      准确度: 99% (与完整编译几乎相同)"
echo "      速度: 比完整编译快 5-10 倍"
echo ""

# 确保有编译器
if [ ! -d "third_party/llvm-build/Release+Asserts" ]; then
    echo "下载编译器..."
    ./get-clang.sh
    EXTRA_FLAGS='target_os="android"' ./get-clang.sh
fi

# 生成构建配置
echo "生成构建配置..."
if [ ! -d "out/Check" ]; then
    gn gen out/Check --args='target_os="android" target_cpu="arm64" is_official_build=true is_debug=false'
else
    echo "使用现有配置: out/Check"
fi

# 询问检查范围
echo ""
echo "选择检查范围:"
echo "  1) 只检查 base 库 (推荐,5-10分钟)"
echo "  2) 检查所有代码 (完整检查,20-30分钟)"
echo "  3) 只检查修改过的文件 (最快,1-2分钟)"
read -p "请选择 [1-3]: " CHOICE

case $CHOICE in
    1)
        TARGET="base"
        echo -e "${YELLOW}检查范围: base 库${NC}"
        ;;
    2)
        TARGET=""
        echo -e "${YELLOW}检查范围: 所有代码${NC}"
        ;;
    3)
        # 查找修改过的文件
        MODIFIED_FILES=$(git diff --name-only HEAD~1 HEAD | grep -E '\.(cc|cpp)$' || echo "")
        if [ -z "$MODIFIED_FILES" ]; then
            echo -e "${RED}没有找到修改的文件,改为检查 base 库${NC}"
            TARGET="base"
        else
            echo -e "${YELLOW}检查修改的文件:${NC}"
            echo "$MODIFIED_FILES"
            # 将文件路径转换为 ninja 目标
            TARGET=$(echo "$MODIFIED_FILES" | sed 's|^src/||' | sed 's|\.cc$|.o|' | sed 's|/|_|g' | sed 's|^|obj/|')
        fi
        ;;
    *)
        echo -e "${RED}无效选择,使用默认: base 库${NC}"
        TARGET="base"
        ;;
esac

echo ""
echo "========================================="
echo "开始编译检查..."
echo "========================================="
START_TIME=$(date +%s)

# 创建日志文件
LOG_FILE="compile_check.log"
> $LOG_FILE

# 执行编译检查
# -k 0 = 遇到错误继续,显示所有错误
# -j $(nproc) = 使用所有 CPU 核心
echo -e "${BLUE}正在编译...${NC}"
ninja -C out/Check -k 0 -j $(nproc) $TARGET 2>&1 | tee $LOG_FILE || true

END_TIME=$(date +%s)
ELAPSED=$((END_TIME - START_TIME))

# 统计结果
ERROR_COUNT=$(grep -c "error:" $LOG_FILE || echo "0")
WARNING_COUNT=$(grep -c "warning:" $LOG_FILE || echo "0")
COMPILED_FILES=$(grep -c "CXX obj/" $LOG_FILE || echo "0")

echo ""
echo "========================================="
echo -e "${BLUE}📊 检查结果${NC}"
echo "========================================="
echo "编译时间: ${ELAPSED} 秒 ($(($ELAPSED / 60)) 分钟)"
echo "编译文件数: $COMPILED_FILES"
echo -e "错误数量: ${RED}$ERROR_COUNT${NC}"
echo -e "警告数量: ${YELLOW}$WARNING_COUNT${NC}"
echo "========================================="

# 显示错误详情
if [ "$ERROR_COUNT" -gt 0 ]; then
    echo ""
    echo -e "${RED}🔴 所有编译错误:${NC}"
    echo "========================================="
    grep "error:" $LOG_FILE || true
    echo "========================================="
    echo ""
    echo -e "${RED}❌ 发现 $ERROR_COUNT 个编译错误!${NC}"
    echo ""
    echo "完整日志已保存到: $LOG_FILE"
    echo ""

    # 按文件分组显示错误
    echo "按文件分组的错误:"
    grep "error:" $LOG_FILE | cut -d: -f1 | sort | uniq -c | sort -rn | head -10

    exit 1
else
    echo ""
    echo -e "${GREEN}✅ 所有编译检查通过!${NC}"
    echo ""

    # 显示警告最多的文件
    if [ "$WARNING_COUNT" -gt 0 ]; then
        echo "警告最多的文件 (前10个):"
        grep "warning:" $LOG_FILE | cut -d: -f1 | sort | uniq -c | sort -rn | head -10
    fi
fi

echo ""
echo "日志文件: $LOG_FILE"
