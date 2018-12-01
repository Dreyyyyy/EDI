/*16. Escreva uma função double* max(double* a, int size) que retorne um ponteiro para
o maior valor contido em um array de elementos do tipo double, se o array estiver vazio,
retorne NULL.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double *max(double *a, int size);

int main(int argc, char const *argv[]) {
  double *p = NULL;
  int i, size = 0;
  printf("\nDigite o tamanho do array: ");
  scanf("%d", &size);
  double a[size];
  for (i = 0; i < size; i++) {
    a[i] = rand () % 50;
    printf("Valor gerado no array: %.2lf\n", a[i]);
  }
  p = max(a, size);
  if (p == NULL) printf("Array estava vazio!\n\n");
  else printf("\nMaior elemento do array: %.2lf\n\n", *p);
  return 0;
}

double *max(double *a, int size) {
  int i;
  double maior = 0, *maiorE = NULL;
  for (i = 0; i < size; i++) {
    if (maior < a[i]) {
      maior = a[i];
      maiorE = &a[i];
    }
  }
  return maiorE;
}
