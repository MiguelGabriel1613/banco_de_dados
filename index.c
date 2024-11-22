#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    char telefone[15]; // Formato: (XX)XXXXX-XXXX
} Cadastro;

void cadastrarPessoa(Cadastro pessoa[], int *contador) {
    if (*contador >= 10) {
        printf("Limite de cadastros atingido!\n");
        return;
    }

    printf("Digite o nome (sem espaços): ");
    scanf("%s", pessoa[*contador].nome);

    printf("Digite a idade: ");
    while (scanf("%d", &pessoa[*contador].idade) != 1 || pessoa[*contador].idade <= 0) {
        printf("Idade inválida! Digite novamente: ");
        while (getchar() != '\n'); // Limpa o buffer
    }

    printf("Digite o telefone no formato (XX)XXXXX-XXXX: ");
    scanf("%s", pessoa[*contador].telefone);

    // Validação simples do telefone
    if (pessoa[*contador].telefone[0] != '(' || pessoa[*contador].telefone[3] != ')' || pessoa[*contador].telefone[9] != '-') {
        printf("Formato de telefone inválido! Cadastro cancelado.\n");
        return;
    }

    (*contador)++;
    printf("Pessoa cadastrada com sucesso!\n");
}

void exibirPessoas(Cadastro pessoa[], int contador) {
    if (contador == 0) {
        printf("\nNenhuma pessoa cadastrada.\n");
        return;
    }

    printf("\n--- Dados Cadastrados ---\n");
    for (int i = 0; i < contador; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoa[i].nome);
        printf("Idade: %d\n", pessoa[i].idade);
        printf("Telefone: %s\n", pessoa[i].telefone);
    }
}

int main() {
    Cadastro pessoa[10];
    int opcao, contador = 0;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar pessoa\n");
        printf("2. Exibir pessoas\n");
        printf("3. Sair\n");
        printf("Escolha uma opção (1-3): ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Digite um número.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrarPessoa(pessoa, &contador);
                break;
            case 2:
                exibirPessoas(pessoa, contador);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Escolha entre 1 e 3.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}
