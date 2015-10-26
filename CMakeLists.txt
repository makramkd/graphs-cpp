cmake_minimum_required(VERSION 3.3)
project(graphs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp edge.cpp edge.h graph.cpp graph.h adjacency_list.cpp adjacency_list.h matrix.cpp matrix.h adjacency_matrix.cpp adjacency_matrix.h incidence_matrix.cpp incidence_matrix.h laplacian_matrix.cpp laplacian_matrix.h)
add_executable(graphs ${SOURCE_FILES})