#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro Final:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se pode posicionar o navio
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int deltaLinha, int deltaColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + i * deltaLinha;
        int c = coluna + i * deltaColuna;
        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tabuleiro[l][c] != AGUA)
            return 0;
    }
    return 1;
}

// Posiciona o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int deltaLinha, int deltaColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + i * deltaLinha;
        int c = coluna + i * deltaColuna;
        tabuleiro[l][c] = NAVIO;
    }
}

// Aplica matriz de habilidade no tabuleiro, centralizada no ponto de origem
void aplicarHabilidade(int tabuleiro[TAM][TAM], int origemLinha, int origemColuna, int matriz[7][7], int tamanho) {
    int offset = tamanho / 2;

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (matriz[i][j] == 1) {
                int l = origemLinha + (i - offset);
                int c = origemColuna + (j - offset);
                if (l >= 0 && l < TAM && c >= 0 && c < TAM && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }
        }
    }
}

// Constrói matriz Cone (aponta para baixo)
void construirCone(int matriz[7][7]) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            matriz[i][j] = 0;

    for (int i = 0; i < 7; i++) {
        int start = 3 - i;
        int end = 3 + i;
        for (int j = start; j <= end; j++) {
            if (j >= 0 && j < 7)
                matriz[i][j] = 1;
        }
    }
}

// Constrói matriz Cruz
void construirCruz(int matriz[7][7]) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            matriz[i][j] = (i == 3 || j == 3) ? 1 : 0;
}

// Constrói matriz Octaedro (losango)
void construirOctaedro(int matriz[7][7]) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            matriz[i][j] = (abs(i - 3) + abs(j - 3) <= 3) ? 1 : 0;
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Posiciona navios fixos
    if (podePosicionar(tabuleiro, 1, 2, 0, 1))
        posicionarNavio(tabuleiro, 1, 2, 0, 1); // horizontal
    if (podePosicionar(tabuleiro, 5, 0, 1, 0))
        posicionarNavio(tabuleiro, 5, 0, 1, 0); // vertical
    if (podePosicionar(tabuleiro, 3, 3, 1, 1))
        posicionarNavio(tabuleiro, 3, 3, 1, 1); // diagonal ↘
    if (podePosicionar(tabuleiro, 0, 9, 1, -1))
        posicionarNavio(tabuleiro, 0, 9, 1, -1); // diagonal ↙

    // Criação das matrizes de habilidade
    int cone[7][7], cruz[7][7], octaedro[7][7];
    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Aplicação das habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, 2, 2, cone, 7);        // cone no (2,2)
    aplicarHabilidade(tabuleiro, 5, 5, cruz, 7);        // cruz no (5,5)
    aplicarHabilidade(tabuleiro, 7, 7, octaedro, 7);    // octaedro no (7,7)

    // Exibe o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
