/* R. Fabbri, 2024 */
#include "treasure_hunt.h"
#include <stdlib.h>
#include <string.h>

// Helper function to create a new node
No* criar_no(const char* nome) {
    No* no = (No*) malloc(sizeof(No));
    no->nome = strdup(nome);
    no->tem_tesouro = false;
    no->esquerda = NULL;
    no->direita = NULL;
    no->cima = NULL;
    no->baixo = NULL;
    return no;
}

#include "treasure_hunt.h"
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <random>
#include <queue>
#include <set>
#include <iostream>
#include <ncurses.h>

No* criar_mundo() {
    // Create the nodes
    No* inicio1 = criar_no("Inicio 1");
    No* inicio2 = criar_no("Inicio 2");
    No* meio1 = criar_no("Meio 1");
    No* meio2 = criar_no("Meio 2");
    No* fim1 = criar_no("Fim 1");
    No* boss = criar_no("Boss");

    // Connect the nodes
    inicio1->direita = inicio2;
    inicio2->esquerda = inicio1;

    inicio1->baixo = meio1;
    meio1->cima = inicio1;

    inicio2->baixo = meio2;
    meio2->cima = inicio2;

    meio1->direita = meio2;
    meio2->esquerda = meio1;

    meio1->baixo = fim1;
    fim1->cima = meio1;

    meio2->baixo = boss;
    boss->cima = meio2;

    // Place treasure in a random node
    std::vector<No*> nodes = {inicio1, inicio2, meio1, meio2, fim1, boss};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, nodes.size() - 1);
    int random_index = distrib(gen);
    nodes[random_index]->tem_tesouro = true;

    return inicio1;
}

void destruir_mundo(No* inicio) {
    No* inicio2 = inicio->direita;
    No* meio1 = inicio->baixo;
    No* meio2 = inicio2->baixo;
    No* fim1 = meio1->baixo;
    No* boss = meio2->baixo;

    free(inicio->nome);
    free(inicio);
    free(inicio2->nome);
    free(inicio2);
    free(meio1->nome);
    free(meio1);
    free(meio2->nome);
    free(meio2);
    free(fim1->nome);
    free(fim1);
    free(boss->nome);
    free(boss);
}

#include <queue>
#include <set>

No* No::busca(char* nome_desejado, No* inicio) {
    std::queue<No*> q;
    std::set<No*> visitados;

    q.push(inicio);
    visitados.insert(inicio);

    while (!q.empty()) {
        No* atual = q.front();
        q.pop();

        if (strcmp(atual->nome, nome_desejado) == 0) {
            return atual;
        }

        if (atual->esquerda && visitados.find(atual->esquerda) == visitados.end()) {
            q.push(atual->esquerda);
            visitados.insert(atual->esquerda);
        }
        if (atual->direita && visitados.find(atual->direita) == visitados.end()) {
            q.push(atual->direita);
            visitados.insert(atual->direita);
        }
        if (atual->cima && visitados.find(atual->cima) == visitados.end()) {
            q.push(atual->cima);
            visitados.insert(atual->cima);
        }
        if (atual->baixo && visitados.find(atual->baixo) == visitados.end()) {
            q.push(atual->baixo);
            visitados.insert(atual->baixo);
        }
    }

    return NULL; // Not found
}

#include <ncurses.h>
#include <map>
#include <algorithm>

void desenhar_mapa(No* jogador, No* mundo) {
    No* inicio1 = mundo;
    No* inicio2 = inicio1->direita;
    No* meio1 = inicio1->baixo;
    No* meio2 = inicio2->baixo;
    No* fim1 = meio1->baixo;
    No* boss = meio2->baixo;

    mvprintw(3, 5, "--- MAPA ---");

    // Linha 1
    mvprintw(4, 5, "%s -- %s", (jogador == inicio1 ? "[*]" : "[ ]"), (jogador == inicio2 ? "[*]" : "[ ]"));
    mvprintw(5, 5, " |         |  ");

    // Linha 2
    mvprintw(6, 5, "%s -- %s", (jogador == meio1 ? "[*]" : "[ ]"), (jogador == meio2 ? "[*]" : "[ ]"));
    mvprintw(7, 5, " |         |  ");

    // Linha 3
    mvprintw(8, 5, "%s    %s", (jogador == fim1 ? "[*]" : "[ ]"), (jogador == boss ? "[B]" : "[ ]"));

    mvprintw(9, 5, "------------");
}

No* encontrar_no_do_tesouro(No* mundo) {
    std::queue<No*> q;
    std::set<No*> visitados;

    q.push(mundo);
    visitados.insert(mundo);

    while (!q.empty()) {
        No* atual = q.front();
        q.pop();

        if (atual->tem_tesouro) {
            return atual;
        }

        if (atual->esquerda && visitados.find(atual->esquerda) == visitados.end()) {
            q.push(atual->esquerda);
            visitados.insert(atual->esquerda);
        }
        if (atual->direita && visitados.find(atual->direita) == visitados.end()) {
            q.push(atual->direita);
            visitados.insert(atual->direita);
        }
        if (atual->cima && visitados.find(atual->cima) == visitados.end()) {
            q.push(atual->cima);
            visitados.insert(atual->cima);
        }
        if (atual->baixo && visitados.find(atual->baixo) == visitados.end()) {
            q.push(atual->baixo);
            visitados.insert(atual->baixo);
        }
    }

    return NULL; // Should not happen if treasure is always placed
}

#include <map>
#include <algorithm>

std::vector<No*> encontrar_menor_caminho(No* inicio, No* fim) {
    std::queue<No*> q;
    std::map<No*, No*> pais; // child -> parent map to reconstruct path
    std::vector<No*> caminho;

    q.push(inicio);
    pais[inicio] = nullptr;

    No* atual = nullptr;
    while (!q.empty()) {
        atual = q.front();
        q.pop();

        if (atual == fim) {
            break; // Found the destination
        }

        // Add neighbors to the queue
        if (atual->esquerda && pais.find(atual->esquerda) == pais.end()) {
            q.push(atual->esquerda);
            pais[atual->esquerda] = atual;
        }
        if (atual->direita && pais.find(atual->direita) == pais.end()) {
            q.push(atual->direita);
            pais[atual->direita] = atual;
        }
        if (atual->cima && pais.find(atual->cima) == pais.end()) {
            q.push(atual->cima);
            pais[atual->cima] = atual;
        }
        if (atual->baixo && pais.find(atual->baixo) == pais.end()) {
            q.push(atual->baixo);
            pais[atual->baixo] = atual;
        }
    }

    // Reconstruct path from end to start
    if (atual == fim) {
        for (No* no = fim; no != nullptr; no = pais[no]) {
            caminho.push_back(no);
        }
        std::reverse(caminho.begin(), caminho.end());
    }

    return caminho;
}

const char* obter_direcao(No* de, No* para) {
    if (de == nullptr || para == nullptr) return "";
    if (de->direita == para) return "Direita";
    if (de->esquerda == para) return "Esquerda";
    if (de->baixo == para) return "Baixo";
    if (de->cima == para) return "Cima";
    return "??";
}
