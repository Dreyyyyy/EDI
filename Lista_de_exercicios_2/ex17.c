/*17. 
Fazer um procedimento que recebe como parâmetro uma matriz com 4 notas de 20 
alunos e um vetor de 20 posições. Esta função deve encontrar a média de cada aluno e 
armazenar em sua respectiva posição no vetor. Ao final (no main()) 
deverá imprimir a média de cada aluno contida no vetor. Protótipo: 
void calcula_media(float *matriz, float *vetor).
//E para uma matriz de tamanho n ??*/

#include <stdio.h>
#include <stdlib.h>

void calcula_media(float matriz[20][4], float *vetor);

int main() {
	float notas[20][4], media[20];
	int i = 0, j = 0;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 4; j++) {
			printf("\nDigite a %dº nota do %dº aluno: ", j+1, i+1);
			scanf("%f", &notas[i][j]);
		}
		printf("\n");
	}	
	calcula_media(notas, media);
	for (i = 0; i < 20; i++) {
		printf("\nMédia do %dº aluno: %f\n", i+1, media[i]);
		printf("\n");
	}	
	return 0;
}

void calcula_media(float matriz[20][4], float *vetor) {
	int i = 0, j = 0;
	float media = 0;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 4; j++) {
			media += matriz[i][j];
		}
		media /= 4;
		vetor[i] = media;
	}	
}
