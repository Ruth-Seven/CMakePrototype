add_executable(app main.cpp)

target_compile_definitions(app PRIVATE cxx_std_11)
target_link_libraries(app PRIVATE main_library fmt::fmt)
target_include_directories(app PRIVATE "${PROJECT_SOURCE_DIR}/src")