
#include <iomanip>
#include "Dijkstry.h"

void Dijkstry::findPath(AdjacencyList adjacencyList) {
    initNodeTable();
    int current = start;
    this->visitNode(current);
    AdjList* nodes = adjacencyList.getArray();

    while (current != end) {
        AdjListNode *node = nodes[current].head;
        while (node != nullptr) {
            int newCost = nodeTable[current].cost + node->weight;
            if (newCost < nodeTable[node->dest].cost) {
                nodeTable[node->dest].cost = newCost;
                nodeTable[node->dest].previous = current;
            }
            node = node->next;
        }

        current = getLowestNode();
        this->visitNode(current);
    }

    printNodeTable();
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


void Dijkstry::findPath(IncidenceMatrix incidenceMatrix) {
    initNodeTable();
    int current = start;
    this->visitNode(current);
    int **matrix = incidenceMatrix.getMatrix();

    while (current != end) {
        for (int i = 0; i < this->E; i++) {
            if (matrix[current][i] > 0) {
                int newCost = nodeTable[current].cost + matrix[current][i];
                int dest = -1;
                for (int j = 0; j < V; j++) {
                    if (matrix[j][i] < 0) {
                        dest = j;
                        break;
                    }
                }
                if (newCost < nodeTable[dest].cost) {
                    nodeTable[dest].cost = newCost;
                    nodeTable[dest].previous = current;
                }
            }
        }

        current = getLowestNode();
        this->visitNode(current);
    }

    printNodeTable();
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

void Dijkstry::initNodeTable() {
    for (int i = 0; i < V; ++i) {
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

void Dijkstry::freeMemory() {
    delete[] path;
    delete[] visitedNodes;
    delete[] nodeTable;
}

void Dijkstry::printNodeTable() {
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

int Dijkstry::getLowestNode() {
    int min = INT_MAX;
    int index = -1;
    for (int i = 0; i < V; ++i) {
        if (nodeTable[i].cost < min && i != start && !isNodeVisited(i)) {
            min = nodeTable[i].cost;
            index = i;
        }
    }
    return index;
}

void Dijkstry::visitNode(int node) {
    visitedNodes[node] = 1;
}

bool Dijkstry::isNodeVisited(int node) {
    return visitedNodes[node] == 1;
}

