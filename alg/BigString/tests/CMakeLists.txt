include(GoogleTest)

add_executable(run-bigstring-tests test-big_string.cpp)
target_link_libraries(run-bigstring-tests PRIVATE BigString GTest::gtest_main GTest::gtest)

gtest_discover_tests(run-bigstring-tests)