#include "bib.h"

int main(void) {
    TipoListaSimples *lista = NULL;
    int i = 0, chave = 0;
    lista = criaLista();
    printf("=>Verificando se o nó cabeça foi criado com sucesso:\n");
    if (lista == NULL) {
        printf("O S.O não conseguiu alocar memória.\n");
    }
    else {
        printf("Lista criada com sucesso!\n");
    }
    printf("=>Insere 5 valores aleatórios na lista(pelo início):\n");
    for (i = 0; i < 5; i++) {
        chave = rand () % 50;
        insereInicioListaSimples(cabeca, chave); 
    }
    return 0;
}
