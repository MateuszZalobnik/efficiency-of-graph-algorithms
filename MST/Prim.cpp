
#include "Prim.h"
#include "../Structures/EdgeQueue.h"

Edge *Prim::primMST(AdjacencyList adjacencyList) {
    auto array = adjacencyList.getArray();

    int V = adjacencyList.getV();
    int visitedNodes[V];
    Edge *result = new Edge[V - 1];

    auto priorityQueue = new EdgeQueue();

    // przejście po krawędziach z pierwszego wierzchołka
    int currentNodeIndex = 0;
    int visitedNodesIndex = 0;
    // dodanie poczatkowego wierzcholka
    visitedNodes[visitedNodesIndex] = currentNodeIndex;
    visitedNodesIndex++;

    for (int i = 0; i < V-1; i++) {
        auto node = array[currentNodeIndex].head;

        while (node != nullptr) {
            Edge edge(currentNodeIndex, node->dest, node->weight);

            // do kolejki dodajemy krawedzie prowadzace do nieodwiedzonych wierzcholkow
            if (!IsVisited(visitedNodes, visitedNodesIndex, node->dest)){
                priorityQueue->addEdge(edge);
            }

            // przechodzimy do kolejnej krawedzi w liscie sasiedztwa
            node = node->next;
        }

        // kolejke priorytetyzujemy wzgledem wag
        priorityQueue->sortByWeight();

        // do mst dodajemy krawedz o najnizszej wadze
        auto edgeToAdd = priorityQueue->getFront();
        result[i] = edgeToAdd;

        // dodajemy wierzcholek do odwiedzonych
        visitedNodes[visitedNodesIndex] = edgeToAdd.dest;
        visitedNodesIndex++;

        // aktualizujemy kolejke usuwajac krawedzie prowadzace do dodanego wierzcholka
        priorityQueue->updateQueue(edgeToAdd.dest);
        // przechodzimy na wierzcholek
        currentNodeIndex = edgeToAdd.dest;
    }

    return result;
}

bool Prim::IsVisited(int *arr, int size, int num) {
    for (int i = 0; i < size; i++){
        if(arr[i] == num){
            return true;
        }
    }
    return false;
}

Edge *Prim::primMST(IncidenceMatrix incidenceMatrix) {
    int **matrix = incidenceMatrix.getMatrix();
    int V = incidenceMatrix.getV();
    int E = incidenceMatrix.getE();

    int visitedNodes[V];
    Edge *result = new Edge[V - 1];

    auto priorityQueue = new EdgeQueue();

    // przejście po krawędziach z pierwszego wierzchołka
    int currentNodeIndex = 0;
    int visitedNodesIndex = 0;
    // dodanie poczatkowego wierzcholka
    visitedNodes[visitedNodesIndex] = currentNodeIndex;
    visitedNodesIndex++;

    for (int i = 0; i < V-1; i++) {
        for (int j = 0; j < E; j++) {
            if (matrix[currentNodeIndex][j] != 0) {
                int dest = 0;
                int weight = matrix[currentNodeIndex][j];

                // szukanie wierzcholka docelowego
                for (int k = 0; k < V; k++) {
                    if (matrix[k][j] != 0 && k != currentNodeIndex) {
                        dest = k;
                        break;
                    }
                }

                // jezeli nie znajdzie wierzcholka docelowego to blad w macierzy
                if(dest != 0 && weight == 0){
                    std::cerr << "Error in prim algorithm with incidence matrix." << std::endl;
                    exit(EXIT_FAILURE);
                }

                Edge edge(currentNodeIndex, dest, weight);

                // do kolejki dodajemy krawedzie prowadzace do nieodwiedzonych wierzcholkow
                if (!IsVisited(visitedNodes, visitedNodesIndex, dest)){
                    priorityQueue->addEdge(edge);
                }
            }
        }

        // kolejke priorytetyzujemy wzgledem wag
        priorityQueue->sortByWeight();

        // do mst dodajemy krawedz o najnizszej wadze
        auto edgeToAdd = priorityQueue->getFront();
        result[i] = edgeToAdd;

        // dodajemy wierzcholek do odwiedzonych
        visitedNodes[visitedNodesIndex] = edgeToAdd.dest;
        visitedNodesIndex++;

        // aktualizujemy kolejke usuwajac krawedzie prowadzace do dodanego wierzcholka
        priorityQueue->updateQueue(edgeToAdd.dest);
        // przechodzimy na wierzcholek
        currentNodeIndex = edgeToAdd.dest;
    }

    return result;
}
