#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Implemente, em linguagem C, um algoritmo iterativo que analisa um vetor de valores inteiros 
// e retorna 1, 2, 3 ou 4 caso os elementos estejam desordenados, ordenados em ordem crescente, ordenados
// em ordem descrescente ou são constantes, respectivamente.

int main() {
    int itens = 10;
    int vetor[10] = {4, 3, 2, 1, 1, 1, 1, 1, 1, 1};
    bool cresc = true,cons = true,desc = true;

    for (int i = 0; i < itens-1; i++)
    {
        if (vetor[i]<vetor[i+1]){
            desc = false;
            cons = false;
        }
        
        if(vetor[i]>vetor[i+1]){
            cresc = false;
            cons = false;
        }

    }

    //Verificação
    if (cons == true){
        printf("4");
    }else if(desc == true){
        printf("3");
    }else if (cresc == true){
        printf("2");
    }else{
        printf("1");
    }
    
}