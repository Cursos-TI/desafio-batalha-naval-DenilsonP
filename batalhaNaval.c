#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void print_tabuleiro(int tabuleiro  [10][10]){
 

for (int i = 0; i < 10; i++) {
    printf("%2d ", i);
    for (int j = 0; j < 10; j++) {
        if (tabuleiro[i][j] == 0) {
            printf("~ "); // Água representada por '~'
        } else {
            printf("3 "); // Navios representados por '3'
        }
    }
    printf("\n");
}
}
int validar_posicao(int tabuleiro[10][10], int linha, int coluna, int orientacao) {
    for (int i = 0; i < 3; i++) {
        if (orientacao == 0) { // Horizontal
            if (coluna + i >= 10 || tabuleiro[linha][coluna + i] != 0) {
                return 0;
            }
        } else { // Vertical
            if (linha + i >= 10 || tabuleiro[linha + i][coluna] != 0) {
                return 0;
            }
        }
    }
    return 1;
}



void posicionar_navio(int tabuleiro[10][10], int linha, int coluna, int orientacao) {
    for (int i = 0; i < 3; i++) {
        if (orientacao == 0) { // Horizontal
            tabuleiro[linha][coluna + i] = 3;
        } else { // Vertical
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}




    int main() {
        int tabuleiro[10][10] = {0};
        srand(time(NULL));
        int linha1, coluna1, linha2, coluna2;
        
        // Recebe entrada para o primeiro navio (horizontal)
        do {
            printf("Digite a linha e a coluna iniciais para o navio horizontal (0-9): ");
            scanf("%d %d", &linha1, &coluna1);
        } while (!validar_posicao(tabuleiro, linha1, coluna1, 0));
        posicionar_navio(tabuleiro, linha1, coluna1, 0);
        
        // Recebe entrada para o segundo navio (vertical)
        do {
            printf("Digite a linha e a coluna iniciais para o navio vertical (0-9): ");
            scanf("%d %d", &linha2, &coluna2);
        } while (!validar_posicao(tabuleiro, linha2, coluna2, 1));
        posicionar_navio(tabuleiro, linha2, coluna2, 1);

        // Exibe o tabuleiro inicial
        print_tabuleiro(tabuleiro);
    
    return 0;
}
