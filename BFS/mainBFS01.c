#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BRANCO 0
#define CINZA  1
#define PRETO  2
#define NULO  -1
#define INF    INT_MAX

typedef struct {
    int cor;
    int d;
    int pi;
} Vertice;

// Função para exibir o estado atual (Tabela de Rastreamento)
void mostrar_passo_inicializacao(int n, Vertice vertices[], int s, const char* fase) {
    char nomes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    printf("\n--- %s ---\n", fase);
    
    printf("Vertice | ");
    for (int i = 0; i < n; i++) printf("  %c  | ", nomes[i]);
    printf("\n--------|");
    for (int i = 0; i < n; i++) printf("-----| ");
    
    printf("\nCOR     | ");
    for (int i = 0; i < n; i++) {
        char c = (vertices[i].cor == BRANCO) ? 'B' : (vertices[i].cor == CINZA) ? 'C' : 'P';
        printf("  %c  | ", c);
    }
    
    printf("\nd       | ");
    for (int i = 0; i < n; i++) {
        if (vertices[i].d == INF) printf(" inf | ");
        else printf("  %d  | ", vertices[i].d);
    }
    
    printf("\npi      | ");
    for (int i = 0; i < n; i++) {
        if (vertices[i].pi == NULO) printf(" NIL | ");
        else printf("  %c  | ", nomes[vertices[i].pi]);
    }
    printf("\n");
}

void inicializacao_BFS(int n, int s, Vertice vertices[]) {
    char nomes[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    // 1-4: for cada vértice u em V[G] - {s}
    for (int u = 0; u < n; u++) {
        vertices[u].cor = BRANCO;
        vertices[u].d = INF;
        vertices[u].pi = NULO;
    }
    mostrar_passo_inicializacao(n, vertices, s, "Passo 1-4: Todos os vertices como BRANCO/INF/NIL");

    // 5-7: s.cor = CINZA, s.d = 0, s.pi = NULO
    vertices[s].cor = CINZA;
    vertices[s].d = 0;
    vertices[s].pi = NULO;
    
    char msg[50];
    sprintf(msg, "Passo 5-7: Origem %c configurada (CINZA)", nomes[s]);
    mostrar_passo_inicializacao(n, vertices, s, msg);

    // 8: Q = vazio
    printf("\n--- Passo 8: Q = { } (Fila inicializada vazia) ---\n");
}

int main() {
    int n = 6;
    Vertice *vertices = (Vertice*)malloc(n * sizeof(Vertice));
    int origem = 0; // Vértice A

    printf("=== TESTE DE MESA: INICIALIZACAO DO BFS ===\n");
    
    inicializacao_BFS(n, origem, vertices);

    free(vertices);
    return 0;
}