add_test([=[BigStringTest.Concatenation]=]  /home/aluno/.a/alg-fabbri-IPRJ-UERJ/alg/BigString/tests/run-bigstring-tests [==[--gtest_filter=BigStringTest.Concatenation]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[BigStringTest.Concatenation]=]  PROPERTIES WORKING_DIRECTORY /home/aluno/.a/alg-fabbri-IPRJ-UERJ/alg/BigString/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  run-bigstring-tests_TESTS BigStringTest.Concatenation)
