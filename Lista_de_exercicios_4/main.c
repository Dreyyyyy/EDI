#include "lib.h"

int main() {
    TipoListaSimples *prim = NULL, *busca = NULL, *prim2 = NULL, *prim3 = NULL;
    int chave = 0, valor = 0, chaveB = 0, cont = 0;
    printf("\n=>Insere cinco valores aleatórios no ínicio da lista 1:\n");
    for (chave = 5; chave > 0; chave--) {
        valor = rand () % 50;
        insereInicioListaSimples(&prim, chave, valor);
    }
    printa_lista(prim);
    printf("\n=>Atualiza valor do primeiro nó para 19:\n");
    atualizaValor(prim, 19);
    printa_lista(prim);
    printf("\n=>Remove o primeiro nó da lista 1:\n");
    removePrimeiroNo(&prim);
    printa_lista(prim);
    printf("\n=>Pesquisa pela chave da lista 1:");
    scanf("%d", &chaveB);
    printf("\n");
    busca = pesquisaNo(prim, chaveB);
    if (busca != NULL) {
        printf("\nNó encontrado! Valor do nó: %d\n", busca->valorQualquer);
    }
    else {
        printf("\nNó não encontrado.\n");
    }
    printf("\n=>Insere cinco valores aleatórios no fim da lista 1:\n");
    for (chave = 6; chave <= 10; chave++) {
        valor = rand () % 50;
        insereFimListaSimples(&prim, chave, valor);
    }
    printa_lista(prim);
    printf("\n=>Remove o último nó da lista 1:\n");
    removeUltimoNo(&prim);
    printa_lista(prim);
    printf("\n=>Cria uma cópia da lista 1:\n");
    prim2 = copiaListas(prim);
    printa_lista(prim2);
    printf("\n=>Cria uma terceira lista com a interseção entre as duas primeiras:\n");
    prim3 = intersecaoListas(prim, prim2);
    printa_lista(prim3);
    printf("\n=>Remove o último nó da lista 2 e insere na última posição da lista 1:\n");
    insereRemove(&prim, &prim2);
    printf("\nLista 2:\n");
    printa_lista(prim2);
    printf("\nLista 1:\n");
    printa_lista(prim);
    printf("\nTransplanta o último nó da lista 2 para a última posição da lista 1:\n");
    transplantaNo(&prim, &prim2);
    printf("\nLista 2:\n");
    printa_lista(prim2);
    printf("\nLista 1:\n");
    printa_lista(prim);
    printf("\n=>Número de nós da lista 1:\n");
    cont = contaNo(&prim);
    printf("\n%d Nós\n", cont);
    printf("\n=>Altura dos nós da lista 1 a partir da chave: ");
    scanf("%d", &chave);
    cont = alturaNo(&prim, chave);
    printf("\nAltura:%d\n", cont);
    printf("\n=>Profundidade dos nós da lista 1 a partir da chave: ");
    scanf("%d", &chave);
    cont = profundidadeNo(&prim, chave);
    printf("\nProfundidade:%d\n", cont);
    printf("\n=>Remove todos os nós da lista 1:\n");
    liberaNos(&prim);
    printa_lista(prim);
    return 0;
}
