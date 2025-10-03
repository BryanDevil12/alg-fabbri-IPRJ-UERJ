/* R. Fabbri, 2024 */
#ifndef TREASURE_HUNT_H
#define TREASURE_HUNT_H

#include <vector>

struct No {
    char *nome;
    bool tem_tesouro; // Flag to indicate if the node has the treasure
    No *esquerda;
    No *direita;
    No *cima;
    No *baixo;

    // This is a method, so it's C++
    No *busca(char *nome_desejado, No *inicio);
};

// Function to create the game world
No* criar_mundo();

// Function to free the memory of the world
void destruir_mundo(No* inicio);

// Function to draw the map
void desenhar_mapa(No* jogador, No* mundo);

// Function to find the treasure node
No* encontrar_no_do_tesouro(No* mundo);

// Function to find the shortest path between two nodes
std::vector<No*> encontrar_menor_caminho(No* inicio, No* fim);

// Function to get the direction between two nodes
const char* obter_direcao(No* de, No* para);

#endif
