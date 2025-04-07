#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para verificar se é possível posicionar o navio sem ultrapassar limites e sem sobreposição
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int deltaLinha, int deltaColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + i * deltaLinha;
        int c = coluna + i * deltaColuna;

        if (l < 0 || l >= TAM || c < 0 || c >= TAM)
            return 0; // Fora dos limites
        if (tabuleiro[l][c] != AGUA)
            return 0; // Sobreposição
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int deltaLinha, int deltaColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + i * deltaLinha;
        int c = coluna + i * deltaColuna;
        tabuleiro[l][c] = NAVIO;
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;

    // --- Navio Horizontal ---
    int lH = 1, cH = 2;
    if (podePosicionar(tabuleiro, lH, cH, 0, 1))
        posicionarNavio(tabuleiro, lH, cH, 0, 1);
    else
        printf("Erro ao posicionar navio horizontal.\n");

    // --- Navio Vertical ---
    int lV = 5, cV = 0;
    if (podePosicionar(tabuleiro, lV, cV, 1, 0))
        posicionarNavio(tabuleiro, lV, cV, 1, 0);
    else
        printf("Erro ao posicionar navio vertical.\n");

    // --- Navio Diagonal ↘ (linha++, coluna++) ---
    int lD1 = 3, cD1 = 3;
    if (podePosicionar(tabuleiro, lD1, cD1, 1, 1))
        posicionarNavio(tabuleiro, lD1, cD1, 1, 1);
    else
        printf("Erro ao posicionar navio diagonal ↘.\n");

    // --- Navio Diagonal ↙ (linha++, coluna--) ---
    int lD2 = 0, cD2 = 9;
    if (podePosicionar(tabuleiro, lD2, cD2, 1, -1))
        posicionarNavio(tabuleiro, lD2, cD2, 1, -1);
    else
        printf("Erro ao posicionar navio diagonal ↙.\n");

    // Imprime o resultado final do tabuleiro
    imprimirTabuleiro(tabuleiro);

    return 0;
}
