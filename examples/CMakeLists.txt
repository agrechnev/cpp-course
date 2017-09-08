# Minimal cmake version required
cmake_minimum_required(VERSION 3.1)

# Project title
project(examples)

# Language version required: C++ 14
set(CMAKE_CXX_STANDARD 14)

# Build all examples, each one is a separate sub-project in a subdirectory
add_subdirectory(e1_1)
add_subdirectory(e1_2)

add_subdirectory(e2_1)
add_subdirectory(e2_2)
add_subdirectory(e2_3)

add_subdirectory(e3_1)
add_subdirectory(e3_2)
add_subdirectory(e3_3)
add_subdirectory(e3_4)

add_subdirectory(e4_1)
