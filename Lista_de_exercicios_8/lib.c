#include "lib.h"

iniciofim *aloca() {
    iniciofim *aux = NULL;
    aux = (iniciofim*)malloc(sizeof(iniciofim));
    if (aux == NULL) NULL;
    else return aux;
}

void printa_fila(iniciofim *fila) {
    if (verifica_vazia_fila(fila) == 1) printf("Fila vazia!\n");
    else {
        no *filaAux = NULL;
        filaAux = fila->ini->prox;
        do {
            printf("Chave: %d\n", filaAux->chave);
            filaAux = filaAux->prox;
        }while(filaAux != NULL);
    }
}

int cria_cabeca(iniciofim *fila) {
    no *cabeca = NULL;
    cabeca = (no*)malloc(sizeof(no));
    if (cabeca == NULL) return 0;
    else {
        cabeca->chave = -1;
        cabeca->prox == NULL;
        fila->ini = cabeca;
        fila->fim = cabeca;
        return 1;
    }
}

int verifica_vazia_fila(iniciofim *fila) {
    if (fila->ini->prox == NULL) return 1;
    else return 0;
}

int insere_ini_fila(iniciofim *fila, int chave) {
    no *novoNo = NULL;
    novoNo = (no*)malloc(sizeof(no));
    if (novoNo == NULL) return 0;
    else {
        novoNo->chave = chave;
        novoNo->prox = NULL;
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
        return 1;
    }
}

int remove_ini_fila(iniciofim *fila) {
    if (verifica_vazia_fila(fila) == 1) return 0;
    else {
        no *aux = NULL;
        aux = fila->ini;
        fila->ini = fila->ini->prox;
        free(aux);
        aux = NULL;
        return 1;
    }
}

int remove_toda_fila(iniciofim *fila) {
    if (verifica_vazia_fila(fila) == 1) return 0;
    else {
        while(verifica_vazia_fila(fila) != 1) {
            remove_ini_fila(fila);
        }
        return 1;
    }
}

void printa_pilha(iniciofim *pilha) {
    if (verifica_vazia_pilha(pilha) == 1) printf("Pilha vazia!\n");
    else {
        no *pilhaAux = NULL;
        pilhaAux = pilha->fim;
        do {
            printf("Chave:%d\n", pilhaAux->chave);
            pilhaAux = pilhaAux->prox;
        }while (pilhaAux->chave != -1);
    }
}

int verifica_vazia_pilha(iniciofim *pilha) {
    if (pilha->ini == pilha->fim) return 1;
    else return 0;
}

int insere_topo_pilha(iniciofim *pilha, int chave) {
    no *novoNo = NULL;
    novoNo = (no*)malloc(sizeof(no));
    if (novoNo == NULL) return 0;
    else {
        novoNo->chave = chave;
        novoNo->prox = pilha->fim;
        pilha->fim = novoNo;
        return 1;
    }
}

int remove_topo_pilha(iniciofim *pilha) {
    if (verifica_vazia_pilha(pilha) == 1) return 0;
    else {
        no *aux = NULL;
        aux = pilha->fim;
        pilha->fim = pilha->fim->prox;
        free(aux);
        aux = NULL;
        return 1;
    }
}

int remove_toda_pilha(iniciofim *pilha) {
    if (verifica_vazia_pilha(pilha) == 1) return 0;
    else {
        while (verifica_vazia_pilha(pilha) != 1) {
            remove_topo_pilha(pilha);
        }
        return 1;
    }
}

//Exercícios:
//1. Escreva uma função que recebe como parâmetro de entrada duas filas, f e g, e retorna f concatenada com g.
iniciofim *concatena_filas(iniciofim *f, iniciofim *g) {
    f->fim->prox = g->ini->prox;
    f->fim = g->fim;
    g->ini->prox = NULL;
    g->fim = NULL;
    free(g);
    g = NULL;
    return f;
}

//2. Escreva uma função que recebe comoparâmetro de entrada duas pilhas, p e q,e retorna p concatenada com q.
iniciofim *concatena_pilhas(iniciofim *p, iniciofim *q) {
    no *noAux = NULL;
    while (verifica_vazia_pilha(q) != 1) {
        noAux = q->fim;
        q->fim = q->fim->prox;
        noAux->prox = p->fim;
        p->fim = noAux;
    }
    free(q);
    q = NULL;
    return p;
}

//3. Escreva uma função que recebe comoparâmetro de entrada uma fila f e uma pilha p, e retorna f concatenada com p.
iniciofim *concatena_fila_pilha(iniciofim *f, iniciofim *p) {
    no *noAux = NULL;

    while (verifica_vazia_pilha(p) != 1) {
        noAux = p->fim;
        p->fim = p->fim->prox;
        noAux->prox = NULL;
        f->fim->prox = noAux;
        f->fim = noAux;
    }
    free(p);
    p = NULL;
    return f;
}

//4. Escreva uma função que recebe como parâmetro de entrada uma pilha p e uma fila f, e retorna p concatenada com f.
