#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Implemente, em linguagem C, uma função que verica se duas listas simplesmente ligadas/encadeadas
// dadas são iguais, ou melhor, se têm o mesmo conteúdo. Faça duas versões: uma sem cabeça e outra
// com cabeça
//Criação da lista

typedef struct node * link;

struct node{
    int item;
    link next;
};

void inserir (link *lista, int novoItem){
    
    link novoNode = (link)malloc(sizeof(struct node));
    novoNode->item = novoItem; 
    novoNode->next = (*lista)->next; 
    (*lista)->next = novoNode; 
    
}


void imprimir(link lista) {
    link p = lista->next;
    
    if (p == NULL){
        return;
    }
    else{
        if(p->next == NULL)
            printf("%d ",p->item);
        else
            printf("%d -> ", p->item);
            

        imprimir(p);
    }
}

void verificar(link lista1, link lista2){
    link p1 = lista1->next;
    link p2 = lista2->next;

    do{
        if(p1->item != p2->item){
            printf("Eles não são igual!");
            return;
        }
        p1 = p1->next;
        p2 = p2->next;
    }while(p1->next!=NULL);

    printf("Eles são igual!");
}

int main()
{
    int n;
    
    link Lista1 = (link)malloc(sizeof(struct node));
    Lista1->next = NULL; 

    link Lista2 = (link)malloc(sizeof(struct node));
    Lista2->next = NULL; 
    
    printf("Quantidade de itens na lista1: ");
    scanf("%d", &n);
    printf("\n");
    
    //Nosso rand de numeros aleatorios
    srand((unsigned)time(NULL));
    
    //Inserindo
    for (int i = 0; i < n; i++) {
        inserir(&Lista1,5);
        inserir(&Lista2,5);
    }

    imprimir(Lista1);
    printf("\n");
    imprimir(Lista2);
    printf("\n");
   
    verificar(Lista1,Lista2);
        
    return 0;
}