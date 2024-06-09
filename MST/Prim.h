
#ifndef AIZO2_PRIM_H
#define AIZO2_PRIM_H


#include "../Helpers/Generator.h"
#include "../AdjacencyList/AdjacencyList.h"
#include "../IncidenceMatrix/IncidenceMatrix.h"

class Prim {
private:
    static bool IsVisited(int *arr,int size, int num);
public:
    static Edge* primMST(AdjacencyList adjacencyList);
    static Edge* primMST(IncidenceMatrix incidenceMatrix);
};


#endif //AIZO2_PRIM_H
