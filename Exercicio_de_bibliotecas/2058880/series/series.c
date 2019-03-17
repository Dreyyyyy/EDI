#include "series.h"

//I. 2^1+ 2^2+ 2^3+....+ 2^n, n inteiro positivo
int sequencia_pow(int n) {
  int i = 0, soma = 0;
  for(i = 1; i <= n; i++) {
    soma += pow(2, i);//Não era pra usar pow, arrumarei isso outra hora
  }
  return soma;
}

//II. 1 – 2 + 3 – 4 + 5 ...... n, n inteiro positivo
int sequencia_alternando(int a) {

}
