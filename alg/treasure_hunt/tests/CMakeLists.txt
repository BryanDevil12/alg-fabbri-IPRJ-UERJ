include(GoogleTest)

add_executable(run-treasure_hunt-tests test-treasure_hunt.cpp)
target_link_libraries(run-treasure_hunt-tests PRIVATE treasure_hunt GTest::gtest_main GTest::gtest ${CURSES_LIBRARIES})

gtest_discover_tests(run-treasure_hunt-tests)
