cmake_minimum_required(VERSION 3.14)

project(ODDL)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Options
option(ODDL_BUILD_TESTING "Enables tests for ODDL." OFF)
option(ODDL_BUILD_SHARED_LIBS "Build as a shared library." ON)

# Dependencies
add_subdirectory(deps)

# Define library
add_library(ODDL SHARED)
target_include_directories(ODDL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(src)

# Tests
if(ODDL_BUILD_TESTING AND BUILD_TESTING)
    add_subdirectory(tests)
endif()
