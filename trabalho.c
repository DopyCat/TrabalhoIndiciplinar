#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buffer[100];

FILE *arquivo;
typedef struct passageiro
{
    int codigo;
    char nome[100];
    char endereco[100];
    char telefone[50];
    char fidelidade;
    int pontos_fidelidade;
} passageiro;

typedef struct tripulacao
{
    int codigo;
    char nome[100];
    char telefone[50];
    char cargo[20];
} tripulacao;

typedef struct voo
{
    int codigo;
    char data[10];
    char origem[100];
    char destino[100];
    int codigo_aviao;
    int codigo_piloto;
    int codigo_copiloto;
    int codigo_comissario;
    char status[10];
    int tarifa;
} voo;

typedef struct assento
{
    int codigo;
    int numero;
    char status[20];
} assento;

typedef struct reserva
{
    int codigo;
    int numero_assento;
    int codigo_passageiro;
} reserva;

void registrarPassageiro()
{

    passageiro pessoa;

    printf("escreva seu nome\n");
    fgets(pessoa.nome, 100, stdin);
    fgets(pessoa.nome, 100, stdin);
    pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';

    printf("escreva seu endereco\n");
    fgets(pessoa.endereco, 100, stdin);
    pessoa.endereco[strcspn(pessoa.endereco, "\n")] = '\0';

    printf("escreva seu numero de telefone\n");
    fgets(pessoa.telefone, 50, stdin);
    pessoa.telefone[strcspn(pessoa.telefone, "\n")] = '\0';

    printf("tem fidelidade? (s ou n)\n");
    scanf("%c", &pessoa.fidelidade);

    if (pessoa.fidelidade == 's')
    {
        printf("quantos pontos de fidelidade voce tem?\n");
        scanf("%d", &pessoa.pontos_fidelidade);
    }

    arquivo = fopen("passageiros.txt", "a");
    if (!arquivo)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    sprintf(buffer, "%s\t", pessoa.nome);
    fputs(buffer, arquivo);

    sprintf(buffer, "%s\t", pessoa.endereco);
    fputs(buffer, arquivo);

    sprintf(buffer, "%s\t", pessoa.telefone);
    fputs(buffer, arquivo);

    sprintf(buffer, "%c\t", pessoa.fidelidade);
    fputs(buffer, arquivo);

    if (pessoa.fidelidade == 's')
    {
        sprintf(buffer, "%d\t", pessoa.pontos_fidelidade);
        fputs(buffer, arquivo);
    }

    fclose(arquivo);
}

void registrarTripulacao()
{
    tripulacao pessoa;

    printf("escreva seu nome\n");
    fgets(pessoa.nome, 100, stdin);
    fgets(pessoa.nome, 100, stdin);
    pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';

    printf("escreva seu numero de telefone\n");
    fgets(pessoa.telefone, 50, stdin);
    pessoa.telefone[strcspn(pessoa.telefone, "\n")] = '\0';

    printf("escreva seu cargo\n");
    fgets(pessoa.cargo, 20, stdin);
    pessoa.cargo[strcspn(pessoa.cargo, "\n")] = '\0';

    arquivo = fopen("tripulacao.txt", "a");
    if (!arquivo)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    sprintf(buffer, "%s\t", pessoa.nome);
    fputs(buffer, arquivo);

    sprintf(buffer, "%s\t", pessoa.telefone);
    fputs(buffer, arquivo);

    sprintf(buffer, "%s\t", pessoa.cargo);
    fputs(buffer, arquivo);

    fclose(arquivo);
}

