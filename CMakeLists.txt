cmake_minimum_required(VERSION 3.12)
project(MissionGeometry)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR})

message(STATUS "Executables are placed in: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

include_directories(include)

add_executable(MissionGeometry coordinateTransformations.cpp basicMath.cpp basicTypes.cpp main.cpp)