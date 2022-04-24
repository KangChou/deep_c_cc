# Bazel 教程：构建 C++ 项目


安装教程：
```shell
# Installation
curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor > bazel.gpg
mv bazel.gpg /etc/apt/trusted.gpg.d/
echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list

#
apt-get update && apt-get install -y bazel

# 报错记录error
#The following signatures couldn't be verified because the public key is not available: NO_PUBKEY 3D5919B448457EE0 E: The repository 'https://storage.googleapis.com/bazel-apt stable InRelease' is not signed.

# 解决方法solv: apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 3D5919B448457EE0
reinstall: apt-get update && apt-get install -y bazel

# 查看安装版本
bazel version
```


# bazel一共有三种外部依赖的主要类型

1、依赖于其他Bazel工程

根据这个Bazel工程所处的位置不同，调用不同的内置rule来获得：
```
local_repository：本地
git_repository：git仓库
http_archive：网络下载
```
2、依赖于其他非Bazel工程

还有一种情况是另外一个工程不是Bazel工程，那么就需要另外一种方法来添加依赖引用
```
new_local_repository：本地
new_git_repository：git仓库
new_http_archive：网络下载
```
3、依赖于外部包

Maven仓库：Use the rule maven_jar (and optionally the rule maven_server) to download a jar from a Maven repository and make it available as a Java dependency.

# WORKSPACE

```shell
# WORKSPACE
参考来自：https://www.csdn.net/tags/MtTaEg0sNDM3OTgyLWJsb2cO0O0O.html
1.定义项目根目录和项目名。
2.加载 Bazel 工具和 rules 集。
3.管理项目外部依赖库。
## 加载bazel标准库中的函数http_archive
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

## 调用http_archive下载rules_go
http_archive(
    name = "io_bazel_rules_go",
    # 下面两项需要根据官方的最近版本来修改
    urls = ["https://github.com/bazelbuild/rules_go/releases/download/0.16.1/rules_go-0.16.1.tar.gz"],
    sha256 = "f87fa87475ea107b3c69196f39c82b7bbf58fe27c62a338684c20ca17d1d8613",
)

## 获取gazelle
http_archive(
    name = "bazel_gazelle",
    # 同样需要根据官方最新版本修改
    urls = ["https://github.com/bazelbuild/bazel-gazelle/releases/download/0.15.0/bazel-gazelle-0.15.0.tar.gz"],
    sha256 = "6e875ab4b6bf64a38c352887760f21203ab054676d9c1b274963907e0768740d",
)

## 从rules_go中加载go_rules_dependencies,go_register_toolchains
load("@io_bazel_rules_go//go:def.bzl", "go_rules_dependencies", "go_register_toolchains")

## 加载rules_go依赖
go_rules_dependencies()

## 加载rules_go工具
go_register_toolchains()

## 从gazelle中加载gazelle_dependencies
load("@bazel_gazelle//:deps.bzl", "gazelle_dependencies")

## 加载gazelle依赖
gazelle_dependencies()
```
# bazel工程目录语法

参考：https://docs.bazel.build/versions/4.1.0/build-ref.html

```shell
workspace 工作空间

Repositories 代码仓库

Packages 包

Targets 目标

Labels(标签)

Rules(规则)

BUILD files(BUILD文件）

加载插件

规则分类

外部依赖

依赖外部bazel项目

依赖非bazel项目

依赖外部包

获取依赖

影子依赖

在命令行中覆盖仓库

离线构建
```



参考：https://docs.bazel.build/versions/main/tutorial/cpp.html

写得不错的一篇bazel工程构建 [bazel article](https://blog.csdn.net/A_L_A_N/article/details/88018718)，主要是在当前目录下构建，其他目录类似。
