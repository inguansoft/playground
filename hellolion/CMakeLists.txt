cmake_minimum_required(VERSION 3.26)
project(hellolion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hellolion
        hellolion.cpp
        hellolion.h)
