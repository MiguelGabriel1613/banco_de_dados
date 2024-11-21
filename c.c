#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];  // Armazena o nome da pessoa
    int idade;      // Armazena a idade da pessoa
} Cadastro;

void cadastrarPessoa(Cadastro pessoa[], int *quantidade) {
    if (*quantidade < 10) {  // Verifica se ainda há espaço para mais cadastros
        printf("Digite o nome: ");
        scanf(" %[^\n]s", pessoa[*quantidade].nome);  // Lê o nome completo

        printf("Digite a idade: ");
        scanf("%d", &pessoa[*quantidade].idade);  // Lê a idade

        (*quantidade)++;  // Aumenta a quantidade de pessoas cadastradas
        printf("Pessoa cadastrada com sucesso!\n");
    } else {
        printf("Limite de cadastros atingido.\n");
    }
}

void exibirPessoa(Cadastro pessoa[], int quantidade) {
    if (quantidade == 0) {
        printf("\n--- Nenhuma pessoa cadastrada ---\n");
        printf("Não há pessoas cadastradas.\n");
    } else {
        printf("\n--- Pessoas Cadastradas ---\n");
        for (int i = 0; i < quantidade; i++) {
            printf("Nome: %s\n", pessoa[i].nome);
            printf("Idade: %d\n", pessoa[i].idade);
        }
    }
}

int logarUsuario(Cadastro pessoa[], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhuma pessoa cadastrada para login.\n");
        return -1;  // Nenhum usuário cadastrado
    }

    char nome[50];
    int idade;

    printf("Digite o nome para login: ");
    scanf(" %[^\n]s", nome);  // Lê o nome
    printf("Digite a idade para login: ");
    scanf("%d", &idade);  // Lê a idade

    // Verifica se o nome e idade correspondem a algum cadastro
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(pessoa[i].nome, nome) == 0 && pessoa[i].idade == idade) {
            printf("\nLogin bem-sucedido! Você está logado como: %s, idade: %d\n", pessoa[i].nome, pessoa[i].idade);
            return i;  // Retorna o índice do usuário logado
        }
    }

    printf("Login falhou! Nenhuma pessoa encontrada com essas informações.\n");
    return -1;  // Retorna -1 se não encontrar o usuário
}

void entrarPerfil(Cadastro pessoa[], int usuarioLogado) {
    if (usuarioLogado == -1) {
        printf("Nenhum usuário está logado.\n");
        return;
    }

    char nome[50];
    int idade;

    printf("\nBem-vindo ao seu perfil, %s!\n", pessoa[usuarioLogado].nome);
    printf("Digite seu nome (se quiser atualizar): ");
    scanf(" %[^\n]s", nome);  // Permite que o usuário digite o nome novamente, personalizando a experiência

    printf("Digite sua idade (se quiser atualizar): ");
    scanf("%d", &idade);  // Permite que o usuário digite a idade novamente

    // Atualiza o perfil do usuário
    strcpy(pessoa[usuarioLogado].nome, nome);
    pessoa[usuarioLogado].idade = idade;

    printf("\nPerfil atualizado!\n");
    printf("Nome: %s, Idade: %d\n", pessoa[usuarioLogado].nome, pessoa[usuarioLogado].idade);
}

int main() {
    Cadastro pessoa[10];  // Definindo um array para armazenar até 10 pessoas
    int opcao;
    int quantidade = 0;  // Variável que conta quantas pessoas foram cadastradas
    int usuarioLogado = -1;  // Indica se um usuário está logado (inicia com -1, sem login)

    do {
        // Exibe o menu com as opções solicitadas
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar pessoa\n");
        printf("2. Exibir pessoas cadastradas\n");
        printf("3. Entrar no perfil do usuário\n");
        printf("4. Sair\n");

        // Loop para garantir que o usuário insira uma opção válida
        while (1) {
            printf("Escolha uma opção: ");
            if (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 4) {
                printf("Entrada inválida! Digite um número entre 1 e 4.\n");
                while(getchar() != '\n');  // Limpa o buffer do teclado
            } else {
                break;  // Se a entrada for válida, sai do loop
            }
        }

        switch (opcao) {
            case 1:
                cadastrarPessoa(pessoa, &quantidade);  // Cadastrar uma nova pessoa
                break;
            case 2:
                exibirPessoa(pessoa, quantidade);  // Exibir dados cadastrados
                break;
            case 3:
                usuarioLogado = logarUsuario(pessoa, quantidade);  // Tenta logar um usuário
                if (usuarioLogado != -1) {
                    entrarPerfil(pessoa, usuarioLogado);  // Entrar no perfil do usuário
                }
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                // Não é necessário, pois já estamos validando a entrada antes
                break;
        }

    } while (opcao != 4);  // O loop continua até o usuário escolher a opção 4 para sair

    return 0;
}
