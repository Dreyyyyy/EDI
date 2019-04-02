/*1.
Faça um programa que converta coordenadas polares para cartesianas: 
a.
Crie  e  leia  um  ponto  em  coordenada  polar,  composto  por  raio  (r)  e 
argumento (a) em radianos.
b.
Crie  outro  ponto,  agora  em  coordenada  cartesiana,  composto  por  x  e  y, 
sabendo que (x = r.cos a) e (y = r.sin a)
.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct coordenada_polar {
    float r;
    float sen;
    float cos;
}polar;

typedef struct coordenada_cartesiana {
    float x;
    float y;
}cartesiana;

polar *alocaP();
cartesiana *alocaC();
void converte(polar *ponto);

int main() {
    polar *ponto = NULL;
    ponto = alocaP();
    printf("\nDigite o raio da cordenada: ");
    scanf("%f", &ponto->r);
    printf("\nDigite o seno da cordenada: ");
    scanf("%f", &ponto->sen);
    printf("\nDigite o cosseno da cordenada: ");
    scanf("%f", &ponto->cos);
    printf("\nCordenadas polares, r:%.2f, seno:%.2f e cosseno:%.2f\n", ponto->r, ponto->sen, ponto->cos);
    converte(ponto);  
    return 0;
}

polar *alocaP() {
    polar *aux = NULL;
    aux = (polar*)malloc(sizeof(polar));
    if (aux == NULL) return NULL;
    else return aux;
}

cartesiana *alocaC() {
    cartesiana *aux = NULL;
    aux = (cartesiana*)malloc(sizeof(cartesiana));
    if (aux == NULL) return NULL;
    else return aux;
}

void converte(polar *ponto) {
    cartesiana *pontoC = NULL;
    pontoC = alocaC();
    pontoC->x = ponto->r * ponto->cos;
    pontoC->y = ponto->r * ponto->sen;
    printf("\nCordenadas cartesianas, ponto x:%.2f e ponto y:%.2f\n\n", pontoC->x, pontoC->y);     
}
