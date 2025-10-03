/* Author Ricardo Fabbri rfabbri@iprj.uerj.br 2025 */
#include <benchmark/benchmark.h>
#include "treasure_hunt.h"

static void BM_WorldCreation(benchmark::State& state) {
  for (auto _ : state) {
    No* mundo = criar_mundo();
    destruir_mundo(mundo);
  }
}
BENCHMARK(BM_WorldCreation);

BENCHMARK_MAIN();
