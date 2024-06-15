
#ifndef AIZO2_GENERATOR_H
#define AIZO2_GENERATOR_H

#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "../Structures/SimpleStructures.h"

class Generator {
public:
    // generowanie krawędzie
    static Edge* generateEdges(int V, int E, bool directed);
    static int numberOfEdgesByDensityAndNodes(int V, float density);
private:
    static void generateSpanningTree(int V, Edge* edges, int* currentNumberOfEdges);
};


#endif //AIZO2_GENERATOR_H
