#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    //variaveis
    int seed = time(NULL);
    srand(seed);
    int numeroSecreto = 1 + ( rand() % 50 );
    int chuteUsuario;
    int escolhaDif;
    int dificuldade;
    double pontos;

    //escolha de dificuldade
    while (escolhaDif != 1 && escolhaDif !=2 && escolhaDif !=3)
    {
        printf("Escolha sua dificuldade: \n 1-Facil\n 2-Medio\n 3-Dificil\n");
        scanf("%d",&escolhaDif);

        switch (escolhaDif)
            {
            case 1:
                dificuldade = 12;
                pontos = 500;
                break;
            case 2:
                dificuldade = 8;
                pontos = 800;
                break;
            case 3:
                dificuldade = 5;
                pontos = 1000;
                break;
            
            default:
                printf("Digite valor valido\n");
        }
    }

    for (int tentativas = 1; tentativas <= dificuldade; tentativas++)
    {
        printf("Voce tem %d tentativas de %d\n",tentativas,dificuldade);
        printf("Chute um numero de 0 a 50: \n");
        scanf("%d", &chuteUsuario);

        //tratamento de dados        
        if (chuteUsuario < 0)
        {
            printf("Valor negativo\n");
            tentativas--;
            continue;
        }
        else if (chuteUsuario > 50)
        {
            printf("Valor maior que 50\n");
            tentativas--;
            continue;
        }

        //logica do jogo
        if (chuteUsuario == numeroSecreto)
        {

        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");
        printf("Parabens voce acertou o numero!\n");
            break;
        }
        else if (chuteUsuario > numeroSecreto)
        {
            printf("Numero do usuario: %d é maior que o secreto\n",chuteUsuario);
        }
        else if (chuteUsuario < numeroSecreto)
        {
            printf("Numero do usuario: %d é menor que o secreto\n",chuteUsuario);
        }
        if (tentativas == dificuldade)
        {
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
            printf("Game Over\n");
        }
        //pontuação
        double pontosPerdidos = abs(chuteUsuario - numeroSecreto) / (double)2;
        pontos = pontos - pontosPerdidos;
    }
    printf("O numero secreto era:%d\n", numeroSecreto);
    printf("Seus pontos durante a partida: %.1f",pontos);
}