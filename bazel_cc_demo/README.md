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

参考：https://docs.bazel.build/versions/main/tutorial/cpp.html
