add_executable(bm-big_string-cmd bm_big_string.cpp)
target_link_libraries(bm-big_string-cmd BigString benchmark::benchmark)
set_property(GLOBAL APPEND PROPERTY BENCHMARK_TARGETS bm-big_string-cmd)
