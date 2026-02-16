#include <stdio.h>

int main() {

    int tabuleiro[10][10];
    int i, j;

    /* 1) Zerar o tabuleiro */
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    /* 2) Vetores dos navios */
    int navioH[3] = {3, 3, 3};   // navio horizontal
    int navioV[3] = {3, 3, 3};   // navio vertical

    /* 3) Posicoes iniciais */
    int linhaH = 4;
    int colunaH = 2;

    int linhaV = 1;
    int colunaV = 6;

    /* 4) Validacao de limite */

    /* horizontal */
    if(colunaH + 3 > 10){
        printf("Navio horizontal fora do tabuleiro\n");
        return 0;
    }

    /* vertical */
    if(linhaV + 3 > 10){
        printf("Navio vertical fora do tabuleiro\n");
        return 0;
    }

    /* 5) Colocar navio horizontal */
    for(i = 0; i < 3; i++){

        if(tabuleiro[linhaH][colunaH + i] != 0){
            printf("Sobreposicao no navio horizontal\n");
            return 0;
        }

        tabuleiro[linhaH][colunaH + i] = navioH[i];
    }

    /* 6) Colocar navio vertical */
    for(i = 0; i < 3; i++){

        if(tabuleiro[linhaV + i][colunaV] != 0){
            printf("Sobreposicao no navio vertical\n");
            return 0;
        }

        tabuleiro[linhaV + i][colunaV] = navioV[i];
    }

    /* 7) Imprimir tabuleiro */

    printf("    A B C D E F G H I J\n");

    for(i = 0; i < 10; i++){

        printf("%2d  ", i + 1);

        for(j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}