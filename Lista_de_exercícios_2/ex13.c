/*13. Faça um programa que leia 2 valores inteiros e chame uma função que receba estas
2 variáveis e troque o seu conteúdo, ou seja, esta função é chamada passando duas
variáveis A e B por exemplo e, após a execução da função, A conterá o valor de B e B
terá o valor de A.*/

#include <stdio.h>
#include <stdlib.h>

void troca_valores(int *a, int *b);

int main(int argc, char const *argv[]) {
  int a = 0, b = 0;
  printf("\nDigite respectivamente dois valores inteiros, para a e b: ");
  scanf("%d%d", &a, &b);
  printf("a = %d, b = %d\n\n", a, b);
  troca_valores(&a, &b);
  printf("Valores trocados:\n");
  printf("a = %d, b = %d\n\n", a, b);
  return 0;
}

void troca_valores(int *a, int *b) {
  int aux = 0;
  aux = *a;
  *a = *b;
  *b = aux;
}
