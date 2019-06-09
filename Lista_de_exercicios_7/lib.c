#include "lib.h"
//Alocação padrão de nó, com algumas mudanças nos campos por ser duplamente encadeado
TipoListaEncadeada *aloca_no(int chave, int valor) {
  TipoListaEncadeada *novoNo = NULL;
  novoNo = (TipoListaEncadeada*)malloc(sizeof(TipoListaEncadeada));
  if (novoNo == NULL) printf("O S.O não alocou memória.\n");
  else {
    novoNo->ant = NULL;
    novoNo->chave = chave;
    novoNo->valorQualquer = valor;
    novoNo->prox = NULL;
  }
  return novoNo;
}

void printa_lista(TipoListaEncadeada *lista) {
  if (lista == NULL) printf("Lista vazia.\n");
  else {
    do {
      printf("Chave: %d|| Valor: %d\n", lista->chave, lista->valorQualquer);
      lista = lista->prox;
    }while(lista != NULL);
  }
}

/* -------------------------> Insercao inicio
* Insere novo nó no início de uma lista duplamente encadeada.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.
*/
TipoListaEncadeada *insereInicioListaEncadeada(TipoListaEncadeada **prim, TipoChave chave, TipoValor valor) {
  assert(prim);//Verifica se o ponteiro de ponteiro é válido
  if (*prim == NULL) *prim = aloca_no(chave, valor);//Caso for, aloca o primeiro nó
  else {//Caso contrário, aloca o próximo nó
    TipoListaEncadeada *novoNo = NULL;
    novoNo = aloca_no(chave, valor);
    novoNo->prox = *prim;//Como a inserção é no início, o novo nó será o anterior ao primeiro atual, logo seu "->prox" aponta para o primeiro nó anterior
    (*prim)->ant = novoNo;//Aponta o "->ant" do primeiro nó anterior para o novo nó
    *prim = novoNo;//Aponta o início da lista para o novo primeiro nó
  }
  return *prim;
}
/* -------------------------> Insercao final
* Insere novo nó no final de uma lista duplamente encadeada.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.
*/
TipoListaEncadeada *insereFimListaEncadeada(TipoListaEncadeada **prim, TipoChave chave, TipoValor valor) {
  assert(prim);//Verifica se o ponteiro de ponteiro é válido
  if (*prim == NULL) *prim = aloca_no(chave, valor);//Caso a lista estiber vazia, aloca o primeiro nó
  else {//Caso contrário, aloca o próximo nó
    TipoListaEncadeada *novoNo = NULL, *listaAux = NULL;
    novoNo = aloca_no(chave, valor);
    listaAux = *prim;//Nó auxiliar para percorrer a lista até o seu último elemento
    while (listaAux->prox != NULL) {//Busca o último elemento
      listaAux = listaAux->prox;
    }
    novoNo->ant = listaAux;//Como o novo nó está sendo inserido no fim da lista, seu "->ant" aponta para o último nó anterior
    listaAux->prox = novoNo;//"Linka" a lista com o novo último nó
  }
}
/* -------------------------> Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.
*/
int removeNo(TipoListaEncadeada **prim, TipoChave chave) {
  assert(prim);//Verifica se o ponteiro de ponteiro é válido
  if (*prim == NULL) return 0;//Caso não haja elementos na lista, encerra a função
  else {//Caso contrário, verifica qual é o caso da remoção
    TipoListaEncadeada *listaAux = NULL;
    listaAux = *prim;
    while (listaAux != NULL && listaAux->chave != chave) {//Busca o nó com a chave ou o fim da lista
      listaAux = listaAux->prox;
    }
    if (listaAux == NULL) {//Caso o auxiliar saia nulo, o nó com a chave não se encontra na lista
      printf("Chave não se encontra na lista.\n");
      return 0;
    }
    else if (listaAux->ant == NULL) {//Caso o anterior ao auxiliar seja nulo, o nó a ser removido é o primeiro
      *prim = listaAux->prox;
    }
    else if (listaAux->prox == NULL) {//Caso o próximo ao auxiliar seja nulo, o nó a ser removido é o último
      listaAux->ant->prox = NULL;
    }
    else {//Caso contrário as duas condições, o nó está no meio da lista
      listaAux->ant->prox = listaAux->prox;
    }
    free (listaAux);//Libera o nó e encerra a função
    listaAux = NULL;
    return 1;
  }
}
/* -------------------------> Cria cópia
* Cria uma nova lista cujos nós são múltiplos de 3.
* Devolve o ponteiro para
* o primeiro nó da nova lista.
*/
TipoListaEncadeada *copiaLista3(TipoListaEncadeada *prim) {
  if (prim == NULL) return NULL;
  else {
    TipoListaEncadeada *listaAux = NULL, *novaLista = NULL;
    for (listaAux = prim->prox; listaAux != NULL; listaAux = listaAux->prox) {
      if (listaAux->chave % 3 == 0) {
        insereInicioListaEncadeada(&novaLista, listaAux->chave, listaAux->valorQualquer);
      }
    }
    return novaLista;
  }
}
