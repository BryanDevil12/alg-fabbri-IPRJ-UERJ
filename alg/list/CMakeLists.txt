add_library(list
  lista_simples.cpp
  lista_dupla.cpp
  buffer_circular.cpp
)

target_include_directories(list PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (alg_BUILD_TESTS)
  add_subdirectory(tests)
endif(alg_BUILD_TESTS)
