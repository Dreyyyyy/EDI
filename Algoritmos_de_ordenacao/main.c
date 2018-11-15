/* Aleffer Rocha, 14 de novembro de 2018 */

#include "ordenacao.h"
#include <time.h>

int main(void) {
    int n, i, alg;
    int *vetor;

    while(1){
        puts("\nDigite a quantidade de elementos no vetor:");
        scanf("%d", &n);
        vetor = (int *) malloc(sizeof(int)*n);
        srand(time(NULL));

        for(i = 0; i < n; i++) {
            vetor[i] = rand() % 100;
        }

        puts("Vetor fora de ordem");
        for(i = 0; i < n; i++) {
            printf("%d  ", vetor[i]);
        }

        puts("\n");

        printf("1 - Bubble Sort\n");
        printf("2 - Selection Sort\n");
        printf("3 - Insertion Sort\n");
        printf("4 - Quick Sort\n");
        printf("5 - Shell Sort\n");
        printf("6 - Merge Sort\n");
        printf("0 - Encerra o programa\n");

        puts("\n");

        printf("\nEscolha o algoritmo de ordenacao: ");
        scanf("%d", &alg);
        switch (alg) {
            case 1:
                BubbleSort(vetor, 0, n-1);
                break;
            case 2:
                SelectionSort(vetor, 0, n-1);
                break;
            case 3:
                InsertionSort(vetor, 0, n-1);
                break;
            case 4:
                QuickSort(vetor, 0, n-1);
                break;
            case 5:
                ShellSort(vetor, 0, n-1);
                break;
            case 6:
                MergeSort(vetor, 0, n-1);
                break;
            case 0:
                return 0;
        }

        puts("");

        puts("Vetor ordenado");
        for(i = 0; i < n; i++) {
            printf("%d  ", vetor[i]);
        }

    }

    return 0;

}
