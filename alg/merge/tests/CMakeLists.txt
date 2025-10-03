include(GoogleTest)

add_executable(run-merge-tests test-sorted_merge_3way.cpp)
target_link_libraries(run-merge-tests PRIVATE merge GTest::gtest_main GTest::gtest)

gtest_discover_tests(run-merge-tests)