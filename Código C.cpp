#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 100
#define NUM_QUARTOS 20
#define FILE_CLIENTES "clientes.dat"
#define FILE_FUNCIONARIOS "funcionarios.dat"
#define FILE_ESTADIAS "estadias.dat"
#define FILE_QUARTOS "quartos.dat"

typedef struct {
    int codigo;
    char nome[MAX_LEN];
    char endereco[MAX_LEN];
    char telefone[MAX_LEN];
} Cliente;

typedef struct {
    int codigo;
    char nome[MAX_LEN];
    char telefone[MAX_LEN];
    char cargo[MAX_LEN];
    float salario;
} Funcionario;

typedef struct {
    int numero;
    int capacidade;
    float valorDiaria;
    char status[MAX_LEN];
} Quarto;

typedef struct {
    int codigoEstadia;
    char dataEntrada[MAX_LEN];
    char dataSaida[MAX_LEN];
    int qtdDiarias;
    int codigoCliente;
    int numeroQuarto;
} Estadia;

// Funções para manipulação de arquivos

void inicializarArquivos() {
    FILE *fp;

    fp = fopen(FILE_CLIENTES, "ab");
    fclose(fp);

    fp = fopen(FILE_FUNCIONARIOS, "ab");
    fclose(fp);

    fp = fopen(FILE_ESTADIAS, "ab");
    fclose(fp);

    fp = fopen(FILE_QUARTOS, "ab");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de quartos.\n");
        exit(1);
    }

    // Inicializar os quartos apenas se o arquivo estiver vazio
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    if (fileSize == 0) {
        Quarto quartos[NUM_QUARTOS];

        // Inicializar os quartos com as especificações fornecidas
        int numeroQuarto = 1;
        for (int i = 0; i < NUM_QUARTOS; i++) {
            if (i < 5) {
                quartos[i].numero = numeroQuarto++;
                quartos[i].capacidade = 1;
                quartos[i].valorDiaria = 100.0;
                strcpy(quartos[i].status, "desocupado");
            } else if (i < 10) {
                quartos[i].numero = numeroQuarto++;
                quartos[i].capacidade = 2;
                quartos[i].valorDiaria = 200.0;
                strcpy(quartos[i].status, "desocupado");
            } else if (i < 15) {
                quartos[i].numero = numeroQuarto++;
                quartos[i].capacidade = 3;
                quartos[i].valorDiaria = 300.0;
                strcpy(quartos[i].status, "desocupado");
            } else {
                quartos[i].numero = numeroQuarto++;
                quartos[i].capacidade = 4;
                quartos[i].valorDiaria = 400.0;
                strcpy(quartos[i].status, "desocupado");
            }
        }

        fwrite(quartos, sizeof(Quarto), NUM_QUARTOS, fp);
    }

    fclose(fp);
}

// Inicializa os arquivos que salvam os dados
int salvarClientes(Cliente clientes[], int n) {
    FILE *fp;
    fp = fopen(FILE_CLIENTES, "wb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de clientes.\n");
        return 0;
    }

    fwrite(clientes, sizeof(Cliente), n, fp);
    fclose(fp);
    return 1;
}

int lerClientes(Cliente clientes[]) {
    FILE *fp;
    int n = 0;

    fp = fopen(FILE_CLIENTES, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de clientes.\n");
        return 0;
    }

    while (fread(&clientes[n], sizeof(Cliente), 1, fp) == 1) {
        n++;
    }

    fclose(fp);
    return n;
}

int salvarFuncionarios(Funcionario funcionarios[], int n) {
    FILE *fp;
    fp = fopen(FILE_FUNCIONARIOS, "wb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de funcionarios.\n");
        return 0;
    }

    fwrite(funcionarios, sizeof(Funcionario), n, fp);
    fclose(fp);
    return 1;
}

int lerFuncionarios(Funcionario funcionarios[]) {
    FILE *fp;
    int n = 0;

    fp = fopen(FILE_FUNCIONARIOS, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de funcionarios.\n");
        return 0;
    }

    while (fread(&funcionarios[n], sizeof(Funcionario), 1, fp) == 1) {
        n++;
    }

    fclose(fp);
    return n;
}

