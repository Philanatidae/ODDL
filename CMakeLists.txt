cmake_minimum_required(VERSION 3.14)

project(DDL)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Options
option(DDL_BUILD_TESTING "Enables tests for DDL." OFF)
option(DDL_BUILD_SHARED_LIBS "Build as a shared library." ON)

# Dependencies
add_subdirectory(deps)

# Define library
add_library(DDL SHARED)
target_include_directories(DDL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(src)

# Tests
if(DDL_BUILD_TESTING AND BUILD_TESTING)
    add_subdirectory(tests)
endif()
