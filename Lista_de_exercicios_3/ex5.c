/*5. Faça um programa que leia uma expressão polinomial homogênea (igual a zero). Leia o número n de termose: 
a)Crie e leia um vetor de n termos, sendo que cada termo possui coeficiente, incógnita e expoente. 
b)A expressão pode ter quantas incógnitas o usuário desejar, que deve ser representada por uma letra apenas. 
c)Trate os coeficientes e o expoente como inteiros.
d)Crie um novo vetor, mas simplificando a expressão somando todos os termos com mesma incógnita e mesma potência. 
e)Na sua função main(), mostre a equação original e a equação simplificada.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct expressao_polinomial{
    int coef;
    int exp;
    char incog;
}polinomio;

polinomio *aloca(int n);
polinomio *simplifica_expressao(polinomio *expressao, int n);

int main() {
    int n = 0, i = 0;
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &n);
    setbuf(stdin, NULL);
    polinomio *expressao = NULL, *simplificado = NULL;
    expressao = aloca(n);
    for (i = 0; i < n; i++) {
        printf("\nDigite a incógnita do %dº termo: ", i+1);
        scanf("%c", &(expressao+i)->incog);
        setbuf(stdin, NULL);
        printf("\nDigite o coeficiente do %dº termo: ", i+1);
        scanf("%d", &(expressao+i)->coef);
        setbuf(stdin, NULL);
        printf("\nDigite o expoente do %dº termo: ", i+1);
        scanf("%d", &(expressao+i)->exp);
        setbuf(stdin, NULL);
    }
    printf("\n");
    printf("\nExpressão polinomial:\n");
    for (i = 0; i < n; i++) {
        printf("%d%c^%d + ",(expressao+i)->coef, (expressao+i)->incog, (expressao+i)->exp);
    }
    printf("= 0\n");
    simplificado = simplifica_expressao(expressao, n);
    printf("\n");
    printf("\nExpressão polinomial simplificada:\n");
    for (i = 0; i < n; i++) {
        printf("%d%c^%d + ",(simplificado+i)->coef, (simplificado+i)->incog, (simplificado+i)->exp);
    }
    printf("= 0\n");
    return 0;
}

polinomio *aloca(int n) {
    polinomio *aux = NULL;
    aux = (polinomio*)malloc(sizeof(polinomio) * n);
    if (aux == NULL) return NULL;
    else return aux;
}

polinomio *simplifica_expressao(polinomio *expressao, int n) {
    polinomio *simplificado = NULL;
    int i = 0, j = 0, termos = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((int)(expressao+i)->incog == (int)(expressao+j)->incog) {
                if ((expressao+i)->exp == (expressao+j)->exp) {
                    termos++;
                }
            }
        }
    }
    termos;
    simplificado = aloca(termos);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((int)(expressao+i)->incog == (int)(expressao+j)->incog) {
                if ((expressao+i)->exp == (expressao+j)->exp) {
                    (simplificado+i)->incog = (expressao+i)->incog;
                    (simplificado+i)->exp = (expressao+i)->exp + (expressao+j)->exp;
                    (simplificado+i)->coef = (expressao+i)->coef + (expressao+j)->coef;    
                }
            }
        }
    }
    return simplificado;
}
