#ifndef DYNAGRAPH_HPP
#define DYNAGRAPH_HPP

#include <iostream>
#include <vector>
#include <string>
#include <list>

class No {
public:
    std::string nome;
    std::list<std::pair<No*, int>> conexoes;

    No(std::string nome);
};

class Grafo {
public:
    Grafo();
    ~Grafo();

    void adicionaNo(const std::string& nome);
    void liga(const std::string& nome1, const std::string& nome2, int peso);
    void deletaNo(const std::string& nome);
    void imprimeGrafo();
    std::vector<std::vector<int>> toAdjacencyMatrix();

    No* encontraNo(const std::string& nome);
    const std::vector<No*>& getNos() const;

private:
    std::vector<No*> nos;
};

#endif // DYNAGRAPH_HPP
