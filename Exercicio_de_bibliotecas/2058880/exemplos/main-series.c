#include "/home/drey/EDI/Exercicio_de_bibliotecas/2058880/series/series.c"

int main(int argc, char const *argv[]) {
  int op = 0, res = 0, n = 0;
  printf("\nLeia as instruções da biblioteca pelo arquivo de texto\n");
  printf("\nEscolha uma das opções abaixo:\n");
  printf("\n1. 2^1+ 2^2+ 2^3+....+ 2^n, n inteiro positivo\n");
  printf("\n2. 1 – 2 + 3 – 4 + 5 ...... n, n inteiro positivo\n");
  printf("\nTecle o número correspondente a opção desejada: ");
  scanf("%d", &op);
  switch (op) {
    case 1:
      printf("\nDigite um número inteiro positivo: ");
      scanf("%d", &n);
      res = sequencia_pow(n);
      printf ("\nO resultado será:%d\n\n", res);break;
    case 2:
      printf("\nDigite um número inteiro positivo: ");
      scanf("%d", &n);
      res = sequencia_alternando(n);
      printf ("\nO resultado será:%d\n\n", res);break;
    default:;
  }
  return 0;
}
