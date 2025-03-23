#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct node *link;

struct node
{
    int item;
    link next;
    link prev;
};

void imprimir(link lista){

    link p = lista->next;

    do {
        printf("%d ", p->item);
        p = p->next;
    } while (p != lista);
 
}

void inserir(link *lista, int item){

    link novaNode = (link)malloc(sizeof(struct  node));
    novaNode->item = item;

    if((*lista)->next == (*lista)){
        novaNode->next = *lista;
        novaNode->prev = *lista;
        (*lista)->next = novaNode;
        (*lista)->prev = novaNode;
    }else{
        novaNode->prev = *lista;
        novaNode->next = (*lista)->next;
        (*lista)->next->prev = novaNode;
        (*lista)->next = novaNode;
    }
}

link buscar (link lista, int itemProcura){
    link p = lista->next;

    do {
        if (p->item == itemProcura){
            printf("O item %d foi achado\n", p->item);
            return p;
        }

        p = p->next;

    } while (p != lista);
    return NULL;
}

void trocar(link lista,int itemLista, int itemTroca){
    
    link noLista = buscar(lista,itemLista);
    noLista->item = itemTroca;
}

void remover (link lista, int itemRemover){
    link noLista = buscar(lista,itemRemover);

    if (noLista == NULL) {
        printf("\nItem não encontrado.\n");
        return;
    }

    link prev = noLista->prev;
    link next = noLista->next;

    next->prev = prev;
    prev->next = next;

    free(noLista);
    printf("Item %d removido com sucesso.\n", itemRemover);
}

int main(){
    link Lista = (link)malloc(sizeof(struct node));
    Lista->next = Lista;
    Lista->prev = Lista;

    inserir(&Lista,11);
    inserir(&Lista,8);
    inserir(&Lista,9);
    inserir(&Lista,10);

    printf("\n-----------------\n");
    
    buscar(Lista,10);
    imprimir(Lista);

    printf("\n----------------\n");

    trocar(Lista, 9,6);
    imprimir(Lista);

    printf("\n-----------------\n");

    remover(Lista,6);
    imprimir(Lista);
    return 0;
}
