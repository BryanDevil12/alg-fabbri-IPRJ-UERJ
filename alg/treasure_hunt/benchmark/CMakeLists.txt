add_executable(bm-treasure_hunt-cmd bm_treasure_hunt.cpp)
target_link_libraries(bm-treasure_hunt-cmd treasure_hunt benchmark::benchmark ${CURSES_LIBRARIES})
set_property(GLOBAL APPEND PROPERTY BENCHMARK_TARGETS bm-treasure_hunt-cmd)
