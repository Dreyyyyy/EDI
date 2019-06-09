#include "lib.h"

int main(int argc, char const *argv[]) {
  TipoListaEncadeada *listaDe = NULL;
  int  i = 0, chave = 0, valor = 0;
  printf("=>Inserindo 5 valores aleatórios no início da lista, e as chaves serão do 1 em diante em ordem crescente:\n");
  for (i = 0; i < 5; i++) {
    chave = i+1;
    valor = rand () % 50;
    printf("=>Inserindo o valor: %d, com a chave: %d\n", valor, chave);
    insereInicioListaEncadeada(&listaDe, chave, valor);
  }
  printf("=>Printa a lista completa:\n");
  printa_lista(listaDe);
  printf("\n=>Inserindo 5 valores aleatórios no fim da lista, e as chaves serão do 6 em diante em ordem crescente:\n");
  for (i = 5; i < 10; i++) {
    chave = i+1;
    valor = rand () % 50;
    printf("=>Inserindo o valor: %d, com a chave: %d\n", valor, chave);
    insereFimListaEncadeada(&listaDe, chave, valor);
  }
  printf("=>Printa a lista completa:\n");
  printa_lista(listaDe);
  return 0;
}
