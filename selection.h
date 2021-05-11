#include <stdbool.h>

typedef struct {//estrutura da lista sequencial
    int *vet;
    int ue;
    int max;
}ListaSeq;

ListaSeq * criaListaseq(int n);//funÃ§Ã£o que cria uma lista sequencial

bool insere(ListaSeq *l, int v);//funÃ§Ã£o que insere no final da lista sequencial


typedef struct node{//no de uma lista encadeada
  int data;
  struct node *next;
}node;

typedef struct{//estrutura da lista encadeada
  node *begin;
  int size;
}ListaEnc;

void createList(ListaEnc *l);//funÃ§Ã£o que cria a lista encadeada

void add(ListaEnc *l, int v);//funÃ§Ã£o que insere no final da lista encadeada

void sort_LS(ListaSeq *l);//ordenar em lista sequencial

void sort_LE(ListaEnc* l);//ordenar em lista encadeada

void imprimirLE(ListaEnc lista);

void imprimirLS(ListaSeq *ls);

bool gera_arquivo_desordenado(int n);

bool gera_lista(ListaSeq *ls, ListaEnc *le, int n);//gera as duas listas com a mesma disposiÃ§Ã£o de elementos

bool guardar_LE(ListaEnc l);

bool guardar_LS(ListaSeq *l);