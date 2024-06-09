
#include "IncidenceMatrix.h"

void IncidenceMatrix::printMatrix() {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < E; ++j) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void IncidenceMatrix::freeMemory() {
    for (int i = 0; i < V; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
