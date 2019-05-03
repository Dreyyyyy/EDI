#include "bib.h"

/*============================>PROCEDIMENTOS BÁSICOS DE LISTAS COM CABEÇA
* cabeca é ponteiro para o nó cabeça da lista
* quando não especificado, preencha o campo valorQualquer com 
* o mesmo valor do campo chave.
* não esqueça do assert no ponteiro do nó cabeça
* nos casos de remoção, atente na atualização dos
* campos adequados com NULL
*/

void printa_lista(TipoListaSimples *lista) {
    if (lista == NULL) {
        printf("Nó cabeça não existe!\n");
        return;
    }
    else {
        printf("Nó cabeça, chave:%d\n", lista->chave);//Printa o nó cabeça, apenas para verificação
    }
    if (lista->prox == NULL) {//Verifica se a lista está vazia
        printf("Lista vazia!\n");
    }
    else {
        lista = lista->prox;//Depois avança o ponteiro para o primeiro nó da lista
        do {
            printf("Chave:%d Valor:%d\n", lista->chave,lista->valorQualquer);
            lista = lista->prox;
        }while(lista != NULL);
    }
}

TipoListaSimples *aloca_no(int chave) {
    TipoListaSimples *novoNo = NULL;
    novoNo = (TipoListaSimples*)malloc(sizeof(TipoListaSimples*));
    if (novoNo == NULL) {
        return NULL;
    }
    else {
        novoNo->chave = chave;
        novoNo->valorQualquer = chave+19;
        novoNo->prox = NULL;
        return novoNo;
    }
}

/*
*-------------------------> Criacao
* Cria nó cabeça e devolve ponteiro para ele.*/
TipoListaSimples *criaLista() {
    TipoListaSimples *cabeca = NULL;
    cabeca = (TipoListaSimples*)malloc(sizeof(TipoListaSimples*));
    if (cabeca == NULL) {//Caso o S.O não liberar memória, retorna NULL
        return NULL;
    }
    else {//Caso contrário, devolve o endereço do nó cabeça criado
        cabeca->chave = -1;
        cabeca->valorQualquer = -1;
        cabeca->prox = NULL;
        return cabeca;
    }
}

/* -------------------------> Insercao no início
* Insere no com valor chave igual a chave
* no início de uma lista com cabeça.
* Devolve endereço do nó recém inserido 
* ou NULL em caso de insucesso.*/
TipoListaSimples *insereInicioListaSimples(TipoListaSimples *cabeca, TipoChave chave) {
    if(cabeca->prox == NULL) {//Verifica se a lista está vazia
        cabeca->prox = aloca_no(chave);//Caso estiver, insere o primeiro nó, exclusive o nó cabeça
    }
    else {
        TipoListaSimples *novoNo = NULL;
        novoNo = aloca_no(chave);//devolve o endereço de memória para o novo nó
        novoNo->prox = cabeca->prox;//novo nó aponta para o primeiro nó anterior
        cabeca->prox = novoNo;//novo nó passa a ser o primeiro nó da lista    
    }
    return cabeca->prox;
}

/* -------------------------> Atualiza primeiro no
* Caso o primeiro nó exista, atualiza o campo 
* valorQualquer com novoValor.*/
void atualizaValor(TipoListaSimples *cabeca, TipoValor novoValor) {
    if (cabeca == NULL) {//Verifica se foi criado o nó cabeça
        return;
    }
    if (cabeca->prox == NULL) {//Verifica se a lista está vazia
        return;
    }
    else {//Do contrário, altera o valor do primeiro nó
        cabeca->prox->valorQualquer = novoValor; 
    }
}

/* -------------------------> Remoção no início
* Remove o primeiro no de uma lista com cabeca
* caso ele exista.*/
void removePrimeiroNo(TipoListaSimples *cabeca) {
    if(cabeca == NULL) {//Verifica se foi criado o nó cabeça
        return;
    }
    if(cabeca->prox == NULL){//Verifica se a lista está vazia
        return;
    }
    else {
        TipoListaSimples *noAux = NULL;
        noAux = cabeca->prox;//Auxiliar recebe o endereço do primeiro nó
        cabeca->prox = cabeca->prox->prox;//O ponteiro "->prox" do nó cabeça da lista apontará para o novo primeiro nó, ou seja, o segundo nó anteriormente
        free(noAux);//Libera o primeiro nó anterior
        noAux = NULL;
    }
}

