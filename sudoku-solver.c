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
    // Verifica se o número já existe no bloco 3x3
    int initLin = lin - lin % 3;
    int initCol = col - col % 3;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabela[i + initLin][j + initCol] == num) {
                return true;
            }
        }
    }
    return false;
}

// Resolve a tabela de sudoku
bool resolverSudoku(int tabela[N][N]) {
    int lin, col;
    bool vazioEncontrado = false;
    // Encontra uma célula vazia na tabela
    for (lin = 0; lin < N; lin++) {
        for (col = 0; col < N; col++) {
            if (tabela[lin][col] == 0) {
                vazioEncontrado = true;
                break;
            }
        }
        if (vazioEncontrado) {
            break;
        }
    }
