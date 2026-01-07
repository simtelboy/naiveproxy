# 构建包含 HarmonyOS NDK 的 Docker 镜像

## 步骤 1：下载 Command Line Tools

1. 访问华为开发者网站下载页面
2. 下载 **Command Line Tools for Linux(x86) 6.0.0.878**
3. 保存为 `commandline-tools-linux-x64-6.0.0.878.zip`

下载链接（2小时有效）：
```
https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/94/v3/sk4rFo0CRtSyMJjSv3-o2g/commandline-tools-linux-x64-6.0.0.878.zip?HW-CC-KV=V1&HW-CC-Date=20260107T072458Z&HW-CC-Expire=7200&HW-CC-Sign=4A7613C7CAFF61EEEA8537768D7F4453DF322218F0C6CA61FA07D0C466A5EFF5
```

## 步骤 2：准备构建目录

```bash
# 创建构建目录
mkdir -p ~/ohos-docker-build
cd ~/ohos-docker-build

# 将下载的 zip 文件移动到这里
mv ~/Downloads/commandline-tools-linux-x64-6.0.0.878.zip .

# 解压
unzip commandline-tools-linux-x64-6.0.0.878.zip

# 验证解压结果
ls -la command-line-tools/
```

你应该看到类似的目录结构：
```
command-line-tools/
├── bin/
├── sdk/
│   └── default/
│       └── openharmony/
│           └── native/          # 这就是 NDK
│               ├── llvm/
│               ├── sysroot/
│               └── build-tools/
└── ...
```

## 步骤 3：复制 Dockerfile

将 `Dockerfile.ohos` 复制到构建目录：

```bash
# 假设 Dockerfile.ohos 在你的项目根目录
cp /path/to/naiveproxy-ohos/Dockerfile.ohos .
```

## 步骤 4：构建 Docker 镜像

```bash
# 构建镜像（这会花费 10-20 分钟，因为要复制 2GB 的文件）
docker build -f Dockerfile.ohos -t simtelboy/ohos-build:6.0.0 .

# 同时打上 latest 标签
docker tag simtelboy/ohos-build:6.0.0 simtelboy/ohos-build:latest
```

## 步骤 5：测试镜像

```bash
# 测试镜像是否正常工作
docker run --rm simtelboy/ohos-build:6.0.0 clang --version

# 应该看到类似输出：
# Huawei clang version 15.0.4
# Target: x86_64-unknown-linux-gnu
```

## 步骤 6：推送到 Docker Hub

```bash
# 登录 Docker Hub
docker login

# 推送镜像（这会花费 20-60 分钟，取决于上传速度）
docker push simtelboy/ohos-build:6.0.0
docker push simtelboy/ohos-build:latest
```

## 步骤 7：验证推送成功

访问 https://hub.docker.com/r/simtelboy/ohos-build 查看镜像是否已上传。

## 镜像大小预估

- 基础镜像 (Ubuntu 22.04): ~80MB
- Command Line Tools: ~2GB
- 其他工具: ~200MB
- **总计**: ~2.3GB

## 注意事项

1. **磁盘空间**：确保有至少 10GB 的可用空间
2. **网络**：推送镜像需要稳定的网络连接
3. **时间**：整个过程可能需要 1-2 小时

## 下一步

镜像构建并推送成功后，需要修改 `.github/workflows/build-ohos-docker.yml`，使用新的镜像。
