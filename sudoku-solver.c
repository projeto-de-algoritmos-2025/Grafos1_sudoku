#include <stdio.h>
#include <stdbool.h>
#define N 9

// Estrutura para representar um nó no grafo
typedef struct {
    int lin, col;
} Node;

// Printa a tabela de sudoku
void printTabela(int tabela[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tabela[i][j]);
        }
        printf("\n");
    }
}

bool numerosIguais(int tabela[N][N], int lin, int col, int num) {
    // Verifica se o número já existe na linha ou coluna
    for (int x = 0; x < N; x++) {
        if (tabela[lin][x] == num || tabela[x][col] == num) {
            return true;
        }
    }