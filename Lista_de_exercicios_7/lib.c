#include "lib.h"

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
  assert(prim);
  if (*prim == NULL) *prim = aloca_no(chave, valor);
  else {
    TipoListaEncadeada *novoNo = NULL;
    novoNo = aloca_no(chave, valor);
    novoNo->prox = *prim;
    (*prim)->ant = novoNo;
    *prim = novoNo;
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
  assert(prim);
  if (*prim == NULL) *prim = aloca_no(chave, valor);
  else {
    TipoListaEncadeada *novoNo = NULL, *listaAux = NULL;
    novoNo = aloca_no(chave, valor);
    listaAux = *prim;
    while (listaAux->prox != NULL) {
      listaAux = listaAux->prox;
    }
    novoNo->ant = listaAux;
    listaAux->prox = novoNo;
  }
}
/* -------------------------> Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.
*/
void removeNo(TipoListaEncadeada **prim, TipoChave chave) {

}
/* -------------------------> Cria cópia
* Cria uma nova lista cujos nós são múltiplos de 3.
* Devolve o ponteiro para
* o primeiro nó da nova lista.
*/
TipoListaEncadeada *copiaLista3(TipoListaEncadeada *prim) {

}
