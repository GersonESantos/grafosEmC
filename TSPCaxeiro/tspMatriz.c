#include <stdio.h>

#define TAM 6

int main() {
    // Definição dos nomes das cidades para facilitar a leitura na exibição
    char cidades[TAM] = {'A', 'B', 'C', 'D', 'E', 'F'};

    // Inicialização da Matriz de Adjacência baseada nos pesos do grafo TSP
    // A ordem segue: A, B, C, D, E, F
    int matrizAdjacencia[TAM][TAM] = {
        {0, 7, 2, 1, 2, 4},   // Cidade A
        {7, 0, 9, 6, 2, 5},   // Cidade B
        {2, 9, 0, 11, 3, 2},  // Cidade C
        {1, 6, 11, 0, 8, 4},  // Cidade D
        {2, 2, 3, 8, 0, 10},  // Cidade E
        {4, 5, 2, 4, 10, 0}   // Cidade F
    };

    printf("Matriz de Adjacencia - TSP\n\n");

    // Cabeçalho das colunas
    printf("    ");
    for (int i = 0; i < TAM; i++) {
        printf("%c  ", cidades[i]);
    }
    printf("\n");

    // Impressão das linhas
    for (int i = 0; i < TAM; i++) {
        printf("%c |", cidades[i]); // Nome da cidade na linha
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", matrizAdjacencia[i][j]);
        }
        printf("\n");
    }

    return 0;
}