cmake_minimum_required(VERSION 3.23)
project(TaskCheckingSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(TaskCheckingSystem main.cpp authorization.cpp authorization.h)
