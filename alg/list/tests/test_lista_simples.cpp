#include <gtest/gtest.h>
#include "../lista_simples.h"

TEST(ListaSimplesTest, InserirInicio) {
    Node* head = cria_lista();
    insere_inicio(&head, 10);
    ASSERT_TRUE(head != NULL);
    ASSERT_EQ(head->data, 10);
    insere_inicio(&head, 20);
    ASSERT_EQ(head->data, 20);
    ASSERT_EQ(head->next->data, 10);
    deleta_lista(head);
}

TEST(ListaSimplesTest, DeletarInicio) {
    Node* head = cria_lista();
    insere_inicio(&head, 10);
    insere_inicio(&head, 20);
    deleta_inicio(&head);
    ASSERT_TRUE(head != NULL);
    ASSERT_EQ(head->data, 10);
    deleta_inicio(&head);
    ASSERT_TRUE(head == NULL);
    deleta_lista(head);
}

TEST(ListaSimplesTest, Busca) {
    Node* head = cria_lista();
    insere_inicio(&head, 10);
    insere_inicio(&head, 20);
    insere_inicio(&head, 30);
    Node* found = busca(head, 20);
    ASSERT_TRUE(found != NULL);
    ASSERT_EQ(found->data, 20);
    Node* not_found = busca(head, 40);
    ASSERT_TRUE(not_found == NULL);
    deleta_lista(head);
}
