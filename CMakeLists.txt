cmake_minimum_required(VERSION 3.0)

project(vision)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3") # change from default O2

add_subdirectory(source/week1)

option(BUILD_TESTING OFF)
if (BUILD_TESTING)
	add_subdirectory(source/test)
endif ()

option(BUILD_BENCHMARK OFF)
if (BUILD_BENCHMARK)
	add_subdirectory(source/benchmark)
endif ()
