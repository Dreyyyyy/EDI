#include "bib.h"

int main(void) {
    TipoListaSimples *lista = NULL, *busca = NULL, *lista2 = NULL;
    int i = 0, chave = 0;
    lista = criaLista();
    printf("=>Verificando se o nó cabeça foi criado com sucesso:\n");
    if (lista == NULL) {
        printf("O S.O não conseguiu alocar memória.\n");
    }
    else {
        printf("Lista criada com sucesso!\n");
    }
    printf("\n=>Insere 5 valores aleatórios na lista(pelo início):\n");
    for (i = 0; i < 5; i++) {
        chave = rand () % 50;
        printf("Chave gerada:%d\n", chave);
        insereInicioListaSimples(lista, chave); 
    }
    printf("\n=>Printa a lista(incluindo o nó cabeça, apenas para a verificação):\n");
    printa_lista(lista);
    printf("\n=>Remove o primeiro nó da lista, caso ele exista:\n");
    removePrimeiroNo(lista);
    printa_lista(lista);
    printf("\n=>Busca pelo nó cujo a chave é: ");
    scanf("%d", &chave);
    busca = pesquisaNo(lista, chave);
    if (busca == NULL){
        printf("\nNó não encontrado.\n");
    }
    else {
        printf("\nNó %d encontrado!\n", busca->chave);
    }
    printf("\n=>Insere 5 valores aleatórios na lista (pelo fim):\n");
    for (i = 0; i < 5; i++) {
        chave = rand () % 50;
        printf("Chave gerada:%d\n", chave);
        insereFimListaSimples(lista, chave);
    }
    printf("\n=>Printa a lista (incluindo o nó cabeça, apenas para a verificação):\n");
    printa_lista(lista);
    printf("\n=>Remove o último nó da lista, caso ele exista:\n");
    removeUltimoNo(lista);
    printa_lista(lista);
    printf("\n=>Remove o nó cuja chave é: ");
    scanf("%d", &chave);
    removeNo(lista, chave);
    printa_lista(lista);
    printf("\n=>Remove todos os nós da lista, exceto o nó cabeça:\n");
    liberaNos(lista);
    printa_lista(lista);
    printf("\n=>Remove todos os nós da lista, inclusive o nó cabeça:\n");
    liberaTudo(&lista);
    printa_lista(lista);
    return 0;
}
