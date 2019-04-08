#include <stdio.h>
#include <stdlib.h>

/*
16.
Escreva uma função double* max(double* a, int size) que retorne um ponteiro para
o maior valor contido em um array de elementos do tipo double, se o array estiver vazio,
retorne NULL.*/

double *max(double* a, int size);

int main() {
	int tam = 0, i = 0;
	printf("\nDigite o tamanho do array: \n");
	scanf("%d", &tam);
	double array[tam], *arrayP = NULL;
	for (i = 0; i < tam; i++) {
		printf("\nDigite o %dº elemento do array: ", i+1);
		scanf("%lf", &array[i]);
	}
	arrayP = max(array, tam);
	if (arrayP == NULL) printf("\nArray vazio!\n\n");
	else printf("\nMaior valor: %.2lf\n\n", *arrayP);
	return 0;
}

double *max(double* a, int size) {
	double maior = 0, *maiorP;
	int i = 0;
	for (i= 0; i < size; i++) {
		if (maior < a[i]) {
			*maiorP = a[i];
			maior = a[i];
		}
	}
	if (maior == 0) {
		return NULL;
	}
	else {
		return maiorP;
	}
}
