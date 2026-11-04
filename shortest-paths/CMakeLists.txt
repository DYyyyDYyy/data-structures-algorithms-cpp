cmake_minimum_required(VERSION 3.20)
project(shortest_paths)

set(CMAKE_CXX_STANDARD 20)

add_executable(shortest_paths main.cpp
        graph_solver.h
        dijkstra.cpp
        floyd.cpp
        List.cpp
        List.h)
