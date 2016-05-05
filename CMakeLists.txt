cmake_minimum_required(VERSION 3.3)
project(SubgraphMaching)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp VF2.h)
add_executable(SubgraphMaching ${SOURCE_FILES})