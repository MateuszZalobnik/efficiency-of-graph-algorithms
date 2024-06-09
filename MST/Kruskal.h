
#ifndef AIZO2_KRUSKAL_H
#define AIZO2_KRUSKAL_H


#include "../Helpers/Generator.h"
#include "iostream"

class Kruskal {
public:
    static Edge* kruskalMST(Edge *edges, int V, int E);
private:
    static void heapSortEdgesDesc(Edge *edges, int E);
    static void heapifyDesc(int N, int i, Edge *edges);
};


#endif //AIZO2_KRUSKAL_H
