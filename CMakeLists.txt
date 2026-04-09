cmake_minimum_required(VERSION 3.20)
project(cpp_basic)

set(CMAKE_CXX_STANDARD 20)

# 核心库
add_library(core
        src/module01/calculator.cpp
        src/module02/utils.cpp
        src/module01/data_type.cpp
        src/module01/condition.cpp
)

target_include_directories(core PUBLIC include)

# 主程序
add_executable(cpp_basic main.cpp)
target_link_libraries(cpp_basic core)
