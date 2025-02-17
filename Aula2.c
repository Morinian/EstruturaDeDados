#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSortIterativo(int *v, int n){
    int i, j, aux;
    
    for(j = n-1; j >= 1; j--){
        for(i = 0; i<= j-1;i++){
            if (v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
    }
}


void bubbleSortRecursivo(int *v, int n){
    int aux;
    
    if (n == 1){
        return;
    }
    
    for(int i = 0; i<= n-1;i++){
        if (v[i] > v[i+1]){
            aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
        }
    }
    
    bubbleSortRecursivo(v, n-1);
    
}

int main()
{
    int array[5];//criando array
    srand((unsigned)time(NULL)); //Semente do srand
    
    printf("------------- \n");
    printf("Aleatorizando: \n");
    for(int i = 0; i < 5; i++){
        array[i] = 1 + (rand()%10); //adicionando numeros aleatorios
        printf("V[%d] : %d\n", i, array[i]);
    }
    
    int *v = array;// criando ponteiro
    printf("------------- \n");
    printf("bubbleSortIterativo: \n");
    
    bubbleSortIterativo(v, 5);
    
    for(int i = 0; i < 5; i++){
        printf("Ve[%d] : %d\n", i, array[i]);
    }
    
    printf("------------- \n");
    printf("Aleatorizando: \n");
    //Aleatorizando novamente
    for(int i = 0; i < 5; i++){
        array[i] = 1 + (rand()%10); //adicionando numeros aleatorios
        printf("V[%d] : %d\n", i, array[i]);
    }
    
    printf("------------- \n");
    printf("bubbleSortRecursivo: \n");
    
    bubbleSortRecursivo(v, 5);
    
    for(int i = 0; i < 5; i++){
        printf("Ve[%d] : %d\n", i, array[i]);
    }
    return 0;
}
