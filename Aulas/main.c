#include <stdio.h>
#include <stdlib.h>

typedef struct node* link;

struct node{ 
  int chave; 
  link esq; 
  link dir;
  int h; 
};

int altura (link raiz) {
    return (raiz == NULL) ? -1 : raiz->h;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

link rotacaoDireita(link p) {
     link u;
     u = p->esq;
     p->esq = u->dir; 
     u->dir = p; 
     p->h = max(altura(p->esq), altura(p->dir)) + 1;
     u->h = max(altura(u->esq), p->h) + 1;
     return u; 
}

link rotacaoEsquerda(link p) {
     link z;
     z = p->dir; 
     p->dir = z->esq; 
     z->esq = p; 
     p->h = max(altura(p->esq), altura(p->dir)) + 1;
     z->h = max(p->h, altura(z->dir)) + 1;
     return z; 
}

link rotacaoEsquerdaDireita(link p) {
     link u = p->esq; 
     p->esq = rotacaoEsquerda(u); 
     return rotacaoDireita(p); 
}

link rotacaoDireitaEsquerda(link p) {
     link z = p->dir;
     p->dir = rotacaoDireita(z); 
     return rotacaoEsquerda(p); 
}

link inserirAVL(link raiz, int valor) {
     if (raiz == NULL) { 
        link novoNode = (link)malloc(sizeof(struct node)); 
        novoNode->chave = valor;
        novoNode->esq = NULL; 
        novoNode->dir = NULL; 
        novoNode->h = 0; 
        return novoNode;
     } 
     if (valor < raiz->chave) 
        raiz->esq = inserirAVL(raiz->esq, valor); 
     else 
        raiz->dir = inserirAVL(raiz->dir, valor); 
     
     raiz->h = max(altura(raiz->esq), altura(raiz->dir)) + 1;
     
     int fb = altura(raiz->esq) - altura(raiz->dir);

     if (fb == 2) { 
        if (valor < raiz->esq->chave) 
           return rotacaoDireita(raiz); 
        else
           return rotacaoEsquerdaDireita(raiz); 
     }
     else if (fb == -2) { 
        if (valor > raiz->dir->chave) 
           return rotacaoEsquerda(raiz);
        else
           return rotacaoDireitaEsquerda(raiz);
     }
     
     return raiz; 
}

//Visualização da Arvore
void percursoInOrdem(link raiz) {
     if (raiz != NULL) { 
        percursoInOrdem(raiz->esq);
        printf("%i ", raiz->chave); 
        percursoInOrdem(raiz->dir); 
     }
}

//inserindo
link inserirVetor(link raiz, int* v, int n){
    for(int i = 0; i < n; i++){
        raiz = inserirAVL(raiz, v[i]);
    }
    return raiz;
}


int main(void) {
    int v[5] = {10,7,3,2,9}; 
    int n = 5;
    
    link Arvore = NULL; 

    Arvore = inserirVetor(Arvore, v, n);
    percursoInOrdem(Arvore);

    return 0;
}