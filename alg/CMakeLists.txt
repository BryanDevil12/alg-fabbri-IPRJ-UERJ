cmake_minimum_required(VERSION 3.10)
project(alg)

find_package(Curses REQUIRED)

# Add third-party subdirectories
add_subdirectory(../third_party/googletest ${CMAKE_BINARY_DIR}/googletest)
add_subdirectory(../third_party/benchmark ${CMAKE_BINARY_DIR}/benchmark)

add_subdirectory(merge)
add_subdirectory(BigString)
add_subdirectory(treasure_hunt)
#add_subdirectory(list)

# Custom target to build all benchmarks
add_custom_target(eval
  DEPENDS
    bm-sorted_merge_3way-cmd
    bm-big_string-cmd
    bm-treasure_hunt-cmd
)
