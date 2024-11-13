#include <stdio.h>

typedef struct passageiro
{
    int codigo;
    char nome[100];
    char endereco[100];
    int telefone[50];
    char fidelidade;
    int pontos_fidelidade;
}passageiro;

typedef struct tripulacao
{
    int codigo;
    char nome[100];
    int telefone[50];
    char cargo[10];
}tripulacao;

typedef struct voo
{
    int codigo;
    char data[10];
    char origem [100];
    char destino [100];
    int codigo_aviao;
    int codigo_piloto;
    int codigo_copiloto;
    int codigo_comissairo;
    char status[10];
    int tarifa;
}voo;

typedef struct assento{
    int codigo;
    int numero;
    char status[20];
}assento;

typedef struct reserva{
    int codigo;
    int numero_assento; 
    int codigo_passageiro;
}reserva;


int main (void){
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

        printf("\n");


        scanf("%d",&menu);

        printf("-------------------------------------\n");

    } while (menu != 0);
    
    


    return 0;
}