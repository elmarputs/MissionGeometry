cmake_minimum_required(VERSION 3.12)
project(MissionGeometry)

set(CMAKE_CXX_STANDARD 17)

add_executable(MissionGeometry coordinateTransformations.cpp basicMath.cpp basicTypes.cpp main.cpp)