#include<stdio.h>

int main(){

    int n;
    int *p;
    printf("Informe um numero: ");
    scanf("%d", &n);


    p = &n;

    printf("Valor informado: %d\n", n);

    printf("Valor do ponteiro: %d\n", *p);
    printf("Valor na memoria: %d", p);
    return 0;
}