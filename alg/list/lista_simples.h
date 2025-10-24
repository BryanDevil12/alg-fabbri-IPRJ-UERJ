#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

struct Node {
    int data;
    Node* next;
};

Node* cria_lista();
void insere_inicio(Node** head, int data);
void deleta_inicio(Node** head);
Node* busca(Node* head, int data);
void deleta_lista(Node* head);

#endif // LISTA_SIMPLES_H
