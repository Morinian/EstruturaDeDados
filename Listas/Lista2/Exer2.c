#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// A moda de um conjunto de dados é o valor que detém o maior número de observações, ou seja, o
// valor mais frequente (i.e., o que está na moda). No caso de empate qualquer um dos valores de
// frequência máxima pode ser considerado como sendo uma moda. Implemente, em linguagem C, um
// algoritmo iterativo que calcula a moda de um vetor de valores inteiros

int main(){
    int n = 10; // tamanho dos vetores
    int cont = 0; // conta as vezes que o vetor[i] aparece

    int vetor[10] = {4, 3, 5, 1, 5, 5, 5, 1, 1, 1};
    int qtd[10];

    for (int i = 0; i < n; i++){//pegar um numero do vetor

        for (int j = 0; j < n; j++) //contar quantas vezes aparece o numero do vetor i nele mesmo
        {
            if(vetor[i] == vetor[j])
                cont++;
        }

        qtd[i] = cont; // salva o numero de vezes no vetor
        cont = 0;
    }

    for (int i = 0; i < n; i++){ // analisa nosso vetor de qtd para ver qual que possui o numero maior ou seja o numero moda
        if(qtd[cont] < qtd[i]){
            cont++;
        }
    }

    printf("O numero %d apareceu %d", vetor[cont], qtd[cont]);

}