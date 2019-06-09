#include "lib.h"

TipoListaCircular *aloca_no(int chave, int valor) {
  TipoListaCircular *novoNo = NULL;
  novoNo = (TipoListaCircular*)malloc(sizeof(TipoListaCircular));
  if (novoNo == NULL) printf("O S.O não conseguiu alocar memória!\n");
  else {//Caso a memória seja alocado com sucesso, os campos de dados serão preenchidos
    novoNo->chave = chave;
    novoNo->valorQualquer = valor;
    novoNo->prox = novoNo;
  }
  return novoNo;//Devolve o endereço do novo nó alocado
}

void printa_lista(TipoListaCircular *listaC) {
  if (listaC == NULL) printf("Lista vazia!\n");
  else {//Caso a lista não esteja vazia, entra no loop abaixo
    TipoListaCircular *primeiroNo = listaC->prox, *aux = listaC->prox;
    do {//Printa elemento por elemento, até o ponteiro que está percorrendo a lista for igual ao primeiro da lista, ou seja, a lista já foi printada por completo
      printf("=>Chave: %d || Valor: %d\n", aux->chave, aux->valorQualquer);
      aux = aux->prox;
    }while(aux != primeiroNo);
  }
}

void remove_prim(TipoListaCircular **prim) {
  assert(prim);//Verifica se o ponteiro de ponteiro é válido
  if (*prim == NULL) return;//Verifica se a lista está vazia
  else {
    TipoListaCircular *noPenult = NULL, *noPrim = NULL;
    noPenult = (*prim)->prox;
    noPrim = (*prim)->prox;
    if (noPrim != noPrim->prox) {//Verifica se a lista possui apenas um elemento
      while(noPenult->prox != *prim) {//Busca o penultimo nó
        noPenult = noPenult->prox;
      }
      free(*prim);//remove o primeiro nó da lista
      *prim = NULL;
      noPenult->prox = noPrim;//Aponta o ponteiro do penúltimo para o nó marcado como primeiro(contando a lista da esquerda para direita)
      *prim = noPenult;//Primeiro nó passa a ser o penultimo anterior
    }
    else {//Caso existir apenas um elemento, remove este
      free(*prim);
      *prim = NULL;
    }
  }
}

/*===========================>PROCEDIMENTOS BÁSICOS DE LISTAS CIRCULAR
/* -------------------------> Insercao
* Insere novo nó no início de uma lista encadeada circular.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.
*/
TipoListaCircular *insereInicioListaCircular(TipoListaCircular **prim, TipoChave chave, TipoValor valor) {
  assert(prim);//Verifica se o ponteiro de ponteiro é válido
  if(*prim == NULL) *prim = aloca_no(chave, valor);//Caso a lista esteja vazia, aloca o primeiro nó
  else {//Caso contrário, fará alocação de um novo nó e "linkará" este na lista
    TipoListaCircular *novoNo = NULL;
    novoNo = aloca_no(chave, valor);//Aloca um novo nó
    novoNo->prox = (*prim)->prox;//Aponta o ponteiro "->prox" do novo nó para o último da lista(pois a lista insere no início, no caso o último e o "->prox" do primeiro nó)
    (*prim)->prox = novoNo;//"Linka" o novo nó a lista, apontando o "->prox" do primeiro atual para o novo nó
    *prim = novoNo;//Aponta o ponteiro do primeiro nó para o novo nó
  }
  return *prim;//Retorna o nó alocado
}

/* -------------------------> Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.
*/
int removeNo(TipoListaCircular **prim, TipoChave chave) {
  assert(prim);//Verifica se o ponteiro de ponteiro é válido
  if (*prim == NULL) return 0;//Se a lista for vazia encerra a função
  else if ((*prim)->chave == chave) remove_prim(prim);//Se o primeiro nó for o buscado, remove este pela outra função
  else {//Caso contrário, inicia-se a busca pelo nó desejado
    TipoListaCircular *noAux = NULL, *noPenult = NULL;
    noAux = (*prim)->prox;
    noPenult = *prim;
    while (noAux != *prim && noAux->chave != chave) {//Função usando operações lógicas, quando o && for falso(o && só é verdadeiro quando ambos são verdadeiros) encerra o laço
      noAux = noAux->prox;
      noPenult = noPenult->prox;
    }//Ou seja, Percorre até o fim da lista buscando a chave
    if (noAux == *prim) {
      printf("Chave não encontrada na lista.\n");//Caso o auxiliar tenha chegado ao fim, a chave não foi encontrada
      return 0;
    }
    else {//Caso contrário, remove o nó encontrado
      noPenult->prox = noAux->prox;
      free(noAux);
      noAux = NULL;
    }
  }
  return 1;
}

/* -------------------------> Cria cópia
* Cria uma nova lista cujos nós tem valor chave par
* Devolve o ponteiro para
* o primeiro nó da nova lista.
*/
TipoListaCircular *copiaListaPar(TipoListaCircular *prim) {
  if (prim == NULL) return NULL;
  else {
    TipoListaCircular *listaAux = NULL, *novaLista = NULL;
    for (listaAux = prim->prox; listaAux != prim; listaAux = listaAux->prox) {
      if (listaAux->chave % 2 == 0) {
        insereInicioListaCircular(&novaLista, listaAux->chave, listaAux->valorQualquer);
      }
    }
    return novaLista;
  }
}
