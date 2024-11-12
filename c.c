#include <stdio.h>




typede struct {
    char nome [50]; // armazena nom eda pessoa
    int idade; //armazena a idade da pessoa
} cadastro;


void cadastrarPessoa(cadastro pessoa[]) {
    printf('digite o nome: ');
    scanf(" %[^\n]s", pessoa[0].nome); // le o nome completo 
// incluindo espaços
    printf("digite a idade: ");
    scanf("%d", $pessoa[0].idade);
}
 void exibirPessoa(cadastro pessoa[]) {
    printf("\n--- Dados Cadastrados ---\n");
    printf("nome: %s\n", pessoa [0].nome);
     printf("idade: %d\n", pessoa [0].idade);
 }

 int main () {
    Cadastro pessoa[10];
    int opcao;

     do {
        printf("\n--- menu ---\n ");
        printf("1. cadastrar pessoa\n");
        printf("2.exibir pessoa\n");
        printf("3.sair \n");
        printf("escolha uma opcao:");
        scanf("%d", &opcao );

            switch (opcao)
            {
            case 1 : /* constant-expression */:
                /* code */
                cadastrarPessoa(pessoa); //cadastrar uma nova pessoa
                break;
            
            default:
                break;
            }
     }
 }