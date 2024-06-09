
#ifndef AIZO2_DIJKSTRY_H
#define AIZO2_DIJKSTRY_H


#include "../AdjacencyList/AdjacencyList.h"
#include "../IncidenceMatrix/IncidenceMatrix.h"

struct Node {
    int current;
    int cost;
    int previous;
};

class Dijkstry {
private:
    int V;
    int E;
    int pathLength = 0;
    int *path;
    int *visitedNodes;
    int cost;
    Node *nodeTable;
    int start;
    int end;
    void findPath(AdjacencyList adjacencyList);
    void findPath(IncidenceMatrix incidenceMatrix);
    void freeMemory();
    void printNodeTable();
    int getLowestNode();
    void visitNode(int node);
    bool isNodeVisited(int node);
    void initNodeTable();
public:
    Dijkstry(AdjacencyList adjacencyList, int start, int end) {
        this->V = adjacencyList.getV();
        this->start = start;
        this->end = end;
        this->path = new int[V];
        this->nodeTable = new Node[V];
        this->visitedNodes = new int[V];

        findPath(adjacencyList);
    }

    Dijkstry(IncidenceMatrix incidenceMatrix, int start, int end) {
        this->V = incidenceMatrix.getV();
        this->E = incidenceMatrix.getE();
        this->start = start;
        this->end = end;
        this->path = new int[V];
        this->nodeTable = new Node[V];
        this->visitedNodes = new int[V];

        findPath(incidenceMatrix);
    }

    void printTotalCost() {
        cout << cost;
    }

    void printPath() {
        cout << start;
        for (int i = this->pathLength - 1; i >= 0; i--) {
            cout << "-->" << path[i];
        }
    }

};


#endif //AIZO2_DIJKSTRY_H
