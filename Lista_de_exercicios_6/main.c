#include "lib.h"

int main(int argc, char const *argv[]) {
  TipoListaCircular *listaC = NULL;
  int i = 0, chave = 0, valor = 0;
  printf("=>Inserindo 5 valores aleatórios no início da lista, e as chaves serão do 1 em diante em ordem crescente:\n");
  for (i = 0; i < 5; i++) {
    chave = i+1;
    valor = rand () % 50;
    printf("=>Inserindo o valor: %d, com a chave: %d\n", valor, chave);
    insereInicioListaCircular(&listaC, chave, valor);
  }
  printf("=>Printa a lista completa:\n");
  printa_lista(listaC);
  printf("=>Remove da lista o valor: ");
  scanf("%d", &chave);
  removeNo(&listaC, chave);
  printf("=>Printa a lista completa, com o nó com a chave %d removido:\n", chave);
  printa_lista(listaC);
  return 0;
}
