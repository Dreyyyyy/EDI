#include "lib.h"

int main(void) {
    iniciofim *fila1 = NULL, *fila2 = NULL, *fila3 = NULL, *fila4 = NULL, *pilha1 = NULL, *pilha2 = NULL, *pilha3 = NULL, *pilha4 = NULL;
    int i = 0, chave = 0, op = 0;
    fila1 = aloca();
    fila2 = aloca();
    fila3 = aloca();
    fila4 = aloca();
    pilha1 = aloca();
    pilha2 = aloca();
    pilha3 = aloca();
    pilha4 = aloca();
    cria_cabeca(fila1);
    cria_cabeca(fila2);
    cria_cabeca(pilha1);
    cria_cabeca(pilha2);
    printf("\n=>Inserindo 5 valores aleatórios na fila 1:\n");
    for (i = 0; i < 5; i++) {
        chave = rand() % 100;
        printf("=>Inserindo a chave %d:\n", chave);
        insere_ini_fila(fila1, chave);
    }
    printf("=>Printa a fila completa:\n");
    printa_fila(fila1);
    printf("\n=>Inserindo 5 valores aleatórios na fila 2:\n");
    for (i = 0; i < 5; i++) {
        chave = rand() % 100;
        printf("=>Inserindo a chave %d:\n", chave);
        insere_ini_fila(fila2, chave);
    }
    printf("=>Printa a fila completa:\n");
    printa_fila(fila2);
    printf("\n=>Concatena as duas filas (ou seja, devolve o ponteiro da fila 1, conectada aos elementos da fila 2:\n");
    fila3 = concatena_filas(fila1, fila2);
    printf("=>Printa a fila concatenada:\n");
    printa_fila(fila3);
    printf("\n=>Inserindo 5 valores aleatórios na pilha 1:\n");
    for (i = 0; i < 5; i++) {
        chave = rand() % 100;
        printf("=>Inserindo a chave %d:\n", chave);
        insere_topo_pilha(pilha1, chave);
    }
    printf("=>Printa a pilha completa:\n");
    printa_pilha(pilha1);
    printf("\n=>Inserindo 5 valores aleatórios na pilha 2:\n");
    for (i = 0; i < 5; i++) {
        chave = rand() % 100;
        printf("=>Inserindo a chave %d:\n", chave);
        insere_topo_pilha(pilha2, chave);
    }
    printf("=>Printa a pilha completa:\n");
    printa_pilha(pilha2);
    printf("\n=>Concatena as duas pilhas (ou seja, devolve o ponteiro da pilha 1, conectada aos elementos da pilha 2:\n");
    pilha3 = concatena_pilhas(pilha1, pilha2);
    printf("=>Printa a pilha concatenada:\n");
    printa_pilha(pilha3);
    printf("=>1 - concatenar uma fila com uma pilha (tornando-as uma fila só)\n=>2 - uma pilha com uma fila (tornando-as uma pilha só)\n");
    do {
        printf("=>Digite a opção desejada: ");
        scanf("%d", &op);
    }while(op != 1 || op != 2);
    if (op == 1) {
        printf("\n=>Concatena a fila 3 com a pilha 3 (ou seja, a devolverá o ponteiro da fila 3, conectada aos elementos da pilha 3:\n");
        fila4 = concatena_fila_pilha(fila3, pilha3);
        printf("=>Printa a fila concatenada:\n");
        printa_fila(fila4);
    }
    else if (op == 2) {

    }
    return 0;
}
