/*8. Escreva uma função mm que receba um ponteiro para um vetor inteiro v[0..n-1], o número de
elementos do vetor (n) e os endereços de duas variáveis inteiras, min e Max. Deposite nessas variáveis o
valor de um elemento mínimo e o valor de um elemento máximo do vetor. Escreva também uma função
main que use a função mm.*/

#include <stdio.h>
#include <stdlib.h>

int *aloca(int n);
void mm (int n, int *v, int *min, int *max);

int main(int argc, char const *argv[]) {
  int n = 0, i = 0, min = 0, max = 0;
  printf("\nDigite o tamanho do vetor: ");
  scanf("%d", &n);
  int *v = aloca(n);
  for (i = 0; i < n; i++) {
    printf("\nDigite o %dº elemento do vetor: ", i+1);
    scanf("%d", &(*(v+i)));
  }
  if (v == NULL) printf("\nFalha ao alocar memória ao vetor.\n\n");
  else {
    mm(n, v, &min, &max);
    printf("\nValor mínimo do vetor: %d\n", min);
    printf("\nValor máximo do vetor: %d\n", max);
  }
  return 0;
}

int *aloca(int n) {
  int *aux = NULL;
  aux = (int*)malloc(sizeof(int) * n);
  if (aux == NULL) return NULL;
  else return aux;
}

void mm (int n, int *v, int *min, int *max) {
  int i = 0;
  *min = *max = v[0];
  for (i = 0; i < n; i++) {
    if (*max <= *(v+i)) {
      *max = *(v+i);
    }
    if (*min >= *(v+i)) {
      *min = *(v+i);
    }
  }
}
