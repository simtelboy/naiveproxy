# 鸿蒙 NDK Docker 镜像构建完整教程

本教程将手把手教你从零开始，构建包含鸿蒙 NDK 的 Docker 镜像，实现 NaiveProxy 的自动化编译。

---

## 📋 前置要求

- Windows 10/11 或 macOS 或 Linux
- 至少 20GB 可用磁盘空间
- 稳定的网络连接

---

## 第一部分：注册鸿蒙开发者账号

### 步骤 1.1：访问华为开发者联盟

1. 打开浏览器，访问：https://developer.huawei.com/
2. 点击右上角的 **"登录"** 按钮

![华为开发者首页](https://via.placeholder.com/800x400?text=华为开发者首页)

### 步骤 1.2：注册华为账号

**如果你已有华为账号，跳到步骤 1.3**

1. 点击 **"注册"**
2. 选择注册方式：
   - **推荐**：使用手机号注册
   - 或使用邮箱注册

3. 填写信息：
   ```
   手机号：+86 138xxxxxxxx
   验证码：点击"获取验证码"，输入收到的验证码
   密码：设置一个强密码（至少8位，包含大小写字母和数字）
   ```

4. 勾选 **"我已阅读并同意《华为账号用户协议》"**
5. 点击 **"注册"**

### 步骤 1.3：登录并完善开发者信息

1. 使用刚注册的账号登录
2. 首次登录会提示 **"完善开发者信息"**
3. 填写以下信息：
   ```
   开发者类型：个人开发者
   姓名：你的真实姓名
   身份证号：你的身份证号（用于实名认证）
   手机号：已验证
   ```

4. 点击 **"提交"**
5. 等待审核（通常 1-2 个工作日，但个人开发者一般很快）

**注意**：如果只是下载 SDK，不需要等待审核完成。

---

## 第二部分：下载并安装 DevEco Studio

### 步骤 2.1：下载 DevEco Studio

1. 访问：https://developer.huawei.com/consumer/cn/deveco-studio/
2. 点击 **"立即下载"**
3. 选择你的操作系统：
   - **Windows**: `deveco-studio-x.x.x.exe`
   - **macOS**: `deveco-studio-x.x.x.dmg`
   - **Linux**: `deveco-studio-x.x.x.tar.gz`

4. 下载大小约 **1.5 GB**，耐心等待

### 步骤 2.2：安装 DevEco Studio

#### Windows 用户：

1. 双击下载的 `.exe` 文件
2. 点击 **"Next"**
3. 选择安装路径（建议默认）：
   ```
   C:\Program Files\Huawei\DevEco Studio
   ```
4. 勾选 **"Create Desktop Shortcut"**（创建桌面快捷方式）
5. 点击 **"Install"**
6. 等待安装完成（约 5 分钟）
7. 点击 **"Finish"**

#### macOS 用户：

1. 双击下载的 `.dmg` 文件
2. 将 DevEco Studio 拖到 Applications 文件夹
3. 打开 Applications，找到 DevEco Studio
4. 右键点击，选择 **"打开"**（首次需要授权）

#### Linux 用户：

```bash
# 解压
tar -xzf deveco-studio-x.x.x.tar.gz

# 进入目录
cd deveco-studio/bin

# 运行
./deveco-studio.sh
```

### 步骤 2.3：首次启动配置

1. 启动 DevEco Studio
2. 选择 **"Do not import settings"**（不导入设置）
3. 点击 **"OK"**

4. **欢迎界面**：
   - 点击 **"Next"**

5. **选择主题**：
   - 选择 **"Darcula"**（深色）或 **"Light"**（浅色）
   - 点击 **"Next"**

6. **SDK 安装路径**：
   - Windows 默认：`C:\Users\你的用户名\AppData\Local\Huawei\Sdk`
   - macOS 默认：`~/Library/Huawei/Sdk`
   - Linux 默认：`~/Huawei/Sdk`
   - **记住这个路径，后面会用到！**
   - 点击 **"Next"**

7. **登录华为账号**：
   - 点击 **"Sign In"**
   - 输入你的华为账号和密码
   - 点击 **"登录"**

---

## 第三部分：下载鸿蒙 SDK 和 NDK

### 步骤 3.1：打开 SDK Manager

1. 在 DevEco Studio 欢迎界面，点击 **"Configure"** > **"SDK Manager"**

   或者如果已经打开了项目：
   - 点击顶部菜单 **"File"** > **"Settings"**（Windows/Linux）
   - 或 **"DevEco Studio"** > **"Preferences"**（macOS）
   - 左侧选择 **"SDK"**

### 步骤 3.2：选择 SDK 版本

1. 在 **"SDK Platforms"** 标签页：
   - 勾选 **"HarmonyOS NEXT"**
   - 勾选 **"API 12"**（或最新版本）

2. 在 **"SDK Tools"** 标签页，勾选以下组件：
   ```
   ✅ HarmonyOS SDK
   ✅ Native (这个是 NDK，非常重要！)
   ✅ Toolchains
   ✅ Command Line Tools
   ✅ Previewer
   ```

3. 点击右下角的 **"Apply"**

### 步骤 3.3：开始下载

1. 弹出确认对话框，显示需要下载的组件
2. 查看下载大小（约 **5-8 GB**）
3. 点击 **"OK"** 开始下载

4. **下载进度**：
   ```
   Downloading HarmonyOS SDK...
   Downloading Native (NDK)...
   Downloading Toolchains...
   ```

5. 等待下载完成（根据网速，可能需要 30 分钟到 2 小时）

### 步骤 3.4：验证下载

下载完成后，验证 NDK 是否存在：

#### Windows：
```cmd
dir "C:\Users\你的用户名\AppData\Local\Huawei\Sdk\openharmony"
```

你应该看到类似的目录结构：
```
openharmony/
├── 12/                    # API 版本号
│   ├── native/           # 👈 这就是 NDK！
│   │   ├── llvm/
│   │   │   └── bin/
│   │   │       ├── clang.exe
│   │   │       └── clang++.exe
│   │   ├── sysroot/
│   │   └── build-tools/
│   ├── toolchains/
│   └── ...
```

#### macOS/Linux：
```bash
ls -la ~/Library/Huawei/Sdk/openharmony/12/native
# 或
ls -la ~/Huawei/Sdk/openharmony/12/native
```

### 步骤 3.5：记录 NDK 路径

**非常重要！** 记下完整的 NDK 路径：

- **Windows**: `C:\Users\你的用户名\AppData\Local\Huawei\Sdk\openharmony\12\native`
- **macOS**: `/Users/你的用户名/Library/Huawei/Sdk/openharmony/12/native`
- **Linux**: `/home/你的用户名/Huawei/Sdk/openharmony/12/native`

---

## 第四部分：准备 Docker 环境

### 步骤 4.1：安装 Docker Desktop

#### Windows 用户：

1. 访问：https://www.docker.com/products/docker-desktop/
2. 点击 **"Download for Windows"**
3. 下载 `Docker Desktop Installer.exe`
4. 双击安装
5. 安装过程中会提示安装 WSL2，点击 **"OK"**
6. 重启电脑
7. 启动 Docker Desktop
8. 等待 Docker 引擎启动（右下角图标变绿）

#### macOS 用户：

1. 访问：https://www.docker.com/products/docker-desktop/
2. 选择你的芯片：
   - **Apple Silicon (M1/M2/M3)**: 下载 ARM 版本
   - **Intel**: 下载 Intel 版本
3. 双击 `.dmg` 文件安装
4. 启动 Docker Desktop

#### Linux 用户：

```bash
# Ubuntu/Debian
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh

# 添加当前用户到 docker 组
sudo usermod -aG docker $USER

# 重新登录或运行
newgrp docker

# 启动 Docker
sudo systemctl start docker
sudo systemctl enable docker
```

### 步骤 4.2：验证 Docker 安装

打开终端（Windows 用户打开 PowerShell 或 CMD），运行：

```bash
docker --version
```

应该看到类似输出：
```
Docker version 24.0.7, build afdd53b
```

测试 Docker 是否正常工作：
```bash
docker run hello-world
```

如果看到 "Hello from Docker!"，说明安装成功！

### 步骤 4.3：注册 Docker Hub 账号

1. 访问：https://hub.docker.com/signup
2. 填写信息：
   ```
   Docker ID: simtelboy（或你想要的用户名）
   Email: 你的邮箱
   Password: 设置密码
   ```
3. 点击 **"Sign Up"**
4. 验证邮箱（检查收件箱，点击验证链接）

### 步骤 4.4：登录 Docker Hub

在终端运行：
```bash
docker login
```

输入你的 Docker Hub 用户名和密码：
```
Username: simtelboy
Password: ********
Login Succeeded
```

---

## 第五部分：复制并打包 NDK

### 步骤 5.1：创建工作目录

打开终端，创建一个工作目录：

```bash
# Windows (PowerShell)
cd C:\Users\你的用户名\Desktop
mkdir ohos-docker
cd ohos-docker

# macOS/Linux
cd ~/Desktop
mkdir ohos-docker
cd ohos-docker
```

### 步骤 5.2：复制 NDK 到工作目录

#### Windows (PowerShell)：
```powershell
# 复制整个 native 目录
Copy-Item -Path "C:\Users\你的用户名\AppData\Local\Huawei\Sdk\openharmony\12\native" -Destination ".\ohos-ndk" -Recurse

# 验证
dir ohos-ndk
```

#### macOS：
```bash
# 复制整个 native 目录
cp -r ~/Library/Huawei/Sdk/openharmony/12/native ./ohos-ndk

# 验证
ls -la ohos-ndk
```

#### Linux：
```bash
# 复制整个 native 目录
cp -r ~/Huawei/Sdk/openharmony/12/native ./ohos-ndk

# 验证
ls -la ohos-ndk
```

### 步骤 5.3：验证 NDK 内容

确保复制的目录包含以下内容：

```bash
# Windows
dir ohos-ndk\llvm\bin\clang.exe

# macOS/Linux
ls ohos-ndk/llvm/bin/clang
```

如果文件存在，说明复制成功！

---

## 第六部分：创建 Dockerfile

### 步骤 6.1：创建 Dockerfile

在 `ohos-docker` 目录中创建一个名为 `Dockerfile` 的文件（没有扩展名）。

#### Windows 用户：
```powershell
# 使用记事本创建
notepad Dockerfile
```

#### macOS/Linux 用户：
```bash
# 使用文本编辑器创建
nano Dockerfile
# 或
vim Dockerfile
```

### 步骤 6.2：编写 Dockerfile 内容

将以下内容复制到 `Dockerfile` 中：

```dockerfile
# 使用 Ubuntu 22.04 作为基础镜像
FROM ubuntu:22.04

# 设置非交互模式（避免安装过程中的提示）
ENV DEBIAN_FRONTEND=noninteractive

# 更新包列表并安装基础工具
RUN apt-get update && apt-get install -y \
    curl \
    wget \
    git \
    python3 \
    python3-pip \
    build-essential \
    ninja-build \
    pkg-config \
    ccache \
    unzip \
    tar \
    xz-utils \
    ca-certificates \
    gnupg \
    lsb-release \
    file \
    && rm -rf /var/lib/apt/lists/*

# 创建 NDK 目录
RUN mkdir -p /opt/ohos-ndk

# 复制鸿蒙 NDK 到镜像中
# 这是关键步骤！将本地的 ohos-ndk 目录复制到镜像的 /opt/ohos-ndk
COPY ohos-ndk /opt/ohos-ndk

# 设置环境变量
ENV OHOS_NDK_HOME=/opt/ohos-ndk
ENV PATH=$PATH:/opt/ohos-ndk/llvm/bin

# 验证 NDK 安装
RUN echo "验证鸿蒙 NDK 安装..." && \
    ls -la /opt/ohos-ndk && \
    /opt/ohos-ndk/llvm/bin/clang --version

# 设置工作目录
WORKDIR /workspace

# 添加标签
LABEL maintainer="simtelboy"
LABEL description="HarmonyOS NDK build environment for NaiveProxy"
LABEL version="1.0"

# 默认命令
CMD ["/bin/bash"]
```

保存文件：
- **记事本**：点击 "文件" > "保存"
- **nano**：按 `Ctrl+O`，回车，然后 `Ctrl+X`
- **vim**：按 `Esc`，输入 `:wq`，回车

### 步骤 6.3：验证文件结构

确保你的目录结构如下：

```
ohos-docker/
├── Dockerfile          # 刚创建的文件
└── ohos-ndk/          # 复制的 NDK 目录
    ├── llvm/
    │   └── bin/
    │       ├── clang
    │       └── clang++
    ├── sysroot/
    └── build-tools/
```

验证命令：

```bash
# Windows
dir

# macOS/Linux
ls -la
```

---

## 第七部分：构建 Docker 镜像

### 步骤 7.1：开始构建

在 `ohos-docker` 目录中，运行以下命令：

```bash
docker build -t simtelboy/ohos-build:latest .
```

**注意**：
- `-t simtelboy/ohos-build:latest` 是镜像的名称和标签
- 将 `simtelboy` 替换为你的 Docker Hub 用户名
- 最后的 `.` 表示使用当前目录的 Dockerfile

### 步骤 7.2：等待构建完成

构建过程会显示类似输出：

```
[+] Building 234.5s (12/12) FINISHED
 => [internal] load build definition from Dockerfile
 => [internal] load .dockerignore
 => [internal] load metadata for docker.io/library/ubuntu:22.04
 => [1/7] FROM docker.io/library/ubuntu:22.04
 => [internal] load build context
 => [2/7] RUN apt-get update && apt-get install -y ...
 => [3/7] RUN mkdir -p /opt/ohos-ndk
 => [4/7] COPY ohos-ndk /opt/ohos-ndk
 => [5/7] RUN echo "验证鸿蒙 NDK 安装..." && ...
 => exporting to image
 => => exporting layers
 => => writing image sha256:abc123...
 => => naming to docker.io/simtelboy/ohos-build:latest
```

**构建时间**：约 5-15 分钟（取决于你的电脑性能）

**镜像大小**：约 3-4 GB

### 步骤 7.3：验证镜像构建成功

```bash
docker images
```

应该看到：
```
REPOSITORY              TAG       IMAGE ID       CREATED         SIZE
simtelboy/ohos-build    latest    abc123def456   2 minutes ago   3.5GB
```

### 步骤 7.4：测试镜像

运行一个测试容器：

```bash
docker run --rm simtelboy/ohos-build:latest clang --version
```

应该看到类似输出：
```
Huawei clang version 15.0.4
Target: aarch64-unknown-linux-ohos
Thread model: posix
```

如果看到这个输出，说明镜像构建成功！🎉

---

## 第八部分：推送镜像到 Docker Hub

### 步骤 8.1：确认已登录

```bash
docker login
```

如果已登录，会显示：
```
Login Succeeded
```

### 步骤 8.2：推送镜像

```bash
docker push simtelboy/ohos-build:latest
```

**推送过程**：

```
The push refers to repository [docker.io/simtelboy/ohos-build]
5f70bf18a086: Pushing [==>                ] 156.7MB/3.5GB
...
```

**推送时间**：约 20-60 分钟（取决于你的上传速度）

### 步骤 8.3：验证推送成功

1. 访问：https://hub.docker.com/
2. 登录你的账号
3. 点击 **"Repositories"**
4. 应该看到 `simtelboy/ohos-build` 仓库

或者在终端运行：
```bash
docker pull simtelboy/ohos-build:latest
```

如果能成功拉取，说明推送成功！

---

## 第九部分：修改 GitHub Actions 工作流

### 步骤 9.1：克隆你的仓库（如果还没有）

```bash
cd ~/Desktop
git clone https://github.com/simtelboy/naiveproxy.git
cd naiveproxy
```

### 步骤 9.2：修改工作流文件

编辑 `.github/workflows/build-ohos-docker.yml`：

找到第 25-50 行左右的内容，替换为：

```yaml
jobs:
  build-ohos-so:
    name: 编译鸿蒙 .so 库 (${{ matrix.arch }})
    runs-on: ubuntu-22.04

    # 使用你的 Docker 镜像
    container:
      image: simtelboy/ohos-build:latest  # 👈 改成你的镜像名
      options: --privileged

    strategy:
      fail-fast: false
      matrix:
        arch: ${{ github.event.inputs.arch == 'both' && fromJSON('["arm64", "x64"]') || github.event.inputs.arch == '' && fromJSON('["arm64"]') || fromJSON(format('["{0}"]', github.event.inputs.arch)) }}

    steps:
      # 不需要安装基础工具了，镜像中已经有了

      - name: Checkout 代码
        uses: actions/checkout@v4

      # 不需要下载鸿蒙 NDK 了，镜像中已经有了

      - name: 验证鸿蒙 NDK
        run: |
          echo "========================================="
          echo "验证鸿蒙 NDK"
          echo "========================================="
          echo "NDK 路径: $OHOS_NDK_HOME"
          clang --version
          echo ""
          echo "✅ 鸿蒙 NDK 已就绪！"

      # 继续后面的编译步骤...
```

### 步骤 9.3：删除不需要的步骤

删除以下步骤（因为镜像中已经包含）：
- ❌ "安装基础工具"
- ❌ "下载并安装鸿蒙 NDK"

保留以下步骤：
- ✅ "Checkout 代码"
- ✅ "验证鸿蒙 NDK"
- ✅ "缓存编译工具链"
- ✅ "修改构建配置支持鸿蒙"
- ✅ 所有编译相关步骤

### 步骤 9.4：提交并推送

```bash
git add .github/workflows/build-ohos-docker.yml
git commit -m "Update workflow to use custom Docker image with HarmonyOS NDK"
git push origin master
```

---

## 第十部分：运行编译测试

### 步骤 10.1：访问 GitHub Actions

1. 打开浏览器
2. 访问：https://github.com/simtelboy/naiveproxy/actions
3. 点击 **"Build NaiveProxy for HarmonyOS"**

### 步骤 10.2：手动触发工作流

1. 点击右侧的 **"Run workflow"** 按钮
2. 选择：
   ```
   Branch: master
   目标架构: arm64
   ```
3. 点击绿色的 **"Run workflow"** 按钮

### 步骤 10.3：查看编译进度

1. 刷新页面，会看到新的工作流运行
2. 点击进入查看详细日志
3. 展开 **"验证鸿蒙 NDK"** 步骤

应该看到：
```
=========================================
验证鸿蒙 NDK
=========================================
NDK 路径: /opt/ohos-ndk
Huawei clang version 15.0.4
Target: aarch64-unknown-linux-ohos

✅ 鸿蒙 NDK 已就绪！
```

### 步骤 10.4：等待编译完成

- 编译时间：约 40-60 分钟
- 可以关闭浏览器，稍后回来查看

### 步骤 10.5：下载编译产物

编译成功后：

1. 滚动到页面底部
2. 在 **"Artifacts"** 部分
3. 下载 `libnaive-ohos-arm64-sha256-xxxxx.zip`
4. 解压得到 `libnaive-ohos-arm64.tar.gz`
5. 再次解压得到 `libnaive.so`

---

## 🎉 完成！

恭喜你！你已经成功：

✅ 注册了鸿蒙开发者账号
✅ 下载了鸿蒙 NDK
✅ 构建了包含 NDK 的 Docker 镜像
✅ 推送到了 Docker Hub
✅ 配置了 GitHub Actions
✅ 编译出了鸿蒙版本的 libnaive.so

---

## 📝 常见问题

### Q1: Docker 构建失败，提示 "no space left on device"

**解决**：
```bash
# 清理 Docker 缓存
docker system prune -a

# 增加 Docker 磁盘空间（Docker Desktop）
# Settings > Resources > Disk image size > 增加到 60GB
```

### Q2: 推送镜像很慢

**解决**：
- 使用国内网络可能较慢
- 可以尝试使用 VPN
- 或者分时段推送（晚上网络较好）

### Q3: GitHub Actions 拉取镜像失败

**解决**：
```yaml
# 确保镜像名称正确
container:
  image: simtelboy/ohos-build:latest  # 检查用户名是否正确
```

### Q4: 编译失败，提示找不到 clang

**解决**：
```bash
# 重新构建镜像，确保 COPY 步骤正确
docker build -t simtelboy/ohos-build:latest . --no-cache
```

---

## 🔄 更新 NDK

如果华为发布了新版本的 NDK，你需要：

1. 在 DevEco Studio 中更新 SDK
2. 重新复制 NDK 到 `ohos-docker` 目录
3. 重新构建镜像：
   ```bash
   docker build -t simtelboy/ohos-build:v2.0 .
   ```
4. 推送新版本：
   ```bash
   docker push simtelboy/ohos-build:v2.0
   ```
5. 更新 GitHub Actions 工作流中的镜像标签

---

## 📞 获取帮助

如果遇到问题：

1. 检查本教程的"常见问题"部分
2. 查看 GitHub Actions 的详细日志
3. 在仓库创建 Issue

---

**祝你编译顺利！** 🚀