void registrarVoo()
{
    voo aviao;

    printf("escreva a data do voo\n");
    fgets(aviao.data, 10, stdin);
    fgets(aviao.data, 10, stdin);
    aviao.data[strcspn(aviao.data, "\n")] = '\0';

    printf("escreva a origem do voo\n");
    fgets(aviao.origem, 100, stdin);

    aviao.origem[strcspn(aviao.origem, "\n")] = '\0';

    printf("escreva o destino do voo\n");
    fgets(aviao.destino, 100, stdin);

    aviao.destino[strcspn(aviao.destino, "\n")] = '\0';

    printf("escreva o codigo do aviao\n");
    scanf("%d", &aviao.codigo_aviao);

    printf("escreva o codigo do piloto\n");
    scanf("%d", &aviao.codigo_piloto);

    printf("escreva o codigo do copiloto\n");
    scanf("%d", &aviao.codigo_copiloto);

    printf("escreva o codigo do comissario\n");
    scanf("%d", &aviao.codigo_comissario);

    printf("escreva o status do voo\n");
    fgets(aviao.status, 10, stdin);
    fgets(aviao.status, 10, stdin);
    aviao.status[strcspn(aviao.status, "\n")] = '\0';

    printf("escreva a tarifa do voo\n");
    scanf("%d", &aviao.tarifa);

    arquivo = fopen("voo.txt", "a");
    if (!arquivo)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    sprintf(buffer, "%s\t", aviao.data);
    fputs(buffer, arquivo);

    sprintf(buffer, "%s\t", aviao.origem);
    fputs(buffer, arquivo);

    sprintf(buffer, "%s\t", aviao.destino);
    fputs(buffer, arquivo);

    sprintf(buffer, "%d\t", aviao.codigo_aviao);
    fputs(buffer, arquivo);

    sprintf(buffer, "%d\t", aviao.codigo_piloto);
    fputs(buffer, arquivo);

    sprintf(buffer, "%d\t", aviao.codigo_copiloto);
    fputs(buffer, arquivo);

    sprintf(buffer, "%d\t", aviao.codigo_comissario);
    fputs(buffer, arquivo);

    sprintf(buffer, "%s\t", aviao.status);
    fputs(buffer, arquivo);

    sprintf(buffer, "%d\t", aviao.tarifa);
    fputs(buffer, arquivo);

    fclose(arquivo);
}

void registrarAssento()
{
    assento cadeira;

    printf("escreva o numero do assento\n");
    scanf("%d", &cadeira.numero);

    printf("escreva status do assento\n");
    fgets(cadeira.status, 20, stdin);
    fgets(cadeira.status, 20, stdin);
    cadeira.status[strcspn(cadeira.status, "\n")] = '\0';

    arquivo = fopen("assentos.txt", "a");
    if (!arquivo)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }
    sprintf(buffer, "%d\t", cadeira.numero);
    fputs(buffer, arquivo);

    sprintf(buffer, "%s\t", cadeira.status);
    fputs(buffer, arquivo);

    fclose(arquivo);
}

void registrarReserva()
{
    reserva reservado;
    printf("escreva codigo do assento\n");
    scanf("%d", &reservado.numero_assento);

    printf("escreva codigo do passageiro\n");
    scanf("%d", &reservado.codigo_passageiro);

    arquivo = fopen("reservas.txt", "a");
    if (!arquivo)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    sprintf(buffer, "%d\t", reservado.numero_assento);
    fputs(buffer, arquivo);

    sprintf(buffer, "%d\t", reservado.codigo_passageiro);
    fputs(buffer, arquivo);

    fclose(arquivo);
}

int main(void)
{
    int menu;
    do
    {
        printf("selecione uma opcao:"
               "\n1 (registrar passageiro)"
               "\n2 (registrar tripulacao)"
               "\n3 (registrar voo)"
               "\n4 (registrar assentos)"
               "\n5 (reservar assento)"
               "\n0 (finalizar cadastro)\n");

        printf("|\n"
               "V\n");

        scanf("%d", &menu);

        printf("-------------------------------------\n");

        switch (menu)
        {
        case 1:
            registrarPassageiro();
            break;

        case 2:
            registrarTripulacao();
            break;

        case 3:
            registrarVoo();
            break;

        case 4:
            registrarAssento();
            break;

        case 5:
            registrarReserva();
            break;
        }

    } while (menu != 0);

    return 0;
}