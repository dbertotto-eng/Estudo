#include<stdio.h>
#include<stdlib.h>

/*
*Realloc - Realocação de memória
*Precisa - Malloc/Calloc
 */

int main(){
    int qtd, *p;

    printf("Informe a quantidade dde elementos: \n");
    scanf("%d", &qtd);

    p = calloc(qtd, sizeof(int));

    if (p == NULL)
    {
        printf("Erro de memoria");
        exit (1);
    }
    
    printf("O  vetor 'p' ocupa %ld bytes\n", qtd * sizeof(int));

    printf("Informe a quantidade para o numero do vetor: \n");
    scanf("%d", &qtd);

    p = realloc(p, qtd * sizeof(int));

    printf("O  vetor 'p' ocupa %ld bytes", qtd * sizeof(int));

    if (p == NULL)
    {
        printf("Erro de memoria");
        exit (1);
    }

    free(p);
    p = NULL;

    return 0;
}