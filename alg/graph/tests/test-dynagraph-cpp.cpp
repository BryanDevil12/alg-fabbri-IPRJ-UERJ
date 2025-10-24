#include <gtest/gtest.h>
#include "../dynagraph.hpp"
#include <sstream>
#include <map>

TEST(DynagraphCppTest, DeleteNode) {
    Grafo g;
    g.adicionaNo("A");
    g.adicionaNo("B");
    g.adicionaNo("C");
    g.liga("A", "B", 10);
    g.liga("B", "C", 20);
    g.liga("A", "C", 30);

    g.deletaNo("B");

    std::stringstream ss;
    std::streambuf* old_cout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    g.imprimeGrafo();

    std::cout.rdbuf(old_cout);

    std::string expected = "graph {\n  \"A\" -- \"C\" [label=30];\n}\n";
    // The order of edges is not guaranteed, so we need to check for both possibilities
    std::string alternative_expected = "graph {\n  \"C\" -- \"A\" [label=30];\n}\n";
    ASSERT_TRUE(ss.str() == expected || ss.str() == alternative_expected);
}

TEST(DynagraphCppTest, ToAdjacencyMatrix) {
    Grafo g;
    g.adicionaNo("A");
    g.adicionaNo("B");
    g.adicionaNo("C");
    g.liga("A", "B", 10);
    g.liga("B", "C", 20);

    std::vector<std::vector<int>> matrix = g.toAdjacencyMatrix();
    const std::vector<No*>& nos = g.getNos();
    std::map<No*, int> node_to_index;
    for (size_t i = 0; i < nos.size(); ++i) {
        node_to_index[nos[i]] = i;
    }

    int a_idx = node_to_index[g.encontraNo("A")];
    int b_idx = node_to_index[g.encontraNo("B")];
    int c_idx = node_to_index[g.encontraNo("C")];

    ASSERT_EQ(matrix[a_idx][b_idx], 10);
    ASSERT_EQ(matrix[b_idx][a_idx], 10);
    ASSERT_EQ(matrix[b_idx][c_idx], 20);
    ASSERT_EQ(matrix[c_idx][b_idx], 20);
    ASSERT_EQ(matrix[a_idx][c_idx], 0);
    ASSERT_EQ(matrix[c_idx][a_idx], 0);
}
