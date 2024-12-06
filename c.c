#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 50

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

void cadastrarProduto(Produto produtos[], int *contador) {
    if (*contador >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    // Verifica se o código já existe
    for (int i = 0; i < *contador; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Código já cadastrado!\n");
            return;
        }
    }

    produtos[*contador].codigo = codigo;

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", produtos[*contador].nome);

    printf("Digite o preço do produto: ");
    while (scanf("%f", &produtos[*contador].preco) != 1 || produtos[*contador].preco < 0) {
        printf("Preço inválido! Digite novamente: ");
        while (getchar() != '\n'); // Limpa o buffer
    }

    printf("Digite a quantidade do produto: ");
    while (scanf("%d", &produtos[*contador].quantidade) != 1 || produtos[*contador].quantidade < 0) {
        printf("Quantidade inválida! Digite novamente: ");
        while (getchar() != '\n'); // Limpa o buffer
    }

    (*contador)++;
    printf("Produto cadastrado com sucesso!\n");
}

void exibirProdutos(Produto produtos[], int contador) {
    if (contador == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    printf("\n--- Produtos Cadastrados ---\n");
    for (int i = 0; i < contador; i++) {
        printf("Código: %d\n", produtos[i].codigo);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preço: %.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n\n", produtos[i].quantidade);
    }
}

void buscarProdutoPorCodigo(Produto produtos[], int contador) {
    if (contador == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < contador; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\n", produtos[i].nome);
            printf("Preço: %.2f\n", produtos[i].preco);
            printf("Quantidade: %d\n", produtos[i].quantidade);
            return;
        }
    }

    printf("Produto não encontrado.\n");
}

void atualizarQuantidade(Produto produtos[], int contador) {
    if (contador == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    int codigo, novaQuantidade;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < contador; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Produto encontrado. Digite a nova quantidade: ");
            while (scanf("%d", &novaQuantidade) != 1 || novaQuantidade < 0) {
                printf("Quantidade inválida! Digite novamente: ");
                while (getchar() != '\n'); // Limpa o buffer
            }

            produtos[i].quantidade = novaQuantidade;
            printf("Quantidade atualizada com sucesso!\n");
            return;
        }
    }

    printf("Produto não encontrado.\n");
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int contador = 0, opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Exibir Todos os Produtos\n");
        printf("3. Buscar Produto por Código\n");
        printf("4. Atualizar Quantidade\n");
        printf("5. Sair\n");
        printf("Escolha uma opção (1-5): ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Digite um número.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &contador);
                break;
            case 2:
                exibirProdutos(produtos, contador);
                break;
            case 3:
                buscarProdutoPorCodigo(produtos, contador);
                break;
            case 4:
                atualizarQuantidade(produtos, contador);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Escolha entre 1 e 5.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
