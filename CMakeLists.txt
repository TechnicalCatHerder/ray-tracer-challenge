cmake_minimum_required(VERSION 3.14...3.28)

project(ray-tracer-challenge LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# defines targets and sources
add_subdirectory(src)
# contains an "external" library we will link to
add_subdirectory(external)
# we're going to use gtest for testing
add_subdirectory(tests)

