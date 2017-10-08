# Minimal cmake version required
cmake_minimum_required(VERSION 3.1)

# Project title
project(examples)

# Build type
if(NOT CMAKE_BUILD_TYPE )
   set( CMAKE_BUILD_TYPE "Debug" )
endif()

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
add_subdirectory(e4_2)
add_subdirectory(e4_3)

add_subdirectory(e5_1)
add_subdirectory(e5_2)
add_subdirectory(e5_3)
add_subdirectory(e5_4)

add_subdirectory(e6_1)
add_subdirectory(e6_2)
add_subdirectory(e6_3)

add_subdirectory(e7_1)
add_subdirectory(e7_2)
add_subdirectory(e7_3)

add_subdirectory(e8_1)
add_subdirectory(e8_2)
add_subdirectory(e8_3)

add_subdirectory(e9_1)
add_subdirectory(e9_2)

add_subdirectory(e10_1)
add_subdirectory(e10_2)
