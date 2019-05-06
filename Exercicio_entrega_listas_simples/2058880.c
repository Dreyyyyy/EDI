#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;
typedef int TipoValor;

struct TipoListaSimples {
 TipoChave chave;
 TipoValor valorQualquer;
 struct TipoListaSimples *prox;
};typedef struct TipoListaSimples TipoListaSimples;

TipoListaSimples *aloca_no(TipoChave chave, TipoValor valor);
void printa_lista(TipoListaSimples *prim);
TipoListaSimples *insereFimListaSimples(TipoListaSimples **prim, TipoChave chave, TipoValor valor);
void removeUltimoNo(TipoListaSimples **prim);
void liberaNos(TipoListaSimples **prim);
TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave);

int main(void) {
    TipoListaSimples *prim = NULL, *busca = NULL;
    int chave = 0, valor = 0;
    printf("\n=>Insere cinco valores aleatórios no fim da lista(recursivo):\n");
    for (chave = 5; chave > 0; chave--) {
        valor = rand () % 50;
        insereFimListaSimples(&prim, chave, valor);
    }
    printa_lista(prim);
    printf("\n=>Pesquisa pelo nó cujo a chave é: ");
    scanf("%d", &chave);
    busca = pesquisaNo(prim, chave);
    if (busca != NULL) {
        printf("\nChave %d encontrada!\n", busca->chave);
    }    
    else {
        printf("\nChave não encontrada.\n");
    }
    printf("\n=>Libera todos os nós!\n");
    liberaNos(&prim);
    printa_lista(prim);
    return 0;
}

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
        return aux;//Retorna o endereço alocado para este nó
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

TipoListaSimples *insereFimListaSimples(TipoListaSimples **prim, TipoChave chave, TipoValor valor) {
    if (*prim == NULL) {
      *prim = aloca_no(chave, valor);//Caso base: Quando o endereço passado é NULL, aloca um novo nó
    }
    else {
        insereFimListaSimples(&(*prim)->prox, chave, valor);//Caso recursivo: Passa o endereço do próximo nó da lista
    }
    return *prim;//Retorna o nó inserido
}

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

void liberaNos(TipoListaSimples **prim) {
  if (*prim == NULL) {//Caso base: Quando a lista estiver vazia, encerra a função
    return;
  }
  else {
    removeUltimoNo(&(*prim));//Remove os nós pelo final da lista
  }
  liberaNos(&(*prim));//Caso recursivo: Remove nó por nó, até cair no caso base e encerrar a função
}

TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave) {
    if (prim == NULL) {//Caso base: Caso chegar ao fim e retornar nulo, a chave não está na lista
        return NULL;
    }
    else if (prim->chave == chave) {//Caso base 2: Caso o elemento for encontrado, retorna o endereço deste
        return prim;
    }
    else {//Caso recursivo: Empilha a função passando o ponteiro para o próximo da lista, até cair em um dos casos base
        pesquisaNo(prim->prox, chave);
    }
}
