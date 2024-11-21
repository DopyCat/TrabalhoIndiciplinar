#include <stdio.h>

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
    char buffer[100];
    passageiro pessoa;

    printf("escreva seu nome\n");
    fgets(pessoa.nome, 100, stdin);
    fgets(pessoa.nome, 100, stdin);

    printf("escreva seu endereco\n");
    fgets(pessoa.endereco, 100, stdin);
    fgets(pessoa.endereco, 100, stdin);

    printf("escreva seu numero de telefone\n");
    fgets(pessoa.telefone, 50, stdin);
    fgets(pessoa.telefone, 50, stdin);

    printf("tem fidelidade? (s ou n)\n");
    scanf("%c", &pessoa.fidelidade);

    if (pessoa.fidelidade == 's')
    {
        printf("quantos pontos de fidelidade voce tem?\n");
        scanf("%d", &pessoa.pontos_fidelidade);
    }

    FILE *arquivo;
    arquivo = fopen("documentos.txt", "w");
    if (!arquivo)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    sprintf(buffer, "%s\t", pessoa.nome);
    fputs(buffer, arquivo);
    fclose(arquivo);
}

void registrarTripulacao()
{
    tripulacao pessoa;

    printf("escreva seu nome\n");
    fgets(pessoa.nome, 100, stdin);
    fgets(pessoa.nome, 100, stdin);

    printf("escreva seu numero de telefone\n");
    fgets(pessoa.telefone, 50, stdin);
    fgets(pessoa.telefone, 50, stdin);

    printf("escreva seu cargo\n");
    fgets(pessoa.cargo, 20, stdin);
    fgets(pessoa.cargo, 20, stdin);

}

void registrarVoo() {
    voo aviao;

    printf("escreva a data do voo\n");
    fgets(aviao.data, 10, stdin);
    fgets(aviao.data, 10, stdin);

    printf("escreva a origem do voo\n");
    fgets(aviao.origem, 100, stdin);
    fgets(aviao.origem, 100, stdin);

    printf("escreva o destino do voo\n");
    fgets(aviao.destino, 100, stdin);
    fgets(aviao.destino, 100, stdin);

    printf("escreva o codigo do aviao\n");
    scanf("%d",&aviao.codigo_aviao);

    printf("escreva o codigo do piloto\n");
    scanf("%d",&aviao.codigo_piloto);

    printf("escreva o codigo do copiloto\n");
    scanf("%d",&aviao.codigo_copiloto);

    printf("escreva o codigo do comissario\n");
    scanf("%d",&aviao.codigo_comissario);

    printf("escreva o status do voo\n");
    fgets(aviao.status, 10, stdin);
    fgets(aviao.status, 10, stdin);

}

void registrarAssento() {
    assento cadeira;

    printf("escreva o nume do assento\n");
    scanf("%d",&cadeira.numero);

    printf("escreva status do assento\n");
    scanf("%d",&cadeira.status);
}

void registrarReserva(){
    reserva reservado;
    printf("escreva codigo do assento\n");
    scanf("%d",&reservado.numero_assento);

    printf("escreva codigo do passageiro\n");
    scanf("%d",&reservado.codigo_passageiro);
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