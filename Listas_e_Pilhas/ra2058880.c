#include "bib.h"

// Recebe como parametro de entrada uma fila ou pilha x
// e cria um no cabeca em x.
int Cabeca(InicioFim *x) {
	TipoCelula *filaAux = (TipoCelula*)malloc(sizeof(TipoCelula));
	if (filaAux == NULL) {
		return 0;
	}
	else {
		aux->prox = NULL;
		x->inicio = x->fim = aux;
		return 1;
	}	 
}

// Recebe como parametro de entrada uma fila ou pilha x
// e verifica se x esta vazia.
int Vazia(InicioFim *x) {
	if (x->inicio->prox == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

// Recebe como parametro de entrada uma fila f e um inteiro k.
// Insere um item na fila f com valor chave k.
int InsereFila(InicioFim *f, int k) {
	TipoCelula *filaAux = (TipoCelula*)malloc(sizeof(TipoCelula));
	if (filaAux == NULL) {
		return 0;
	}
	else {
		filaAux->chave = k;
		filaAux->prox = NULL;
		f->fim = filaAux;
		f->fim->prox = filaAux;
		return 1;
	}
}

// Recebe como parametro de entrada uma fila f.
// Remove um item da fila f.
int RemoveFila(InicioFim *f) {
	if (Vazia(f) == 1) {
		return 0;
	}
	else {
		TipoCelula = *filaAux = f->inicio;
		f->inicio = f->inicio->prox;
		freeAux(filaAux);
		return 1;
	}
}

// Recebe como parametro de entrada uma fila f.
// Remove todos os itens da fila f.
int FFVazia(InicioFim *f) {
	while (Vazia(f) != 1) {
		RetiraFila(f);
	}	
	return 1;
}

// Recebe como parametro de entrada uma fila f.
// Imprime todos os elementos de f.
void ImprimeFila(InicioFim *f) {
	TipoCelula *filaAux = f->inicio->prox;
	int no = 0;
	else {
		while (filaAux != NULL) {
			printf("%dº nó, chave: %d\n", no+1, filaAux->chave);
			filaAux = filaAux->prox;
			no++;
		}
	}
}

// Lista de Exercicios de Fila e Pilha

// Exercicio 1:
/*1. Escreva uma função que recebe como
parâmetro de entrada duas filas, f e g,
e retorna f concatenada com g.*/
InicioFim *ConcatenaPilha(InicioFim *f, InicioFim *g) {
	TipoCelula *filaAuxF = f->inicio->prox, *filaAuxG = g->inicio->prox;
	if (Vazia(f) == 1 || Vazia(g) == 1) return 0;
	else {
			
	}	
}


