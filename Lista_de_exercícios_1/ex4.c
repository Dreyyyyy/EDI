/*4. Crie um programa que receba três valores (obrigatoriamente maiores que
zero), representando as medidas dos trâs lados de um triângulo. Elabore
funções para:
a. Determinar se eles lados formam um triangulo, sabendo que: o
comprimento de cada lado de um triângulo, deve ser menor do
que a soma dos outros dois lados. Essa função deve retornar 0
caso negativo e 1 caso positivo.
b. Determinar e mostrar o tipo de triangulo, caso as medidas
formem um triângulo. Sendo que:
i. Chama-se equilátero o triângulo que tem três lados iguais.
ii. Denominam-se isósceles o triângulo que tem o
comprimento de dois lados iguais.
iii. Recebe o nome de escaleno o triangulo que tem os três
lados diferentes.*/

#include <stdio.h>
#include <stdlib.h>

int forma_triangulo(float a, float b, float c);
int tipo_triangulo(float a, float b, float c);

int main(int argc, char const *argv[]) {
  float a = 0, b = 0, c = 0;
  int resp = 0, resp2 = 0;
  do {
    printf("\nDigite 3 valores sequencialmente, e maiores que 0: ");
    scanf("%f%f%f", &a, &b, &c);
  }while (a < 0 || b < 0 || c < 0);
  resp = forma_triangulo(a, b, c);
  if (resp == 0) printf("\nEstes valores não formam um triângulo.\n");
  else {
    resp2 = tipo_triangulo(a, b, c);
    switch (resp2) {
      case 1:
        printf("\nEstes valores formam um triângulo escaleno.\n");break;
      case 2:
        printf("\nEstes valores formam um triângulo isósceles.\n");break;
      case 3:
        printf("\nEstes valores formam um triângulo equilátero.\n");break;
      default: break;
    }
  }
  return 0;
}

int forma_triangulo(float a, float b, float c) {
  if (a > (b+c)) return 0;
  else {
    if (b > (a+c)) return 0;
    else {
      if (c > (a+b)) return 0;
      else return 1;
    }
  }
}

int tipo_triangulo(float a, float b, float c) {
  if (a != b && a != c && b != c) return 1;
  else {
    if (a == b && a != c || a == c && a != b || b == a && b != c || b == c && b != a || c == a && c != b || c == b && c != a) return 2;
    else return 3;
  }
}
