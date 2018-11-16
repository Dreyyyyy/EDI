#include "lib.h"
#include <time.h>

int main(int argc, char const *argv[]) {
  int op, i, chave;
  InicioFim *x = (InicioFim*)malloc(sizeof(TipoCelula)), *y = (InicioFim*)malloc(sizeof(TipoCelula)), *z = (InicioFim*)malloc(sizeof(TipoCelula));
  if (x == NULL || y == NULL || z == NULL) return 0;
  printf("Escolha uma das opções: ");
  printf("\n1-Fila\n2-Pilha\n");
  scanf("%d", &op);
  switch (op) {
    case 1:
      Cabeca(x);
      Cabeca(y);
      printf("Colocando 5 nós gerados aleatóriamentes na fila 1:\n");
      for(i = 0; i < 5; i++) {
        chave = rand () % 50;
        printf("Número gerado fila 1: %d\n", chave);
        InsereFila(x, chave);
      }
      printf("\nColocando 5 nós gerados aleatóriamentes na fila 2:\n");
      for(i = 0; i < 5; i++) {
        chave = rand () % 50;
        printf("Número gerado fila 2: %d\n", chave);
        InsereFila(y, chave);
      }
      printf("\nImprimindo fila 1:\n");
      ImprimeFila(x);
      printf("\nRemovendo um nó da fila 1:\n");
      RemoveFila(x);
      ImprimeFila(x);
      printf("\nImprimindo fila 2:\n");
      ImprimeFila(y);
      printf("\nRemovendo um nó da fila 2:\n");
      RemoveFila(y);
      ImprimeFila(y);
      printf("\nConcatenando fila 1 e fila 2:\n");
      z = ConcatenaFila(x, y);
      ImprimeFila(z);
      printf("\nInvertendo a fila 3:\n");
      FilaInversa(z);
      ImprimeFila(z);
      printf("\nRemovendo todos os nós da fila 3:\n");
      FFVazia(z);
      ImprimeFila(z);break;
    case 2:
      printf("\nColocando 5 nós gerados aleatóriamentes na pilha:\n");
      for(i = 0; i < 5; i++) {
        chave = rand () % 50;
        printf("Número gerado: %d\n", chave);
        InserePilha(x, chave);
      }
      printf("\nImprimindo pilha:\n");
      ImprimePilha(x);
      printf("\nRemovendo um nó da pilha:\n");
      RetiraPilha(x);
      printf("\nImprimindo pilha:\n");
      ImprimePilha(x);
      printf("\nRemovendo todos os nós da pilha:\n");
      FPVazia(x);
      ImprimePilha(x);break;
    }
  return 0;
}
