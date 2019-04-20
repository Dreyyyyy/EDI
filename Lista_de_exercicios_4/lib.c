#include "lib.h"

TipoListaSimples *aloca_no(TipoChave chave, TipoValor valor) {
    TipoListaSimples *aux = NULL;
    aux = (TipoListaSimples*)malloc(sizeof(TipoListaSimples));//Aloca memória para um nó
    if (aux == NULL) {
        return NULL;
    }
    else {
        aux->chave = chave;//Recebe os campos do nó
        aux->valorQualquer = valor;//Recebe os campos do nó
        aux->prox = NULL;//Recebe os campos do nó
        return aux;//Retorna o endereço alocado para esse nó
    }
}

void printa_lista(TipoListaSimples *prim) {
    if (prim == NULL) {
        printf("\nLista vazia!\n");
    }
    else {
        while(prim != NULL) {
            printf("\n=>Valor: %d =>Chave: %d\n", prim->valorQualquer, prim->chave);
            prim = prim->prox;//Avança o ponteiro local para andar pela lista
       }
    }
}

/*===================================>PROCEDIMENTOS BÁSICOS DE LISTAS
/* -------------------------> Insercao no início
* Insere novo nó no início de uma lista encadeada.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.*/
TipoListaSimples *insereInicioListaSimples(TipoListaSimples **prim, TipoChave chave, TipoValor valor) {
    if (*prim == NULL) {
        *prim = aloca_no(chave, valor);//Caso a lista esteja vazia, aloca o primeiro nó
    }
    else {
        TipoListaSimples *no = NULL;
        no = aloca_no(chave, valor);//Aloca endereço um nó
        no->prox = *prim;//Como a inserção é no início, o novo nó aponta para o primeiro nó anterior, assim então se tornando o novo primeiro nó
        *prim = no;//Faz o ponteiro da main apontar para o novo primeiro nó
    }
    return *prim;
}

/* -------------------------> Atualiza primeiro no
* Caso o primeiro nó exista, atualiza o campo
* valorQualquer com novoValor. É dado o ponteiro para
* o primeiro nó.*/
void atualizaValor(TipoListaSimples *prim, TipoValor novoValor) {
    if (prim == NULL) {
        return;
    }
    else {
        prim->valorQualquer = novoValor;
    }
}

/* -------------------------> Remoção no início
* Remove o primeiro nó de uma lista
* caso ele exista. O segundo, se existir, passará
* a ser o primeiro.*/
void removePrimeiroNo(TipoListaSimples **prim) {
    if(*prim == NULL) {
        return;
    }
    else {
        TipoListaSimples *aux = NULL;
        aux = *prim;//Auxiliar armazena o endereço de memória do primeiro nó que será removido
        *prim = (*prim)->prox;//O ponteiro da main passa a apontar para o segundo nó
        free(aux);//libera o primeiro nó
        aux = NULL;
    }
}

/* -----------------> Busca pelo endereço de um nó dado um valor de chave
* Devolve ponteiro para o nó cujo valor chave é 'chave'
* ou NULL caso este não exista.*/
TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave) {
    TipoListaSimples *listaAux = NULL;
    for (listaAux = prim; listaAux != NULL; listaAux = listaAux->prox) {//Laço para andar pela lista até o fim
        if (listaAux->chave == chave) {
            return listaAux;//Caso encontrar a chave, termina a função e retorna o endereço do no encontrado para o ponteiro
        }
    }
    return NULL;
}

/* -------------------------> Inserção no fim de uma lista
* Insere nó no fim de uma lista dada a referência do ponteiro
* do primeiro nó.
* Devolve endereço do novo nó ou NULL em caso de
* insucesso.
*/
TipoListaSimples * insereFimListaSimples(TipoListaSimples **prim, TipoChave chave, TipoValor valor) {
    if (*prim == NULL) {
      *prim = aloca_no(chave, valor);//Caso base: Quando o endereço passado é NULL, aloca um novo nó
    }
    else {
        insereFimListaSimples(&(*prim)->prox, chave, valor);//Caso recursivo: Passa o endereço do próximo nó da lista
    }
    return *prim;//Retorna o nó inserido
}

