cmake_minimum_required(VERSION 3.25)

project(test_memory)

add_executable(test_memory
${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/timer.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/timer.hpp
${CMAKE_CURRENT_SOURCE_DIR}/src/matrix.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/matrix.hpp)

target_link_directories(test_memory PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")