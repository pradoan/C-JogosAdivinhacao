#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    
    printf("                    T~~                             \n");
    printf("                    |                               \n");
    printf("                    /'\\                            \n");
    printf("            T~~     |'| T~~                         \n");
    printf("        T~~ |    T~ WWWW|               Bem Vinda/o \n");
    printf("        |  /'\\   |  |  |/\\T~~         ao jogo de  \n");
    printf("        /'\\ WWW  /'\\ |' |WW|          Adivinhacao \n");
    printf("        WWWWW/\\| /   \\|'/\\|/'\\                  \n");
    printf("        |   /__\\/]WWW[\\/__\\WWWW                  \n");
    printf("        |'  WWWW'|I_I|'WWWW'  |                     \n");
    printf("        |   |' |/  -  \\|' |'  |                    \n");
    printf("        |'  |  |LI=H=LI|' |   |                     \n");
    printf("        |   |' | |[_]| |  |'  |                     \n");
    printf("        |   |  |_|###|_|  |   |                     \n");
    printf("        '---'--'-/___\\-'--'---'                    \n");


    int segundos = time(0);
    srand(segundos);
    int numRandomico = rand();
    int numeroSecreto = numRandomico % 100;

    int chute;
    double pontos = 1000;
    int acertou = (chute == numeroSecreto);
    int nivel;
    printf("Qual o nivel de dificuldade?\n");
    printf("(1)Facil     (2)Medio     (3)Dificil\n\n");
    printf("Escolha: \n");
    scanf("%d", &nivel);

    int tentativas;

    switch (nivel)
    {
    case 1:
        tentativas = 20;
        break;
    case 2:
        tentativas = 15;
        break; 
    default:
        tentativas = 5;
        break;
    }


    for(int i = 1; i <= tentativas; i++)
    {
        printf("Tentativa %d de %d\n", i, tentativas);
        printf("Qual eh o seu chute? \n");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0)
        {
            printf("Sao aceitos apenas numeros positivos.\n");
            i--;
            continue;
        }
        
        int menor = (chute < numeroSecreto);
        if(acertou)
        {
            break;
        }
        else if(menor)
        {
            printf("O Numero Secreto eh MAIOR que o teu chute.\n");
        }
        else
        {
            printf("O Numero Secreto eh MENOR que o teu chute.\n");
        }
        double pontosPerdidos = abs(chute - numeroSecreto) / 2.0;
        pontos = pontos - pontosPerdidos;
        
    }

    printf("Fim de jogo.\n");

    if(acertou)
    {
        printf("Acertaste. o/\n");
        printf("Total de pontos: %.1f\n", pontos);
    }
    else
    {
        // added ascii art
        printf("Tu perdeste. Tente de novo.\n");
        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");

        printf("O Numero Secreto era %d\n", numeroSecreto);
    }
}