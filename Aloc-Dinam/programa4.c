#include<stdio.h>
#include<stdlib.h>

int main(){

    int *p, linha = 3, coluna = 3;

    p = malloc(linha * coluna * sizeof(int));

    if (p == NULL)
    {
        printf("Problema de memoria");
        exit(1);
    }

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            p[i * coluna + j] =  3 * i + j;
        }
        
    }

    for (int i = 0; i < linha; i++)
    {
        printf("\n");
        for (int j = 0; j < coluna; j++)
        {
            printf("%d ", p[i * coluna + j]);
        }
        
    }
    

    free(p);
    p = NULL;
    


    

    return 0;
}