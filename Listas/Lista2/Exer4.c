#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Implemente, em linguagem C, um algoritmo recursivo para encontrar o valor máximo em
// um vetor de inteiros, dividindo o vetor em dois subvetores de tamanho aproximadamente n/2 cada.
int valorMaximo(int* vetor,int inicio, int fim){

    if(fim - inicio == 0){ //condição de parada
        return vetor[inicio]; // retornar com o unico numero que tem no vetor
    }

    int tamanho = (fim + inicio)/2; //aqui adiquirimos o meio
    
    int valorEsq = valorMaximo(vetor, inicio, tamanho);
    int valorDir = valorMaximo(vetor, tamanho + 1, fim);

    if(valorEsq > valorDir){ //retorna qual resultado é maior
        return valorEsq;
    }
    else{
        return valorDir;
    }
}
int main(){
    int n = 6;

    int* vetor = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) { //preenchendo o vetor
        vetor[i] = i + 1;  
    }

    printf("---------------\n");
    printf("Maior numero: %d",valorMaximo(vetor,0,n-1));
    printf("\n---------------");
    free(vetor);
}