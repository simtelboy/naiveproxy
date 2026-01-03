# NaiveProxy 鸿蒙版本

本仓库是 [NaiveProxy](https://github.com/klzgrad/naiveproxy) 的 Fork，添加了鸿蒙 (HarmonyOS NEXT) 平台支持。

## 🚀 快速开始

### 使用 GitHub Actions 自动编译

1. **启用 Actions**
   - 进入仓库的 **Actions** 标签
   - 点击 **I understand my workflows, enable them**

2. **运行编译**
   - 选择 **Build NaiveProxy for HarmonyOS** 工作流
   - 点击 **Run workflow**
   - 选择架构（arm64 或 x64）
   - 等待编译完成（约 40-60 分钟）

3. **下载产物**
   - 在 **Artifacts** 部分下载 `libnaive-ohos-arm64.tar.gz`
   - 解压得到 `libnaive.so`

## 📚 文档

- **[鸿蒙编译指南](OHOS_BUILD_GUIDE.md)** - 本地编译详细步骤
- **[GitHub Actions 指南](GITHUB_ACTIONS_BUILD.md)** - 云端编译说明
- **[Fork 指南](FORK_AND_BUILD_GUIDE.md)** - Fork 和使用说明

## ⚙️ 当前状态

| 功能 | 状态 |
|------|------|
| GitHub Actions 工作流 | ✅ 已配置 |
| 鸿蒙构建脚本 | ✅ 已添加 |
| 共享库编译目标 | ✅ 已添加 |
| 鸿蒙 NDK 配置 | ⏳ 待配置 |
| 实际编译测试 | ⏳ 待测试 |

## 🔧 配置鸿蒙 NDK

当前工作流使用 Android NDK 测试编译流程。要编译真正的鸿蒙版本，需要：

### 方案 A: 上传到 GitHub Release

1. 下载鸿蒙 NDK
2. 打包：`tar czf ohos-ndk.tar.gz native/`
3. 创建 Release 并上传
4. 修改工作流第 50 行的下载链接

### 方案 B: 使用 GitHub Secrets

1. 上传 NDK 到云存储
2. Settings > Secrets > Actions > New repository secret
3. 添加 `OHOS_NDK_URL`
4. 工作流会自动使用

## 📝 许可证

BSD License（与原项目一致）

## 🔗 相关链接

- [原项目](https://github.com/klzgrad/naiveproxy)
- [鸿蒙开发者文档](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/application-dev-guide-V5)
