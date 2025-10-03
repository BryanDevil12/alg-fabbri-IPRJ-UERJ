cmake_minimum_required(VERSION 3.10)
project(alg)

find_package(Curses REQUIRED)

# Add third-party dependencies if they haven't been added by a parent project
if(NOT TARGET gtest)
  add_subdirectory(../third_party/googletest ${CMAKE_BINARY_DIR}/googletest)
endif()

if(NOT TARGET benchmark::benchmark)
  add_subdirectory(../third_party/benchmark ${CMAKE_BINARY_DIR}/benchmark)
endif()

add_subdirectory(merge)
add_subdirectory(BigString)
add_subdirectory(treasure_hunt)
#add_subdirectory(list)
