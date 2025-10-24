#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

DNode* cria_lista_dupla();
void insere_inicio_dupla(DNode** head, int data);
void deleta_inicio_dupla(DNode** head);
DNode* busca_dupla(DNode* head, int data);
void deleta_lista_dupla(DNode* head);

#endif // LISTA_DUPLA_H
