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
int totalRotasEncontradas = 0;

void calcularTSP(int cidadeAtual, int cont, int distanciaAcumulada) {
    caminhoAtual[cont - 1] = cidadeAtual;

    if (cont == TAM) {
        totalRotasEncontradas++;
        int distanciaFinal = distanciaAcumulada + matrizAdjacencia[cidadeAtual][0];
        
        printf("Rota %3d: ", totalRotasEncontradas);
        for (int i = 0; i < TAM; i++) {
            printf("%c -> ", cidades[caminhoAtual[i]]);
        }
        printf("%c | Distancia: %d\n", cidades[caminhoAtual[0]], distanciaFinal);

        if (distanciaFinal < menorDistanciaTotal) {
            menorDistanciaTotal = distanciaFinal;
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
    
    printf("Listando todas as rotas Hamiltonianas possiveis:\n");
    printf("-----------------------------------------------\n");
    
    calcularTSP(0, 1, 0);

    printf("\n-----------------------------------------------\n");
    printf("RESUMO DO PROCESSAMENTO\n");
    printf("Total de rotas validas exploradas: %d\n", totalRotasEncontradas);
    printf("Menor distancia encontrada: %d\n", menorDistanciaTotal);
    
    // Nova linha detalhando os pesos da melhor rota
    printf("Pesos da melhor rota: ");
    for (int i = 0; i < TAM - 1; i++) {
        printf("%d + ", matrizAdjacencia[melhorCaminho[i]][melhorCaminho[i+1]]);
    }
    printf("%d = %d\n", matrizAdjacencia[melhorCaminho[TAM-1]][melhorCaminho[0]], menorDistanciaTotal);

    printf("Melhor Rota:        ");
    for (int i = 0; i < TAM; i++) {
        printf("%c -> ", cidades[melhorCaminho[i]]);
    }
    printf("%c\n", cidades[melhorCaminho[0]]);

    return 0;
}