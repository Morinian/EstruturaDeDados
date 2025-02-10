#include <stdio.h>
#include <stdlib.h>
int main()
{
    
    //EX: A
    //dimensões variaveis
    int x = 0, y = 0, z = 0;
    
    //ponteiro de ponteiro
    int ***matriz;
    
    //pedindo metricas
    printf("Digite dimensões X, Y e Z");
    printf("\nDimensão X\n");
    scanf("%d", &x);
    printf("\nDimensão Y\n");
    scanf("%d", &y);
    printf("\nDimensão Z\n");
    scanf("%d", &z);
    printf("------------------------------");
    
    //EX: B
    //Alocação de memória "Malloc"
    
    //alocação linha
    matriz = (int ***) malloc(x * sizeof(int **));
    
    //alocação coluna
    for (int i = 0; i < x; i++){
        matriz[i] = (int**) malloc(y * sizeof(int*));
    }
    
    //alocação profunda
    for(int i = 0; i < x; i++){//linha
        for (int j = 0; j < y; j++){//coluna
            matriz[i][j] = (int*) malloc (z * sizeof(int));
        }
    }
    
    //EX: C
    for(int i = 0; i < x; i++){//linha
        for (int j = 0; j < y; j++){//coluna
            for ( int k = 0; k < z; k++){//profundida
                printf("\nElemento matriz[%d]-[%d]-[%d] \n", i,j,k);
                scanf("%d", &matriz[i][j][k]);
            }
        }
    }
    
    //EX: D
    printf("\n-----------------------------------\n");
    for(int i = 0; i < x; i++){//linha
        printf("\nCamada %d\n",i);
        for (int j = 0; j < y; j++){//coluna
            for ( int k = 0; k < z; k++){//profundida
              printf("%d ", matriz[i][j][k]);
            }
        printf("\n");
        }
    }
    
    //EX: E
    
    //Desalocação profunda
    for(int i = 0; i < x; i++){//linha
        for (int j = 0; j < y; j++){//coluna
            free(matriz[i][j]);
        }
    }
    
    //Desalocação coluna
    for (int i = 0; i < x; i++){
        free(matriz[i]);
    }
    
    //Desalocação linha
    free(matriz);
    

}