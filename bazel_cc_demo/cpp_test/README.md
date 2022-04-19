# Examples to build C++ code

This package will showcase how to build C++ code in stages.

共有三组文件，每组代表本教程中的一个阶段。

在第一阶段，您将构建驻留在单个包中的单个目标。

在第二阶段，您将项目拆分为多个目标，但将其保存在一个包中。

在第三个也是最后一个阶段，您将项目拆分为多个包并使用多个目标构建它。

### Stage 1
The first stage is really simple and shows you how to compile a binary with a single source file.

### Stage 2
The second stage will showcase how to build an application with multiple source and header files, separated in a library and a binary.

### Stage 3
The third stage showcases how to link multiple build directories by building multiple libraries in different packages and then connecting it up with the main application.

# 编译参数解释

## 1、WORKSPACE
在构建项目之前，您需要设置其工作区。工作区是一个包含项目源文件和 Bazel 构建输出的目录。它还包含 Bazel 认为特殊的文件：

该WORKSPACE文件将目录及其内容标识为 Bazel 工作区，并位于项目目录结构的根目录中，

一个或多个BUILD文件，告诉 Bazel 如何构建项目的不同部分。（工作空间中包含BUILD文件的目录是一个包。您将在本教程后面了解包。）

要将目录指定为 Bazel 工作区，请 WORKSPACE在该目录中创建一个名为的空文件。

Bazel 构建项目时，所有输入和依赖项都必须在同一个工作区中。除非链接，否则驻留在不同工作区中的文件相互独立，这超出了本教程的范围。

## 2、BUILD
一个BUILD文件包含几种不同类型的 Bazel 指令。最重要的类型是build rule，它告诉 Bazel 如何构建所需的输出，例如可执行的二进制文件或库。文件中构建规则的每个实例BUILD都称为目标，并指向一组特定的源文件和依赖项。一个目标也可以指向其他目标。
```cpp
cc_binary(
    name = "hello-world",
    srcs = ["hello-world.cc"],
)

```

示例中，hello-world目标实例化了 Bazel 的内置 cc_binary规则。该规则告诉 Bazel 从hello-world.cc源文件构建一个独立的可执行二进制文件，没有依赖关系。

目标中的属性明确声明其依赖项和选项。虽然该name属性是强制性的，但许多是可选的。例如，在 hello-world目标中，name是必需的且不言自明，并且srcs是可选的，并指定 Bazel 从中构建目标的源文件。

## 3、Build the project
要构建您的示例项目，请导航到该test1目录并运行：
```
bazel build //main:hello-world
```
在目标标签中，//main:部分是BUILD 文件相对于工作空间根的位置，是文件hello-world中的目标名称BUILD。（您将在本教程末尾更详细地了解目标标签。）

Bazel 产生类似于以下内容的输出：
```
INFO: Found 1 target...
Target //main:hello-world up-to-date:
  bazel-bin/main/hello-world
INFO: Elapsed time: 2.267s, Critical Path: 0.25s
```
恭喜，您刚刚构建了您的第一个 Bazel 目标！Bazel 将构建输出放在bazel-bin工作区根目录的目录中。浏览其内容以了解 Bazel 的输出结构。

现在测试您新构建的二进制文件：
```
./bazel-bin/main/hello-world
或者
bazel run //main:hello-world
# 由于c++该demo有传入参数的功能，可以直接
bazel run //main:hello-world 2022data
或者 ./bazel-bin/main/hello-world 2022data
```

## 4、查看编译的依赖关系图
BUILD 成功的构建在文件中明确说明了其所有依赖项。Bazel 使用这些语句创建项目的依赖关系图，从而实现准确的增量构建。

要可视化示例项目的依赖关系，您可以通过在工作区根目录运行以下命令来生成依赖关系图的文本表示：
```
bazel query --notool_deps --noimplicit_deps "deps(//main:hello-world)" \
  --output graph
```
上面的命令告诉 Bazel 查找目标的所有依赖项 //main:hello-world（不包括主机和隐式依赖项）并将输出格式化为图形。

然后，将文本粘贴到GraphViz中。

在 Ubuntu 上，您可以通过安装 GraphViz 和 xdot Dot Viewer 在本地查看图形：
```
sudo apt update && sudo apt install graphviz xdot
```
然后，您可以通过将上面的文本输出直接传送到 xdot 来生成和查看图形：
```
xdot <(bazel query --notool_deps --noimplicit_deps "deps(//main:hello-world)" \
  --output graph)
```
如您所见，示例项目的第一阶段有一个单一的目标，它构建一个没有额外依赖项的单一源文件：

'hello-world' 的依赖关系图
![image](https://user-images.githubusercontent.com/36963108/163914693-8bfb1b4d-6511-46a7-872e-34aaab3fe8f5.png)


在设置好工作区、构建项目并检查其依赖项之后，您可以添加一些复杂性。

# 参考
https://docs.bazel.build/versions/main/tutorial/cpp.html
