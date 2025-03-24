#include <stdio.h>
#include <stdlib.h>

typedef struct node* link;

struct node{ 
    char item; 
    link next; 
};

typedef struct{
  link topo;
} PILHA;

void inicializar(PILHA *p){
  p->topo = NULL; 
}

void empilhar(PILHA *p, char x){
  link novoNode = (link) malloc(sizeof(struct node));
  novoNode->item = x; 
  novoNode->next = p->topo; 
  p->topo = novoNode; 
}


char desempilhar(PILHA *p){
  if (p->topo == NULL) {
     printf("Pilha Vazia!\n");
     return '\0';
  }
  
  char item = p->topo->item; 
  link tmp = p->topo; 
  p->topo = p->topo->next; 
  free(tmp);
  return item;
}


void inserirFim(struct node **lista, char novoItem) {
    struct node *novoNode = (struct node *)malloc(sizeof(struct node));
    novoNode->item = novoItem;
    novoNode->next = NULL;

    if (*lista == NULL) {
        *lista = novoNode;
    } else {
        struct node *temp = *lista;
        while (temp->next != NULL) { 
            temp = temp->next;
        }
        temp->next = novoNode; 
    }
}


char removerInicioLista(struct node **lista) {
    if (*lista == NULL) {
        printf("Lista Vazia!\n");
        return '\0';
    }

    char item = (*lista)->item;
    struct node *tmp = *lista;
    *lista = (*lista)->next;
    free(tmp);
    return item;
}


void imprimirPilha(PILHA p){
  link q = p.topo;
  printf("Pilha:\n ");
  while (q != NULL) { 
    printf(" %c\n ", q->item);
    q = q->next;
  }
}


void imprimirLista(struct node *lista){
    struct node *p = lista;
    printf("Lista: ");
    while (p != NULL){
        printf("%c ", p->item);
        p = p->next;
    }
    printf("\n");
}


void verificarInverso(PILHA *p, struct node **lista) {
    while (p->topo != NULL && *lista != NULL) {
        char topoPilha = desempilhar(p);
        char primeiroLista = removerInicioLista(lista);

        printf("\nComparando: Pilha[%c] vs Lista[%c]", topoPilha, primeiroLista);

        if (topoPilha != primeiroLista) {
            printf("\nA lista NÃO é o inverso da pilha!\n");
            return;
        }
    }

    if (p->topo == NULL && *lista == NULL) {
        printf("\nA lista É o inverso da pilha!\n");
    } else {
        printf("\nA lista NÃO é o inverso da pilha!\n");
    }
}

int main(void){
  char l;
  struct node *Lista = NULL;
  PILHA p; 
  inicializar(&p);

  printf("\nEmpilhe caracteres (digite 'c' para parar): ");
  while(1){
    printf("\nEscolha a letra para empilhar: ");
    scanf(" %c", &l);  
    if(l == 'c') break;
    empilhar(&p, l);
  }

  printf("\nInsira na lista (digite 'f' para parar): ");
  while(1){
    printf("\nEscolha a letra para a lista: ");
    scanf(" %c", &l);  
    if(l == 'f') break;
    inserirFim(&Lista, l);  
  }

  printf("\nEstrutura atual da pilha:\n");
  imprimirPilha(p);

  printf("\nEstrutura atual da lista:\n");
  imprimirLista(Lista);

  verificarInverso(&p, &Lista);

  return 0;
}
