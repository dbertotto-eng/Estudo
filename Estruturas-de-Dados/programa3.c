#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Lista Encadeada
//possui um ponteiro apontando pro proximo / prox;
//podemos inserir o elemento no inicio ou no fim

struct st_no//estrutura chamada nó
{
    int valor;//variavel do tipo inteiro
    struct st_no *prox;//atributo do proprio tipo da struct
};

typedef struct st_no no;

int vazia(no *le){//le de lista encadeada
    if (le->prox == NULL)//le->prox seria como le.prox, nesse sentido
    {
        return 1;
    }else{
        return 0;
    }
    
}

void inicia(no *le){
    le->prox = NULL;
}

void libera(no *le){
    if(!vazia(le)){
        no *proxNo, *atual;
        atual = le->prox;
        while (atual->prox != NULL)
        {
            proxNo = atual->prox;
            free(atual);
        }
        
    }
}

void exibe(no *le){
    if (vazia(le))
    {
        printf("A lsita esta vazia");
        return;
    }
    no *temp;
    temp = le->prox;
    while (temp->prox != NULL)
    {
        printf("%d", temp->valor);
        temp = temp->prox;//seria o temp++
    }
    printf("\n\n");
}

void insere_inicio(no *le){
    no *novo = (no*)malloc(sizeof(no));//inicia a memoria com um malloc

    if (novo == NULL)//verifica se deu erro
    {
        printf("Erro de memoria");
        exit (1);
    }
    printf("Informe o valor: ");
    scanf("%d", &novo->valor); 
    
    no *oldHead = le->prox; 
    le->prox = novo;
    novo->prox = oldHead;//o novo vai ser a cabeçaa e a antiga cabeça vai ser o proximo elemento
}

void insere_final(no *le){
    no *novo = (no*)malloc(sizeof(no));

    if (novo == NULL)
    {
        printf("Problema de memoria!!!");
        exit (1);
    }
    printf("Informe o valor: ");
    scanf("%d", &novo->valor);

    novo->prox = NULL;

    if (vazia(le))
    {
        le->prox = novo;
    }else{

        no *tmp = le->prox;

        while (tmp->prox != NULL)
        {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    
    
}

void opcao(no *le, int op){
    switch (op)
    {
    case 1:
        exibe(le);
        break;
    case 2:
        insere_inicio(le);
        break;
    case 3:
        insere_final(le);
        break;
    case 4:
        inicia(le);
        break;
    case 0:
        printf("Saindo...");
        break;
    
    default:
        printf("Valor invalido");
        break;
    }
}


int main(){

    no *le = (no*)malloc(sizeof(no));

    if (le == NULL)
    {
        printf("Erro de memoria");
        exit(1);
    }
    inicia(le);
    

    int op = - 1;

    while (op != 0)
    {
        printf("==========Escolha uma opcao==========\n");
        printf("1 - Exibir : \n");
        printf("2 - Insere inicio : \n");
        printf("3 - Insere Fim : \n");
        printf("4 - Inicia : \n");
        printf("0 - Sair : \n");
        scanf("%d", &op);
        opcao(le, op);
    }

    free(le);
    le = NULL;

    return 0;
}