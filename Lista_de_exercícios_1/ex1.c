/*1. Defina funções para as quatro operações aritméticas elementares
 Defina o nome do arquivo como main.c
 Antes da função apresente um comentário explicando o que a função
faz e sob que circunstâncias dá a resposta correta.*/

#include <stdio.h>
#include <stdlib.h>

//Soma dois números inteiros ou reais
float soma(float a, float b);
//Subtrai dois números inteiros ou reais
float subtracao(float a, float b);
//Multiplica dois números inteiros ou reais
float multiplicacao(float a, float b);
//Divide dois números inteiros ou reais
float divisao(float a, float b);

int main(int argc, char const *argv[]) {
  float a = 0, b = 0, res = 0;
  int op = 0, op2 = 0;
  do {
    printf("\nDigite dois valores, sequencialmente: ");
    scanf("%f%f", &a, &b);
    printf("\nEscolha uma das operações aritméticas abaixo:\n");
    printf("1-Soma\n");
    printf("2-Subtração\n");
    printf("3-Multiplicação\n");
    printf("4-Divisão\n");
    printf("\nDigite o número da operação desejada: ");
    scanf("%d", &op);
    switch (op) {
      case 1:
        res = soma(a, b);
        printf("Resultado: %.2f + %.2f = %.2f\n", a, b, res);break;
      case 2:
        res = subtracao(a, b);
        printf("Resultado: %.2f - %.2f = %.2f\n", a, b, res);break;
      case 3:
        res = multiplicacao(a, b);
        printf("Resultado: %.2f * %.2f = %.2f\n", a, b, res);break;
      case 4:
        res = divisao(a, b);
        printf("Resultado: %.2f / %.2f = %.2f\n", a, b, res);break;
      default: break;
    }
    printf("\nDeseja reexecutar o algorítmo? Tecle 1 para sim e qualquer outro para não: ");
    scanf("%d", &op2);
  }while (op2 == 1);
  return 0;
}

//Soma dois números inteiros ou reais
float soma(float a, float b) {
  return a + b;
}
//Subtrai dois números inteiros ou reais
float subtracao(float a, float b) {
  return a - b;
}
//Multiplica dois números inteiros ou reais
float multiplicacao(float a, float b) {
  return a * b;
}
//Divide dois números inteiros ou reais
float divisao(float a, float b) {
  return a / b;
}
