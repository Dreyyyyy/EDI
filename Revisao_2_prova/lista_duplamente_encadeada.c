#include <stdio.h>
#include <stdlib.h>

struct lista {
    int chave;
    struct lista *ant;
    struct lista *prox;
};
typedef struct lista listaD;

listaD *aloca_no_D(int chave);
int insere_lista_D(listaD **lista, int chave);
void printa_lista_D(listaD*lista);
void remove_lista_D(listaD **lista);

int main(void) {
    int i = 0, chave = 0, ver = 0;
    listaD *lista = NULL;
    printf("=>Insere 5 valores aleatórios no início da lista:\n");
    for (i = 0; i < 5; i++) {
        chave = rand()% 50;
        printf("\n=>Inserindo a chave:%d...\n", chave);
        ver = insere_lista_D(&lista, chave);
        if (ver == 1) printf("\n=>Chave inserida com sucesso.\n");
    }
    printf("\n=>Printa a lista completa:\n");
    printa_lista_D(lista);
    printf("\n=>Remove a lista completa:\n");
    remove_lista_D(&lista);
    printa_lista_D(lista);
    return 0;
}

listaD *aloca_no_D(int chave) {
    listaD *novoNo = NULL;
    novoNo = (listaD*)malloc(sizeof(listaD));
    if (novoNo == NULL) return NULL;
    else {
        novoNo->chave = chave;
        novoNo->ant = NULL;
        novoNo->prox = NULL;
        return novoNo;
    }
}

int insere_lista_D(listaD **lista, int chave) {
    if(*lista == NULL) {
        *lista = aloca_no_D(chave);
        if (*lista == NULL) return 0;
    }
    else {
        listaD *novoNo = NULL;
        novoNo = aloca_no_D(chave);
        novoNo->prox = *lista;
        (*lista)->ant = novoNo;
        *lista = novoNo;
    }
    return 1;
}

void printa_lista_D(listaD *lista) {
    if (lista == NULL) printf("\n=>Lista vazia!\n");
    else {
        do {
            printf("\nChave:%d\n", lista->chave);
            lista = lista->prox;
        }while(lista != NULL);
    }
}

void remove_lista_D(listaD **lista) {
    if (*lista == NULL) return;
    else {
        listaD *noAux = NULL;
        noAux = *lista;
        *lista = (*lista)->prox;
        free(noAux);
        noAux = NULL;
        remove_lista_D(lista);
    }
}
