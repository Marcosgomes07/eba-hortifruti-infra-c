#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

#define EBA_SENHA 6     // Definindo a constante para o tamanho da senha
#define EBA_LOGIN 50    // Definindo a constante para o tamanho do login
#define EBA_FRUTAS 10   // Definindo a constante para o número máximo de frutas

// Estrutura que representa uma fruta
typedef struct {
    char nome[20];    // Nome da fruta
    float preco;      // Preço por unidade ou por kg
    int quantidade;   // Quantidade disponível
    char tipo[10];    // Tipo (unidade ou kg)
} Fruta;

// Array para armazenar os produtos (frutas)
Fruta produtos[EBA_FRUTAS];
int numProdutos = 0; // Contador de produtos cadastrados

// Macro para limpar o buffer de entrada
#define CLEAN_BUFF do { int c; while ((c = getchar()) != '\n' && c != EOF); } while (0)

// Função que valida o login do usuário
int validarUsuario(const char* user, const char* senha) {
    // Verifica combinações de usuário e senha
    if (strcmp(user, "Gilson") == 0 && strcmp(senha, "doce") == 0) {
        return 1; // Usuário 1
    } else if (strcmp(user, "Romero") == 0 && strcmp(senha, "gool") == 0) {
        return 2; // Usuário 2
    }
    return 0; // Usuário inválido
}

// Função que cria uma senha a partir da entrada do usuário
char* criarSenha() {
    char* senha = (char*)malloc(sizeof(char) * (EBA_SENHA + 1)); // Aloca memória para a senha
    if (!senha) {
        printf("Erro de alocação de memória.\n");
        exit(1); // Saída se falhar a alocação
    }

    int i;
    for (i = 0; i < EBA_SENHA; i++) {
        senha[i] = getch(); // Captura a senha sem exibir
        if (senha[i] == '\r') {
            break; // Para a entrada se o usuário pressionar 'Enter'
        } else {
            printf("*"); // Exibe um asterisco para cada caractere
        }
    }
    senha[i] = '\0'; // Finaliza a string da senha

    return senha; // Retorna a senha criada
}

// Função que valida se o nome da fruta é composto apenas por letras e espaços
int validarNome(const char* nome) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return 0; // Nome inválido se contiver caracteres não alfabéticos
        }
    }
    return 1; // Nome válido
}

// Função que valida se o preço é positivo
int validarPreco(float preco) {
    return preco > 0; // Retorna verdadeiro se o preço for positivo
}

// Função que inicializa a lista de produtos (frutas) com dados padrão
void inicializarProdutos() {
    // Adiciona frutas com nome, preço e tipo
    strcpy(produtos[0].nome, "Maçã");
    produtos[0].preco = 2.50;
    produtos[0].quantidade = 0;
    strcpy(produtos[0].tipo, "unidade");

    strcpy(produtos[1].nome, "Banana");
    produtos[1].preco = 1.20;
    produtos[1].quantidade = 0;
    strcpy(produtos[1].tipo, "unidade");

    strcpy(produtos[2].nome, "Laranja");
    produtos[2].preco = 1.50;
    produtos[2].quantidade = 0;
    strcpy(produtos[2].tipo, "unidade");

    strcpy(produtos[3].nome, "Uva");
    produtos[3].preco = 3.00;
    produtos[3].quantidade = 0;
    strcpy(produtos[3].tipo, "unidade");

    strcpy(produtos[4].nome, "Pera");
    produtos[4].preco = 2.00;
    produtos[4].quantidade = 0;
    strcpy(produtos[4].tipo, "unidade");

    strcpy(produtos[5].nome, "Manga");
    produtos[5].preco = 2.80;
    produtos[5].quantidade = 0;
    strcpy(produtos[5].tipo, "unidade");

    numProdutos = 6; // Atualiza o contador de produtos
}

// Função que verifica se o produto já está cadastrado
int produtoExistente(const char* nome) {
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            return 1; // Retorna verdadeiro se o produto já existir
        }
    }
    return 0; // Retorna falso se não existir
}

