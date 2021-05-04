cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0054 NEW)
project(GoogleTestofTest VERSION 1.0)

cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    set(CMAKE_CXX_EXTENSIONS OFF)

    set_property(GLOBAL PROPERTY USE_FOLDERS ON)


    INCLUDE(CTest)

    find_package(Doxygen)
    if(Doxygen_FOUND)
        add_subdirectory(docs)
    else()
        message("Doxygen is not found, not building docs.")
    endif()
endif()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)
if(${CMAKE_VERSION} VERSION_LESS 3.14)
  include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()

# 测试 find_package 功能
find_package(Boost REQUIRED)


# fetch_content
FetchContent_Declare(
    fmtlib
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 5.3.0
)
# Adds fmt::fmt 
FetchContent_MakeAvailable(fmtlib)




# The executable code is here
add_subdirectory(apps)



# The compiled library code is here
add_subdirectory(src)

# compile jtest library
add_subdirectory(include/jtest)


if((CMAKE_PROJECT_NAME STREQUAL  PROJECT_NAME AND BUILD_TESTS))
    add_subdirectory(tests)
    
endif()


