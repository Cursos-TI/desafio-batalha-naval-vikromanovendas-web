#include <stdio.h>

#define TAM 10
#define H 5

void imprimeTabuleiro(int tab[TAM][TAM]) {
    int i, j;

    /* letras das colunas */
    printf("   ");
    for (j = 0; j < TAM; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    for (i = 0; i < TAM; i++) {

        /* numero da linha */
        if (i + 1 < 10)
            printf("%2d ", i + 1);
        else
            printf("%2d ", i + 1);

        for (j = 0; j < TAM; j++) {

            if (tab[i][j] == 0)
                printf("0 ");
            else if (tab[i][j] == 3)
                printf("3 ");
            else if (tab[i][j] == 5)
                printf("5 ");
        }

        printf("\n");
    }
}

int main() {

    int tabuleiro[TAM][TAM];
    int cone[H][H];
    int cruz[H][H];
    int octaedro[H][H];

    int i, j;

    /* ------------------------------
       Zerar tabuleiro
    --------------------------------*/
    for (i = 0; i < TAM; i++)
        for (j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    /* ------------------------------
       Navios de exemplo
    --------------------------------*/
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;

    tabuleiro[6][6] = 3;
    tabuleiro[7][6] = 3;

    /* =====================================================
       MATRIZ CONE (apontando para baixo)
    ===================================================== */
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {

            int centro = H / 2;

            if (j >= centro - i && j <= centro + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    /* =====================================================
       MATRIZ CRUZ
    ===================================================== */
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {

            if (i == H / 2 || j == H / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    /* =====================================================
       MATRIZ OCTAEDRO (losango)
    ===================================================== */
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {

            int di = i - H / 2;
            int dj = j - H / 2;

            if (di < 0) di = -di;
            if (dj < 0) dj = -dj;

            if (di + dj <= H / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    /* =====================================================
       ORIGENS DAS HABILIDADES
    ===================================================== */
    int origemConeL = 1, origemConeC = 7;
    int origemCruzL = 5, origemCruzC = 2;
    int origemOctL  = 6, origemOctC  = 7;

    /* =====================================================
       SOBREPOR CONE
    ===================================================== */
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {

            if (cone[i][j] == 1) {

                int l = origemConeL + i;
                int c = origemConeC + j - H / 2;

                if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                    if (tabuleiro[l][c] == 0)
                        tabuleiro[l][c] = 5;
                }
            }
        }
    }

    /* =====================================================
       SOBREPOR CRUZ
    ===================================================== */
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {

            if (cruz[i][j] == 1) {

                int l = origemCruzL + i - H / 2;
                int c = origemCruzC + j - H / 2;

                if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                    if (tabuleiro[l][c] == 0)
                        tabuleiro[l][c] = 5;
                }
            }
        }
    }

    /* =====================================================
       SOBREPOR OCTAEDRO
    ===================================================== */
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {

            if (octaedro[i][j] == 1) {

                int l = origemOctL + i - H / 2;
                int c = origemOctC + j - H / 2;

                if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                    if (tabuleiro[l][c] == 0)
                        tabuleiro[l][c] = 5;
                }
            }
        }
    }

    imprimeTabuleiro(tabuleiro);

    return 0;
}