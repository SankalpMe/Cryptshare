cmake_minimum_required(VERSION 3.14)
project(hello)

set(CMAKE_CXX_STANDARD 14)

add_executable(hello main.cpp RSA.cpp RSA.h Loader.cpp Loader.h)