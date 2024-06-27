# Trabalho Interdisciplinar AEDS e Fundamentos da Engenharia de Software
# -- Hotel bom descanso --
 



# Sumário
- [Funções](#Funções)
- [Testes](#Testes)
- [Desenvolvedores](#Desenvolvedores)


# Funções
Listagem das funções do programa e o que elas fazem.

## void inicializarArquivos()
	
A função abre um arquivo para cada classe (clientes, funcionários, estadias e quartos) em modo "ab", que significa que eles serão abertos para edição. Se os arquivos não existirem, eles são criados. 

A função também verifica no arquivo de quartos se ele está vazio para então salvar o que for informado na execução.

- **Parâmetros:** Nenhum
- **Retorno:** Nenhum

##  void cadastrarCliente()

Cadastra os clientes com as informações: código, nome, endereço e telefone, que são informadas pelo usuário durante a execução. Chama as funções lerClientes (usado para verificar se o usuário já está cadastrado) e salvarClientes e por fim adiciona mais um na quantidade de clientes.

## int lerClientes(Cliente clientes[])

Abre o arquivo dos clientes e lê os clientes que já estão cadastrados.

-   **Parâmetros**:
    -   `Cliente clientes[]`: Array onde os clientes lidos serão armazenados.
-   **Retorno**: Número
 
## int salvarClientes(Cliente clientes[], int n)

Salva o cliente, que no código está armazenado como variável, no arquivo de clientes.

-   **Parâmetros**:
    -   `Cliente clientes[]`: Array de clientes a serem salvos.
    -   `int n`: Número de clientes no array.
-   **Retorno**: 1 se a operação for bem-sucedida, 0 caso contrário.

##  void cadastrarFuncionario()

Cadastra os funcionários com as informações: nome, telefone, cargo e salario, que são informadas pelo usuário durante a execução. Chama as funções lerFuncionarios (usado para verificar se o funcionário já está cadastrado) e salvarClientes, e por fim adiciona mais um na quantidade de clientes.

## int lerFuncionarios(Funcionario funcionarios[])

Abre o arquivo de funcionários e lê os funcionários que já estão cadastrados.

  -   **Parâmetros**:
        -   `Funcionario funcionarios[]`: Array onde os funcionários lidos serão armazenados.
   -   **Retorno**: Número de funcionários lidos.
   
## int salvarFuncionarios(Funcionario funcionarios[], int n)

Salva o funcionário, que no código está armazenado como variável, no arquivo de funcionários.

-   **Parâmetros**:
    -   `Funcionario funcionarios[]`: Array de funcionários a serem salvos.
    -   `int n`: Número de funcionários no array.
-   **Retorno**: 1 se a operação for bem-sucedida, 0 caso contrário.

## void cadastrarEstadia()

Cadastra as estadias com as informações: data de entrada, data de saida, codigo do cliente e quarto selecionado, que são informadas pelo usuário durante a execução. Chama as funções lerEstadias (para verificar se a estadia não existe), lerQuartos (usada para verificar se o quarto selecionado está disponível e alterar seu estado para 'ocupado'), lerClientes (verifica se o código do cliente informado existe antes de permitir o cadastro de estadia), calcularDiasEntreDatas (Calcula a duração da estadia com as datas de entrada e saída), salvarEstadia (salva a estadia no arquivo) e atualizarQuartos (salva o estado do quarto no arquivo). E por fim adiciona mais um na quantidade de estadias.

## int lerEstadias(Estadia estadias[])

Abre o arquivo de estadias e lê as estadias que já estão cadastradas.

-   **Parâmetros**:
    -   `Estadia estadias[]`: Array onde as estadias lidas serão armazenadas.
-   **Retorno**: Número de estadias lidas.

## int salvarEstadias(Estadia estadias[], int n)

Salva a estadia no arquivo de estadias.

-   **Parâmetros**:
    -   `Estadia estadias[]`: Array de estadias a serem salvas.
    -   `int n`: Número de estadias no array.
-   **Retorno**: 1 se a operação for bem-sucedida, 0 caso contrário.

## void darBaixaEstadia()

Finaliza uma estadia, desocupando o quarto e removendo a estadia do arquivo.

## void atualizarQuartos(Quarto quartos[], int n)

Atualiza o arquivo de quartos com os dados fornecidos.
   
 -   **Parâmetros**:
        -   `Quarto quartos[]`: Array de quartos a serem atualizados.
        -   `int n`: Número de quartos no array.
    -   **Retorno**: Nenhum.

##  int lerQuartos(Quarto quartos[])

Abre o arquivo dos quartos e lê os cadastrados.

-   **Parâmetros**:
    -   `Quarto quartos[]`: Array onde os quartos lidos serão armazenados.
-   **Retorno**: Número de quartos lidos.

## int salvarQuartos(Quarto quartos[], int n)

Salva os dados dos quartos no arquivo.

-   **Parâmetros**:
    -   `Quarto quartos[]`: Array de quartos a serem salvos.
    -   `int n`: Número de quartos no array.
-   **Retorno**: 1 se a operação for bem-sucedida, 0 caso contrário.

##  int calcularDiasEntreDatas(const char dataInicio[], const char dataFim[])

Calcula a quantidade de dias entre duas datas fornecidas.

   -   **Parâmetros**:
        -   `const char dataInicio[]`: Data de início no formato `dd/mm/aaaa`.
        -   `const char dataFim[]`: Data de fim no formato `dd/mm/aaaa`.
    -   **Retorno**: Quantidade de dias entre as duas datas.
    
## void pesquisarCliente()

Pesquisa um cliente pelo código e exibe suas informações.

## void pesquisarFuncionario()

Pesquisa um funcionário pelo código e exibe suas informações.

## void verEstadiasCliente()

Exibe todas as estadias de um cliente especificado pelo código.

# Testes

## 1 - Cadastrar clientes:

#### Caso de Teste 1

-   **Entrada**:
    -   `codigo = 1`
    -   `nome = "João da Silva"`
    -   `endereco = "Rua A, 123"`
    -   `telefone = "123456789"`

-   **Resultado Esperado**:
    -   Cliente é adicionado ao arquivo `clientes.dat`.
    -   Mensagem: "Cliente cadastrado com sucesso!"

**Resultado obtido de acordo com o esperado**
  
  #### Caso de Teste 2

-   **Entrada**:
    -   `codigo = 1` (já existente)
    -   `nome = "Maria Souza"`
    -   `endereco = "Rua B, 456"`
    -   `telefone = "987654321"`

-   **Resultado Esperado**:
    -   Cliente não é adicionado.
    -   Mensagem: "Já existe um cliente com esse código!"
  
**Resultado obtido de acordo com o esperado**
   

## 2 - Cadastrar funcionário:

#### Caso de Teste 1

-   **Entrada**:
    -   `codigo = 101`
    -   `nome = "Carlos Pereira"`
    -   `telefone = "321654987"`
    -   `cargo = "Recepcionista"`
    -   `salario = 1500.0`

-   **Resultado Esperado**:
    -   Funcionário é adicionado ao arquivo `funcionarios.dat`.
    -   Mensagem: "Funcionário cadastrado com sucesso!"
 
 **Resultado obtido de acordo com o esperado**

 
 #### Caso de Teste 2

-   **Entrada**:
    -   `codigo = 101` (já existente)
    -   `nome = "Ana Oliveira"`
    -   `telefone = "456123789"`
    -   `cargo = "Gerente"`
    -   `salario = 3000.0`
-   **Resultado Esperado**:
    -   Funcionário não é adicionado.
    -   Mensagem: "Já existe um funcionário com esse código!"
  
**Resultado obtido de acordo com o esperado**


## 3 - Pesquisar cliente:

#### Caso de Teste 1

-   **Entrada**:
    -   `codigo = 1` (existente)

-   **Resultado Esperado**:
    -   Informações do cliente são exibidas.
        
        - Cliente encontrado:
	   Nome: João da Silva
        Endereço: Rua A, 123
        Telefone: 123456789

**Resultado obtido de acordo com o esperado**


## 4 - Pesquisar funcionários:

#### Caso de Teste 1

-   **Entrada**:
    -   `codigo = 101` (existente)

-   **Resultado Esperado**:
    -   Informações do funcionário são exibidas:
        
        Funcionário encontrado:
        Nome: Carlos Pereira
        Telefone: 321654987
        Cargo: Recepcionista
        Salário: 1500.00`

**Resultado obtido de acordo com o esperado**


#### Caso de Teste 2

-   **Entrada**:
    -   `codigo = 102` (não existente)

-   **Resultado Esperado**:
    -   Mensagem: "Funcionário não encontrado!"

**Resultado obtido de acordo com o esperado**


## 5 - Cadastrar estadia:

#### Caso de Teste 1

-   **Entrada**:
    -   `codigoEstadia = 1`
    -   `dataEntrada = "01/01/2024"`
    -   `dataSaida = "05/01/2024"`
    -   `codigoCliente = 1` (existente)
    -   `tipoQuarto = 2` (duplo, disponível)

-   **Resultado Esperado**:
    -   Estadia é adicionada ao arquivo `estadias.dat`.
    -   Mensagem: "Estadia cadastrada com sucesso!"
    -   Quarto do tipo duplo é marcado como "ocupado".
  
**Resultado obtido de acordo com o esperado**


  #### Caso de Teste 2

-   **Entrada**:
    -   `codigoEstadia = 1` (já existente)

-   **Resultado Esperado**:
    -   Estadia não é adicionada.
    -   Mensagem: "Já existe uma estadia com esse código!"
  
**Resultado obtido de acordo com o esperado**


  #### Caso de Teste 3

-   **Entrada**:
    -   `codigoCliente = 2` (não existente)

-   **Resultado Esperado**:
    -   Estadia não é adicionada.
    -   Mensagem: "Cliente não encontrado!"
  
**Resultado obtido de acordo com o esperado**


  #### Caso de Teste 4

-   **Entrada**:
    -   `tipoQuarto = 3` (triplo, não disponível)

-   **Resultado Esperado**:
    -   Estadia não é adicionada.
    -   Mensagem: "Não há quartos disponíveis para o tipo escolhido!"
   
   **Resultado obtido de acordo com o esperado**


## 6 - Dar baixa na estadia:

#### Caso de Teste 1

-   **Entrada**:
    -   `codigoEstadia = 1` (existente)

-   **Resultado Esperado**:
    -   Estadia é removida do arquivo `estadias.dat`.
    -   Mensagem: "Baixa da estadia realizada com sucesso!"
    -   Quarto correspondente é marcado como "desocupado".

**Resultado obtido de acordo com o esperado**


#### Caso de Teste 2

-   **Entrada**:
    -   `codigoEstadia = 2` (não existente)

-   **Resultado Esperado**:
    -   Mensagem: "Estadia não encontrada!"
 
**Resultado obtido de acordo com o esperado**


## 7 - Ver estadias de um cliente:

#### Caso de Teste 1

-   **Entrada**:
    -   `codigoCliente = 1` (com estadias)

-   **Resultado Esperado**:
    -   Informações das estadias são exibidas:
       
        Estadias do cliente 1 (João da Silva):
        Código da Estadia: 1
        Data de Entrada: 01/01/2024
        Data de Saída: 05/01/2024
        Número do Quarto: 2
        Quantidade de Diárias: 4` 
        
**Resultado obtido de acordo com o esperado**


#### Caso de Teste 2

-   **Entrada**:
    -   `codigoCliente = 2` (sem estadias)

-   **Resultado Esperado**:
    -   Mensagem: "Nenhuma estadia encontrada para o cliente 2."

**Resultado obtido de acordo com o esperado**


# Desenvolvedores:
- João Marcelo Carvalho Pereira Araújo
- Miguel Figueiredo Diniz




