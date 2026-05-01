#include <stdio.h>
#include <stdbool.h>

#define TAM 6
#define INFINITO 999999

// Matriz de Adjacência baseada nos dados do grafo TSP
int matrizAdjacencia[TAM][TAM] = {
    {0, 7, 2, 1, 2, 4},   // A
    {7, 0, 9, 6, 2, 5},   // B
    {2, 9, 0, 11, 3, 2},  // C
    {1, 6, 11, 0, 8, 4},  // D
    {2, 2, 3, 8, 0, 10},  // E
    {4, 5, 2, 4, 10, 0}   // F
};

bool visitado[TAM];
int menorDistanciaTotal = INFINITO;

/**
 * Função recursiva para encontrar o menor caminho (Backtracking)
 * cidadeAtual: índice da cidade onde o caixeiro está agora
 * cont: quantas cidades já foram visitadas
 * distanciaAcumulada: a soma dos pesos das arestas percorridas até aqui
 */
void calcularTSP(int cidadeAtual, int cont, int distanciaAcumulada) {
    
    // Caso base: se todas as cidades foram visitadas
    if (cont == TAM) {
        // Adiciona a distância de volta para a cidade de origem (0 = 'A')
        int distanciaFinal = distanciaAcumulada + matrizAdjacencia[cidadeAtual][0];
        
        if (distanciaFinal < menorDistanciaTotal) {
            menorDistanciaTotal = distanciaFinal;
        }
        return;
    }

    // Explora as cidades vizinhas
    for (int proximaCidade = 0; proximaCidade < TAM; proximaCidade++) {
        if (!visitado[proximaCidade] && matrizAdjacencia[cidadeAtual][proximaCidade] > 0) {
            visitado[proximaCidade] = true;
            calcularTSP(proximaCidade, cont + 1, distanciaAcumulada + matrizAdjacencia[cidadeAtual][proximaCidade]);
            
            // Backtracking: desmarca para tentar outros caminhos
            visitado[proximaCidade] = false;
        }
    }
}

int main() {
    // Inicializa o array de visitados
    for (int i = 0; i < TAM; i++) visitado[i] = false;

    // Começamos pela cidade A (índice 0)
    visitado[0] = true;
    
    printf("Calculando a menor rota para o TSP (6 cidades)...\n");
    calcularTSP(0, 1, 0);

    printf("Menor distancia encontrada: %d\n", menorDistanciaTotal);

    return 0;
}