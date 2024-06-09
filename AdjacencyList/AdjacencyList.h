
#ifndef AIZO2_ADJACENCYLIST_H
#define AIZO2_ADJACENCYLIST_H

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include "../Helpers/Generator.h"

using namespace std;

class AdjacencyList {
private:
    int V;
    int E;
    bool directed = false;
    struct AdjList* array;
    void addEdge(int src, int dest, int weight);
    AdjListNode* newAdjListNode(int dest, int weight);
public:
    explicit AdjacencyList(int V, int E, Edge *edges, bool directed) {
        this->directed = directed;
        this->V = V;
        this->E = E;
        this->array = new struct AdjList[V];

        for (int i = 0; i < V; ++i) {
            this->array[i].head = nullptr;
        }

        for (int i = 0; i < E; ++i) {
            int u = edges[i].src;
            int v = edges[i].dest;
            int weight = edges[i].weight;
            addEdge(u, v, weight);
        }
    }

    AdjList* getArray() {
        return this->array;
    }
    int getV() {
        return this->V;
    }
    void printGraph();
    void freeMemory();

};


#endif //AIZO2_ADJACENCYLIST_H
