add_library(treasure_hunt 
  treasure_hunt.cpp
)
# export public header path for other components
target_include_directories(treasure_hunt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(cmd)

if (alg_BUILD_TESTS)
add_subdirectory(tests)
endif(alg_BUILD_TESTS)

if (alg_BUILD_BENCHMARKS)
add_subdirectory(benchmark)
endif(alg_BUILD_BENCHMARKS)
