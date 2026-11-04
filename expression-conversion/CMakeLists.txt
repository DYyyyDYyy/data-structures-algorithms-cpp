cmake_minimum_required(VERSION 3.20)
project(expression_conversion)

set(CMAKE_CXX_STANDARD 20)

add_executable(expression_conversion main.cpp
        Convert.cpp
        Convert.h
        List.h
        List.cpp
)
