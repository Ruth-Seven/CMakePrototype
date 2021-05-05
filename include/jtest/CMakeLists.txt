cmake_minimum_required(VERSION 3.9.1)

#如果有 libray 需要编译的话，应该添加一个 库编译输出路径和目标
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_library(libjtest SHARED jtest.cxx )


