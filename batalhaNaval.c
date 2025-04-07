#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

int main() {
    // Declaração da matriz 10x10 representando o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicialização do tabuleiro com água (valor 0)
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // Coordenadas iniciais do navio horizontal (linha, coluna)
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica se as posições estão livres (sem sobreposição)
        int podeColocar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != AGUA) {
                podeColocar = 0;
                break;
            }
        }

        // Posiciona o navio horizontal se possível
        if (podeColocar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = NAVIO;
            }
        } else {
            printf("Erro: Não foi possível posicionar o navio horizontal (sobreposição).\n");
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
    }

    // Coordenadas iniciais do navio vertical (linha, coluna)
    int linhaVertical = 5;
    int colunaVertical = 7;

    // Verifica se o navio vertical cabe no tabuleiro
    if (linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica se as posições estão livres (sem sobreposição)
        int podeColocar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] != AGUA) {
                podeColocar = 0;
                break;
            }
        }

        // Posiciona o navio vertical se possível
        if (podeColocar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = NAVIO;
            }
        } else {
            printf("Erro: Não foi possível posicionar o navio vertical (sobreposição).\n");
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
    }

    // Impressão do tabuleiro
    printf("\nTabuleiro Batalha Naval:\n\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
