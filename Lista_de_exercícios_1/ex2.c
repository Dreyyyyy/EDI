/*2. Faça uma função que receba uma palavra como parâmetro de entrada e a
imprima de tras-para-frente.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ao_contrario(char *palavra);

int main(int argc, char const *argv[]) {
  char palavra[30];
  printf("\nDigite uma palavra(máximo 30 caracteres): ");
  scanf("%s", palavra);
  ao_contrario(palavra);
  return 0;
}

void ao_contrario(char *palavra) {
  int tam = strlen(palavra), i;
  printf("\nPalavra digitada, porém agora de trás para frente: ");
  for (i = tam; i >= 0; i--) {
    printf("%c", palavra[i]);
  }
  printf("\n\n");
}
