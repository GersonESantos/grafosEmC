#include <stdio.h>
#include <stdbool.h>

#define TAM 6
#define INFINITO 999999

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
int caminhoAtual[TAM];
int melhorCaminho[TAM];
char cidades[] = {'A', 'B', 'C', 'D', 'E', 'F'};

void calcularTSP(int cidadeAtual, int cont, int distanciaAcumulada) {
    caminhoAtual[cont - 1] = cidadeAtual;

    if (cont == TAM) {
        int distanciaFinal = distanciaAcumulada + matrizAdjacencia[cidadeAtual][0];
        
        if (distanciaFinal < menorDistanciaTotal) {
            menorDistanciaTotal = distanciaFinal;
            // Salva o melhor caminho encontrado
            for (int i = 0; i < TAM; i++) {
                melhorCaminho[i] = caminhoAtual[i];
            }
        }
        return;
    }

    for (int proximaCidade = 0; proximaCidade < TAM; proximaCidade++) {
        if (!visitado[proximaCidade] && matrizAdjacencia[cidadeAtual][proximaCidade] > 0) {
            visitado[proximaCidade] = true;
            calcularTSP(proximaCidade, cont + 1, distanciaAcumulada + matrizAdjacencia[cidadeAtual][proximaCidade]);
            visitado[proximaCidade] = false;
        }
    }
}

int main() {
    for (int i = 0; i < TAM; i++) visitado[i] = false;

    visitado[0] = true;
    
    printf("Calculando a melhor rota para o TSP...\n\n");
    calcularTSP(0, 1, 0);

    printf("Menor distancia encontrada: %d\n", menorDistanciaTotal);
    printf("Rota: ");
    for (int i = 0; i < TAM; i++) {
        printf("%c -> ", cidades[melhorCaminho[i]]);
    }
    printf("%c\n", cidades[melhorCaminho[0]]); // Retorno à origem

    return 0;
}