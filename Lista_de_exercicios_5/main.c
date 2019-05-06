#include "bib.h"

int main(void) {
    TipoListaSimples *lista = NULL, *busca = NULL, *lista2 = NULL, *lista3 = NULL, *lista4 = NULL;
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
    printf("\n=>Cria uma segunda lista, que é a cópia da primeira:\n");
    lista2 = copiaListas(lista);
    printa_lista(lista2); 
    printf("\n=>Cria uma terceira lista com a interseção das chaves das listas anteriores:\n");
    lista3 = intersecaoListas(lista, lista2);
    printa_lista(lista3);
    printf("\n=>Remove o último da segunda lista e insere um novo com os mesmos valores na primeira, pelo fim:\n");
    insereRemove(lista, lista2);
    printf("\n=>Lista 2 com o último nó removido:\n");
    printa_lista(lista2);
    printf("\n=>Nó removido da lista 2 inserido um novo com os mesmos valores no fim da lista 1:\n");
    printa_lista(lista);
    printf("\n=>Desconecta o último da lista 2 e insere este na lista 1:\n");
    transplantaNo(lista, lista2);
    printf("\n=>Lista 2 com o último nó desconectado:\n");
    printa_lista(lista2);
    printf("\n=>Nó desconectado da lista 2 inserido no fim da lista 1:\n");
    printa_lista(lista);
    printf("\n=>Cria uma nova quarta lista com os valores da primeira lista, porém ordenados em ordem crescente:\n");
    lista4 = ordenaLista(lista);
    printa_lista(lista4);
    printf("\n=>Remove todos os nós das listas 1, 2, 3 e 4, exceto o nó cabeça:\n");
    liberaNos(lista);
    printa_lista(lista);
    liberaNos(lista2);
    printa_lista(lista2);
    liberaNos(lista3);
    printa_lista(lista3);
    liberaNos(lista4);
    printa_lista(lista4);
    printf("\n=>Remove todos os nós das lista 1, 2, 3 e 4, inclusive o nó cabeça:\n");
    liberaTudo(&lista);
    printa_lista(lista);
    liberaTudo(&lista2);
    printa_lista(lista2);
    liberaTudo(&lista3);
    printa_lista(lista3);
    liberaTudo(&lista4);
    printa_lista(lista4);
    return 0;
}
