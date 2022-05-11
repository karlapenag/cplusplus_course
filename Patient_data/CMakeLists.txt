cmake_minimum_required(VERSION 3.21)
project(Patient_data)

set(CMAKE_CXX_STANDARD 14)

add_executable(Patient_data main.cpp Clinic.cpp Patient.cpp Visit.cpp)
