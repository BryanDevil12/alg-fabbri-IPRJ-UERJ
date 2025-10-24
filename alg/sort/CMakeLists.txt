add_library(sort
  sort.cpp
)

target_include_directories(sort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (alg_BUILD_TESTS)
  add_subdirectory(tests)
endif(alg_BUILD_TESTS)
