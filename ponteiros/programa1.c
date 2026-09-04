#include<stdio.h>

//ponteiro aponta pro endereço de memória

void incrementa(int *contador){
    printf("Antes de incrementar\n");
    printf("O contador vale: %d\n", (*contador));
    printf("O endereco de memoria vale: %d\n", contador);

    printf("Depois de incrementar\n"); 
    printf("O contador vale %d\n", ++(*contador));
    printf("O endereco de memoria vale: %d\n", contador);
}

int main(){
    int contador = 10;

    printf("Antes de incrementar\n");
    printf("O contador vale %d\n", contador);
    printf("O endereco de memoria vale: %d\n", &contador);

    incrementa(&contador);
    //sem o ponteiro ele não "salva" pois a função não retorna nada

    printf("Depois de incrementar\n");
    printf("O contador vale %d\n", contador);
    printf("O endereco de memoria vale: %d\n", &contador);
    return 0;
}