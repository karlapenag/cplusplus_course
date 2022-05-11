cmake_minimum_required(VERSION 3.21)
project(march)

set(CMAKE_CXX_STANDARD 14)

add_executable(march main.cpp)
add_executable(scratch scratch.cpp)
add_executable(scratch2 scratch2.cpp)
add_executable(exercise1 exercise1.cpp)
add_executable(files files.cpp)
add_executable(readfile readfile.cpp)
add_executable(example example.cpp)
add_executable(dummy main.cpp dummy.cpp)