#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    int qtd, *p;

    printf("Informe o numero de elementos para o vetor\n");
    scanf("%d", &qtd);

    p = malloc(qtd * sizeof(int));
    if (p == NULL)
    {
        printf("Erro de memoria");
        exit (1);
    }
    

    for (int i = 0; i < qtd; i++)
    {
        printf("Informe o valor do ponteiro na posição %d\n", i);
        scanf("%d", &p[i]);
    }
    
    for (int i = 0; i < qtd; i++)
    {
        printf("No vetor 'Numero[%d] esta o valor %d\n", i,p[i]);
    }

    printf("A memoria ocupa %ld", qtd * sizeof(int));

    free(p);
    p = NULL;

    return 0;
}