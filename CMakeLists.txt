# 最低版本要求
cmake_minimum_required(VERSION 4.1)
# 项目名称
project(cpp_basic)

# 设置变量
set(CMAKE_CXX_STANDARD 26)

# 定义可执行程序
add_executable(cpp_basic main.cpp
        include/calculator.h
        src/module01/calculator.cpp
        include/utils.h
        include/student.h
        include/math_utils.h
        include/array_utils.h
        include/constants.h
        src/module02/utils.cpp
        src/module01/data_type.cpp
        include/data_type.h
)