cmake_minimum_required(VERSION 3.20)
project(linked_lists)

set(CMAKE_CXX_STANDARD 20)

add_executable(linked_lists main.cpp
        List.h
        List.cpp)
