/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void converteHoras(int total_segundos, int *horas, int *min, int *seg){

    *horas = total_segundos/3600;
    *min = (total_segundos%3600)/60;
    *seg = (total_segundos%3600)%60;
    
}

int main()
{
    int total_segundos;
    int horas, min, seg;
    int *h = &horas, *m = &min,*s = &seg;
    
    printf("Digite o total de segundos \n");
    scanf("%d", &total_segundos); 

    converteHoras(total_segundos,h,  m, s);
    printf("%d:%d:%d", horas, min, seg);
}
