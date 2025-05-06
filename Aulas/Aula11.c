/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100 // Tamanho mÃ¡ximo do heap

int pai(int i) {
    return (i/2)-1; // Retorna o Ã­ndice do pai do nÃ³ i
}

int esq(int i) {
    return 2*i+1; // Retorna o Ã­ndice do filho Ã  esquerda de i
}

int dir(int i) {
    return 2*i+2; // Retorna o Ã­ndice do filho Ã  direita de i
}

void subir(int *heap, int i) {
     int aux;
     int p = pai(i); // Calcula o Ã­ndice do pai
     if (p >= 0) { // Se pai(i) pertence ao heap
        if (heap[i] > heap[p]) { // Se o filho for maior que o pai (max-heap)
           // Troca pai e filho
           aux = heap[i];
           heap[i] = heap[p];
           heap[p] = aux;
          subir(heap, p); // Continua subindo recursivamente
        }
     }
}

void inserir(int *heap, int *n, int novoItem) {
     *n = *n + 1; // Aumenta o nÃºmero de elementos no heap
     heap[*n] = novoItem; // Insere o novo elemento no final
     subir(heap, *n); // Sobe o Ãºltimo elemento do heap
}

void descer(int *heap, int n, int i) {
     int aux;
     // Descobrir quem Ã© o maior filho de i
     int e = esq(i); // Ãndice do filho Ã  esquerda
     int d = dir(i); // Ãndice do filho Ã  direita
     int maior = i; // Inicialmente o maior Ã© o pai
     if ((e <= n) && (heap[e] > heap[i]))
        maior = e; // Filho da esquerda maior que o pai
     if ((d <= n) && (heap[d] > heap[maior]))
        maior = d; // Filho da direita maior que o maior
     if (maior != i) { // Se o maior nÃ£o Ã© o pai
        // Troca pai e maior filho
        aux = heap[i];
        heap[i] = heap[maior];
        heap[maior] = aux;
        descer(heap, n, maior); // Continua descendo recursivamente
      }
}

int removerMaximo(int *heap, int *n) {
    int maximo = heap[0]; // A raiz contÃ©m o maior valor no max-heap
    heap[0] = heap[*n-1]; // Coloca o Ãºltimo elemento na raiz
    *n = *n - 1; // Diminui o tamanho do heap
    descer(heap, *n, 0); // Desce o elemento na raiz do heap
    return maximo; // Retorna o maior elemento do heap
}

void imprimirHeap(int *heap, int n, int i, int b) {
     int j;
     if (i > n) { // NÃ³ nulo (alÃ©m do tamanho do heap), imprime "NULL"
        for (j = 0; j < b; j++) printf("-----");
        printf("NULL\n");
        return;
     }
     imprimirHeap(heap, n, dir(i), b + 1); // Imprime subÃ¡rvore direita
     for (j = 0; j < b; j++) printf("-----"); // IndentaÃ§Ã£o
     printf("%i\n", heap[i]); // Imprime o valor do nÃ³ com Ã­ndice i
     imprimirHeap(heap, n, esq(i), b + 1); // Imprime subÃ¡rvore esquerda
}

void construirHeapDescendo(int *heap, int n) {
     int i;
     int j = n/2-1; // ComeÃ§a no Ãºltimo nÃ³ nÃ£o-folha
     for (i = j; i >= 0; i--)
         descer(heap, n, i); // Desce o elemento
} 

void construirHeapSubindo(int *heap, int n) {
     int i;  
     for (i = 1; i <= n; i++) // ComeÃ§a no filho Ã  esquerdo da raiz
         subir(heap, i); // Sobe o elemento
}

void heapSort(int *heap, int n) {
     int i;
     int aux;

     construirHeapDescendo(heap, n); // Garante que o vetor seja max-heap
     for (i = n; i > 0; i--){
         // Troca raiz (mÃ¡ximo) com o Ãºltimo elemento do heap
         aux = heap[i];
         heap[i] = heap[0];
         heap[0] = aux;
         n = n - 1; // Diminui o tamanho Ãºtil do heap
         descer(heap, n, 0); // Desce a raiz no novo heap de tamanho n-1
      }
}

int main(void) {
    int heap[MAX]; // Vamos considerar um heap de inteiros
    int n = -1; // Heap inicia com 0 elementos
    int i, m;
     
    // InserÃ§Ã£o manual de elementos no heap
    inserir(heap, &n, 17);
    inserir(heap, &n, 15);
    inserir(heap, &n, 12);
    inserir(heap, &n, 9);
    inserir(heap, &n, 10);
    inserir(heap, &n, 4);
    inserir(heap, &n, 1);
    inserir(heap, &n, 7);
    inserir(heap, &n, 3);
    inserir(heap, &n, 6);

    // Exibe o vetor linear do heap
    for (i = 0; i < n; i++) printf("heap[%d] = %d\n", i, heap[i]);
    printf("\n");
  
    // Exibe o heap em formato de Ã¡rvore (bidimensional)
    imprimirHeap(heap, n, 0, 0);
    
    // Remove o maior valor do max-heap
    printf("\nExtraÃ§Ã£o do maior elemento do heap: %d\n\n", removerMaximo(heap, &n));

    // Exibe o vetor linear do heap, depois da remoÃ§Ã£o
    for (i = 1; i <= n; i++) printf("heap[%d] = %d\n", i, heap[i]);
    printf("\n");

    imprimirHeap(heap, n, 1, 0);
    
    // Prepara um vetor de inteiros para ordenaÃ§Ã£o
    printf("\nQuantidade de elementos para ordenar: ");
    scanf("%d", &m);
 
    int vetor[m + 1]; // Vetor para ordenaÃ§Ã£o com Heap Sort
    
    // Inserir m elementos (pseudo)aleatÃ³rios no vetor
    srand((unsigned)time(NULL));

    for (i = 1; i <= m; i++) 
        vetor[i] = 1 + (rand()%100);
    
    printf("\nAntes de ordenar:\n");    
    for (i = 1; i <= m; i++) printf("vetor[%d] = %d\n", i, vetor[i]);
    
    heapSort(vetor, m); // Ordena com Heap Sort
    
    printf("\nDepois de ordenar com Heap Sort:\n");
    for (i = 1; i <= m; i++) printf("vetor[%d] = %d\n", i, vetor[i]);

  return 0;
}
