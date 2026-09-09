#include<stdio.h>
#include<string.h>

//não importa quantas variaveis se colocar, sempre vai ocupar o espaço da maior dessa variáveis
union pessoa
{
    char nome[100];//1 * 100 = 100 bytes
    int idade;// 4 bytes
}pes;// 100 bytes


 
int main(){

    strcpy(pes.nome, "Claudio Aguileira\n");
    printf("Nome: %s", pes.nome);

    pes.idade = 40;

    printf("Idade: %d\n", pes.idade);

    printf("A variavel 'pes' tem %ld bytes de tamanho", sizeof(pes));

    return 0;
}