int salvarEstadias(Estadia estadias[], int n) {
    FILE *fp;
    fp = fopen(FILE_ESTADIAS, "wb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de estadias.\n");
        return 0;
    }

    fwrite(estadias, sizeof(Estadia), n, fp);
    fclose(fp);
    return 1;
}

int lerEstadias(Estadia estadias[]) {
    FILE *fp;
    int n = 0;

    fp = fopen(FILE_ESTADIAS, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de estadias.\n");
        return 0;
    }

    while (fread(&estadias[n], sizeof(Estadia), 1, fp) == 1) {
        n++;
    }

    fclose(fp);
    return n;
}

int salvarQuartos(Quarto quartos[], int n) {
    FILE *fp;
    fp = fopen(FILE_QUARTOS, "wb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de quartos.\n");
        return 0;
    }

    fwrite(quartos, sizeof(Quarto), n, fp);
    fclose(fp);
    return 1;
}

int lerQuartos(Quarto quartos[]) {
    FILE *fp;
    int n = 0;

    fp = fopen(FILE_QUARTOS, "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de quartos.\n");
        return 0;
    }

    while (fread(&quartos[n], sizeof(Quarto), 1, fp) == 1) {
        n++;
    }

    fclose(fp);
    return n;
}

// Função para calcular a quantidade de diárias

int calcularDiasEntreDatas(const char dataInicio[], const char dataFim[]) {
    struct tm tmInicio = {0};
    struct tm tmFim = {0};

    sscanf(dataInicio, "%d/%d/%d", &tmInicio.tm_mday, &tmInicio.tm_mon, &tmInicio.tm_year);
    sscanf(dataFim, "%d/%d/%d", &tmFim.tm_mday, &tmFim.tm_mon, &tmFim.tm_year);

    tmInicio.tm_mon -= 1; // Ajuste do mês para o formato correto
    tmFim.tm_mon -= 1;
    tmInicio.tm_year -= 1900; // Ajuste do ano para o formato correto
    tmFim.tm_year -= 1900;

    time_t timeInicio = mktime(&tmInicio);
    time_t timeFim = mktime(&tmFim);

    double diffTime = difftime(timeFim, timeInicio);
    int diffDays = diffTime / (60 * 60 * 24);

    return diffDays;
}

void atualizarQuartos(Quarto quartos[], int n) {
    salvarQuartos(quartos, n);
}

// Funções principais do programa

// Cadastro de clientes
void cadastrarCliente() {
    Cliente cliente;
    Cliente clientes[MAX_LEN];
    int qtdClientes = lerClientes(clientes);

    printf("Codigo do cliente: ");
    scanf("%d", &cliente.codigo);

    for (int i = 0; i < qtdClientes; i++) {
        if (clientes[i].codigo == cliente.codigo) {
            printf("Ja existe um cliente com esse codigo!\n");
            return;
        }
    }

    printf("Nome: ");
    scanf(" %[^\n]", cliente.nome);
    printf("Endereco: ");
    scanf(" %[^\n]", cliente.endereco);
    printf("Telefone: ");
    scanf(" %[^\n]", cliente.telefone);

    clientes[qtdClientes] = cliente;
    qtdClientes++;

    if (salvarClientes(clientes, qtdClientes)) {
        printf("Cliente cadastrado com sucesso!\n");
    } else {
        printf("Erro ao cadastrar o cliente.\n");
    }
}

// Cadastro de funcionários
void cadastrarFuncionario() {
    Funcionario funcionario;
    Funcionario funcionarios[MAX_LEN];
    int qtdFuncionarios = lerFuncionarios(funcionarios);

    printf("Codigo do funcionario: ");
    scanf("%d", &funcionario.codigo);

    for (int i = 0; i < qtdFuncionarios; i++) {
        if (funcionarios[i].codigo == funcionario.codigo) {
            printf("Ja existe um funcionario com esse codigo!\n");
            return;
        }
    }

    printf("Nome: ");
    scanf(" %[^\n]", funcionario.nome);
    printf("Telefone: ");
    scanf(" %[^\n]", funcionario.telefone);
    printf("Cargo: ");
    scanf(" %[^\n]", funcionario.cargo);
    printf("Salario: ");
    scanf("%f", &funcionario.salario);

    funcionarios[qtdFuncionarios] = funcionario;
    qtdFuncionarios++;

    if (salvarFuncionarios(funcionarios, qtdFuncionarios)) {
        printf("Funcionario cadastrado com sucesso!\n");
    } else {
        printf("Erro ao cadastrar o funcionario.\n");
    }
}

