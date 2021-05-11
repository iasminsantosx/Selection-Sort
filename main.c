#include <stdio.h>
#include "selection.h"
#include <stdbool.h>


int main() {
  int n = 0;//quantidade de elementos nas listas
  printf("Digite a quantidade de elementos presentes nas listas: ");
  scanf("%d", &n);
  ListaSeq *ls = criaListaseq(n); //criando lista sequencial
  ListaEnc le; 
  createList(&le); //criando lista encadeada


  gera_arquivo_desordenado(n);//gera o arquivo .txt com os numeros aleatorios
  gera_lista(ls,&le,n);//le o .txt e insere os numeros em ambas as listas 


  
  sort_LS(ls);//ordena a lista sequencial
  sort_LE(&le);// ordena a lista encadeada
  //printf("%d\n", ls->ue);

  guardar_LE(le);//guarda o conteudo presente na lista encadeada em um arquivo.txt
  //guardar_LS(ls);//guarda o conteudo presente na lista sequencial em um arquivo.txt
  

  return true;
}
