#include <stdio.h>
#include <stdlib.h>

typedef struct numero_complexo {
	float real;
	int imaginario;
}complexo;

complexo *aloca(int n);
void imprime(complexo *vetor_complexos, int n);
void copia(complexo *vetor_complexos, int n);
void soma(complexo *vetor_complexos, int n);
void teste_real(complexo *vetor_complexos, int n);

int main () {
	int i = 0;
	complexo *vetor_complexos = NULL;
	printf("\n=>Atribui:\n");
	vetor_complexos = aloca(3);
	for (i = 0; i < 2; i++) {
		printf("\nDigite o número real do %dº número complexo: ", i+1);
		scanf("%f", &(vetor_complexos+i)->real);
		printf("\nDigite o número imaginário do %dº número complexo: ", i+1);
		scanf("%d", &(vetor_complexos+i)->imaginario);
	}	
	printf("\n=>Imprime os números complexos:\n");
	imprime(vetor_complexos, 2);
	printf("\n=>Copia o valor de um número para outro:\n");
	copia(vetor_complexos, 2);
	imprime(vetor_complexos, 2);
	printf("\n=>Soma dois números complexos:\n");
	soma(vetor_complexos, 3);
	imprime((vetor_complexos+2), 1);
	printf("\n=>Testa se o número é real:\n");
	teste_real(vetor_complexos, 2);
	return 0;
}

complexo *aloca(int n) {
	complexo *aux = NULL;
	aux = (complexo*)malloc(sizeof(complexo) * n);
	if (aux == NULL) return NULL;
	else return aux;
}

void imprime(complexo *vetor_complexos, int n) {
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("%.2f + %di\n", (vetor_complexos+i)->real, (vetor_complexos+i)->imaginario);	
	}
}		

void copia(complexo *vetor_complexos, int n) {
	complexo *aux = NULL;
	aux = aloca(1);
	aux->real = (vetor_complexos+0)->real;
	aux->imaginario = (vetor_complexos+0)->imaginario;
	(vetor_complexos+0)->real = (vetor_complexos+1)->real;
	(vetor_complexos+0)->imaginario = (vetor_complexos+1)->imaginario;
	(vetor_complexos+1)->real = aux->real;
	(vetor_complexos+1)->imaginario = aux->imaginario;
	free(aux);
	aux = NULL;
}

void soma(complexo *vetor_complexos, int n) {
	(vetor_complexos+2)->real = (vetor_complexos+0)->real + (vetor_complexos+1)->real;
	(vetor_complexos+2)->imaginario = (vetor_complexos+0)->imaginario + (vetor_complexos+1)->imaginario;
}

void teste_real(complexo *vetor_complexos, int n) {
	int i = 0;
	for (i = 0; i < n; i++) {
		if ((int)(vetor_complexos+i)->real == (vetor_complexos+i)->real) {
			printf("\nO número do campo real, no %dº número complexo não é real.\n\n", i+1);
		} 
		else printf("\nO número do campo real, no %dº número complexo é real!\n\n", i+1);
	}	
}
