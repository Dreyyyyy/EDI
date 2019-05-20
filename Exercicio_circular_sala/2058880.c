#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int key;
    struct list *next;
}Clist;

Clist *create_node(int key);
Clist *insert_circular(Clist **list, int key);
void print_list(Clist *list);

int main(void) {
    Clist *list = NULL;
    int i = 0, key = 0;
    printf("=>Add 5 random nodes on list:\n");
    for (i = 0; i < 5; i++) {
        key = rand () % 50;
        insert_circular(&list, key);
        printf("=>%dº added key: %d\n", i+1, key);
    }
    printf("\nPrinted list:\n");
    print_list(list);
}

Clist *create_node(int key) {
    Clist *node = NULL;
    node = (Clist*)malloc(sizeof(Clist));
    if (node == NULL) {
        return NULL;
    }
    else {
        node->key = key;
        node->next = node;
        return node;     
    }
}

Clist *insert_circular(Clist **list, int key) {
    if (*list == NULL) {
        *list = create_node(key);
    }
    else {
        Clist *newNode = NULL, *nodeAux = NULL;
        newNode = create_node(key);
        nodeAux = *list;
        while (nodeAux->next != *list) {
          nodeAux = nodeAux->next;
        }
        nodeAux->next = newNode;
        newNode->next = *list;
        *list = newNode;
    }
    return *list;
}

void print_list(Clist *list) {
    if (list == NULL) {
        printf("\nList is empty.\n");
    }
    else {
        Clist *AuxList = NULL;
        AuxList = list;
        do {
            printf("=>Key: %d\n", AuxList->key);
            AuxList = AuxList->next;
        }while(AuxList != list);
    }
}
