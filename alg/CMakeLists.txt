cmake_minimum_required(VERSION 3.10)
project(alg)

find_package(Curses REQUIRED)

add_subdirectory(merge)
add_subdirectory(BigString)
add_subdirectory(treasure_hunt)
#add_subdirectory(list)