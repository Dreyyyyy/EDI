/*15. Crie uma função que receba um ponteiro para um array de float com 10 elementos.
Imprima o endereço de cada posição desse array.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprime_array(float *p);

int main(int argc, char const *argv[]) {
  float array[10], *p = NULL;
  int i;
  printf("\n");
  for (i = 0; i < 10; i++) {
    array[i] = rand () % 15;
    printf("Valor gerado no array: %.2f\n", array[i]);
  }
  p = array;
  imprime_array(p);
  return 0;
}

void imprime_array(float *p) {
  int i;
  printf("\nArray printada pelo ponteiro:\n\n");
  for (i = 0; i < 10; i++) {
    printf("%dº elemento do array: %.2f\n", i+1, *(p+i));
  }
  printf("\n");
}
