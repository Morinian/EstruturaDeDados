#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define BRANCO 0
#define CINZA  1
#define PRETO  2

#define INFINITO INT_MAX
#define NULO     -1

// RepresentaÃ§Ã£o de um grafo usando matriz de adjacÃªncia
typedef struct {
    int numVertices;
    int **matrizAdj;
} Grafo;

// Criar um grafo com um nÃºmero especÃ­fico de vÃ©rtices
Grafo *criarGrafo(int numVertices) {
    Grafo *grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;
    grafo->matrizAdj = (int**)malloc(numVertices * sizeof(int*));

    for (int i = 0; i < numVertices; i++) {
        grafo->matrizAdj[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++)
            grafo->matrizAdj[i][j] = 0;
    }
    return grafo;
}

void adicionarAresta(Grafo *grafo, int origem, int destino) {
    grafo->matrizAdj[origem][destino] = 1;
    grafo->matrizAdj[destino][origem] = 1;
}

void imprimirGrafo(Grafo *grafo) {
    printf("Grafo nÃ£o orientado (VÃ©rtices adjacentes):\n");
    for (int i = 0; i < grafo->numVertices; i++) {
        printf("VÃ©rtice %d: ", i);
        bool primeiro = true;
        for (int j = 0; j < grafo->numVertices; j++) {
            if (grafo->matrizAdj[i][j] == 1) {
                if (!primeiro) printf(", ");
                printf("%d", j);
                primeiro = false;
            }
        }
        printf("\n");
    }
}

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

Fila* criarFila() {
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = fila->fim = NULL;
    return fila;
}

bool filaVazia(Fila *fila) {
    return fila->inicio == NULL;
}

void enfileirar(Fila *fila, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    if (fila->fim == NULL) {
        fila->inicio = fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

int desenfileirar(Fila *fila) {
    if (filaVazia(fila)) return -1;
    No *temp = fila->inicio;
    int valor = temp->dado;
    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL)
        fila->fim = NULL;
    free(temp);
    return valor;
}

void imprimirArvoreBFS(Grafo *grafo, int *pai) {
    printf("\nÁrvore BFS (de distâncias):\n");
    for (int i = 0; i < grafo->numVertices; i++) {
        if (pai[i] != NULO)
            printf("Pai de %d Ã© %d\n", i, pai[i]);
        else 
            printf("%d nÃ£o tem pai\n", i);
    }
}

void BFS(Grafo *grafo, int origem) {
    int cor[grafo->numVertices];
    int distancia[grafo->numVertices];
    int pai[grafo->numVertices];

    for (int i = 0; i < grafo->numVertices; i++) {
        cor[i] = BRANCO;
        distancia[i] = INFINITO;
        pai[i] = NULO;
    }

    cor[origem] = CINZA;
    distancia[origem] = 0;

    Fila *fila = criarFila();
    enfileirar(fila, origem);

    while (!filaVazia(fila)) {
        int u = desenfileirar(fila);
        printf("Visitando vÃ©rtice %d\n", u);

        for (int v = 0; v < grafo->numVertices; v++) {
            if (grafo->matrizAdj[u][v] == 1 && cor[v] == BRANCO) {
                cor[v] = CINZA;
                distancia[v] = distancia[u] + 1;
                pai[v] = u;
                enfileirar(fila, v);
            }
        }
        cor[u] = PRETO;
    }

    imprimirArvoreBFS(grafo, pai);
}

// -------------------- FUNÇÃO PRINCIPAL --------------------

int main(void) {
    int numVertices = 8;

    Grafo *grafo = criarGrafo(numVertices);

    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 3);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 3, 4);
    adicionarAresta(grafo, 3, 5);
    adicionarAresta(grafo, 4, 5);
    adicionarAresta(grafo, 4, 6);
    adicionarAresta(grafo, 5, 7);
    adicionarAresta(grafo, 6, 7);

    imprimirGrafo(grafo);
    printf("\nBusca em Largura (BFS):\n");
    BFS(grafo, 0);

    return 0;
}
