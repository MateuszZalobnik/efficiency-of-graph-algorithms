//
// Created by MateuszZalobnik on 6/5/2024.
//

#include "Kruskal.h"

Edge *Kruskal::kruskalMST(Edge *edges, int V, int E) {
    Edge *result = new Edge[V];

    // sortujemy krawędzie malejąco
    heapSortEdgesDesc(edges, E);

    for (int i = 0; i < E; i++) {
        std::cout << "Edge " << i << ": (" << edges[i].src << ", "
                  << edges[i].dest << ", " << edges[i].weight << ")\n";
    }


    return result;
}


void Kruskal::heapSortEdgesDesc(Edge *edges, int E) {
    for (int i = E / 2 - 1; i >= 0; i--) {
        heapifyDesc(E, i, edges);
    }

    for (int i = E - 1; i >= 0; i--) {
        std::swap(edges[0], edges[i]);
        heapifyDesc(i, 0, edges);
    }
}

void Kruskal::heapifyDesc(int N, int i, Edge *edges) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && edges[left].weight < edges[smallest].weight) {
        smallest = left;
    }

    if (right < N && edges[right].weight < edges[smallest].weight) {
        smallest = right;
    }

    if (smallest != i) {
        std::swap(edges[i], edges[smallest]);
        heapifyDesc(N, smallest, edges);
    }
}

