include(GoogleTest)

add_executable(run-list-tests test_lista_simples.cpp test_lista_dupla.cpp test_buffer_circular.cpp)
target_link_libraries(run-list-tests PRIVATE list GTest::gtest_main GTest::gtest)

gtest_discover_tests(run-list-tests)
