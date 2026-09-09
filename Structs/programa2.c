#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//typedef --> redefinir tipos

int main(){

    typedef float nota;

    //declarando variáveis

    nota prova1 = 7.0;
    nota prova2 = 6.0;

    nota soma = prova1 + prova2;

    printf("Soma das notas: %.2f", soma);

    return 0;
}