// Função que cadastra um novo produto
void cadastrarProduto() {
    if (numProdutos >= EBA_FRUTAS) {
        printf("Limite de produtos alcançado.\n");
        return; // Se já alcançou o limite, encerra a função
    }

    Fruta novoProduto; // Estrutura para o novo produto

    // Loop para obter um nome válido para o novo produto
    do {
        printf("Cadastrar produto (nome): ");
        fgets(novoProduto.nome, sizeof(novoProduto.nome), stdin);
        novoProduto.nome[strcspn(novoProduto.nome, "\n")] = 0; // Remove a nova linha
        if (!validarNome(novoProduto.nome)) {
            printf("Nome aceito! O nome deve conter apenas letras e espaços.\n");
        } else if (produtoExistente(novoProduto.nome)) {
            printf("Produto já está cadastrado! Tente outro produto.\n");
        }
    } while (!validarNome(novoProduto.nome) || produtoExistente(novoProduto.nome));

    // Loop para obter um tipo válido para o novo produto
    do {
        printf("Cadastrar tipo (unidade/kg): ");
        fgets(novoProduto.tipo, sizeof(novoProduto.tipo), stdin);
        novoProduto.tipo[strcspn(novoProduto.tipo, "\n")] = 0; // Remove a nova linha
        if (strcmp(novoProduto.tipo, "unidade") != 0 && strcmp(novoProduto.tipo, "kg") != 0) {
            printf("Comando inválido! O tipo deve ser 'unidade' ou 'kg'.\n");
        }
    } while (strcmp(novoProduto.tipo, "unidade") != 0 && strcmp(novoProduto.tipo, "kg") != 0);

    char inputPreco[10]; // Array para capturar o preço do produto
    // Loop para obter um preço válido
     // Solicitar preço do produto
    do {
        printf("Cadastrar preço por %s: ", novoProduto.tipo);
        scanf("%f", &novoProduto.preco);
        CLEAN_BUFF; // Limpa o buffer
        if (!validarPreco(novoProduto.preco)) {
            printf("Valor inválido! O preço deve ser um número positivo.\n");
        }
    } while (!validarPreco(novoProduto.preco));

    novoProduto.quantidade = 0; // Inicializa a quantidade
    produtos[numProdutos++] = novoProduto;

    printf("Produto cadastrado com sucesso!\n");
}



// Função que lista todos os produtos cadastrados
void listarProdutos() {
    if (numProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return; // Se não houver produtos, exibe mensagem e encerra
    }

    printf("\nLista de Produtos:\n");
    for (int i = 0; i < numProdutos; i++) {
        // Exibe informações de cada produto
        printf("%d. %s - Preço: R$ %.2f por %s\n", i + 1, produtos[i].nome, produtos[i].preco, produtos[i].tipo);
    }
}

