cmake_minimum_required(VERSION 3.20)
project(ArraySorter LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(
    sorting
    app/main.cpp
    include/sorting.hpp
    src/sorting.cpp
)

target_include_directories(
    sorting
    PRIVATE
    include
)
