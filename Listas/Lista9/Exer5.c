#include <stdio.h>
#include <stdlib.h>

typedef struct node* link;
typedef struct node_fila* link_fila;

// Árvore
struct node {
    int chave;
    link esq;
    link dir;
};

// Fila (agora com ponteiros para nós da árvore)
struct node_fila {
    link item;
    link_fila next;
};

typedef struct {
    link_fila inicio;
    link_fila fim;
} FILA;

// Inserção na árvore
link inserir(link raiz, int valor) {
    if (raiz == NULL) {
        link novoNode = (link)malloc(sizeof(struct node));
        novoNode->chave = valor;
        novoNode->esq = NULL;
        novoNode->dir = NULL;
        return novoNode;
    }
    if (valor < raiz->chave)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

// Inicializa fila
void inicializarFila(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

// Enfileirar nó da árvore
void enfileirar(FILA* f, link node) {
    link_fila novoNode = (link_fila)malloc(sizeof(struct node_fila));
    novoNode->item = node;
    novoNode->next = NULL;

    if (f->inicio == NULL) {
        f->inicio = novoNode;
    } else {
        f->fim->next = novoNode;
    }
    f->fim = novoNode;
}

// Desenfileirar e retornar o nó
link desenfileirar(FILA* f) {
    if (f->inicio == NULL) return NULL;

    link_fila temp = f->inicio;
    link node = temp->item;
    f->inicio = f->inicio->next;
    if (f->inicio == NULL)
        f->fim = NULL;
    free(temp);
    return node;
}

// Verifica se fila está vazia
int filaVazia(FILA* f) {
    return f->inicio == NULL;
}

// Impressão por nível (largura)
void imprimirLargura(link raiz) {
    if (raiz == NULL) return;

    FILA f;
    inicializarFila(&f);
    enfileirar(&f, raiz);

    printf("Percurso em largura: ");

    while (!filaVazia(&f)) {
        link atual = desenfileirar(&f);
        printf("%d ", atual->chave);

        if (atual->esq != NULL)
            enfileirar(&f, atual->esq);
        if (atual->dir != NULL)
            enfileirar(&f, atual->dir);
    }

    printf("\n");
}

int main(void) {
    link Arvore = NULL; // Inicializar a ABB vazia
    int chave;

    Arvore = inserir(Arvore, 50); // Inserir 50 na ABB
    Arvore = inserir(Arvore, 40); // Inserir 40 na ABB
    Arvore = inserir(Arvore, 60); // Inserir 60 na ABB
    Arvore = inserir(Arvore, 35); // Inserir 35 na ABB
    Arvore = inserir(Arvore, 45); // Inserir 45 na ABB
    Arvore = inserir(Arvore, 55); // Inserir 55 na ABB
    Arvore = inserir(Arvore, 65); // Inserir 65 na ABB

    imprimirLargura(Arvore);

    return 0;
} 
    