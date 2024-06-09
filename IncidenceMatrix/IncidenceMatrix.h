
#ifndef AIZO2_INCIDENCEMATRIX_H
#define AIZO2_INCIDENCEMATRIX_H

#include <iostream>
#include <iomanip>
#include "../Helpers/Generator.h"

using namespace std;

class IncidenceMatrix {
private:
int **matrix;
    int V;
    int E;
public:
    IncidenceMatrix(int V, int E, Edge *edges){
        this->V = V;
        this->E = E;
        matrix = new int *[V];
        for (int i = 0; i < V; ++i) {
            matrix[i] = new int[E];
            for (int j = 0; j < E; ++j) {
                matrix[i][j] = 0; // Inicjalizacja zerami
            }
        }

        for (int i = 0; i < E; ++i) {
            matrix[edges[i].src][i] = edges[i].weight;
            matrix[edges[i].dest][i] = edges[i].weight;
        }
    }

    int getV() {
        return this->V;
    }

    int getE() {
        return this->E;
    }

    int **getMatrix() {
        return this->matrix;
    }
    void printMatrix();
    void freeMemory();
};


#endif //AIZO2_INCIDENCEMATRIX_H
