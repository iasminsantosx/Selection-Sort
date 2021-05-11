#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "selection.h"



ListaSeq * criaListaseq(int n) {
    ListaSeq *nova = (ListaSeq*)malloc(sizeof(ListaSeq));//aloca dinamicamente a estrtura da lista
    nova->vet = (int*)malloc(n*sizeof(int));//aloca dinamicamente o vetor
    nova->max = n;//numero recebido como parametro que Ã© o maximo de elementos
    nova->ue = 0;//quantidade de elementos
    return nova;
}

bool insere(ListaSeq * l, int v) {
    if (l->ue == l->max) return false;
    l->vet[l->ue] = v;
    l->ue++;
    return true;
}

//Lista encadeada

void createList(ListaEnc *l){
  l->begin =NULL;//o apontador do inicio aponta para null
  l->size = 0;//tamanho = 0
}

void add(ListaEnc *l, int v){
  node* novo = (node*) malloc (sizeof(node));
  novo->next=NULL;
  novo->data = v;
  node *aux = l->begin;
  if (l->begin == NULL) l->begin = novo;

  else{
    while (aux->next != NULL){
      aux = aux->next;
    }
    aux->next = novo;
  }
  l->size++;
}


void sort_LS(ListaSeq* l) { 
  int tam = l->ue;
  int *vet = l->vet;

  int i, j, min, aux;
  clock_t tempo_Ord;

  tempo_Ord = clock();
  for (i = 0; i < tam-1; i++) 
  {
     min = i;
     for (j =i+1; j < tam; j++) {//j comeÃ§a como sendo o elemento imediatamente depois do i na lista
       if(vet[j] < vet[min]) 
         min = j;
     }
     if (vet[i] != vet[min]) {
       aux = vet[i];
       vet[i] = vet[min];
       vet[min] = aux;
     }
  }
  tempo_Ord = clock() - tempo_Ord;
  printf("Tempo de execuÃ§Ã£o em lista sequencial: %fs\n", ((float)tempo_Ord)/CLOCKS_PER_SEC);
}


void sort_LE(ListaEnc* l){
  node *aux1 = l->begin;// o valor a ser comparado
  node *aux2 = l->begin->next;// o valor imediatamente posterior ao aux1
  node* min; //guardar o endereÃ§o do lugar que conter o menor valor
  int aux;
  clock_t tempo_Ord;

  tempo_Ord = clock();
  for (;aux1->next != NULL; aux1=aux1->next, aux2=aux1->next){//caso o elemento posterior ao aux1 nÃ£o existir o for para e a cada iteraÃ§Ã£o o aux1 recebe o proximo e o aux2 recebe o elemento posterior ao aux1

    min = aux1;
    for (;aux2 != NULL; aux2=aux2->next){
      if (aux2->data < min->data)
        min = aux2;
    }
    if (aux1->data != min->data){
      aux = aux1->data;
      aux1->data = min->data;
      min->data = aux;
    }
  }
  tempo_Ord = clock() - tempo_Ord;
  printf("Tempo de execuÃ§Ã£o em lista encadeada: %fs\n", ((float)tempo_Ord)/CLOCKS_PER_SEC);
}

void imprimirLE ( ListaEnc lista ) {
	node* aux = lista.begin;
  printf( "[");

  while (aux!=NULL){
    if (aux->next !=NULL) printf("%d,", aux->data);
    else printf("%d]\n", aux->data);
    aux = aux->next;
  }
}

void imprimirLS(ListaSeq *l){
  printf("[");
  for (int i=0; i< l->ue; i++){
    if (i!=l->ue-1) printf("%d,",l->vet[i]);
    else printf("%d]\n",l->vet[i]);
  }
}

bool gera_arquivo_desordenado(int n){// gera o
  int num;
  FILE *file;
  file = fopen("desordenado.txt","w");

  for (int i=0; i<n;i++){
    num = rand() %9999;
    fprintf(file,"%d\n", num);
  }
  fclose(file);
  return true;
}

bool gera_lista(ListaSeq *ls, ListaEnc *le, int n){
  int num;
  char x[10];
  FILE *file;
  file = fopen("desordenado.txt","r");
  if (file == NULL) return false;

  while (fgets(x,10,file) != NULL){
    num = atoi(x);
    add(le, num);
    insere(ls, num);
  }
  return true;
}




bool guardar_LE(ListaEnc l){
  FILE *file;
  file = fopen("ordenado.txt", "w");
	node* aux = l.begin;

  while (aux!=NULL){
    fprintf(file,"%d\n", aux->data);
    aux = aux->next;
  }
  fclose(file);
  return true;
}

bool guardar_LS(ListaSeq *l){
  FILE *file;
  file = fopen("ordenado.txt", "w");

  for (int i=0; i< l->ue; i++){
    fprintf(file ,"%d\n",l->vet[i]);
  }
  fclose(file);
  return true;
}