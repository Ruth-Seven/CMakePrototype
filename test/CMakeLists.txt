# Testing library
include(GoogleTest)
FetchContent_Declare(
    GoogleTest 
    GIT_REPOSITORY  https://github.com/google/googletest.git
    GIT_TAG release-1.10.0
)
FetchContent_MakeAvailable(GoogleTest)

# Tests need to be added as executables first
add_executable(maintest test.cpp test2.cpp)

# I'm using C++11 in the test
target_compile_features(maintest PRIVATE cxx_std_11)

# Should be linked to the main library, as well as the GoogleTest testing library
# target_link_libraries(maintest PRIVATE GoogleTest)
target_link_libraries(maintest PRIVATE libjtest) # 使用自定义 测试框架
target_link_libraries(maintest PRIVATE main_library) # 添加测试函数的库
target_include_directories(maintest PRIVATE ../include)
target_include_directories(maintest PRIVATE ../src)



# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME maintestTest COMMAND maintest) # COMMAND cna be a target


# conditional controal test log function.
option(USE_LOG "if you want to close test log, set it as true." OFF)
message(${USE_LOG})
if(USE_LOG)
    target_compile_definitions(maintest PRIVATE ISIGNORE_LOG=1)
endif()