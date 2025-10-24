#include <gtest/gtest.h>
#include "../lista_dupla.h"

TEST(ListaDuplaTest, InserirInicio) {
    DNode* head = cria_lista_dupla();
    insere_inicio_dupla(&head, 10);
    ASSERT_TRUE(head != NULL);
    ASSERT_EQ(head->data, 10);
    ASSERT_TRUE(head->prev == NULL);
    insere_inicio_dupla(&head, 20);
    ASSERT_EQ(head->data, 20);
    ASSERT_EQ(head->next->data, 10);
    ASSERT_EQ(head->next->prev, head);
    deleta_lista_dupla(head);
}

TEST(ListaDuplaTest, DeletarInicio) {
    DNode* head = cria_lista_dupla();
    insere_inicio_dupla(&head, 10);
    insere_inicio_dupla(&head, 20);
    deleta_inicio_dupla(&head);
    ASSERT_TRUE(head != NULL);
    ASSERT_EQ(head->data, 10);
    ASSERT_TRUE(head->prev == NULL);
    deleta_inicio_dupla(&head);
    ASSERT_TRUE(head == NULL);
    deleta_lista_dupla(head);
}

TEST(ListaDuplaTest, Busca) {
    DNode* head = cria_lista_dupla();
    insere_inicio_dupla(&head, 10);
    insere_inicio_dupla(&head, 20);
    insere_inicio_dupla(&head, 30);
    DNode* found = busca_dupla(head, 20);
    ASSERT_TRUE(found != NULL);
    ASSERT_EQ(found->data, 20);
    DNode* not_found = busca_dupla(head, 40);
    ASSERT_TRUE(not_found == NULL);
    deleta_lista_dupla(head);
}