// Função para alterar um produto
void alterarProduto() {
    if (numProdutos == 0) {
        printf("Nenhum produto cadastrado para alterar.\n");
        return;
    }

    // Exibe apenas os nomes dos produtos
    printf("\nLista de Produtos:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("%d. %s\n", i + 1, produtos[i].nome);
    }

    int escolha;
    printf("Escolha um produto para alterar (1-%d) ou 0 para cancelar: ", numProdutos);
    scanf("%d", &escolha);
    CLEAN_BUFF; // Limpa o buffer

    if (escolha < 1 || escolha > numProdutos) {
        printf("Escolha inválida! Operação cancelada.\n");
        return;
    }

    Fruta* produtoSelecionado = &produtos[escolha - 1];

    // Exibe detalhes do produto selecionado
    printf("\nProduto selecionado: %s\n", produtoSelecionado->nome);
    printf("Preço atual: R$ %.2f\n", produtoSelecionado->preco);
    printf("Tipo atual: %s\n", produtoSelecionado->tipo);

    // Atualiza preço
    char inputPreco[10]; // Array para capturar o novo preço
    float novoPreco;
    int valido;
    do {
        printf("Novo preço para %s (use , para decimal): ", produtoSelecionado->nome);
        fgets(inputPreco, sizeof(inputPreco), stdin);

        // Verifica se há ponto no input e troca por vírgula
        valido = 1;
        for (int i = 0; inputPreco[i] != '\0'; i++) {
            if (inputPreco[i] == '.') {
                valido = 0; // Marca como inválido
                break;
            }
            if (!isdigit(inputPreco[i]) && inputPreco[i] != ',' && inputPreco[i] != '\n') {
                valido = 0; // Se contém caracteres inválidos, marca como inválido
            }
        }

        if (valido) {
            // Se válido, substitui vírgula por ponto para conversão
            for (int i = 0; inputPreco[i] != '\0'; i++) {
                if (inputPreco[i] == ',') {
                    inputPreco[i] = '.'; // Troca vírgula por ponto para a conversão
                }
            }
            novoPreco = atof(inputPreco); // Converte a string em float
            if (!validarPreco(novoPreco)) {
                printf("Valor inválido! O preço deve ser um número positivo.\n");
                valido = 0; // Reseta o estado de validade
            }
        } else {
            printf("Entrada inválida! Use apenas números e ',' para decimal.\n");
        }
    } while (!validarPreco(novoPreco) || !valido);

    char novoTipo[10]; // Array para capturar o novo tipo
    // Loop para obter um novo tipo
    do {
        printf("Novo tipo (unidade/kg) para %s: ", produtoSelecionado->nome);
        fgets(novoTipo, sizeof(novoTipo), stdin);
        novoTipo[strcspn(novoTipo, "\n")] = 0; // Remove a nova linha
        if (strcmp(novoTipo, "unidade") != 0 && strcmp(novoTipo, "kg") != 0) {
            printf("Comando inválido! O tipo deve ser 'unidade' ou 'kg'.\n");
        }
    } while (strcmp(novoTipo, "unidade") != 0 && strcmp(novoTipo, "kg") != 0);

    strcpy(produtoSelecionado->tipo, novoTipo); // Atualiza o tipo do produto

    produtoSelecionado->preco = novoPreco;

    printf("Produto atualizado com sucesso!\n");

}

// Função que gerencia o caixa, permitindo ao usuário comprar produtos
void caixa() {
    int escolha, quantidade;
    float total = 0.0; // Inicializa o total da compra

    while (1) {
        listarProdutos(); // Lista produtos disponíveis

        printf("Escolha um produto (1-%d para selecionar): ", numProdutos);
        while (1) {
            scanf("%d", &escolha); // Captura a escolha do produto
            CLEAN_BUFF;
            if (escolha < 1 || escolha > numProdutos) {
                printf("Escolha inválida! Escolha Novamente: "); // Valida a escolha
            } else {
                break; // Saída do loop se a escolha for válida
            }
        }

        Fruta* produtoSelecionado = &produtos[escolha - 1]; // Ponteiro para o produto selecionado

        char input[10]; // Array para capturar a quantidade
        while (1) {
            printf("Quantas %s(s) você deseja comprar? ", produtoSelecionado->tipo);
            fgets(input, sizeof(input), stdin); // Captura a quantidade
            if (sscanf(input, "%d", &quantidade) != 1 || quantidade < 1) {
                printf("Quantidade inválida! Deve ser um número inteiro positivo.\n"); // Valida a quantidade
            } else {
                break; // Saída do loop se a quantidade for válida
            }
        }

        produtoSelecionado->quantidade += quantidade; // Atualiza a quantidade do produto
        total += produtoSelecionado->preco * quantidade; // Atualiza o total da compra

        char opcao;
        do {
            printf("Deseja continuar comprando? (s/n): ");
            opcao = getchar(); // Captura a opção do usuário
            CLEAN_BUFF;
            if (opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N') {
                printf("Opção inválida! Digite 's' para sim ou 'n' para não.\n");
            }
        } while (opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N');

        if (opcao == 'n' || opcao == 'N') {
            break; // Sai do loop se o usuário não quiser continuar
        }
    }

    printf("\nResumo da compra:\n");
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].quantidade > 0) {
            float subtotal = produtos[i].quantidade * produtos[i].preco; // Calcula subtotal
            printf("%s: %d unidade(s) - Preço: R$ %.2f\n", produtos[i].nome, produtos[i].quantidade, subtotal);
        }
    }
    printf("Valor total da compra: R$ %.4f\n", total); // Exibe o total da compra

    printf("clique em qualquer tecla volta ao menu passado\n");
    getch(); // Aguarda a entrada do usuário antes de voltar
}

