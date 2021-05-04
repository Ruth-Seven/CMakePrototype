# This is the source directory of the last call to the project() command made in the current directory scope or one of its parents.
# set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/jtest/")
# or use glob
file(GLOB JTEST_HEADER_LIST "${PROJECT_SOURCE_DIR}/include/jtest/*.h*") # 神奇的glob
# lib的设置和include是分开的
add_library(main_library add.cpp ${JTEST_HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(main_library  PUBLIC ../include)

# This depends on (header only) boost
target_link_libraries(main_library PRIVATE Boost::boost)

# All users of this library will need at least C++11
target_compile_features(main_library PUBLIC cxx_std_11)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${JTEST_HEADER_LIST} ${MY_HEADER_LIST} )

## 运行

编译
```shell
rm build -rf
cmake -S . -B build -D BUILD_TESTS=1 
cmake --build build  
```
> `BUILD_TESTS`： `cmake`进行测试相关构建

使用自定义测试框架：
```shell
./build/test/maintest
```
运行主程序：
```shell
./build/apps/app
```
