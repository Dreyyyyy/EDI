/*13. Fazer um programa contendo as seguintes funções:
Leitura: lê um vetor de números inteiros positivos
Separa: separa os elementos do vetor em dois vetores, sendo que um deles conterá
os números pares e o outro os números ímpares. Todos os vetores dinâmicos. 
Não esqueça de liberar memória quando possível.
Imprime: exibe na tela os elementos contidos no vetor passado por parâmetro.*/

#include <stdio.h>
#include <stdlib.h>

int *aloca_vetor(int tam);
void separa_vetores(int *v, int tam);

int main() {
	int tam, i;
	printf("\nDigite o número de elementos do vetor: ");
	scanf("%d", &tam);
	printf("\n");
	int *v = aloca_vetor(tam);
	for (i = 0; i < tam; i++) {
		printf("%dº elemento: ", i+1);
		scanf("%d", &v[i]);
	}
	printf("\nVetor completo:\n\n");
	for (i = 0; i < tam; i++) {
		printf("%d ", v[i]);
	}	
	printf("\n\n");
	separa_vetores(v, tam);
	free(v);
	v = NULL;
	if (v == NULL) printf("\nVetor v liberado.\n\n");
	return 0;
}

int *aloca_vetor(int tam) {
	int *v = (int*)malloc(sizeof(int) * tam);
	if (v == NULL) printf("O S.O não alocou memória!\n");
	else return v;
}

void separa_vetores(int *v, int tam) {
	int *par = NULL, *impar = NULL, imp = 0, p = 0, i, j;
	for (i = 0; i < tam; i++) {
		if (v[i] % 2 == 0) p++;
		else imp++;
	}
	par = aloca_vetor(p);
	impar = aloca_vetor(imp);
	for (i = 0, j = 0; i < tam; i++) {
		if (v[i] % 2 == 0) {
			par[j] = v[i];
			j++;
		}
	}
	for (i = 0, j = 0; i < tam; i++) {
		if (v[i] % 2 != 0) {
			impar[j] = v[i];
			j++;
		}
	}
	printf("Vetor par:\n\n");	
	for (i = 0; i < p; i++) {
		printf("%d ", par[i]);
	}	
	free(par);
	par = NULL;
	printf("\n\n");	
	printf("Vetor impar:\n\n");	
	for (i = 0; i < imp; i++) {
		printf("%d ", impar[i]);
	}	
	free(impar);
	impar = NULL;
	printf("\n\n");
	if (par == NULL && impar == NULL) printf("\nVetores impar e par foram liberados.\n");		
}
