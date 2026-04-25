
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definimos o tamanho máximo de vértices para o exemplo
#define MAX_VERTICES 5

int main() {
    // 1. Criar e inicializar a matriz com zeros
    // matriz[linha][coluna]
    int matrizAdjacencia[MAX_VERTICES][MAX_VERTICES];

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            matrizAdjacencia[i][j] = 0;
        }
    }

    // 2. Montar as conexões (Arestas) baseadas na sua imagem
    // Conexões do vértice 0
    matrizAdjacencia[0][1] = 1;
    matrizAdjacencia[0][2] = 1;
    matrizAdjacencia[0][3] = 1;

    // Como o grafo é não-direcionado, se 0 conecta com 1, 1 também conecta com 0
    matrizAdjacencia[1][0] = 1;
    matrizAdjacencia[2][0] = 1;
    matrizAdjacencia[3][0] = 1;

    // Outras conexões
    matrizAdjacencia[1][3] = 1;
    matrizAdjacencia[3][1] = 1;

    matrizAdjacencia[3][4] = 1;
    matrizAdjacencia[4][3] = 1;

    // 3. Exibir a matriz no console para conferir
    printf("Matriz de Adjacencia:\n");
    printf("    0 1 2 3 4\n");
    printf("    ---------\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("%d | ", i);
        for (int j = 0; j < MAX_VERTICES; j++) {
            printf("%d ", matrizAdjacencia[i][j]);
        }
        printf("\n");
    }

    return 0;
}