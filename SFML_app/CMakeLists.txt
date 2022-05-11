cmake_minimum_required(VERSION 3.21)
project(SFML_app)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(SFML_app main.cpp)
target_link_libraries(SFML_app sfml-graphics sfml-audio)

