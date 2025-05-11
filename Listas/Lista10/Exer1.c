#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100 // Tamanho mÃ¡ximo do heap

int pai(int i) {
    return i/2; // Retorna o Ã­ndice do pai do nÃ³ i
}

int esq(int i) {
    return 2*i; // Retorna o Ã­ndice do filho Ã  esquerda de i
}

int dir(int i) {
    return 2*i+1; // Retorna o Ã­ndice do filho Ã  direita de i
}

void subir(int *heap, int i) {
     int aux;
     int p = pai(i); // Calcula o Ã­ndice do pai
     if (p >= 1) { // Se pai(i) pertence ao heap
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

void construirHeapDescendo(int *heap, int n) {
     int i;
     int j = n/2; // ComeÃ§a no Ãºltimo nÃ³ nÃ£o-folha
     for (i = j; i >= 1; i--)
         descer(heap, n, i); // Desce o elemento
} 

void construirHeapSubindo(int *heap, int n) {
     int i;  
     for (i = 2; i <= n; i++) 
         subir(heap, i);
}

void heapSort(int *heap, int n) {
     int i;
     int aux;

     construirHeapDescendo(heap, n); 
     for (i = n; i > 1; i--){

         aux = heap[i];
         heap[i] = heap[1];
         heap[1] = aux;
         n = n - 1; 
         descer(heap, n, 1); 
      }
}

void VerificarHeap(int *heap, int tamanho){
    for (int i = 1; i <= tamanho; i++){
        if(heap[1] < heap[i]){
            printf("Não é um HEAP");
            return;
        }
    }
    printf("É um HEAP");
}

int main(void) {
    int heap[MAX]; // Vamos considerar um heap de inteiros
    int n = 0; // Heap inicia com 0 elementos
    int i, m;
     
    // InserÃ§Ã£o manual de elementos no heap
    inserir(heap, &n, 16);
    inserir(heap, &n, 15);
    inserir(heap, &n, 12);
    inserir(heap, &n, 9);
    inserir(heap, &n, 10);
    inserir(heap, &n, 4);
    inserir(heap, &n, 1);
    inserir(heap, &n, 7);
    inserir(heap, &n, 3);
    inserir(heap, &n, 30);

    // Exibe o vetor linear do heap
    for (i = 1; i <= n; i++) printf("heap[%d] = %d\n", i, heap[i]);
    printf("\n");
    VerificarHeap(heap,n);
    
    // Verifica um vetor
    int numeros[5] = {1, 2, 3, 4, 5};
    printf("\n");
    VerificarHeap(numeros,5);
  return 0;
}
