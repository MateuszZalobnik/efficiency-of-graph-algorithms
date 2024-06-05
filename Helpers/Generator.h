
#ifndef AIZO2_GENERATOR_H
#define AIZO2_GENERATOR_H

#include <cstdlib>
#include <ctime>
#include <stdexcept>

class Generator {
public:
    // generowanie krawędzie
    static int** generateEdges(int V, int E);
    static int** createIncidenceMatrix(int V, int E, int** edges);
    static int** createIncidenceMatrix(int V, int E, int** edges);
private:
    static int** initEdgesTable(int E);
    static void generateSpanningTree(int V, int** edges);
};


#endif //AIZO2_GENERATOR_H
