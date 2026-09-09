#include<stdio.h>
#include<stdlib.h>

//pilha / stack
//FIFO -primeiro a entrar / ultimo a sair
//LIFO - ultimo a entrar / primeiro a sair
#define TAMPILHA 10

int pilha[TAMPILHA] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int topo = 0;

void listar_pilha(){
    for (int i = TAMPILHA - 1; i >= 0; i--)
    {   
        printf("-");
        printf("|%d|\n", pilha[i]);
        printf("-");
    }
    printf("\nTopo: %d", topo);
    printf("\n\n");
    
}

void push(){
    int val;
    if (topo < TAMPILHA)
    {
        printf("Digite o elemento: ");
        scanf("%d", &val);
        pilha[topo] = val;
        topo++;
    }else{
        printf("Pilha cheia\n");
    }
    listar_pilha();
}

void pop(){
    if (topo >= 0)
    {
        pilha[topo] = 0;
        topo = topo - 1;
    }else{
        printf("Pilha Vazia");
    }
    listar_pilha();
}

void clear(){
    for (int i = 0; i < TAMPILHA; i++)
    {
        pilha[i] = 0;
    }
    topo = 0;
}

int main(){
    int op = - 1;

    while (op != 0)
    {   printf("======Opcoes======\n");
        printf("1 - Adicionar\n");
        printf("2 - Retirar\n");
        printf("3 - Limpar\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            clear();
            break;
        case 0:
            printf("Saindo...\n");
            printf("Terminando execucao");
            break;
        
        default:
            printf("Valor invalido");
            break;
        }

    }
    

    return 0;
}