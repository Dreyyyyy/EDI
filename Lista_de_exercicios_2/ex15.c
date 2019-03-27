#include <stdio.h>
#include <stdlib.h>

/*15.
Crie uma função que receba um ponteiro para um array de float com 10 elementos.
Imprima o endereço de cada posição desse array. */

void imprime_endereco(float *array);

int main() {
	float array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	imprime_endereco(array);
	return 0;
}

void imprime_endereco(float *array) {
	int i = 0;
	for (i = 0; i < 10; i++) {
		printf("\nEndereço do índice %d: %p\n", i+1, &array[i]);
	}
	printf("\n");
}
