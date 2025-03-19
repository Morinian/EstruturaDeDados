#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Implemente, em linguagem C, uma função que encontre o nó com o conteúdo de valor
// mínimo em uma lista simplesmente encadeada/ligada sem cabeça de valores inteiros. Faça duas
// versões: uma iterativa e uma recursiva

typedef struct node * link;

struct node
{
   int item;
   struct node *next;
};

void inserir(struct node **Lista,int itemNovo){

    struct node *novoNode = (struct node *)malloc(sizeof(struct node));
    novoNode->item = itemNovo; 
    novoNode->next = *Lista; 
    *Lista = novoNode; 

}

void imprimir(struct node *Lista){
    struct node *p = Lista;
    
    while( p != NULL){
        if(p->next == NULL)
            printf("%d", p->item);
        else    
            printf("%d -> ", p->item);
    
        p = p->next;
    }
}

void numMenorIterativo(struct node *Lista){
    struct node *p = Lista;
    int item = p->item;
    
    while( p != NULL){
        
        if(item > p->item)
            item = p->item;
        
        p = p->next;
    }

    printf("O numero menor é (iterativo): %d", item);
}

void numMenorRecursivo(struct node *Lista, int item){
    struct node *p = Lista;

    if(p == NULL){
        printf("O numero menor é (recursivo): %d", item);
        return;
    }
    else{
        if (item > p->item)
        {
            numMenorRecursivo(p->next, p->item);
        }else{
            numMenorRecursivo(p->next, item);
        }
        
    }
}

int main(){

    struct node *Lista = NULL; //iniciando a lista vazia sem cabeça
    int tamanho;

    printf("Qual tamanho da sua lista? ");
    scanf("%d",&tamanho);
    printf("\n");

    srand((unsigned)time(NULL));

    for(int i = 0; i < tamanho; i++)
        inserir(&Lista, 1 + (rand()%100));

    imprimir(Lista);
    printf("\n");
    numMenorIterativo(Lista);
    printf("\n");
    numMenorRecursivo(Lista, Lista->item);

    return 0;
}