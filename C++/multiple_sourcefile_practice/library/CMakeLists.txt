cmake_minimum_required(VERSION 3.20)
project(library LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(
    library
    app/main.cpp
    include/searching.hpp
    src/searching.cpp
)

target_include_directories(
    library
    PRIVATE
    include
)
