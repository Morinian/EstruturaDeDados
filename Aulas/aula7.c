#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct node * link;

struct node{
    char item[20]; 
    link next;
};

typedef struct{
    link inicio;
    link final;
} FILA;

void inicializar(FILA *f){
    f->inicio = NULL;
    f->final = NULL;
}

void enfileirar(FILA *f, char *x){
    link novoNode = (link) malloc(sizeof(struct node));
    strcpy(novoNode->item, x);
    novoNode->next = NULL;
    if(f->inicio == NULL)
        f->inicio = novoNode;
    else
        f->final->next=novoNode;
    f->final = novoNode;
}

void desenfileirar(FILA *f, char *i){
  if (f->inicio == NULL) 
    printf("Fila Vazia!\n");
  else{ 
     
     printf("%s\n",f->inicio->item);

     strcpy(i, f->inicio->item);
     link tmp = f->inicio; 
     f->inicio = f->inicio->next;
     if (f->inicio == NULL) 
       f->final= NULL;
      
     free(tmp);
  }
}

int main()
{
  int i, n;
  FILA f; 
  inicializar(&f); 
  
  char a[20];
  a[0] = '1';
  
  char tmp[20];
  
  char c[20];
  
  printf("Quantidade de elementos: ");
  scanf("%d", &n);
  printf("\n");

  for (i = 0; i <= n; i++){

    
    if(i==0){
        enfileirar(&f, a);
    }else{
        desenfileirar(&f, c);
        strcpy(tmp, c);
        
        strcpy(a, tmp);
        strcat(a,"0");
        enfileirar(&f, a);

        strcpy(a, tmp);
        strcat(a,"1");
        enfileirar(&f, a);
    } 
  }
    
  return 0;
}
