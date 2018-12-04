/*12. Escrever um procedimento que faça a União de dois vetores dinâmicos(C = A B).
Lembre-se de liberar a memória dos vetores A e B após a concatenação.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *aloca_vetor(int tam);
int *concatena_vetores(int *v1, int *v2, int tam, int tam2);

int main() {
	int tam = 0, tam2 = 0, *v1 = NULL, *v2 = NULL, *v3 = NULL, i;
	printf("\nInforme o tamanho do primeiro vetor: ");
	scanf("%d", &tam);
	v1 = aloca_vetor(tam);
	printf("Vetor 1:\n");
	for (i = 0; i < tam; i++) {
		*(v1+i) = rand () % 50;
		printf("%d ", *(v1+i));
	}		
	printf("\n\n");
	printf("Informe o tamanho do segundo vetor: ");
	scanf("%d", &tam2);
	v2 = aloca_vetor(tam2);
	printf("Vetor 2:\n");
	for (i = 0; i < tam2; i++) {
		*(v2+i) = rand () % 50;
		printf("%d ", *(v2+i));
	}		
	printf("\n\n");	
	printf("Vetores concatenados:\n");
	v3 = concatena_vetores(v1, v2, tam, tam2);
	for (i = 0; i < (tam+tam2); i++) {
		printf("%d ", *(v3+i));
	}
	printf("\n\n");
	free(v2);
	v2 = NULL;
	free(v1);
	v1 = NULL;
	if (v1 == NULL && v2 == NULL) printf("Vetores 1 e 2 liberados.\n\n");
	return 0;
}

int *aloca_vetor(int tam) {
	int *v = (int*)malloc(sizeof(int) * tam);
	if (v == NULL) return NULL;
	else return v;
}

int *concatena_vetores(int *v1, int *v2, int tam, int tam2) {
	int tam3 = tam+tam2, i, j, k, *v3 = NULL;
	v3 = aloca_vetor(tam3);
	for (i = 0; i < tam; i++) {
		v3[i] = v1[i];
	}
	for (j = i, k = 0; k < tam2; k++, j++) {
		v3[j] = v2[k];
	}
	return v3;
}