// Cadastro de estadia
void cadastrarEstadia() {
    Estadia estadia;
    Estadia estadias[MAX_LEN];
    int qtdEstadias = lerEstadias(estadias);
    Quarto quartos[NUM_QUARTOS];
    int qtdQuartos = lerQuartos(quartos);
    Cliente clientes[MAX_LEN];
    int qtdClientes = lerClientes(clientes);

    printf("Codigo da estadia: ");
    scanf("%d", &estadia.codigoEstadia);

    for (int i = 0; i < qtdEstadias; i++) {
        if (estadias[i].codigoEstadia == estadia.codigoEstadia) {
            printf("Ja existe uma estadia com esse codigo!\n");
            return;
        }
    }

    printf("Data de entrada (dd/mm/aaaa): ");
    scanf(" %[^\n]", estadia.dataEntrada);
    printf("Data de saida (dd/mm/aaaa): ");
    scanf(" %[^\n]", estadia.dataSaida);
    printf("Codigo do cliente: ");
    scanf("%d", &estadia.codigoCliente);

    // Verificar se o cliente existe
    int clienteExiste = 0;
    for (int i = 0; i < qtdClientes; i++) {
        if (clientes[i].codigo == estadia.codigoCliente) {
            clienteExiste = 1;
            break;
        }
    }

    if (!clienteExiste) {
        printf("Cliente nao encontrado!\n");
        return;
    }

    printf("Escolha o tipo de quarto:\n");
    printf("1. Solteiro (1 pessoa) - R$ 100,00\n");
    printf("2. Duplo (2 pessoas) - R$ 200,00\n");
    printf("3. Triplo (3 pessoas) - R$ 300,00\n");
    printf("4. Quadruplo (4 pessoas) - R$ 400,00\n");
    int tipoQuarto;
    scanf("%d", &tipoQuarto);

    // Verificar se há quartos disponíveis do tipo escolhido
    int quartoEncontrado = 0;
    for (int i = 0; i < qtdQuartos; i++) {
        if (quartos[i].capacidade == tipoQuarto && strcmp(quartos[i].status, "desocupado") == 0) {
            estadia.numeroQuarto = quartos[i].numero;
            strcpy(quartos[i].status, "ocupado");
            quartoEncontrado = 1;
            break;
        }
    }

    if (!quartoEncontrado) {
        printf("Nao ha quartos disponiveis para o tipo escolhido!\n");
        return;
    }

    // Calcular quantidade de diárias
    estadia.qtdDiarias = calcularDiasEntreDatas(estadia.dataEntrada, estadia.dataSaida);

    estadias[qtdEstadias] = estadia;
    qtdEstadias++;

    if (salvarEstadias(estadias, qtdEstadias)) {
        printf("Estadia cadastrada com sucesso!\n");
    } else {
        printf("Erro ao cadastrar a estadia.\n");
    }

    // Atualizar status dos quartos
    atualizarQuartos(quartos, qtdQuartos);
}

// Finaliza a estadia
void darBaixaEstadia() {
    int codigoEstadia;
    Estadia estadias[MAX_LEN];
    int qtdEstadias = lerEstadias(estadias);
    Quarto quartos[NUM_QUARTOS];
    int qtdQuartos = lerQuartos(quartos);

    printf("Codigo da estadia para dar baixa: ");
    scanf("%d", &codigoEstadia);

    for (int i = 0; i < qtdEstadias; i++) {
        if (estadias[i].codigoEstadia == codigoEstadia) {
            // Calcular o valor total da estadia
            int numeroQuarto = estadias[i].numeroQuarto;
            float valorDiaria = 0.0;

            for (int j = 0; j < qtdQuartos; j++) {
                if (quartos[j].numero == numeroQuarto) {
                    valorDiaria = quartos[j].valorDiaria;
                    strcpy(quartos[j].status, "desocupado"); // Desocupar o quarto
                    break;
                }
            }

            float valorTotal = estadias[i].qtdDiarias * valorDiaria;
            printf("Valor total da estadia: R$ %.2f\n", valorTotal);

            // Remover a estadia
            for (int j = i; j < qtdEstadias - 1; j++) {
                estadias[j] = estadias[j + 1];
            }
            qtdEstadias--;

            if (salvarEstadias(estadias, qtdEstadias)) {
                printf("Baixa da estadia realizada com sucesso!\n");
            } else {
                printf("Erro ao dar baixa na estadia.\n");
            }

            // Atualizar status dos quartos
            atualizarQuartos(quartos, qtdQuartos);

            return;
        }
    }

    printf("Estadia nao encontrada!\n");
}

