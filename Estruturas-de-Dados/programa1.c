#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Fila/Queue --> Primeiro a entrar primeiro a sair
//Sempre que um elemento novo é adicionado ele vai pro final da 'fila'
//FIFO -- Firt in / First out

//enqueue - adiciona elementos
//dequeue - removve elementos
//clear - limpa a fila

#define TAMFILA 10

int fila[TAMFILA] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int head = 0;
int tail = 0;

void lista_elementos(){
    printf("===========Fila atual==========\n");

    for (int i = 0; i < TAMFILA; i++)
    {
        printf("-");
        printf("|%d|", fila[i]);
        printf("-");
    }
    printf("\nHead: %d\n", fila[0]);
    printf("Tail: %d\n", fila[TAMFILA - 1]);
}

void enqueue(){
    int val;
    if (tail < TAMFILA)
    {
        printf("Informe o elemento para adicionar na fila: \n");
        scanf("%d", &val);
        fila[tail] = val;
        tail++;
        
    }else{
        printf("Fila cheia\n");
    }
    
}

void dequeue(){
    if (head < tail)
    {
        fila[head] = 0;
        head++;
        
    }else{
        printf("A fila esta vazia");
    }
    
}

void clear(){
    for (int i = 0; i < TAMFILA; i++)
    {
        fila[i] = 0;
    }
    head = 0;
    tail = 0;
    
}

int main(){

    int op = -1;
    
    while (op != 0)
    {
        printf("Escolha uma opcao\n");
        printf("==========Opcoes==========\n");
        printf("1 - Listar elementos\n");
        printf("2 - Adicionar elemento\n");
        printf("3 - Remover elemento\n");
        printf("4 - Limpar a Fila\n");
        printf("0 - Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            lista_elementos();
            break;
        case 2:
            enqueue();
            break;
        case 3:
            dequeue();
            break;
        case 4:
            clear();
            break;
        case 0:
            printf("Saindo...");
            break;
        
        default:
            printf("Valor invalido");
            break;
        }
    }
    
    
    

    return 0;
}