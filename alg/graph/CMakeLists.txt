add_library(graph
  tree.cpp
  dynagraph.cpp
)

add_executable(dynagraph dynagraph.c)

target_include_directories(graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (alg_BUILD_TESTS)
  add_subdirectory(tests)
endif(alg_BUILD_TESTS)
