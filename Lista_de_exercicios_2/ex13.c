#include <stdio.h>
#include <stdlib.h>

/*13.
Faça um programa que leia 2 valores inteiros e chame uma função que receba estas
2 variáveis e troque o seu conteúdo, ou seja, esta função é chamada passando duas
variáveis A e B por exemplo e, após a execução da função, A conterá o valor de B e B
terá o valor de A.
OBS: resolvido no slide de aula... é ó testar!*/

void troca_valores(int *A, int *B);

int main() {
    int A = 0, B = 0;
    printf("\nDigite 2 números inteiros seguidos: ");
    scanf("%d%d", &A, &B);
    printf("\nValores: A = %d e B = %d\n", A, B);
    troca_valores(&A, &B);
    printf("\nValores trocados: A = %d e B = %d\n\n", A, B);
    return 0;
}

void troca_valores(int *A, int *B) {
    int aux = 0;
    aux = *A;
    *A = *B;
    *B = aux;
}
