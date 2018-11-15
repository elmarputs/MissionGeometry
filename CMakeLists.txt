cmake_minimum_required(VERSION 3.12)
project(MissionGeometry)

set(CMAKE_CXX_STANDARD 17)

add_executable(MissionGeometry main.cpp include/constants.h include/basicTypes.h coordinateTransformations.cpp include/coordinateTransformations.h)