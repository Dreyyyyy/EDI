#include "/home/drey/EDI/2058880/operacoes/operacoes.c"

int main(int argc, char const *argv[]) {
  int op = 0, res = 0, a = 0, b = 0;
  printf("\nLeia as instruções da biblioteca pelo arquivo de texto\n");
  printf("\nEscolha uma das opções abaixo:\n");
  printf("\n1. Multiplicação de números naturais usando soma\n");
  printf("\n2. Fatorial n! = (n-1) * (n-2) * (n-3) ... 2 * 1\n");
  printf("\n3. Divisão de números naturais usando subtração\n");
  printf("\nTecle o número correspondente a opção desejada: ");
  scanf("%d", &op);
  switch (op) {
    case 1:
      printf("\nDigite dois números consecutivos, sendo estes naturais: ");
      scanf("%d%d", &a, &b);
      res = multiplicacao_naturais(a, b);
      printf ("\nO resultado será:%d\n\n", res);break;
    case 2:
      printf("\nDigite um número natural para o cálculo de seu fatorial: ");
      scanf("%d", &a);
      res = fatorial(a);
      printf ("\nO resultado será:%d\n\n", res);break;
    case 3:
      printf("\nDigite dois números consecutivos, sendo estes naturais: ");
      scanf("%d%d", &a, &b);
      res = divisao(a, b);
      printf ("\nO resultado será:%d\n\n", res);break;    
    default:;
  }
  return 0;
}
