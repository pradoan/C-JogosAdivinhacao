#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Bem vinda ao jogo de Adivinhacao\n");

    int segundos = time(0);
    srand(segundos);
    int numRandomico = rand();
    int numeroSecreto = numRandomico % 100;

    int tentativas = 1;
    int chute;
    double pontos = 1000;

    while(1)
    {
        printf("Tentativa %d\n", tentativas);
        printf("Qual eh o seu chute? \n");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0)
        {
            printf("Sao aceitos apenas numeros positivos.\n");
            continue;
        }

        int acertou = (chute == numeroSecreto);
        int menor = (chute < numeroSecreto);

        if(acertou)
        {
            printf("Show. Acertaste. o/ \n");
            break;
        }
        else if(menor)
        {
            printf("O numero secreto eh MAIOR que o teu chute.\n");
        }
        else
        {
            printf("O numero secreto eh MENOR que o teu chute.\n");
        }
        tentativas++;
        double pontosPerdidos = abs(chute - numeroSecreto) / 2.0;
        pontos = pontos - pontosPerdidos;
    }
    printf("Fim de jogo.\n");
    printf("Foram %d tentativas\n", tentativas);
    printf("Total de pontos: %.1f\n", pontos);
}