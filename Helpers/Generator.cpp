
#include "Generator.h"

int **Generator::generateEdges(int V, int E){
    // Sprawdzenie czy graf może być spójny
    if(E < V-1){
        throw std::runtime_error("Graf niespójny");
    }

    // inicjalizacja tablicy krawędzi
    int** edges = Generator::initEdgesTable(E);

    // generowanie drzewa rozpinającego
    Generator::generateSpanningTree(V, edges);
    // aktualizacja indeksu
    int index = V-1;

    for (int i = index; i < E; i++) {
        int u = rand() % V;
        int v = rand() % V;
        while (v == u) {
            v = rand() % V; // Zapewniamy, że u != v
        }
        edges[i][0] = u;
        edges[i][1] = v;
    }

    return edges;
}

int **Generator::createIncidenceMatrix(int V, int E, int** edges) {
    int **incidenceMatrix = new int *[V];
    for (int i = 0; i < V; ++i) {
        incidenceMatrix[i] = new int[E];
        for (int j = 0; j < E; ++j) {
            incidenceMatrix[i][j] = 0; // Inicjalizacja zerami
        }
    }

    for (int i = 0; i < E; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        incidenceMatrix[u][i] = 1;
        incidenceMatrix[v][i] = 1;
    }

    return incidenceMatrix;
}

int **Generator::initEdgesTable(int E) {
    int **edges = new int *[E];
    for (int i = 0; i < E; i++) {
        edges[i] = new int[2];
    }
    return edges;
}

void Generator::generateSpanningTree(int V, int **edges){
    for (int i = 0; i < V-1; i++) {
        edges[i][0] = i;
        edges[i][1] = i+1;
    }
}