

# CMake Prototype 
这个项目是为了记录一点点学习`cmake`后的资料和实践结果的，笔记由于不成体系，而且`cmake`难度主要在于理解编译过程，就不放了。重要的是给出学习方向，节省时间。

# What is Cmake?

Cmake是跨系统，C++现行标准构建标准的build system of build system。学习CMake需要一点点耐心，因为CMake需要你首先有操作系统如何编译文件的前提知识，当然你也可以直接跳过这个部分，手把手看`cmake`代码，马上上手项目。但是前者追求是程序员的理解，功夫更深更扎实。

# How to understand and use CMake?
以下是我翻阅的一些`cmake`有趣实用的资料，按适宜实用顺序排列：

- [Cmake Tutorial](https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b): 💖从零基础解释CMake基础概念
- [modern-cmake](https://cliutils.gitlab.io/modern-cmake/chapters/intro/newcmake.html) ✅: 最详细，有很多项目经验，本身也有着几个详细的小CMake项目例子
- [Original cmake tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html) ✅ ：`CMake`官方出的跟着做比较有意思，可以多多尝试，就是有点花时间。后面部分内容可以看看

纸上得来终觉浅，绝知此事要躬行。


# 测试框架实践
在阅读了GoogleTest测试框架源代码后，我也撸了一个玩具性质的测试框架。运行只需要导入`jtest.hpp`，进行配置即可：
```c++
#include "add.hxx"
// 单元测试样例
TEST(HelloTest1, ADD1){
    //LOG("test1")
	EXPECT_EQ(ADD1(3,4), 7);
	EXPECT_NE(ADD1(3,4), 6);
	EXPECT_LT(ADD1(3,4), 8);
	EXPECT_LE(ADD1(3,4), 7);
	EXPECT_GT(ADD1(3,4), 6);
	EXPECT_GE(ADD1(3,4), 7);
}

int main(){
	return RUN_ALL_TESTS();
}
```
> 目前支持六个数值判断逻辑测试。


项目中`test.cpp`运行结果如下：

![image-20210504225232757](http://static.come2rss.xyz/image-20210504225232757.png)

在用`cmake`编译链接，可在`./build/test`下运行测试`target`二进制文件。

## 主要原理
利用C++/宏进行`TEST`功能的宏替换，实现自动函数定义，测试单元信息注册和销毁。
同时输出鲜明的判断信息，比如颜色，文件和行数帮助结果查看。


## 技术卡点
- 宏替换：多行宏替换，宏参数的字符串化和连接，中间层宏编写
- 注册函数、注销函数
- printf颜色控制
- 单元测试方法信息注册实现方法

