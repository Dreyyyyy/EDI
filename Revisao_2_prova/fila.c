#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
    int chave;
    struct Fila *prox;
}Tfila;

struct InicioFim {
    Tfila *ini;
    Tfila *fim;
};
typedef struct InicioFim inifim;

inifim *aloca();
int cria_fila(inifim *fila);
int insere_fila_D(inifim *fila, int chave);
void printa_fila_D(inifim *fila);
void remove_fila_D(inifim *fila);

int main(void) {
    int i = 0, chave = 0, ver = 0;
    inifim *fila = NULL;
    fila = aloca();
    ver = cria_fila(fila);
    if (ver == 0) printf("\n=>O S.O não alocou espaço para a fila.\n");
    else {
        printf("=>Insere 5 valores aleatórios no início da fila:\n");
        for (i = 0; i < 5; i++) {
            chave = rand()% 50;
            printf("\n=>Inserindo a chave:%d...\n", chave);
            ver = insere_fila_D(fila, chave);
            if (ver == 1) printf("\n=>Chave inserida com sucesso.\n");
        }
        printf("\n=>Printa a fila completa:\n");
        printa_fila_D(fila);
        printf("\n=>Remove a fila completa:\n");
        remove_fila_D(fila);
        printa_fila_D(fila);
    }
    return 0;
}

inifim *aloca() {
    inifim *aux = NULL;
    aux = (inifim*)malloc(sizeof(inifim));
    if (aux == NULL) return NULL;
    else return aux;
}

int cria_fila(inifim *fila) {
    Tfila *cabeca = NULL;
    cabeca = (Tfila*)malloc(sizeof(Tfila));
    if (cabeca == NULL) return 0;
    else {
        cabeca->chave = -1;
        cabeca->prox = NULL;
        fila->ini = cabeca;
        fila->fim = cabeca;
    }
    return 1;
}

int insere_fila_D(inifim *fila, int chave) {
    Tfila *novoNo = NULL;
    novoNo = (Tfila*)malloc(sizeof(Tfila));
    if (novoNo == NULL) return 0;
    else {
        novoNo->chave = chave;
        novoNo->prox = NULL;
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
    return 1;
}

void printa_fila_D(inifim *fila) {
    if (fila->ini == NULL) printf("\n=>Fila sem cabeça!\n");
    else if (fila->ini->prox == NULL) printf("\n=>Fila vazia!\n");
    else {
        Tfila *aux = NULL;
        aux = fila->ini->prox;
        do {
            printf("=>Chave:%d\n", aux->chave);
            aux = aux->prox;
        }while(aux != NULL);
    }
}

void remove_fila_D(inifim *fila) {
    if (fila->ini->prox == NULL) return;
    else { 
        while(fila->ini != NULL) {
            Tfila *noAux = NULL;
            noAux = fila->ini;
            fila->ini = fila->ini->prox;
            free(noAux);
            noAux = NULL;
        }
    }
}
