#include <stdio.h>
#include <stdlib.h>

/*13. 
Fazer um programa contendo as seguintes funções:
Leitura: lê um vetor de números inteiros positivos.
Separa: separa os elementos do vetor em dois vetores, sendo que um deles conterá os números pares e o outro os números ímpares. Todos os vetores dinâmicos. 
Não esqueça de liberar memória quando possível.
Imprime: exibe na tela os elementos contidos no vetor passado por parâmetro.*/

int *aloca_vetor(int tam);
void separa_vetor(int tam, int *v);
void libera_vetor(int **v);

int main() {
    int tam = 0, i = 0;
    printf("\nInforme o tamanho do vetor: ");
    scanf("%d", &tam);
    int *v = aloca_vetor(tam);
    for (i = 0; i < tam; i++) {
        printf("\n\nDigite o %dº número do vetor: ", i+1);
        scanf("%d", &(*(v+i)));
    }
    printf("\nPrintando o vetor completo:\n");
    for (i = 0; i < tam; i++) {
        printf("%d ", *(v+i));
    }
    printf("\n");
    separa_vetor(tam, v);
    return  0;
}

int *aloca_vetor(int tam) {
    int *v = NULL;
    v = (int*)malloc(sizeof(int) * tam);
    if (v == NULL) printf("\nO S.O não conseguiu alocar memória!\n\n");
    else return v;
}

void separa_vetor(int tam, int *v) {
    int i = 0, j = 0, *v_par = NULL, *v_impar = NULL, cont_par = 0, cont_impar = 0;
    for (i = 0; i < tam; i++) {
        if (*(v+i) % 2 == 0) {
            cont_par++;
        }
        else {
            cont_impar++;
        }
    }
    v_par = aloca_vetor(cont_par);
    v_impar = aloca_vetor(cont_impar);
	for (i = 0, j = 0; i < tam; i++) {
		if (*(v+i) % 2 == 0) {
			*(v_par+j) = *(v+i);
			j++;
		}
	}
	for (i = 0, j = 0; i < tam; i++) {
		if (*(v+i) % 2 != 0) {
			*(v_impar+j) = *(v+i);
			j++;
		}
    }
    libera_vetor(&v);
	printf("\nVetor par:\n\n");	
	for (i = 0; i < cont_par; i++) {
		printf("%d ", *(v_par+i));
    } 
	printf("\nVetor impar:\n\n");	
	for (i = 0; i < cont_par; i++) {
		printf("%d ", *(v_impar+i));
    }
    printf("\n\n");
}

void libera_vetor(int **v) {
    free(*v);
    *v = NULL;
}

