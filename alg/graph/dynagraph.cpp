#include "dynagraph.hpp"
#include <algorithm>
#include <map>

No::No(std::string nome) : nome(nome) {}

Grafo::Grafo() {}

Grafo::~Grafo() {
    for (No* no : nos) {
        delete no;
    }
}

void Grafo::adicionaNo(const std::string& nome) {
    nos.push_back(new No(nome));
}

No* Grafo::encontraNo(const std::string& nome) {
    for (No* no : nos) {
        if (no->nome == nome) {
            return no;
        }
    }
    return nullptr;
}

const std::vector<No*>& Grafo::getNos() const {
    return nos;
}

void Grafo::liga(const std::string& nome1, const std::string& nome2, int peso) {
    No* no1 = encontraNo(nome1);
    No* no2 = encontraNo(nome2);
    if (no1 && no2) {
        no1->conexoes.push_back({no2, peso});
        no2->conexoes.push_back({no1, peso});
    }
}

void Grafo::deletaNo(const std::string& nome) {
    No* no_para_deletar = encontraNo(nome);
    if (!no_para_deletar) return;

    // Remove conexoes para este no
    for (No* no : nos) {
        no->conexoes.remove_if([&](const std::pair<No*, int>& p) {
            return p.first == no_para_deletar;
        });
    }

    // Remove o no do vetor
    nos.erase(std::remove_if(nos.begin(), nos.end(), [&](No* no) {
        return no == no_para_deletar;
    }), nos.end());

    delete no_para_deletar;
}

void Grafo::imprimeGrafo() {
    std::cout << "graph {\n";
    for (No* no : nos) {
        for (const auto& conexao : no->conexoes) {
            if (no < conexao.first) {
                std::cout << "  \"" << no->nome << "\" -- \"" << conexao.first->nome << "\" [label=" << conexao.second << "];\n";
            }
        }
    }
    std::cout << "}\n";
}

std::vector<std::vector<int>> Grafo::toAdjacencyMatrix() {
    int n = nos.size();
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    std::map<No*, int> node_to_index;
    for (int i = 0; i < n; ++i) {
        node_to_index[nos[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        for (const auto& conexao : nos[i]->conexoes) {
            int j = node_to_index[conexao.first];
            matrix[i][j] = conexao.second;
        }
    }

    return matrix;
}
