#include "operacoes.h"

int main(int argc, char const *argv[]) {
  int op = 0, res = 0;
  printf("\nLeia as instruções da biblioteca pelo arquivo de texto\n");
  printf("\nEscolha uma das opções abaixo:\n");
  printf("\n1. Multiplicação de números naturais usando soma\n");
  printf("\n2. Fatorial n! = (n-1) * (n-2) * (n-3) ... 2 * 1\n");
  printf("\n3. Divisão de números naturais usando subtração\n");
  printf("\nTecle o número correspondente a opção desejada: ");
  scanf("%d", &op);
  switch (op) {
    case 1:
      int a = 0, b = 0;
      printf("\nDigite dois números consecutivos, sendo estes naturais: ");
      scanf("%d%d", &a, &b);
      res = multiplicacao_naturais(a, b);
      printf ("\nO resultado será:%d\n", res);break;
    /*case 2:
    case 3:*/
    default:;
  }
  return 0;
}