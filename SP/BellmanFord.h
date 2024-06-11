
#ifndef AIZO2_BELLMANFORD_H
#define AIZO2_BELLMANFORD_H


#include "../AdjacencyList/AdjacencyList.h"
#include "../IncidenceMatrix/IncidenceMatrix.h"
#include "../Helpers/Timer.h"

class BellmanFord {
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
    double time;
    void findPath(AdjacencyList adjacencyList);
    void findPath(IncidenceMatrix incidenceMatrix);
    void printNodeTable();
    void initNodeTable();
public:
    BellmanFord(AdjacencyList adjacencyList, int start, int end) {
        this->E = adjacencyList.getE();
        this->V = adjacencyList.getV();
        this->start = start;
        this->end = end;
        this->path = new int[V];
        this->nodeTable = new Node[V];
        this->visitedNodes = new int[V];

        auto timer = Timer();
        timer.StartCounter();

        findPath(adjacencyList);

        this->time = timer.GetCounter();
    }

    BellmanFord(IncidenceMatrix incidenceMatrix, int start, int end) {
        this->V = incidenceMatrix.getV();
        this->E = incidenceMatrix.getE();
        this->start = start;
        this->end = end;
        this->path = new int[V];
        this->nodeTable = new Node[V];
        this->visitedNodes = new int[V];

        auto timer = Timer();
        timer.StartCounter();

        findPath(incidenceMatrix);

        this->time = timer.GetCounter();
    }

    void printPath() {
        cout << start;
        for (int i = this->pathLength - 1; i >= 0; i--) {
            cout << "-->" << path[i];
        }
    }

    void printTotalCost() {
        cout << cost;
    }

    double GetTime() {
        return this->time;
    }

    void freeMemory();

};


#endif //AIZO2_BELLMANFORD_H
