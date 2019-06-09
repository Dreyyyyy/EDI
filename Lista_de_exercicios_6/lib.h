#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
* Faça uma biblioteca para as definições
* abaixo especificadas.
*/
typedef int TipoChave;
typedef int TipoValor;
struct TipoListaCircular
{
 TipoChave chave;
 TipoValor valorQualquer;
 struct TipoListaCircular *prox;
};
typedef struct TipoListaCircular TipoListaCircular;

TipoListaCircular *aloca_no(int chave, int valor);

void printa_lista(TipoListaCircular *listaC);

void remove_prim(TipoListaCircular **prim);

TipoListaCircular *insereInicioListaCircular(TipoListaCircular **prim, TipoChave chave, TipoValor valor);

int removeNo(TipoListaCircular **prim, TipoChave chave);

TipoListaCircular *copiaListaPar(TipoListaCircular *prim);
