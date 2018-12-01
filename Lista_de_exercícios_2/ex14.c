/*14. Escreva uma função que calcule o perímetro de um retângulo (P=2b+2h). A função
deverá retornar o valor do perímetro calculado. Após o cálculo do perímetro altere o
valor das variáveis base e altura para: b=2*b e h=2*h. No programa principal imprima o
valor do perímetro calculado e os novos valores da base e da altura. OBS: Utilize
passagem de parâmetros por referência.
Protótipo: float perímetro(float *a, float *b)*/

#include <stdio.h>
#include <stdlib.h>

float perimetro(float *a, float *b);
void altera_valores(float *b, float *h);

int main(int argc, char const *argv[]) {
  float b = 0, h = 0, per = 0;
  printf("\nDigite o valor da base e da altura do respectivo retângulo: ");
  scanf("%f%f", &b, &h);
  per = perimetro(&b, &h);
  altera_valores(&b, &h);
  printf("\nBase e altura mutliplicados por 2, e logo em seguida o perímetro calculado:\n");
  printf("Base = %.2f, Altura = %.2f, Perímetro = %.2f\n\n", b, h, per);
  return 0;
}

float perimetro(float *a, float *b) {
  return (2 * (*a) + 2 * (*b));
}

void altera_valores(float *b, float *h) {
  *b = 2 * (*b);
  *h = 2 * (*h);
}
