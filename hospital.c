#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medico
{
    int id;
    char nome[50];
    char especialidade[50];
    struct Medico *proximo;
} Medico;

typedef struct
{
    Medico *medicos;
    int tamanho;
} ListaMedicos;

void iniciarListaMedicos(ListaMedicos *ListaDMedico)
{
    ListaDMedico->medicos = NULL;
    ListaDMedico->tamanho = 0;
}

Medico *CriarMedico(int id, char *nome, const char *especialidade)
{
    struct Medico *novoMedico = (struct Medico *)malloc(sizeof(struct Medico));
    if (novoMedico == NULL)
    {
        printf("Erro ao alocar memoria!");
        exit(1);
    }

    novoMedico->id = id;
    strcpy(novoMedico->nome, nome);
    strcpy(novoMedico->especialidade, especialidade);
    novoMedico->proximo = NULL;
    return novoMedico;
}

void IncluirMedico(ListaMedicos *listaDMedicos)
{
    Medico *novoMedico = CriarMedico(0, "", "");

    printf("Digite o nome do Medico: ");
    fgets(novoMedico->nome, 50, stdin);
    novoMedico->nome[strcspn(novoMedico->nome, "\n")] = '\0';

    printf("Digite o id do Medico: ");
    scanf("%d", &novoMedico->id);

    getchar();

    printf("Digite a especialidade do Medico: ");
    fgets(novoMedico->especialidade, 50, stdin);
    novoMedico->especialidade[strcspn(novoMedico->especialidade, "\n")] = '\0';

    if (listaDMedicos->medicos == NULL)
    {
        listaDMedicos->medicos = novoMedico;
    }
    else
    {
        Medico *ultimoMedico = listaDMedicos->medicos;
        while (ultimoMedico->proximo != NULL)
        {
            ultimoMedico = ultimoMedico->proximo;
        }
        ultimoMedico->proximo = novoMedico;
    }

    listaDMedicos->tamanho++;
    printf("Medico cadastrado com sucesso!\n");
    printf("\n");
}

void exibirMedicos(ListaMedicos *listaDMedicos)
{
    Medico *atual = listaDMedicos->medicos;
    while (atual != NULL)
    {
        printf("ID: %d\n", atual->id);
        printf("Nome: %s\n", atual->nome);
        printf("Especialidade: %s\n", atual->especialidade);
        printf("----------------------\n");
        atual = atual->proximo;
    }
}

void procurarMedico(ListaMedicos *listaDMedicos)
{
    int id;
    printf("Digite o id do medico que quer procurar: ");
    scanf("%d", &id);

    Medico *atual = listaDMedicos->medicos;
    while (atual != NULL)
    {
        if (atual->id == id)
        {
            printf("Medico encontado: \n");
            printf("\n");
            printf("ID: %d\n", atual->id);
            printf("Nome: %s\n", atual->nome);
            printf("Especialidade: %s\n", atual->especialidade);
            printf("--------------------\n");
            return;
        }
        atual = atual->proximo;
    }
    printf("Medico nao encontrado!\n");
}

void atualizarMedico(ListaMedicos *listaDMedicos)
{
    int id;
    Medico *atualizar = listaDMedicos->medicos;
    printf("Digite o id do medico que sera atualizado: ");
    scanf("%d", &id);

    while (atualizar != NULL)
    {
        if (atualizar->id == id)
        {
            printf("\n");
            printf("Digite os dados atualizados: \n");
            printf("ID: ");
            scanf("%d", &atualizar->id);
            getchar();
            printf("Nome: ");
            fgets(atualizar->nome, 50, stdin);
            atualizar->nome[strcspn(atualizar->nome, "\n")] = '\0';
            printf("Especialidade: ");
            fgets(atualizar->especialidade, 50, stdin);
            atualizar->especialidade[strcspn(atualizar->especialidade, "\n")] = '\0';
            printf("Medico atualizado com sucesso!\n");
            return;
        }
        atualizar = atualizar->proximo;
    }
    printf("Medico nao encontrado!\n");
}

typedef struct Paciente
{
    char nome[50];
    int id;
    int idade;
    char sexo[15];
    char endereco[100];
    char telefone[30];
    struct Paciente *prox; // ponteiro para o próximo nó
} Paciente;

// vetor de pacientes
typedef struct
{
    Paciente *pacientes;
    int tamanho;
} ListaPacientes;

