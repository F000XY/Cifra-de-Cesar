cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled
        cmake-build-debug/main.cpp
        cmake-build-debug/Criptografia.h
        cmake-build-debug/Cripitografia.cpp
)
