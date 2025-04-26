#include <stdio.h>
#include <stdlib.h>

// DefiniÃ§Ã£o do tipo link como ponteiro para struct node
typedef struct node* link;

// DefiniÃ§Ã£o da estrutura node
struct node{ 
  int chave; 
  link esq; // Ponteiro para filho esquerdo (subÃ¡rvore)
  link dir; // Ponteiro para filho direito (subÃ¡rvore)
  int h; // Essencial para calcular o fator de balanceamento
};

// FunÃ§Ã£o que retorna a altura de um nÃ³, ou -1 se for NULL
int altura (link raiz) {
    return (raiz == NULL) ? -1 : raiz->h;
}

// FunÃ§Ã£o que retorna o maior entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// RotaÃ§Ã£o simples Ã  direita (caso LL - esq + esq)
link rotacaoDireita(link p) {
     link u;
     u = p->esq; // u serÃ¡ o novo pai
     p->esq = u->dir; // SubÃ¡rvore direita de u vira esquerda de p
     u->dir = p; // p se torna filho direito de u
     // Atualiza alturas
     p->h = max(altura(p->esq), altura(p->dir)) + 1;
     u->h = max(altura(u->esq), p->h) + 1;
     return u; // Novo nÃ³ raiz da subÃ¡rvore
}

// RotaÃ§Ã£o simples Ã  esquerda (caso RR - dir + dir)
link rotacaoEsquerda(link p) {
     link z;
     z = p->dir; // z serÃ¡ o novo pai
     p->dir = z->esq; // SubÃ¡rvore esquerda de z vira direita de p
     z->esq = p; // p se torna filho esquerdo de z
     // Atualiza alturas
     p->h = max(altura(p->esq), altura(p->dir)) + 1;
     z->h = max(p->h, altura(z->dir)) + 1;
     return z; // Novo nÃ³ raiz da subÃ¡rvore
}

// RotaÃ§Ã£o dupla Ã  direita (caso LR - esq + dir)
link rotacaoEsquerdaDireita(link p) {
     link u = p->esq; // u Ã© filho da esquerda de p
     p->esq = rotacaoEsquerda(u); // Primeiro, faz rotaÃ§Ã£o simples Ã  esquerda em u
     return rotacaoDireita(p); // Depois, faz rotaÃ§Ã£o simples Ã  direita em p
}

// RotaÃ§Ã£o dupla Ã  esquerda (caso RL - dir + esq)
link rotacaoDireitaEsquerda(link p) {
     link z = p->dir; // z Ã© filho da direita de p
     p->dir = rotacaoDireita(z); // Primeiro, faz rotaÃ§Ã£o simples Ã  direita em z
     return rotacaoEsquerda(p); // Depois, faz rotaÃ§Ã£o simples Ã  esquerda em p
}

// FunÃ§Ã£o para inserir um elemento na Ã¡rvore AVL
link inserirAVL(link raiz, int valor) {
     if (raiz == NULL) { // Verifica se a Ã¡rvore estÃ¡ vazia
        link novoNode = (link)malloc(sizeof(struct node)); // Aloca novo nÃ³
        novoNode->chave = valor; // Valor chave
        novoNode->esq = NULL; // Filho esquerdo
        novoNode->dir = NULL; // // Filho direito
        novoNode->h = 0; // Altura inicial do nÃ³ Ã© 0
        return novoNode; // Retorna ponteiro para o novo nÃ³
     } 
     if (valor < raiz->chave) // Se o valor for menor que a chave da raiz
        raiz->esq = inserirAVL(raiz->esq, valor); // Inserir na subÃ¡rvore esquerda
     else // Se o valor for maior que a chave da raiz
        raiz->dir = inserirAVL(raiz->dir, valor); // Inserir na subÃ¡rvore direita
     
     // Atualizar a altura do nÃ³ atual    
     raiz->h = max(altura(raiz->esq), altura(raiz->dir)) + 1;
     
     // Calcular o fator de balanceamento
     int fb = altura(raiz->esq) - altura(raiz->dir);

     if (fb == 2) { // SubÃ¡rvore esquerda desbalanceou
        if (valor < raiz->esq->chave) // Caso LL - esq + esq (reta)
           return rotacaoDireita(raiz); // RotaÃ§Ã£o simples Ã  direita
        else // Caso LR - esq + dir (curva)
           return rotacaoEsquerdaDireita(raiz); // RotaÃ§Ã£o dupla Ã  direita
     }
     else if (fb == -2) { // SubÃ¡rvore direita desbalanceou
        if (valor > raiz->dir->chave) // Caso RR - dir + dir (reta)
           return rotacaoEsquerda(raiz); // RotaÃ§Ã£o simples Ã  esquerda
        else // Caso RL - dir + esq (curva)
           return rotacaoDireitaEsquerda(raiz); // RotaÃ§Ã£o dupla Ã  esquerda
     }
     
     return raiz; // Se nÃ£o houve desbalanceamento, retorna a raiz normalmente
}

