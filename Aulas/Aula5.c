#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Implemente uma lista simplesmente ligada/encadeada circular com
// cabeça (head node ou dummy node), com as operações de inserção,
// busca e remoção.

//Criação da lista

typedef struct node * link;

struct node{
    int item;
    link next;
};

void inserir (link *lista, int novoItem){
    
    //Criando novo node
    link novoNode = (link)malloc(sizeof(struct node));
    novoNode->item = novoItem; // adicionando o item
    
    if((*lista)->next == (*lista)){
        
        novoNode->next = (*lista)->next; //apontando para cabeça
        (*lista)->next = novoNode;
        
    }else{
        novoNode->next = (*lista)->next;
        (*lista)->next = novoNode;
    }
    
}

void buscar (link lista, int itemBusca){
    
    link p = lista->next;
    bool itemEncontrado = false;
    
    while (p != lista) { 
        if(itemBusca == p->item){
            printf("Item encontrado: %d",p->item);
            itemEncontrado = true; 
        }
        p = p->next; 
    }
    
    if(itemEncontrado == false){
        printf("Item não encontado");
    }
}

void imprimir(link lista) {
    link cab = lista;
    link p = lista->next; 
    printf("Lista: ");
    while (p != lista) { 
        if (p->next != lista)
            printf("%d -> ", p->item); 
        else
            printf("%d", p->item);
        p = p->next; 
    }
}

void remover(link *lista, int itemRemover){
    
    link c = (*lista);
    link p = (*lista)->next;
    bool itemEncontrado = false;
    
    while (p != (*lista)) { 
        if(itemRemover == p->item){
            printf("\n");
            printf("Item encontrado: %d",p->item);
            printf("\n");
            itemEncontrado = true;
            c->next = p->next; 
        }
        c = c->next;
        p = p->next; 
    }
    
    if(itemEncontrado == false){
        printf("Item não encontado");
    }
}

int main()
{
    int n, i;
    //Craindo a cabeça da lista circular
    link Lista = (link)malloc(sizeof(struct node));
    Lista->next = Lista; // Valor da cabeça 
    
    printf("Quantidade de itens na lista: ");
    scanf("%d", &n);
    printf("\n");
    
    //Nosso rand de numeros aleatorios
    srand((unsigned)time(NULL));
    
    //Inserindo
    for (int i = 0; i < n; i++) 
        inserir(&Lista, 1 + (rand()%100));
    
    imprimir(Lista);
    printf("\n");
    
    //Buscando
    printf("\n");
    printf("Qual item quer procurar? ");
    scanf("%d", &i);
    printf("\n");
    
    buscar(Lista,i);
    
    //Removendo
    printf("\n");
    printf("Qual item quer remover? ");
    scanf("%d", &i);
    printf("\n");
    
    remover(&Lista, i);
    
    imprimir(Lista);
        
    return 0;
}