// Função que solicita o login do usuário
void solicitarLogin(char* user, char** senha) {
    int valido;
    do {
        printf("Digite seu login: ");
        scanf("%s", user); // Captura o login

        valido = validarNome(user); // Valida o login
        if (!valido) {
            printf("Comando inválido! O login deve conter apenas caracteres alfanuméricos.\n");
        }
    } while (!valido);

    printf("Digite sua senha: ");
    *senha = criarSenha(); // Captura a senha

    valido = validarNome(*senha);
    while (!valido) {
        printf("Comando inválido! A senha deve conter apenas caracteres alfanuméricos.\n");
        printf("Digite sua senha novamente: ");
        *senha = criarSenha(); // Solicita nova senha se a anterior não for válida
        valido = validarNome(*senha);
    }
}

// Função que exibe o menu de entrada
void exibirMenuEntrada() {
    printf("Escolha uma opção:\n");
    printf("1. Login como Estação\n");
    printf("2. Login como Caixa\n");
    printf("3. Sair\n");
}

// Função que gerencia o menu da estação
void menuEstacao() {
    int opcaoEstacao;
    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Alterar Produto\n");
        printf("4. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoEstacao);
        CLEAN_BUFF;

        switch (opcaoEstacao) {
            case 1:
                cadastrarProduto(); // Chama a função para cadastrar produtos
                break;
            case 2:
                listarProdutos(); // Chama a função para listar produtos
                break;
            case 3:
                alterarProduto(); // Chama a função para alterar produtos
                break;
            case 4:
                printf("Voltando ao menu de entrada...\n");
                break; // Retorna ao menu anterior
            default:
                printf("Opção inválida! Tente novamente.\n"); // Mensagem de erro
        }
    } while (opcaoEstacao != 4); // Continua até que o usuário escolha voltar
}

// Função principal do programa
int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura a localidade para português

    char login[EBA_LOGIN]; // Array para armazenar o login
    char* senha = NULL; // Ponteiro para a senha

    inicializarProdutos(); // Inicializa a lista de produtos

    int opcaoEntrada;
    do {
        exibirMenuEntrada(); // Exibe o menu de entrada
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoEntrada); // Captura a opção do usuário
        CLEAN_BUFF;

        switch (opcaoEntrada) {
            case 1: {
                solicitarLogin(login, &senha); // Solicita login e senha

                int validacao = validarUsuario(login, senha); // Valida o usuário
                if (validacao == 1) {
                    printf("\nLogin de Estação bem-sucedido!\n");
                    menuEstacao(); // Abre o menu da estação
                } else {
                    printf("Usuário ou senha inválidos!\n");
                }

                free(senha); // Libera a memória da senha
                senha = NULL; // Zera o ponteiro
                break;
            }
            case 2: {
                solicitarLogin(login, &senha); // Solicita login e senha

                int validacao = validarUsuario(login, senha); // Valida o usuário
                if (validacao == 2) {
                    printf("\nLogin de caixa bem-sucedido!\n");
                    caixa(); // Abre o caixa
                } else {
                    printf("Usuário ou senha inválidos!\n");
                }

                free(senha); // Libera a memória da senha
                senha = NULL; // Zera o ponteiro
                break;
            }
            case 3:
                printf("Saindo do programa...\n"); // Mensagem de saída
                break;
            default:
                printf("Opção inválida! Tente novamente.\n"); // Mensagem de erro
        }
    } while (opcaoEntrada != 3); // Continua até que o usuário escolha sair

    return 0; // Finaliza o programa
}