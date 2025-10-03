/* Author Ricardo Fabbri rfabbri@iprj.uerj.br 2025 */
#include <benchmark/benchmark.h>
#include <big_string.h>
#include <string>
#include <vector>

class BigStringFixture : public benchmark::Fixture {
public:
  void SetUp(const ::benchmark::State& state) {
    int len = state.range(0);
    str1.assign(len, 'a');
    str2.assign(len, 'b');
    out.resize(2 * len + 1);
  }

  std::string str1;
  std::string str2;
  std::vector<char> out;
};

BENCHMARK_DEFINE_F(BigStringFixture, BM_big_string_cat)(benchmark::State& state) {
  for (auto _ : state) {
    big_string_cat(str1.c_str(), str2.c_str(), out.data());
  }
  state.SetItemsProcessed(state.iterations() * state.range(0) * 2);
}

BENCHMARK_REGISTER_F(BigStringFixture, BM_big_string_cat)->Range(1, 1<<20);

BENCHMARK_MAIN();
