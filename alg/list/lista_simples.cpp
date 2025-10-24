#include "lista_simples.h"
#include <cstddef>

Node* cria_lista() {
    return NULL;
}

void insere_inicio(Node** head, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void deleta_inicio(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;
}

Node* busca(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleta_lista(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
}
