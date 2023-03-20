#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

    //  cabecalho do jogo
    printf("******************************************\n");
    printf("* Bem vindo ao jogo de adivinhação *\n");
    printf("******************************************\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;

    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nível de dificuldade? \n");
    printf("1 - fácil; 2 - médio; 3 - difícil \n\n");
    printf("Escolha o nível : ");
    scanf("%d", &nivel);


    int numerodetentativas; 

    switch (nivel)
    {
    case 1:
        numerodetentativas = 20;
        break;

    case 2:
        numerodetentativas = 15;
        break;

    default:
        numerodetentativas = 6;
        break;
    }


    for(int i = 1; i <= numerodetentativas; i++) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute?\n ");

        scanf("%d", &chute);
        printf("Seu chute foi %d \n", chute);



        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            printf("\n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou) {
            break;
        }

        else if(maior) {
            printf("Seu chute foi maior que o número secreto\n");
        } 

        else {
            printf("Seu chute foi menor que o número secreto\n");
        }

        tentativas++;

        double pontosPerdidos = abs(chute - numerosecreto) / 2;
             pontos = pontos -  pontosPerdidos;
     }



    printf("\n");
    printf("Fim de jogo!\n");

    if(acertou){
        printf("Você ganhou! \n");
        printf("Você acertou em %d tentativas!", tentativas);
        printf("Pontos = %.3lf\n", pontos);


    }else{
        printf("Você perdeu! Tente de novo. \n");
    }



}