/* -----------------> Busca pelo endereço de um nó dado um valor de chave
* Devolve ponteiro para o nó cujo valor chave é 'chave'
* ou NULL caso este não exista.*/
TipoListaSimples *pesquisaNo(TipoListaSimples *cabeca, TipoChave chave) {
    if(cabeca == NULL) {//Caso base 1:Verifica se a lista está vazia
        return NULL;
    }
    else if(cabeca->chave == chave) {//Caso base 3:Caso a chave for igual a procurada, retorna o endereço do ponteiro que contém a chave
        return cabeca;
    }
    else {//Caso recursivo: Chama a própria função novamente, passando o próximo nó da lista
        return pesquisaNo(cabeca->prox, chave);
    }
}

/* -------------------------> Inserção no fim de uma lista
* Insere nó no fim de uma lista com cabeça.
* Devolve endereço do nó ou NULL em caso de
* insucesso.*/
TipoListaSimples *insereFimListaSimples(TipoListaSimples *cabeca, TipoChave chave) {
    if(cabeca == NULL) {//Caso base 1:Verifica se foi criado o nó cabeça
        return NULL;
    }
    else if(cabeca->prox == NULL) {//Caso base 2:Verifica se a lista está vazia
        cabeca->prox = aloca_no(chave);//Caso estiver, insere o primeiro nó, exclusive o nó cabeça
    }
    else {//Caso recursivo: Retorna o próximo nó da lista, e empilha até cair no caso base, e começar a inserir conforme desempilha, ou seja, do último para o primeiro
        insereFimListaSimples(cabeca->prox, chave);
    }
}

/* -------------------------> Remoção último nó
* Remove o último nó de uma lista com cabeca
* caso ele exista.*/
void removeUltimoNo(TipoListaSimples *cabeca) {
    if (cabeca == NULL) {//Verifica se a lista possui o nó cabeça
        return;
    }
    else if (cabeca->prox == NULL) {//Verifica se a lista está vazia
        return;
    }
    else {
        TipoListaSimples *noAnt = NULL, *noAux = NULL;
        noAnt = cabeca->prox;//no anterior armazenará o endereço do nó que será o último após a remoção
        noAux = cabeca->prox->prox;//no auxiliar percorrerá a lista até chegar ao último elemento antes da remoção
        while (noAux->prox != NULL) {
            noAnt = noAux;
            noAux = noAux->prox;
        }
        noAnt->prox = NULL;//no anterior passa a ser o último
        free(noAux);//libera o último nó antes da remoção
        noAux = NULL;
    }
}

/* -------------------------> Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.*/
void removeNo(TipoListaSimples *cabeca, TipoChave chave) {
    if (cabeca == NULL) {//Verifica se a lista possui cabeça
        return;    
    }
    else if (cabeca->prox == NULL) {//Verifica se a lista está vazia
        return;
    }
    else {
        int check = 0;
        TipoListaSimples *noAnt = NULL, *noAux = NULL;
        noAnt = cabeca->prox;//Guarda o nó anterior ao que será removido
        noAux = cabeca->prox->prox;//Recebe o segundo nó da lista, para andar nela
        if (noAnt->chave == chave) {//Caso o primeiro nó da lista tiver a chave igual, remove este e encerra a função
            cabeca->prox = noAnt->prox;
            free(noAnt);
            noAnt= NULL;
            check = 1;
        }
        else {
            while (noAux != NULL) {//Caso contrário, busca pelo nó que será removido, e remove caso encontrar
                if (noAux->chave == chave) {
                    noAnt->prox = noAux->prox;
                    free(noAux);
                    noAux = NULL;
                    check = 1;
                    break;
                }
                noAnt = noAux;
                noAux = noAux->prox;
            } 
        }
        if (check == 0) {//Se não encontrar, printa a seguinte frase e encerra a função
            printf("\nChave inexistente!\n");                   
        }       
    }
}//No meu ver ficou bem prolixo isso aqui, porém arrumarei quando pensar em uma forma mais otimizada de fazer isso

/* -------------------------> Remove todos nós
* Remove TODOS os nos da lista exceto o nó cabeça.*/
void liberaNos(TipoListaSimples *cabeca) {
    if (cabeca->prox == NULL) {//Caso base: Verifica se a lista está vazia
        return;
    }
    else {
        removePrimeiroNo(cabeca);//Caso não estiver, remove nó por nó, pelo início
        liberaNos(cabeca);//Caso recursivo: Empilhará a função até liberar todos os nós e cair no caso base
    }
}