/* -------------------------> Remoção último nó
* Remove o último nó de uma lista (caso ele exista) dada a
* referência do ponteiro do primeiro nó.
*/
void removeUltimoNo(TipoListaSimples **prim) {
  if (*prim == NULL) return;//Caso não tenha nós na lista, a função termina
  else if ((*prim)->prox == NULL) {//Caso base: busca o último elemento, e remove este
    TipoListaSimples *noAux = NULL;
    noAux = *prim;
    *prim = NULL;
    free(noAux);
    noAux = NULL;
    return;
  }
  else {
    removeUltimoNo(&(*prim)->prox);//Caso recursivo: Função que remove o último nó sempre retornará o seu "->prox" até que o caso base seja feito
  }
}

/* -------------------------> Remove todos nós
* Remove TODOS os nos da lista exceto e atualiza
* ponteiro para o primeiro para NULL.
* Dica: recursividade pode ajudar muito!
*/
void liberaNos(TipoListaSimples **prim) {
  if (*prim == NULL) {//Caso base: Quando a lista estiver vazia, encerra a função
    return;
  }
  else {
    removeUltimoNo(&(*prim));//Remove os nós pelo final da lista
  }
  liberaNos(&(*prim));//Caso recursivo: Remove nó por nó, até cair no caso base e encerrar a função
}

/*================================>PROCEDIMENTOS ESPECÍFICOS DE LISTAS
/* -------------------------> Cria cópia
* Cria uma nova lista cujos nós têm os mesmos
* valores da lista dada. Devolve o ponteiro para
* o primeiro nó da nova lista.
*/
TipoListaSimples *copiaListas(TipoListaSimples *prim) {
  TipoListaSimples *novaLista = NULL;
  while (prim != NULL) {
    insereInicioListaSimples(&novaLista, prim->chave, prim->valorQualquer);
    prim = prim->prox;
  }
  return novaLista;
}

/* -------------------------> Cria cópia
* Calcula a interseção entre as duas listas
* dadas e insere tais nós numa (nova) terceira
* lista. Devolve o ponteiro para o cabeça da nova lista.
* A interseção deve considerar o campo chave.
*/
TipoListaSimples *intersecaoListas(TipoListaSimples *prim1, TipoListaSimples *prim2) {
  TipoListaSimples *novaLista = NULL, *listaAux1 = NULL, *listaAux2 = NULL;
  for (listaAux1 = prim1; listaAux1 != NULL; listaAux1 = listaAux1->prox) {//Percorre a lista 1 inteira
    for (listaAux2 = prim2; listaAux2 != NULL; listaAux2 = listaAux2->prox) {//Percorre a lista 2 inteira
      if (listaAux1->chave == listaAux2->chave) {//Compara os campos chaves da lista 1 e 2, os nós iguais serão inseridos na terceira lista
        insereInicioListaSimples (&novaLista, listaAux1->chave, listaAux2->valorQualquer);//Insere o nó no ínicio da nova lista (Coloquei o chave da lista 1 e o valor da lista 2 só pra ter certeza de que estava funcionando)
      }
    }
  }
  return novaLista;//Retorna a nova lista
}

/* -------------------------> Remove/Insere
* Remove último nó da segunda lista (caso ele exista).
* Insere um novo nó na última posição da primeira lista.
* O novo nó deve ter os mesmos valores do nó removido.
* A referencia do ponteiro para o primeiro nó das listas de entrada
* são primLista1 e primLista2, respectivamente.
*/
void insereRemove(TipoListaSimples **primLista1, TipoListaSimples **primLista2) {
  if (*primLista2 == NULL) {//Caso a lista 2 não exista, encerra a função
    return;
  }
  else {
    TipoListaSimples *listaAux = NULL, *noAnt = NULL;
    listaAux = (*primLista2)->prox;
    noAnt = *primLista2;
    while (listaAux->prox != NULL) {//Busca o último e o penúltimo nó
      noAnt = noAnt->prox;
      listaAux = listaAux->prox;
    }
    insereFimListaSimples(&(*primLista1), listaAux->chave, listaAux->valorQualquer);//Insere o último nó na lista 1
    free(listaAux);//Remove o último nó da lista 2
    listaAux = NULL;
    noAnt->prox = NULL;
  }
}