// Pesquisa de clientes
void pesquisarCliente() {
    int codigo;
    Cliente clientes[MAX_LEN];
    int qtdClientes = lerClientes(clientes);

    printf("Codigo do cliente: ");
    scanf("%d", &codigo);

    for (int i = 0; i < qtdClientes; i++) {
        if (clientes[i].codigo == codigo) {
            printf("Cliente encontrado:\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("Endereco: %s\n", clientes[i].endereco);
            printf("Telefone: %s\n", clientes[i].telefone);
            return;
        }
    }

    printf("Cliente nao encontrado!\n");
}

// Pesquisa de funcionários
void pesquisarFuncionario() {
    int codigo;
    Funcionario funcionarios[MAX_LEN];
    int qtdFuncionarios = lerFuncionarios(funcionarios);

    printf("Codigo do funcionario: ");
    scanf("%d", &codigo);

    for (int i = 0; i < qtdFuncionarios; i++) {
        if (funcionarios[i].codigo == codigo) {
            printf("Funcionario encontrado:\n");
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("Telefone: %s\n", funcionarios[i].telefone);
            printf("Cargo: %s\n", funcionarios[i].cargo);
            printf("Salario: %.2f\n", funcionarios[i].salario);
            return;
        }
    }

    printf("Funcionario nao encontrado!\n");
}

// Visualiza as estadias dos clientes cadastrados
void verEstadiasCliente() {
    int codigoCliente;
    Estadia estadias[MAX_LEN];
    int qtdEstadias = lerEstadias(estadias);
    Cliente clientes[MAX_LEN];
    int qtdClientes = lerClientes(clientes);

    printf("Codigo do cliente: ");
    scanf("%d", &codigoCliente);

    int estadiaEncontrada = 0;
    for (int i = 0; i < qtdEstadias; i++) {
        if (estadias[i].codigoCliente == codigoCliente) {
            if (!estadiaEncontrada) {
                // Buscar o nome do cliente
                char nomeCliente[MAX_LEN];
                for (int j = 0; j < qtdClientes; j++) {
                    if (clientes[j].codigo == codigoCliente) {
                        strcpy(nomeCliente, clientes[j].nome);
                        break;
                    }
                }

                printf("Estadias do cliente %d (%s):\n", codigoCliente, nomeCliente);
                estadiaEncontrada = 1;
            }
            printf("Codigo da Estadia: %d\n", estadias[i].codigoEstadia);
            printf("Data de Entrada: %s\n", estadias[i].dataEntrada);
            printf("Data de Saida: %s\n", estadias[i].dataSaida);
            printf("Numero do Quarto: %d\n", estadias[i].numeroQuarto);
            printf("Quantidade de Diarias: %d\n", estadias[i].qtdDiarias);
            printf("\n");
        }
    }

    if (!estadiaEncontrada) {
        printf("Nenhuma estadia encontrada para o cliente %d.\n", codigoCliente);
    }
}

// Inicializa o programa
int main() {
    int opcao;

    inicializarArquivos();

    do {
        printf("\n--Sistema de Gestao do Hotel Descanso Garantido--\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Cadastrar Funcionario\n");
        printf("3. Pesquisar Cliente\n");
        printf("4. Pesquisar Funcionario\n");
        printf("5. Cadastrar Estadia\n");
        printf("6. Dar Baixa na Estadia\n");
        printf("7. Ver Estadias de um Cliente\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
		printf("\n");
		
        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                cadastrarFuncionario();
                break;
            case 3:
                pesquisarCliente();
                break;
            case 4:
                pesquisarFuncionario();
                break;
            case 5:
                cadastrarEstadia();
                break;
            case 6:
                darBaixaEstadia();
                break;
            case 7:
                verEstadiasCliente();
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
} 


