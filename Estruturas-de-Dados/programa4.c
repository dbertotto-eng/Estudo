//Lista com cabeça

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct lista{
    char nome[100];
    int idade;
    char cpf[11];
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
        while (atual != NULL)
        {   
            proxNo = atual->prox;//proxNo++
            free(atual);//libera o atual
            atual = proxNo;//atualiza o atual pro prox
        }
        le->prox = NULL;//Atualiza o prox da cabeça pra NULL;
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
        printf("Nome: %s", temp->nome);
        printf("Idade: %d\n", temp->idade);
        printf("CPF: %s", temp->cpf);
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
    printf("Informe o nome a ser adicionado: \n");
    fgets(novo->nome, 100, stdin);

    printf("Insira a idade da pessoa: \n");
    scanf("%d", &novo->idade);
    getchar();

    printf("Informe o CPF: \n");
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

void busca_nome(no *le){
    char n[100];
    no *aux;
    aux = (no*)malloc(sizeof(no));
    if (aux == NULL)
    {
        printf("Erro de memoria");
        exit(1);
    }
    
    if (vazia(le))
    {
        exibe(le);        
    }

    printf("Digite o nome a ser encontrado: \n");
    fgets(n, 100, stdin);
    
    aux = le->prox;

    while (aux != NULL)
    {
        if (strcmp(n, aux->nome) == 0)
        {
            printf("\n\n====================\n");
            printf("Nome: %s", aux->nome);
            printf("Idade: %d\n", aux->idade);
            printf("CPF: %s", aux->cpf);
            return;
        }else{
            aux = aux->prox;
        }
        
    }
    printf("Nome não cadatrado!!!");
}

void busca_primeiro_nome(no *le){
    char primeiro1[50];
    char primeiro2[50];
    char n[50];
    int cont = 0;
    no *aux;

    if (vazia(le))
    {
        exibe(le);
    }
    
    aux = (no*)malloc(sizeof(no));

    if (aux == NULL)
    {
        printf("Problema de memoria");
        exit(1);
    }

    printf("Digite o primeiro nome: \n");
    fgets(n, 50, stdin);

    n[strcspn(n, "\n")] = '\0';

    sscanf(n, "%s", primeiro1);
    
    aux = le->prox;

    while (aux != NULL)
    {   cont++;
        aux = aux->prox;
    }
    aux = le->prox;

    for (int i = 0; i < cont; i++)
    {
        sscanf(aux->nome, "%s", primeiro2);
        if (strcmp(primeiro1,primeiro2) == 0)
        {
            printf("\n\n====================\n");
            printf("Nome: %s\n", aux->nome);
            printf("Idade: %d\n", aux->idade);
            printf("CPF: %s\n", aux->cpf);
        }
        
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
    case 5:
        busca_nome(le);
        break;
    case 6:
        busca_primeiro_nome(le);
    case -1:
        printf("Saindo...");
        break;
    
    default:
        printf("Opcao invalida");
        break;
    }
}



int main(){

    int op = 0;
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
        printf("5 - Buscar por nome\n");
        printf("6 - Busca Primeiro Nome\n");
        printf("-1 - Sair\n");
        scanf("%d", &op);
        getchar();
        opcao(ini, op);
    }

    free(ini);
    return 0;
}