// iniciar a lista
void iniciarListaPacientes(ListaPacientes *lista)
{
    lista->pacientes = NULL;
    lista->tamanho = 0;
}

Paciente *CriarPaciente(int id, const char *nome, int idade, const char *sexo, const char *endereco, const char *telefone)
{
    struct Paciente *novoPaciente = (struct Paciente *)malloc(sizeof(struct Paciente));
    if (novoPaciente == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    novoPaciente->id = id;
    strcpy(novoPaciente->nome, nome);
    novoPaciente->idade = idade;
    strcpy(novoPaciente->sexo, sexo);
    strcpy(novoPaciente->endereco, endereco);
    strcpy(novoPaciente->telefone, telefone);
    novoPaciente->prox = NULL;
    return novoPaciente;
}

void incluirPaciente(ListaPacientes *lista)
{
    Paciente *novoPaciente = CriarPaciente(0, "", 0, "", "", "");

    printf("Digite o nome do Paciente: ");
    fgets(novoPaciente->nome, 50, stdin);
    novoPaciente->nome[strcspn(novoPaciente->nome, "\n")] = '\0';

    printf("Digite o id do Paciente: ");
    scanf("%d", &novoPaciente->id);

    printf("Digite a idade do paciente: ");
    scanf("%d", &novoPaciente->idade);

    getchar(); // limpar o buffer de entrada

    printf("Digite o sexo do paciente: ");
    fgets(novoPaciente->sexo, 10, stdin);
    novoPaciente->sexo[strcspn(novoPaciente->sexo, "\n")] = '\0';

    printf("Digite o endereco do paciente: ");
    fgets(novoPaciente->endereco, 100, stdin);
    novoPaciente->endereco[strcspn(novoPaciente->endereco, "\n")] = '\0';

    printf("Digite o telefone do paciente: ");
    fgets(novoPaciente->telefone, 30, stdin);
    novoPaciente->telefone[strcspn(novoPaciente->telefone, "\n")] = '\0';

    if (lista->tamanho == 0)
    {
        lista->pacientes = novoPaciente;
    }
    else
    {
        Paciente *ultimoPaciente = lista->pacientes;
        while (ultimoPaciente->prox != NULL)
        {
            ultimoPaciente = ultimoPaciente->prox;
        }
        ultimoPaciente->prox = novoPaciente;
    }

    lista->tamanho++;
    printf("\n");
    printf("Paciente cadastrado com sucesso!\n");
    printf("\n");
}

void exibirPacientes(ListaPacientes *lista)
{
    Paciente *atual = lista->pacientes;
    while (atual != NULL)
    {
        printf("ID: %d\n", atual->id);
        printf("Nome: %s\n", atual->nome);
        printf("Idade: %d\n", atual->idade);
        printf("Sexo: %s\n", atual->sexo);
        printf("Endereco: %s\n", atual->endereco);
        printf("Telefone: %s\n", atual->telefone);
        printf("-------------------\n");
        atual = atual->prox;
    }
}

void procurarPaciente(ListaPacientes *lista)
{
    int id;
    printf("Digite o id do paciente que quer encontrar: ");
    scanf("%d", &id);

    Paciente *atual = lista->pacientes;
    while (atual != NULL)
    {
        if (atual->id == id)
        {
            printf("\n");
            printf("Paciente encontrado: \n");
            printf("\n");
            printf("ID: %d\n", atual->id);
            printf("Nome: %s\n", atual->nome);
            printf("idade: %d\n", atual->idade);
            printf("Sexo: %s\n", atual->sexo);
            printf("Endereco: %s\n", atual->endereco); // precisa do return e tem que chamar o proximo
            printf("Telefone: %s\n", atual->telefone);
            printf("-------------------\n");
            return;
        }
        atual = atual->prox;
    }
    printf("Paciente nao encontrado!\n");
}

void excluirPaciente(ListaPacientes *lista)
{
    int id;
    printf("Digite o id do paciente que deseja excluir: ");
    scanf("%d", &id);

    Paciente *atual = lista->pacientes;
    Paciente *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->id == id)
        {
            if (anterior == NULL)
            {
                lista->pacientes = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }

            free(atual);
            lista->tamanho--;
            printf("Paciente excluido com sucesso!\n");
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("Paciente nao encontrado!\n");
}

void atualizarPaciente(ListaPacientes *listaP)
{
    int idP;
    Paciente *atualizar = listaP->pacientes;
    printf("Digite o ID do paciente que sera atualizado: \n");
    scanf("%d", &idP);
    getchar();

    while (atualizar != NULL)
    {
        if (atualizar->id == idP)
        {
            printf("\n");
            printf("Digite o nome do paciente: \n");
            fgets(atualizar->nome, 50, stdin);
            atualizar->nome[strcspn(atualizar->nome, "\n")] = '\0';

            printf("Digite o ID: \n");
            scanf("%d", &atualizar->id);
            getchar();

            printf("Digite a idade: \n");
            scanf("%d", &atualizar->idade);
            getchar();

            printf("Digite o sexo: \n");
            fgets(atualizar->sexo, 15, stdin);
            atualizar->sexo[strcspn(atualizar->sexo, "\n")] = '\0';

            printf("Digite o endereco: \n");
            fgets(atualizar->endereco, 100, stdin);
            atualizar->endereco[strcspn(atualizar->endereco, "\n")] = '\0';

            printf("Digite o telefone: \n");
            fgets(atualizar->telefone, 30, stdin);
            atualizar->telefone[strcspn(atualizar->telefone, "\n")] = '\0';

            printf("Paciente atualizado com sucesso!\n");
            return;
        }
        atualizar = atualizar->prox;
    }
    printf("Paciente nao encotrado!\n");
}

typedef struct Consulta
{
    int numero;
    Medico *medico;
    Paciente *paciente;
    char horario[20];
    char duracao[20];
    char data[20];
    struct Consulta *prox;
} Consulta;

typedef struct ListaConsulta
{
    Consulta *consultas;
    int tamanho;
} ListaConsulta;

void iniciarConsultas(ListaConsulta *listaC)
{
    listaC->consultas = NULL;
    listaC->tamanho = 0;
}

Consulta *criarConsulta(int numero, Medico *medico, Paciente *paciente, char *horario, char *duracao, char *data)
{
    Consulta *novaConsulta = (Consulta *)malloc(sizeof(Consulta));
    if (novaConsulta == NULL)
    {
        printf("Erro ao alocar mémoria!\n");
        exit(1);
    }

    novaConsulta->numero = numero;
    novaConsulta->medico = medico;
    novaConsulta->paciente = paciente;
    strcpy(novaConsulta->horario, horario);
    strcpy(novaConsulta->duracao, duracao);
    strcpy(novaConsulta->data, data);
    novaConsulta->prox = NULL;

    return novaConsulta;
}

void incluirConsulta(ListaConsulta *listaC, ListaMedicos *listaM, ListaPacientes *listaP)
{
    int num, idMedico, idPaciente;
    char horario[20];
    char duracao[20];
    char data[20];

    printf("Digite o ID da Consulta: ");
    scanf("%d", &num);

    printf("Digite o ID do Medico: ");
    scanf("%d", &idMedico);

    Medico *medico = listaM->medicos;
    while (medico != NULL && medico->id != idMedico)
    {
        medico = medico->proximo;
    }
    if (medico == NULL)
    {
        printf("Medico nao encontrado!\n");
        return;
    }

    printf("Digite o ID do paciente: ");
    scanf("%d", &idPaciente);

    Paciente *paciente = listaP->pacientes;
    while (paciente != NULL && paciente->id != idPaciente)
    {
        paciente = paciente->prox;
    }
    if (paciente == NULL)
    {
        printf("Paciente não encontrado!\n");
        return;
    }

    getchar();

    printf("Digite o horario da consulta(HH:MM): ");
    fgets(horario, 20, stdin);
    horario[strcspn(horario, "\n")] = '\0';

    printf("Digite a duracao da consulta(minutos): ");
    fgets(duracao, 20, stdin);
    duracao[strcspn(duracao, "\n")] = '\0';

    printf("Digite a data da consulta(DD/MM/AAAA): ");
    fgets(data, 20, stdin);
    data[strcspn(data, "\n")] = '\0';

    Consulta *novaConsulta = criarConsulta(num, medico, paciente, horario, duracao, data);

    if (listaC->consultas == NULL)
    {
        listaC->consultas = novaConsulta;
    }
    else
    {
        Consulta *ultima = listaC->consultas;
        while (ultima->prox != NULL)
        {
            ultima = ultima->prox;
        }
        ultima->prox = novaConsulta;
    }

    listaC->tamanho++;
    printf("Consulta cadastrada com sucesso!\n");
}

void exibirConsultas(ListaConsulta *listaC)
{
    Consulta *atual = listaC->consultas;
    if (atual == NULL)
    {
        printf("Nenhuma consulta cadastrada!\n");
        return;
    }

    printf("Lista das consultas:\n");
    while (atual != NULL)
    {
        printf("Numero da Consulta: %d\n", atual->numero);
        printf("Medico: %s (ID: %d)\n", atual->medico->nome, atual->medico->id);
        printf("Paciente: %s (ID: %d)\n", atual->paciente->nome, atual->paciente->id);
        printf("Data: %s\n", atual->data);
        printf("Horario: %s\n", atual->horario);
        printf("Duracao: %s minutos\n", atual->duracao);
        printf("------------------------------\n");
        atual = atual->prox;
    }
}

void procurarConsultas(ListaConsulta *listaC)
{
    int num;
    printf("Digite o numero da consulta: ");
    scanf("%d", &num);

    Consulta *atual = listaC->consultas;
    if (atual == NULL)
    {
        printf("Nao existe nenhuma consulta!\n");
    }

    while (atual != NULL)
    {
        if (atual->numero == num)
        {
            printf("\n");
            printf("--Consulta encontrada!--\n");
            printf("Numero: %d\n", atual->numero);
            printf("Medico: %s (ID: %d)\n", atual->medico->nome, atual->medico->id);
            printf("Paciente: %s (ID: %d)\n", atual->paciente->nome, atual->paciente->id);
            printf("Data: %s\n", atual->data);
            printf("Horario: %s\n", atual->horario);
            printf("Duracao: %s\n", atual->duracao);
            printf("-----------------------\n");
            return;
        }
        atual = atual->prox;
    }
    printf("Consulta nao encontrada!\n");
}

void procurarRelatorioPorMedico(ListaConsulta *listaC)
{
    int idmedico;
    printf("Digite o ID do medico: ");
    scanf("%d", &idmedico);

    Consulta *atual = listaC->consultas;
    int encontrou = 0;

    while (atual != NULL)
    {

        if (atual->medico->id == idmedico)
        {
            printf("Numero: %d\n", atual->numero);
            printf("Medico: %s\n", atual->medico->nome);
            printf("Paciente: %s\n", atual->paciente->nome);
            printf("Data: %s\n", atual->data);
            printf("Horario: %s\n", atual->horario);
            printf("Duracao: %s\n", atual->duracao);
            printf("-----------------------\n");
            encontrou = 1;
        }
        atual = atual->prox;
    }
    if(encontrou == 0)
        printf("Consulta nao encontrada!\n");
    else
        printf("Consulta(s) encontrada(s)!\n");
}

void procurarRelatorioPorPaciente(ListaConsulta *listaC)
{
    int idPaciente;
    printf("Digite o ID do paciente: ");
    scanf("%d", &idPaciente);

    Consulta *atual = listaC->consultas;
    int encontrou = 0;

    while (atual != NULL)
    {
        if (atual->paciente->id == idPaciente)
        {
            printf("Numero: %d\n", atual->numero);
            printf("Medico: %s\n", atual->medico->nome);
            printf("Paciente: %s\n", atual->paciente->nome);
            printf("Data: %s\n", atual->data);
            printf("Horario: %s\n", atual->horario);
            printf("Duracao: %s\n", atual->duracao);
            printf("----------------------------\n");
            encontrou = 1;
        }
        atual = atual->prox;
    }
    if(encontrou == 0)
        printf("Consulta nao encontrada!\n");
    else
        printf("Consulta(s) encontrada(s)!\n");
}

void procurarRelatorioPorEspecialidade(ListaConsulta *listaC, ListaMedicos *listaM)
{
    char especialidade[50];
    printf("Digite a especialidade: ");
    fgets(especialidade, 50, stdin);
    especialidade[strcspn(especialidade, "\n")] = '\0';

    int encontrou = 0;

    Medico *medico = listaM->medicos;
    while (medico != NULL)
    {
        if (strcmp(medico->especialidade, especialidade) == 0)
        {
            Consulta *atual = listaC->consultas;
            while (atual != NULL)
            {
                if (atual->medico->id == medico->id)
                {
                    printf("Numero: %d\n", atual->numero);
                    printf("Medico: %s\n", atual->medico->nome);
                    printf("Paciente: %s\n", atual->paciente->nome);
                    printf("Data: %s\n", atual->data);
                    printf("Horario: %s\n", atual->horario);
                    printf("Duracao: %s\n", atual->duracao);
                    printf("----------------------------\n");
                    encontrou = 1;
                }
                atual = atual->prox;
            }
        }
        medico = medico->proximo;
    }

    if (!encontrou)
        printf("Consulta nao encontrada!\n");
}

void atualizarConsulta(ListaConsulta *listaC)
{
    // Lê o número da consulta que deseja atualizar
    int numero;
    printf("Digite o numero da consulta: ");
    scanf("%d", &numero);

    // Inicializa um ponteiro para a consulta que deseja atualizar
    Consulta *atualizar = listaC->consultas;

    // Percorre a lista de consultas até encontrar a consulta que deseja atualizar
    while (atualizar != NULL)
    {
        if (atualizar->numero == numero)
        {
            // Lê o novo número da consulta
            printf("Digite o novo numero da consulta: ");
            scanf("%d", &atualizar->numero);
            getchar();

            // Lê o novo ID do médico
            int idMedico;
            printf("Digite o novo ID do Medico: ");
            scanf("%d", &idMedico);
            getchar();

            // Inicializa um ponteiro para o médico que deseja atualizar
            Medico *medico = listaC->consultas->medico;

            // Percorre a lista de médicos até encontrar o médico que deseja atualizar
            while (medico != NULL && medico->id != idMedico)
            {
                medico = medico->proximo;
            }

            // Verifica se o médico foi encontrado
            if (medico == NULL)
            {
                printf("Medico nao encontrado!\n");
                return;
            }

            // Atualiza o médico da consulta
            atualizar->medico = medico;

            // Lê o novo ID do paciente
            int idPaciente;
            printf("Digite o novo ID do Paciente: ");
            scanf("%d", &idPaciente);
            getchar();

            // Inicializa um ponteiro para o paciente que deseja atualizar
            Paciente *paciente = listaC->consultas->paciente;

            // Percorre a lista de pacientes até encontrar o paciente que deseja atualizar
            while (paciente != NULL && paciente->id != idPaciente)
            {
                paciente = paciente->prox;
            }

            // Verifica se o paciente foi encontrado
            if (paciente == NULL)
            {
                printf("Paciente nao encontrado!\n");
                return;
            }

            // Atualiza o paciente da consulta
            atualizar->paciente = paciente;

            // Lê a nova data da consulta
            printf("Digite a nova data: ");
            fgets(atualizar->data, 20, stdin);
            atualizar->data[strcspn(atualizar->data, "\n")] = '\0';

            // Lê o novo horário da consulta
            printf("Digite o novo horario: ");
            fgets(atualizar->horario, 20, stdin);
            atualizar->horario[strcspn(atualizar->horario, "\n")] = '\0';

            // Lê a nova duração da consulta
            printf("Digite a nova duracao: ");
            fgets(atualizar->duracao, 20, stdin);
            atualizar->duracao[strcspn(atualizar->duracao, "\n")] = '\0';

            // Retorna após atualizar a consulta
            return;
        }
        atualizar = atualizar->prox;
    }

    // Se a consulta não foi encontrada, imprime uma mensagem de erro
    printf("Consulta nao encontrada!\n");
}

int main()
{
    ListaMedicos listaM;
    iniciarListaMedicos(&listaM);

    ListaPacientes listaP;
    iniciarListaPacientes(&listaP);

    ListaConsulta listaC;
    iniciarConsultas(&listaC);

    int opcao;
    int opcaoMedico;
    int opcaoPaciente;
    int opcaoConsulta;
    int opcaoRelatorio;

    do
    {
        printf("\n");
        printf("~~ Seja bem vindo ao Hospital Bertolato Faria! ~~");
        printf("\n");
        printf("-- Menu Hospital --\n");
        printf("1. | Medicos\n");
        printf("2. | Pacientes\n");
        printf("3. | Consultas\n");
        printf("4. | Relatorios\n");
        printf("5. | Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");
        getchar();

        switch (opcao)
        {
        case 1:
            do
            {
                printf("\n");
                printf("~~ Hospital Bertolato Faria ~~");
                printf("\n");
                printf("-- Medicos --");
                printf("\n");
                printf("1. | Incluir Medico\n");
                printf("2. | Exibir Medicos\n");
                printf("3. | Procurar Medico\n");
                printf("4. | Atualizar Medico\n");
                printf("5. | Voltar\n");
                printf("Digite uma opcao: ");
                scanf("%d", &opcaoMedico);
                printf("\n");
                getchar();

                switch (opcaoMedico)
                {
                case 1:
                    IncluirMedico(&listaM);
                    break;
                case 2:
                    exibirMedicos(&listaM);
                    break;
                case 3:
                    procurarMedico(&listaM);
                    break;
                case 4:
                    atualizarMedico(&listaM);
                    break;
                case 5:
                    break;
                default:
                    printf("Opcao invalida!\n");
                    break;
                }

            } while (opcaoMedico != 5);
            break;

        case 2:
            do
            {
                printf("\n");
                printf("~~ Hospital Bertolato Faria ~~");
                printf("\n");
                printf("-- Pacientes --");
                printf("\n");
                printf("1. | Incluir pacientes\n");
                printf("2. | Exibir pacientes\n");
                printf("3. | Procurar paciente\n");
                printf("4. | Atualizar paciente\n");
                printf("5. | Voltar\n");
                printf("Digite uma opcao: ");
                scanf("%d", &opcaoPaciente);
                printf("\n");
                getchar();

                switch (opcaoPaciente)
                {
                case 1:
                    incluirPaciente(&listaP);
                    break;
                case 2:
                    exibirPacientes(&listaP);
                    break;
                case 3:
                    procurarPaciente(&listaP);
                    break;
                case 4:
                    atualizarPaciente(&listaP);
                    break;
                case 5:
                    break;
                default:
                    printf("Opcao invalida!\n");
                    break;
                }

            } while (opcaoPaciente != 5);
            break;

        case 3:
            do
            {
                printf("\n");
                printf("~~ Hospital Bertolato Faria ~~");
                printf("\n");
                printf("--Consultas--");
                printf("\n");
                printf("1. | Incluir Consulta\n");
                printf("2. | Exibir Consultas\n");
                printf("3. | Procurar Consultas\n");
                printf("4. | Atualizar Consulta\n");
                printf("5. | Voltar\n");
                printf("Digite uma opcao: ");
                scanf("%d", &opcaoConsulta);
                printf("\n");
                getchar();

                switch (opcaoConsulta)
                {
                case 1:
                    incluirConsulta(&listaC, &listaM, &listaP);
                    break;
                case 2:
                    exibirConsultas(&listaC);
                    break;
                case 3:
                    procurarConsultas(&listaC);
                    break;
                case 4:
                    atualizarConsulta(&listaC);
                    break;
                case 5:
                    break;
                default:
                    printf("Opcao invalida!\n");
                    break;
                }
            } while (opcaoConsulta != 5);
            break;
        case 4:

            do {
                printf("\n");
                printf("~~ Hospital Bertolato Faria ~~");
                printf("\n");
                printf("-- Relatorios --");
                printf("\n");
                printf("1. | Lista de Consultas por Medico\n");
                printf("2. | Lista de Consultas por Paciente\n");
                printf("3. | Lista de Consultas por Especialidade\n");
                printf("4. | Voltar\n");
                printf("Digite uma opcao: ");
                scanf("%d", &opcaoRelatorio);
                printf("\n");
                getchar();

                switch (opcaoRelatorio)
                {
                case 1:
                    procurarRelatorioPorMedico(&listaC);
                    break;
                case 2:
                    procurarRelatorioPorPaciente(&listaC);
                    break;
                case 3:
                    procurarRelatorioPorEspecialidade(&listaC, &listaM);
                    break;
                case 4:
                    break;
                default:
                    printf("Opcao invalida!\n");
                    break;
                }
            } while (opcaoRelatorio != 4);
            break;
            
        case 5:
            printf("Saindo...\n");
            exit(1);
        default:
            printf("Opcao nao encontrada!\n");
            break;
        }

    } while (opcao != 0);

    free(listaM.medicos);
    free(listaP.pacientes);
    free(listaC.consultas);
    return 0;
}
