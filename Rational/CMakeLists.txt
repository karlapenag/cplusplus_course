cmake_minimum_required(VERSION 3.14)
project(Rational)

set(CMAKE_CXX_STANDARD 14)

add_executable(Rational src/main.cpp src/Rational.cpp include/Rational.h)