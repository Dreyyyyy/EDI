#include "operacoes.h"

//I. Multiplicação de números naturais usando soma
int multiplicacao_naturais(int a, int b) {
  int res = 0, i = 0;
  for (i = 0; i < b; i++) {
    res += a;
  }
  return res;
}
