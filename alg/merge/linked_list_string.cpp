/* R. Fabbri, 2024 */
#include "linked_list_string.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

#define MAX_NUMERO_DE_CARACTERES 64
struct No {
  //char *name;
  char name[MAX_NUMERO_DE_CARACTERES];
  /*
   opcional: convencao de '\0' no final
  */
  No *next;
};

int sum(No *p){
  int somaDosTamanhos = 0;
  No *noAtual = p;

  while (noAtual != NULL){
   somaDosTamanhos += strlen(noAtual->name);
   noAtual = noAtual->next;
  }
  
  return somaDosTamanhos;

}

struct Noo2 {
  char *name;
  Noo2 *next;
};
int sum(Noo2 *p){
  if (p ==NULL){
    return 0;
  }
  return strlen(p->name) + sum(p->next);
}

struct No3 {
  char name[MAX_NUMERO_DE_CARACTERES];
  No3 *esq;
  No3 *dir;
};


typedef No *Lista;

// ---------------------------------------------------------------
// mesma lista, mas com ponteiro pra char
struct No2 {
  char *name;
  //char name[MAX_NUMERO_DE_CARACTERES];
  /*
   opcional: convencao de '\0' no final
  */
  No *next;
};

typedef No2 *Lista2;

void 
playground_lista()
{
  std::cout << "teste" << std::endl;
  Lista l;

  // cria um novo no
  
  l = (No *) malloc(sizeof(No));

  // no caso da implementacao estatica
  l->name[0] = '\0';
  
  // ou no caso do char * :
  //l->name = "";
  //l->name = 0;

  std::cout << std::string(l->name) << std::endl;

  std::cout << "teste" << std::endl;
  // ou
  printf("%s", l->name); // assume que nome contem '\0'
  
  strncpy(l->name, "joao", MAX_NUMERO_DE_CARACTERES);
  
  printf("%s", l->name); // assume que nome contem '\0'
}

void 
playground_lista2()
{
  // Exercicio1: prencher com lista 2
  std::cout << "teste" << std::endl;
  Lista l;

  // cria um novo no
  
  l = (No *) malloc(sizeof(No));

  // no caso da implementacao estatica
  l->name[0] = '\0';
  
  // ou no caso do char * :
  //l->name = "";
  //l->name = 0;

  std::cout << std::string(l->name) << std::endl;

  std::cout << "teste" << std::endl;
  // ou
  printf("%s", l->name); // assume que nome contem '\0'
  
  strncpy(l->name, "joao", MAX_NUMERO_DE_CARACTERES);
  
  printf("%s", l->name); // assume que nome contem '\0'
}


void
playground_lista3()
{
  std::cout << "\n--- teste arvore (playground_lista3() ---"<< std::endl;

  No3 *raiz = new No3();
  No3 *noEsquerda = new No3();
  No3 *noDireita = new No3();
  No3 *noFolha = new No3();

  strncpy(raiz->name, "Joao", MAX_NUMERO_DE_CARACTERES);
  strncpy(noEsquerda->name, "MAria", MAX_NUMERO_DE_CARACTERES);
  strncpy(noDireita->name, "Pedro", MAX_NUMERO_DE_CARACTERES);
  strncpy(noFolha->name, "Ana", MAX_NUMERO_DE_CARACTERES);

  raiz->esq = noEsquerda;
  raiz->dir = noDireita;

  noEsquerda->esq=noFolha;
  noEsquerda->dir = NULL;

  noDireita->esq = NULL;
  noDireita->dir = NULL;
  noFolha->esq = NULL;
  noFolha->dir = NULL;


  std::cout << "Raiz da arvore: " << raiz->name << std::endl;
  std::cout << "Filho da esquerda de: " << raiz->name << ": "<< raiz->esq->name <<  std::endl;
  std::cout << "Filho da direita de: " << raiz->name << ": "<< raiz->dir->name <<  std::endl;
  std::cout << "Filho da esquerda de: " << raiz->esq->name << ": "<< raiz->esq->esq->name <<  std::endl;

  delete raiz;
  delete noEsquerda;
  delete noDireita;
  delete noFolha;
}


