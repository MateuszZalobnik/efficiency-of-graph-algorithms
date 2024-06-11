
#ifndef AIZO2_PRIM_H
#define AIZO2_PRIM_H


#include "../Helpers/Generator.h"
#include "../AdjacencyList/AdjacencyList.h"
#include "../IncidenceMatrix/IncidenceMatrix.h"

class Prim {
private:
    Edge* result;
    bool IsVisited(int *arr,int size, int num);
    void findPath(AdjacencyList adjacencyList);
    void findPath(IncidenceMatrix incidenceMatrix);
    int V;
    double time;
public:
    Prim(AdjacencyList adjacencyList, int V){
        this->V = V;
        findPath(adjacencyList);
    }

    Prim(IncidenceMatrix incidenceMatrix, int V){
        this->V = V;
        findPath(incidenceMatrix);
    }

    void printResult();
    void freeMemory();
    double GetTime(){
        return time;
    }
};


#endif //AIZO2_PRIM_H