// FunÃ§Ã£o para visualizaÃ§Ã£o bidimensional da Ã¡rvore
void imprimirInOrdem(link p, int b) {
     int i;
     if (p == NULL) {
        for (i = 0; i < b; i++) printf("-----");
        printf("NULL\n");
        return;
     }
     imprimirInOrdem(p->dir, b + 1);
     for (i = 0; i < b; i++) printf("-----");
     printf("%i\n", p->chave);
     imprimirInOrdem(p->esq, b + 1);
}

//---------------------

link encontrarMinimo(link raiz) {
    while (raiz->esq != NULL)
        raiz = raiz->esq;
    return raiz;
}

link removerAVL(link raiz, int valor) {

    if (valor < raiz->chave) {
        raiz->esq = removerAVL(raiz->esq, valor);
    } else if (valor > raiz->chave) {
        raiz->dir = removerAVL(raiz->dir, valor);
    } else {
        if (raiz->esq == NULL || raiz->dir == NULL) {
            link temp = raiz->esq ? raiz->esq : raiz->dir;
            if (temp == NULL) { // Sem filhos
                temp = raiz;
                raiz = NULL;
            } else { // Um filho
                *raiz = *temp; 
            }
            free(temp);
        } else { // Dois filhos
            link temp = encontrarMinimo(raiz->dir); 
            raiz->chave = temp->chave; 
            raiz->dir = removerAVL(raiz->dir, temp->chave); 
        }
    }

    if (raiz == NULL) return NULL; 
    raiz->h = max(altura(raiz->esq), altura(raiz->dir)) + 1;
    int fb = altura(raiz->esq) - altura(raiz->dir);

    // Caso LL
    if (fb > 1 && (altura(raiz->esq->esq) >= altura(raiz->esq->dir)))
        return rotacaoDireita(raiz);

    // Caso LR
    if (fb > 1 && (altura(raiz->esq->esq) < altura(raiz->esq->dir))) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    // Caso RR
    if (fb < -1 && (altura(raiz->dir->dir) >= altura(raiz->dir->esq)))
        return rotacaoEsquerda(raiz);

    // Caso RL
    if (fb < -1 && (altura(raiz->dir->dir) < altura(raiz->dir->esq))) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

//-------------------------

int main(void) {
    link Arvore = NULL; //Inicializar a Ã¡rvore AVL vazia

    Arvore = inserirAVL(Arvore, 1); // Inserir 1 na AVL
    Arvore = inserirAVL(Arvore, 2); // Inserir 2 na AVL
    Arvore = inserirAVL(Arvore, 3); // Inserir 3 na AVL
    Arvore = inserirAVL(Arvore, 4); // Inserir 4 na AVL
    Arvore = inserirAVL(Arvore, 5); // Inserir 5 na AVL
    Arvore = inserirAVL(Arvore, 6); // Inserir 6 na AVL
    Arvore = inserirAVL(Arvore, 7); // Inserir 7 na AVL

    imprimirInOrdem(Arvore, 0); // VisualizaÃ§Ã£o bidimensional

    printf("\n");
    Arvore = removerAVL(Arvore, 4);
    printf("\n");
    
    imprimirInOrdem(Arvore, 0); // VisualizaÃ§Ã£o bidimensional

    return 0;
}
