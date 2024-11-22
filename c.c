#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    char telefone[15]; // Espaço para telefone no formato (XX) XXXXX-XXXX
} Cadastro;

void limparBuffer() {
    while (getchar() != '\n');
}

void cadastrarPessoa(Cadastro pessoa[], int *contador) {
    if (*contador >= 10) {
        printf("Limite de cadastros atingido!\n");
        return;
    }

    printf("Digite o nome: ");
    limparBuffer(); // Limpa o buffer do `scanf` anterior
    fgets(pessoa[*contador].nome, sizeof(pessoa[*contador].nome), stdin);
    pessoa[*contador].nome[strcspn(pessoa[*contador].nome, "\n")] = '\0'; // Remove '\n'

    printf("Digite a idade: ");
    while (scanf("%d", &pessoa[*contador].idade) != 1 || pessoa[*contador].idade < 0) {
        printf("Idade inválida! Digite novamente: ");
        limparBuffer();
    }

    printf("Digite o telefone ((XX) XXXXX-XXXX): ");
    limparBuffer(); // Limpa o buffer de entrada
    fgets(pessoa[*contador].telefone, sizeof(pessoa[*contador].telefone), stdin);
    pessoa[*contador].telefone[strcspn(pessoa[*contador].telefone, "\n")] = '\0'; // Remove '\n'

    // Validação básica do formato do telefone
    if (strlen(pessoa[*contador].telefone) != 14 || pessoa[*contador].telefone[0] != '(' || pessoa[*contador].telefone[3] != ')' || pessoa[*contador].telefone[9] != '-') {
        printf("Formato de telefone inválido! Digite novamente.\n");
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
            printf("Entrada inválida! Por favor, escolha uma opção numérica válida.\n");
            limparBuffer();
            continue; // Reinicia o loop para permitir nova tentativa
        }

        limparBuffer(); // Adiciona limpeza para evitar problemas em inputs subsequentes

        if (opcao < 1 || opcao > 3) {
            printf("Opção inválida! Escolha uma opção entre 1 e 3.\n");
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
        }
    } while (opcao != 3);

    return 0;
}
