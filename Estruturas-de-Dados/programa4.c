//Lista com cabeça

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct lista{
    char nome[100];
    int idade;
    char cpf[14];
    struct lista *prox;
};

typedef struct lista no;

int vazia(no *le){
    if (le->prox == NULL)
    {
        //lista vazia
        return 1;
    }else{
        return 0;
    }
    
}

void start(no *le){
    le->prox = NULL;
}

void libera(no *le){
    if (!vazia(le))
    {
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
        printf("A Lista esta vazia");
        return;
    }
    no *temp;
    temp = le->prox;
    while (temp != NULL)
    {   
        printf("\n\n====================\n");
        printf("Nome: %s\n", temp->nome);
        printf("Idade: %d\n", temp->idade);
        printf("CPF: %s\n", temp->cpf);
        temp = temp->prox;
    }
}

void inserir_inicio(no *le){
    no *novo;
    novo = (no*)malloc(sizeof(no));

    if (novo == NULL)
    {
        printf("Erro de memoria");
        exit(1);
    }
    printf("Informe o nome a ser adicionado:");
    fgets(novo->nome, 100, stdin);
    printf("Insira a idade da pessoa: ");
    scanf("%d", &novo->idade);
    getchar();
    printf("Informe o CPF:");
    fgets(novo->cpf, 14, stdin);

    no *oldHead = le->prox;
    le->prox = novo;
    novo->prox = oldHead;
}

void inserir_Fim(no *le){
    no *novo;
    novo = (no*)malloc(sizeof(no));
    if (novo == NULL)
    {
        printf("Erro de memoria");
        exit(1);
    }

    //primeiro faz as informações do novo e depois coloca o novo->prox apontando pra NULL
    printf("Informe o nome a ser adicionado: \n");
    fgets(novo->nome, 100, stdin);

    printf("Insira a idade da pessoa: \n");
    scanf("%d", &novo->idade);
    getchar();
    printf("Informe o CPF: \n");
    fgets(novo->cpf, 14, stdin);

    novo->prox = NULL;

    if (vazia(le))
    {
        le->prox = novo;//se a lista estiver vazia a proxima celula vai ser o novo e não mais o NULL;
    }else{
        no *temp = le->prox;
        while (temp->prox != NULL)
        //enquanto temp->prox for diferente de NULL temp vai percorrer a lista ate chegar no final dela
        {
            temp = temp->prox;
        }
        temp->prox = novo;
        //quando chegar no final da lista temp->prox vai apontar pro novo e o novo->prox ja ta apontando pra NULL
    }
}

void opcao(no *le, int op){
    switch (op)
    {
    case 1:
        exibe(le);
        break;
    case 2:
        inserir_inicio(le);
        break;
    case 3:
        inserir_Fim(le);
        break;
    case 4:
        libera(le);
        break;
    case -1:
        printf("Saindo...");
        break;
    
    default:
        printf("Opcao invalida");
        break;
    }
}



int main(){

    int op;
    no *ini;

    ini = (no*)malloc(sizeof(no));
    if (ini == NULL)
    {
        printf("Erro de memoria");
        exit(1);
    }

    start(ini);

    while (op != -1)
    {
        printf("\n=====Escolha uma opcao=====\n");
        printf("1 - Exibir Lista\n");
        printf("2 - Inserir no Inicio\n");
        printf("3 - Inserir no Final\n");
        printf("4 - Libera a Lista\n");
        printf("-1 - Sair\n");
        scanf("%d", &op);
        getchar();
        opcao(ini, op);
    }

    free(ini);
    return 0;
}