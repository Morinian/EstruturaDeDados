#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Implemente, em linguagem C, um programa que utilize ponteiro de ponteiro para manipular um vetor de palavras (strings). 
// Seu programa deve: 

//(a) Pedir ao usuário que informe a quantidade de palavras que deseja inserir; 

//(b) Alocar dinamicamente um vetor de ponteiros para char, para armazenar as palavras, com no máximo 100 caracteres cada;

//(c) Solicitar ao usuário que insira as palavras, alocando dinamicamente memória para cada uma delas; 

//(d) Codicar uma função chamada converterParaMaiusculo, que recebe um ponteiro de ponteiro e a quantidade de palavras,
// convertendo todas para maiúsculas (CAIXA ALTA); 

//(e) Exibir as palavras informadas pelo usuário antes e depois da conversão; 

//(f ) Liberar (desalocar) toda a memória alocada dinamicamente ao nal do programa.

void converterParaMaiusculo(char **vetor, int tamanho){
    
    for (int i = 0; i < tamanho; i++) { 
    char *p = vetor[i]; 
        
    while (*p) { 
        *p = toupper(*p); 
         p++; 
    }

}

int main()
{

  //Quantas palavras a pessoa vai adicionar
  int tamanho;
  printf("Quantas palavras você irá adicionar: ");
  scanf("%d", &tamanho);
  
  //criando vetor
  char **vetor;
  
  //alocando
  vetor = (char **) malloc(tamanho * sizeof(char*));
  
  //alocando e pedindo as palavras
  for(int i = 0; i < tamanho; i++){
      vetor[i] = (char *) malloc(100 * sizeof(char));
      scanf("%s", vetor[i]);
  }
  
  //Escrevendo normalmente as palavras
  printf("\nAs palavras são:  \n ");
  for (int i = 0; i < tamanho; i++){
      printf("%s \n ", vetor[i]);
  }
  
  //chamando função
  converterParaMaiusculo(vetor,tamanho);
  
  //Escrevendo as palavras depois da função
  printf("\nAs palavras são:  \n ");
  for (int i = 0; i < tamanho; i++){
      printf("%s \n ", vetor[i]);
  }
  
  //Dessalocando memória
    for (int i = 0; i < tamanho; i++){
       free(vetor[i]);
    }
    free(vetor);
  
}