/* -------------------------> Remove todos nós
* Remove TODOS os nós da lista em que o nó cabeça encontra-se
* armazenado no endereço 
*cabeca. Também remove o nó cabeça.*/

void liberaTudo(TipoListaSimples **cabeca) {
    if (*cabeca == NULL) {//Caso base: Quando o ponteiro cabeça da main estiver nulo, ou seja, quando a lista estiver vazia e sem cabeça, encerra a função
        return;
    }
    else {//Caso contrário, remove ponteiro por ponteiro pelo início(inclusive o cabeça)
        TipoListaSimples *aux = NULL;
        aux = *cabeca;
        *cabeca = (*cabeca)->prox;
        free(aux);
        aux = NULL;
        liberaTudo(&(*cabeca));//Caso Recursivo: Chama a própria função até cair no caso base, ou seja, lista estiver vazia e sem cabeça
    }
}

/*========================>PROCEDIMENTOS ESPECÍFICOS DE LISTAS COM CABEÇA
/* -------------------------> Cria cópia 
* Cria uma nova lista cujos nós têm os mesmos
* valores da lista dada. Devolve o ponteiro para 
* o cabeça da nova lista. */
TipoListaSimples *copiaListas(TipoListaSimples *cabeca) {
    TipoListaSimples *novaLista = NULL;
    novaLista = criaLista();//Cria uma cabeça para a nova lista
    cabeca = cabeca->prox;//Avança o ponteiro da primeira lista, para não ser copiado o nó cabeça desta
    while (cabeca != NULL) {//Copia todos os nós da primeira lista, até esta chegar ao fim
        insereInicioListaSimples(novaLista, cabeca->chave);
        cabeca = cabeca->prox;
    }
    return novaLista;//Retorna um ponteiro pro cabeça da nova lista
}

/* -------------------------> Cria cópia 
* Calcula a interseção entre as duas listas
* dadas e insere tais nós numa (nova) terceira
* lista. Devolve o ponteiro para o cabeça da nova lista.*/
TipoListaSimples * intersecaoListas(TipoListaSimples *cabeca1, TipoListaSimples *cabeca2) {
    if (cabeca1 == NULL || cabeca2 == NULL) {//Verifica se a lista possui cabeça
        return NULL;
    }
    else if (cabeca1->prox == NULL && cabeca2->prox == NULL) {//Verificar se a lista está vazia
        return NULL;
    }
    else {
        TipoListaSimples *lista3 = NULL, *cabecaAux1 = NULL, *cabecaAux2 = NULL;
        lista3 = criaLista();
        for (cabecaAux1 = cabeca1->prox; cabecaAux1 != NULL; cabecaAux1 = cabecaAux1->prox) {//Percorre a lista 1
            for (cabecaAux2 = cabeca2->prox; cabecaAux2 != NULL; cabecaAux2 = cabecaAux2->prox) {//Percorre a lista 2
                if (cabecaAux1->chave == cabecaAux2->chave) {//Quando os valores de ambas as listas forem iguais, insere na nova lista 3
                    insereInicioListaSimples(lista3, cabecaAux1->chave);
                }
            }
        }
        return lista3;//Retorna um ponteiro para o cabeça da lista 3
    }
}

/* -------------------------> Insere ordenado
* Caso a lista dada não seja vazia, ASSUMA que ela está em ordem crescente por valor chave.
* Ou seja, o valor chave do primeiro nó é menor ou igual ao do segundo e assim sucessivamente.
* Você deve inserir um novo nó com valor chave igual a chave de forma que a lista mantenha-se
* ordenada.*/
void insereOrdenado(TipoListaSimples *cabeca, TipoChave chave);

/* -------------------------> Ordena
* Devolve o nó cabeça de uma nova lista
* com os mesmos valores da lista dada porém
* na nova lista os valores são ordenados  */
TipoListaSimples *ordenaLista(TipoListaSimples *cabeca);

/* -------------------------> Remove/Insere
* Remove último nó da segunda lista (caso ele exista).
* Insere um nó na última posição da primeira lista.
* O novo nó deve ter os mesmos valores do nó removido.
*/void insereRemove(TipoListaSimples *cabeca1,TipoListaSimples *cabeca2);

/* -------------------------> Transplanta Nó.
* Desconecta o último nóda segunda lista (caso ele exista). 
* Conecta tal nó na última posição da primeira lista.
* NOTE QUE A REGIÃO DE MEMÓRIA DO NÓ NÃO MUDA!*/
void transplantaNo(TipoListaSimples *cabeca1, TipoListaSimples *cabeca2);
