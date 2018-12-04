/*8. Escreva uma função mm que receba um ponteiro para um vetor inteiro v[0..n-1], 
o número de elementos do vetor (n) e os endereços de duas variáveis inteiras, min e Max.
Deposite nessas variáveis o valor de um elemento mínimo e o valor de um elemento máximo do vetor. 
Escreva também uma função main que use a função mm*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *aloca_ponteiro();
void mm (int *v, int n, int *min, int *max);

int main() {
	int n = 0, i, min = 0, max = 0;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	int v[n];
	printf("Elementos do vetor:\n");
	for (i = 0; i < n; i++) {
		v[i] = rand () % 50;
		printf("%d ", *(v+i));
	}
	printf("\n");
	mm(v, n, &min, &max);
	printf("Valor mínimo: %d\nValor máximo: %d\n", min, max);
	return 0;
}

int *aloca_ponteiro(int *ponteiro) {
	int *p = (int*)malloc(sizeof(int));
	if (p == NULL) return NULL;
	else {
		return p;
	} 
}

void mm (int *v, int n, int *min, int *max) {
	int i;
	*min = v[0];
	for (i = 0; i < n; i++) {
		if (*(v+i) <= *min) {
			*min = *(v+i);
		}
		if (*(v+i) >= *max) {
			*max = *(v+i);
		}
	}
}

