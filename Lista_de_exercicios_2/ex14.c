#include <stdio.h>
#include <stdlib.h>

/*14.
Escreva uma função que calcule o perímetro de um retângulo (P=2b+2h). A função
deverá retornar o valor do perímetro calculado. Após o cálculo do perímetro altere o
valor das variáveis base e altura para: b=2*b e h=2*h. No programa principal imprima 
o valor do perímetro calculado e os novos valores da base e da altura.
OBS: Utilize passagem de parâmetros por referência.
Protótipo: float perímetro(float *a, float *b)*/

float perimetro(float *a, float *b);

int main() {
	float b = 0, h = 0, P = 0;
	printf("\nDigite o valor da base e da altura, sequencialmente: ");
	scanf("%f%f", &b, &h);
	P = perimetro(&b, &h);
	printf("\nPerímetro = %.2f, base e altura multiplicados por 2: b = %.2f e h = %.2f\n\n", P, b, h);
	return 0;
}

float perimetro(float *a, float *b) {
	float temp = 0;
	temp = 2 *(*a) + 2 *(*b);
	*a = 2 *(*a);
	*b = 2 *(*b);
	return temp;
}
