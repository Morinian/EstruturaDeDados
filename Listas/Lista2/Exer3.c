#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

//Forma recursiva
void alEuclides(int num1, int num2){

   if(num1 % num2 == 0){
    printf("Recurdivo: maximo divisor: %d", num2);
    return;
   }else
    alEuclides(num2,num1%num2);

}

int main(){
    int num1 , num2;
    num1 = 42;
    num2 = 30;

    alEuclides(num1,num2);

    while (num1%num2 != 0)
    {
        int temp;
        temp = num2;
        num2 = num1%num2;
        num1 = temp;
    }
    printf("\nIterativo: maximo divisor: %d", num2);

}