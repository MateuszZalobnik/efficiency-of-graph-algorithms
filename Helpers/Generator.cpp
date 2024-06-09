
#include "Generator.h"

Edge *Generator::generateEdges(int V, int E) {
    // Sprawdzenie czy graf może być spójny
    if (E < V - 1) {
        throw std::runtime_error("Graf niespójny");
    }

    auto *edges = new Edge[E];
    // generowanie drzewa rozpinającego
    Generator::generateSpanningTree(V, edges);
    // aktualizacja indeksu
    int index = V - 1;

    for (int i = index; i < E; i++) {
        int u = rand() % V;
        int v = rand() % V;
        while (v == u) {
            v = rand() % V; // Zapewniamy, że u != v
        }
        edges[i].src = u;
        edges[i].dest = v;
        edges[i].weight = rand() % 10 + 1;
    }

    return edges;
}

void Generator::generateSpanningTree(int V, Edge *edges) {
    for (int i = 0; i < V - 1; i++) {
        edges[i].src = i;
        edges[i].dest = i + 1;
        edges[i].weight = rand() % 10 + 1;
    }
}

int Generator::numberOfEdgesByDensityAndNodes(int V, float density) {
    int max_edges = (V * (V - 1)) / 2;
    int E = density * max_edges;
    return E;
}
