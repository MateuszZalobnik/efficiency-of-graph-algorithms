
#include "Generator.h"

Edge *Generator::generateEdges(int V, int E, bool directed) {
    // Sprawdzenie czy graf może być spójny
    if (E < V - 1) {
        throw std::runtime_error("Graf niespójny");
    }

    int maxEdgeNumberFromNode;

    if (directed) {
        maxEdgeNumberFromNode = E / V + 1;
    } else {
        maxEdgeNumberFromNode =  2 * E / V + 1;
    }

    auto *currentNumberOfEdges = new int[V];
    for (int i = 0; i < V; i++) {
        currentNumberOfEdges[i] = 0;
    }


    auto *edges = new Edge[E];
    // generowanie drzewa rozpinającego
    Generator::generateSpanningTree(V, edges, currentNumberOfEdges);
    // aktualizacja indeksu
    int index = V - 1;

    for (int i = index; i < E; i++) {
        int u = rand() % V;
        int v = rand() % V;

        while (currentNumberOfEdges[u] >= maxEdgeNumberFromNode) {
            u = rand() % V;
        }
        currentNumberOfEdges[u]++;

        while (v == u) {
            v = rand() % V; // Zapewniamy, że u != v
        }
        edges[i].src = u;
        edges[i].dest = v;
        edges[i].weight = rand() % INT_MAX + 1;
    }

    return edges;
}

void Generator::generateSpanningTree(int V, Edge *edges, int *currentNumberOfEdges) {
    for (int i = 0; i < V - 1; i++) {
        currentNumberOfEdges[i]++;
        edges[i].src = i;
        edges[i].dest = i + 1;
        edges[i].weight = rand() % INT_MAX + 1;
    }
}

int Generator::numberOfEdgesByDensityAndNodes(int V, float density) {
    int max_edges = (V * (V - 1)) / 2;
    int E = density * max_edges;
    return E;
}
