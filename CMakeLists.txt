cmake_minimum_required(VERSION 3.12)
project(MissionGeometry)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/lib)

message(STATUS "Executables are placed in: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "Libraries are placed in: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

add_subdirectory(Basics)

add_executable(MissionGeometry main.cpp)
target_link_libraries(MissionGeometry mgBasics)