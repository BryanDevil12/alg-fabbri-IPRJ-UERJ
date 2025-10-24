#include "lista_dupla.h"
#include <cstddef>

DNode* cria_lista_dupla() {
    return NULL;
}

void insere_inicio_dupla(DNode** head, int data) {
    DNode* new_node = new DNode();
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void deleta_inicio_dupla(DNode** head) {
    if (*head == NULL) return;
    DNode* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    delete temp;
}

DNode* busca_dupla(DNode* head, int data) {
    DNode* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleta_lista_dupla(DNode* head) {
    DNode* current = head;
    DNode* next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
}
