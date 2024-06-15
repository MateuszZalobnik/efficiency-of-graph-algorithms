
#include "BellmanFord.h"

void BellmanFord::initNodeTable() {
    for (int i = 0; i < V; i++) {
        if (i == start) {
            nodeTable[i].cost = 0;
            nodeTable[i].previous = i;
        } else{
            nodeTable[i].cost = INT_MAX;
            nodeTable[i].previous = -1;
        }
        nodeTable[i].current = i;
    }
}

void BellmanFord::freeMemory() {
    delete[] path;
    delete[] visitedNodes;
    delete[] nodeTable;
}


void BellmanFord::printNodeTable() {
    cout << endl;
    for (int i = 0; i < V; ++i) {
        cout << setw(3) << i << "|";
    }
    cout << endl;
    for (int i = 0; i < V; ++i) {
        if (nodeTable[i].cost == INT_MAX) {
            cout << setw(3) << "inf" << "|";
        } else {
            cout << setw(3) << nodeTable[i].cost << "|";
        }
    }
    cout << endl;
    for (int i = 0; i < V; ++i) {
        cout << setw(3) << nodeTable[i].previous << "|";
    }
    cout << endl;
    cout << "-----------------------------------" << endl;
}

void BellmanFord::findPath(AdjacencyList adjacencyList) {
    initNodeTable();
    AdjList* nodes = adjacencyList.getArray();
    int k = 0, current = 0;
    AdjListNode *node = nodes[current].head;

    for (int i = 0; i < V - 1; i++) {
        while (k < E) {
            int cost = node->weight;
            if (nodeTable[current].cost + cost < nodeTable[node->dest].cost && nodeTable[current].cost != INT_MAX) {
                // wykonujemy relaksacje
                nodeTable[node->dest].cost = nodeTable[current].cost + cost;
                nodeTable[node->dest].previous = current;
            }

            if (node->next != nullptr) {
                node = node->next;
            } else {
                current++;
                node = nodes[current].head;
            }
            k++;
        }

        k = 0;
        current = 0;
        node = nodes[current].head;
    }

    // generowanie sciezki
    int i = 0;
    path[i] = end;
    while (path[i] != start) {
        path[i + 1] = nodeTable[path[i]].previous;
        i++;
    }
    pathLength = i;

    // koszt calkowity
    cost = nodeTable[end].cost;
}

void BellmanFord::findPath(IncidenceMatrix incidenceMatrix) {
    initNodeTable();
    int k = 0, current = start, dest = 0;
    int **matrix = incidenceMatrix.getMatrix();


    for (int i = 0; i < V - 1; i++) {
        k = 0;
        while (k < E) {
            for (int j = 0; j < V; j++){
                if(matrix[j][k] < 0){
                    dest = j;
                }
                if (matrix[j][k] > 0) {
                    current = j;
                }
            }
            int cost = matrix[current][k];

            // sprawdzamy czy relaksacja jest mozliwa
            if (nodeTable[current].cost + cost < nodeTable[dest].cost && nodeTable[current].cost != INT_MAX) {
                // wykonujemy relaksacje
                nodeTable[dest].cost = nodeTable[current].cost + cost;
                nodeTable[dest].previous = current;
            }
            k++;
        }
    }

    // generowanie sciezki
    int i = 0;
    path[i] = end;
    while (path[i] != start) {
        path[i + 1] = nodeTable[path[i]].previous;
        i++;
    }
    pathLength = i;

    // koszt calkowity
    cost = nodeTable[end].cost;

}
