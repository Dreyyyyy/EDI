#include "lib.h"

int main(int argc, char const *argv[]) {
  TipoListaEncadeada *listaDe = NULL, *lista3De = NULL;
  int  i = 0, chave = 0, valor = 0, ver = 0;
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
  printf("\n=>Remove o nó da lista com a chave: ");
  scanf("%d", &chave);
  ver = removeNo(&listaDe, chave);
  if (ver == 1) {
    printf("=>Printa a lista com o nó cujo a chave era %d removido:\n", chave);
    printa_lista(listaDe);
  }
  printf("\n=>Cria uma nova lista com os nós contendo chaves da primeira lista que são múltiplos de 3:\n");
  lista3De = copiaLista3(listaDe);
  printf("=>Printa a lista completa:\n");
  printa_lista(lista3De);
  return 0;
}