/* -------------------------> Transplanta Nó.
* Desconecta o último nó da segunda lista (caso ele exista).
* Conecta tal nó na última posição da primeira lista.
* NOTE QUE A REGIÃO DE MEMÓRIA DO NÓ NÃO MUDA!
* A referencia do ponteiro para o primeiro nó das listas de entrada
* são primLista1 e primLista2, respectivamente.
*/
void transplantaNo(TipoListaSimples **primLista1, TipoListaSimples **primLista2) {
  if (*primLista2 == NULL) {//Caso a lista 2 não exista, encerra a função
    return;
  }
  else {
    TipoListaSimples *listaAux2 = NULL, *noAnt2 = NULL, *listaAux1 = NULL;
    listaAux2 = (*primLista2)->prox;
    noAnt2 = *primLista2;
    while (listaAux2->prox != NULL) {//Busca o último e o penúltimo nó da segunda lista
      noAnt2 = noAnt2->prox;
      listaAux2 = listaAux2->prox;
    }
    noAnt2->prox = NULL;
    listaAux1 = (*primLista1)->prox;//Desconecta o último nó da segunda lista
    while (listaAux1->prox != NULL) {//Busca o último e o penúltimo nó da primeira lista
      listaAux1 = listaAux1->prox;
    }
    listaAux1->prox = listaAux2;//Conecta o nó desconectado da segunda lista na última posição da primeira lista
  }
}

/* -------------------------> Conta Nó.
* Conta o número de nós de uma lista encadeada.
* Retorno número de nós
*/
int contaNo(TipoListaSimples **primLista1) {
  TipoListaSimples *listaAux = NULL;
  int cont = 0;
  listaAux = *primLista1;//Auxiliar para não alterar o ponteira principal da lista
  while (listaAux != NULL) {//Conta todos os nós da lista
    cont++;
    listaAux = listaAux->prox;
  }
  return cont;
}

int alturaNo(TipoListaSimples **primLista1, TipoChave chave) {
  int contador = 0;
  TipoListaSimples *listaAux = NULL;//Ponteiro auxiliar para não alterar o endereço original da lista
  for (listaAux = *primLista1; listaAux != NULL; listaAux = listaAux->prox) {//Enquanto não chegar ao fim da lista
    if (listaAux->chave == chave) {//Caso a chave seja encontrada, começa a incrementar o contador
      while (listaAux != NULL) {
        contador++;
        listaAux = listaAux->prox;
      }
      break;//Quando terminar o laço while, o for não será mais útil
    }
  }
  return contador;//Retorna a altura
}


/* -------------------------> Profundidade do Nó.
* Escreva uma função que calcule a profundidade de um dado nó (baseado na
*chave).
* A profundidade de um nó c em uma lista encadeada é o número de passos do
*único caminho que vai do primeiro nó da lista até c.
*/
int profundidadeNo(TipoListaSimples **primLista1, TipoChave chave) {
  int contador = 0;
  TipoListaSimples *listaAux = NULL;//Ponteiro auxiliar para não alterar o endereço original da lista
  for (listaAux = *primLista1; listaAux != NULL; listaAux = listaAux->prox) {Enquanto não chegar ao fim da lista
    if (listaAux->chave == chave) {//Caso a chave seja encontrada, incrementa mais uma vez e encerra o laço for, pois assim terá sido contado apenas do ínicio até o nó com a chave(profundidade)
      contador++;
      break;
    }
    contador++;
  }
  return contador;//Retorna a profundidade
}
