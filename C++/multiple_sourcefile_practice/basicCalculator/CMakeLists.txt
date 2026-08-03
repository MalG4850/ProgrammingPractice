cmake_minimum_required(VERSION 3.20)
project(BasicCalculator LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(
    basicCalculator
    app/main.cpp
    src/add.cpp
    src/subtract.cpp
    src/multiply.cpp
    src/divide.cpp
)

target_include_directories(
    basicCalculator
    PRIVATE
    include
)
