#include "lib.h"

int main(int argc, char const *argv[]) {
  TipoListaCircular *listaC = NULL, *listaCpar = NULL;
  int i = 0, chave = 0, valor = 0, ver = 0;
  printf("=>Inserindo 5 valores aleatórios no início da lista, e as chaves serão do 1 em diante em ordem crescente:\n");
  for (i = 0; i < 5; i++) {
    chave = i+1;
    valor = rand () % 50;
    printf("=>Inserindo o valor: %d, com a chave: %d\n", valor, chave);
    insereInicioListaCircular(&listaC, chave, valor);
  }
  printf("=>Printa a lista completa:\n");
  printa_lista(listaC);
  printf("\n=>Remove da lista a chave: ");
  scanf("%d", &chave);
  ver =removeNo(&listaC, chave);
  if (ver == 1) {
    printf("=>Printa a lista completa, com o nó com a chave %d removido:\n", chave);
    printa_lista(listaC);
  }
  printf("\n=>Cria nova lista, com os nós com o campo chave da primeira lista que são pares:\n");
  listaCpar = copiaListaPar(listaC);
  printf("=>Printa lista com chaves pares:\n");
  printa_lista(listaCpar);
  return 0;
}
