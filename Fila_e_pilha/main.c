#include "lib.h"
#include <time.h>

int main(int argc, char const *argv[]) {
  int i, chave;
  InicioFim *xF = (InicioFim*)malloc(sizeof(TipoCelula)), *yF = (InicioFim*)malloc(sizeof(TipoCelula)), *zF = (InicioFim*)malloc(sizeof(TipoCelula));
  if (xF == NULL || yF == NULL || zF == NULL) return 0;
  InicioFim *xP = (InicioFim*)malloc(sizeof(TipoCelula)), *yP = (InicioFim*)malloc(sizeof(TipoCelula)), *zP = (InicioFim*)malloc(sizeof(TipoCelula));
  if (xP == NULL || yP == NULL || zP == NULL) return 0;
  Cabeca(xF);
  Cabeca(yF);
  printf("Colocando 5 nós gerados aleatóriamentes na fila 1:\n");
  for(i = 0; i < 3; i++) {
    chave = rand () % 10;
    printf("Número gerado fila 1: %d\n", chave);
    InsereFila(xF, chave);
  }
  printf("\nColocando 5 nós gerados aleatóriamentes na fila 2:\n");
    for(i = 0; i < 3; i++) {
      chave = rand () % 10;
      printf("Número gerado fila 2: %d\n", chave);
      InsereFila(yF, chave);
    }
  printf("\nImprimindo fila 1:\n");
  ImprimeFila(xF);
  printf("\nRemovendo um nó da fila 1:\n");
  RemoveFila(xF);
  ImprimeFila(xF);
  printf("\nImprimindo fila 2:\n");
  ImprimeFila(yF);
  printf("\nRemovendo um nó da fila 2:\n");
  RemoveFila(yF);
  ImprimeFila(yF);
  printf("\nConcatenando fila 1 e fila 2:\n");
  zF = ConcatenaFila(xF, yF);
  ImprimeFila(zF);
  /*printf("\nInvertendo a fila 3:\n");
  FilaInversa(z);
  ImprimeFila(z);*/
  printf("\nColocando 5 nós gerados aleatóriamentes na pilha 1:\n");
  for(i = 0; i < 3; i++) {
    chave = rand () % 10;
    printf("Número gerado pilha 1: %d\n", chave);
    InserePilha(xP, chave);
  }
  printf("\nColocando 5 nós gerados aleatóriamentes na pilha 2:\n");
  for(i = 0; i < 3; i++) {
    chave = rand () % 10;
    printf("Número gerado pilha 2: %d\n", chave);
    InserePilha(yP, chave);
  }
  printf("\nImprimindo pilha 1:\n");
  ImprimePilha(xP);
  printf("\nRemovendo um nó da pilha 1:\n");
  RetiraPilha(xP);
  printf("\nImprimindo pilha 1:\n");
  ImprimePilha(xP);
  printf("\nImprimindo pilha 2:\n");
  ImprimePilha(yP);
  printf("\nRemovendo um nó da pilha 2:\n");
  RetiraPilha(yP);
  printf("\nImprimindo pilha 2:\n");
  ImprimePilha(yP);
  printf("\nConcatenando pilha 1 e pilha 2:\n");
  zP = ConcatenaPilha(xP, yP);
  ImprimePilha(zP);
  printf("\nConcatenando fila 3 com pilha 3:\n");
  zF = ConcatenaFilaPilha(zF, zP);
  ImprimeFila(zF);
  printf("\nConcatenando pilha 4 com fila 4:\n");
  zP = ConcatenaFilaPilha(zP2, zF2);
  ImprimeFila(zP);
  printf("\nRemovendo todos os nós da pilha 3:\n");
  FPVazia(zP);
  ImprimePilha(zP);
  printf("\nRemovendo todos os nós da fila 3:\n");
  FFVazia(zF);
  ImprimeFila(zF);
  return 0;
}
