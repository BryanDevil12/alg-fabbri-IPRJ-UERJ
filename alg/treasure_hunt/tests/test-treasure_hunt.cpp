/* R. Fabbri, 2024 */
#include <gtest/gtest.h>
#include "treasure_hunt.h"

TEST(TreasureHuntTest, WorldCreation) {
    No* mundo = criar_mundo();
    ASSERT_TRUE(mundo != NULL);
    ASSERT_STREQ(mundo->nome, "Inicio 1");
    destruir_mundo(mundo);
}

TEST(TreasureHuntTest, ShortestPath) {
    // Since the treasure is random, we can't test the exact path.
    // But we can create a non-random world here to test the algorithm.
    No* inicio1 = criar_no("Inicio 1");
    No* inicio2 = criar_no("Inicio 2");
    No* meio1 = criar_no("Meio 1");
    No* meio2 = criar_no("Meio 2");
    No* fim1 = criar_no("Fim 1");
    No* boss = criar_no("Boss");

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

    // Test path from inicio1 to boss
    std::vector<No*> caminho = encontrar_menor_caminho(inicio1, boss);

    // Expected path: inicio1 -> inicio2 -> meio2 -> boss
    ASSERT_EQ(caminho.size(), 4);
    ASSERT_EQ(caminho[0], inicio1);
    ASSERT_EQ(caminho[1], inicio2);
    ASSERT_EQ(caminho[2], meio2);
    ASSERT_EQ(caminho[3], boss);

    // Free memory
    free(inicio1->nome); free(inicio1);
    free(inicio2->nome); free(inicio2);
    free(meio1->nome); free(meio1);
    free(meio2->nome); free(meio2);
    free(fim1->nome); free(fim1);
    free(boss->nome); free(boss);
}