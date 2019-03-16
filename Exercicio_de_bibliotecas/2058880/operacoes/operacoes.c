#include "operacoes.h"

//I. Multiplicação de números naturais usando soma
int multiplicacao_naturais(int a, int b) {
  int res = 0, i = 0;
  for (i = 0; i < b; i++) {
    res += a;
  }
  return res;
}

//II. Fatorial n! = (n-1) * (n-2) * (n-3) ... 2 * 1
int fatorial(int n) {
  if (n == 1 || n == 0) return 1;//Caso base: Se n for 1 ou 0, o fatorial será 1;
  if (n == 2) return 2;//Segundo caso base: Se n for 2, função retornará 2;
  else {
    int total = fatorial(n-1);//Aplica recursiva até chegar ao caso base "2";
    int soma = 0;
    for(int i=1; i<=n;i++) {//Soma o caso base "2" o número de vezes necessário para o fatorial;
	    soma+=total;
    }
    return soma;
  }
}

//III. Divisão de números naturais usando subtração.
int divisao(int a, int b) {
  int i = 0, res = 0;
  while (a > 0) {
    a -= b;//Reduz o A até chegar em 0;
    res++;//Conta quantas vezes "a" foi subtraído de "b", assim dando o resultado da divisão
  }
  return res;
}
