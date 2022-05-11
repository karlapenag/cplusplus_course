cmake_minimum_required(VERSION 3.21)
project(Bank)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bank main.cpp Account.cpp BankApp.cpp Client.cpp SavingsAccount.cpp)

