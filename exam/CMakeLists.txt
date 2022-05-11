cmake_minimum_required(VERSION 3.21)
project(exam)

set(CMAKE_CXX_STANDARD 14)

add_executable(exam main.cpp)
add_executable(dotProduct dotProduct.cpp)
add_executable(isSorted isSorted.cpp)
add_executable(allocator allocator.cpp)
add_executable(linkedList linkedList.cpp)
add_executable(sudoku sudoku.cpp)
add_executable(library_scaffold library_scaffold.cpp)