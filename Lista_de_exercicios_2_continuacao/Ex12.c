/*
12. Escrever um procedimento que faça a União de dois vetores dinâmicos(C = A U B). Lembre-se de liberar a memória dos vetores A e B após a concatenação.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *aloca(int tam);
void desaloca(int *ponteiro);
void une_vetores(int *A, int *B, int tam, int tam1, int tam2);

int main () {
    int *A = NULL, *B = NULL, tam1 = 0, tam2 = 0, tam = 0, i = 0;
    printf("Informe o número de elementos desejados para o vetor A: ");
    scanf("%d", &tam1);
    printf("Informe o número de elementos desejados para o vetor B: ");
    scanf("%d", &tam2);
    tam = tam1 + tam2;
    A = aloca(tam1);//Recebe o endereço de memória alocado pela função
    B = aloca(tam2);//Recebe o endereço de memória alocado pela função
    for (i = 0; i < tam1; i++) {
        *(A+i) = rand() % 50;        
    }
    printf("Vetor A:\n");
    for (i = 0; i < tam1; i++) {
        printf("%d ", *(A+i));
    }
    printf("\n");
    for (i = 0; i < tam2; i++) {
        *(B+i) = rand() % 50;        
    }
    printf("Vetor B:\n");
    for (i = 0; i < tam2; i++) {
        printf("%d ", *(B+i));
    }
    printf("\n");
    une_vetores(A, B, tam, tam1, tam2);//Passagem por referência dos dois vetores
    free(A);
    A = NULL;//Libera memória do ponteiro local A
    free(B);
    B = NULL;//Libera memória do ponteiro local B
    return 0;
}

int *aloca(int tam) {
    int *aux = NULL;
    aux = (int*)malloc(sizeof(int) * tam);//ponteiro auxiliar recebe um endereço de memória alocado
    if (aux == NULL) {
        return NULL;//Caso não seja alocado, retorna nulo como verificação
    }
    else {
        return aux;//Caso contrário, retorna o endereço ao qual a função "malloc" alocou memória
    }
}


void une_vetores(int *A, int *B, int tam, int tam1, int tam2) {
    int *C = NULL, i = 0, j = 0, iaux = 0;
    C = aloca(tam);
    for (i = 0; i < tam1; i++) {
        *(C+i) = *(A+i);
        iaux++;//Flag para manter o índice de onde o ponteiro C deve continuar a alocar valores
    }
    for (i = iaux, j = 0; j < tam2; j++, i++) {//i continua a alocar valores de B ao ponteiro C de onde parou com o ponteiro A, e j manipula os índices de B
        *(C+i) = *(B+j);
    }  
    free(A);//Libera memória do ponteiro local A
    A = NULL;
    free(B);//Libera memória do ponteiro local B
    B = NULL;
    printf("Vetor C = A U B:\n");
    for (i = 0; i < tam; i++) {
        printf("%d ", *(C+i));
    }
    printf("\n");
}
