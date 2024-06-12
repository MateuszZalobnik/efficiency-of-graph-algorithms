#include <iostream>

#include "Helpers/Generator.h"
#include "AdjacencyList/AdjacencyList.h"
#include "IncidenceMatrix/IncidenceMatrix.h"
#include "MST/Kruskal.h"
#include "MST/Prim.h"
#include "Test/Test.h"
#include "Simulation/Simulation.h"
#include "SP/BellmanFord.h"
#include "SP/Dijkstry.h"
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    srand(time(NULL));

    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Symulacja" << endl;
        cout << "2. Test" << endl;
        cout << "3. Exit" << endl;
        cout << "Wybierz: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;

        if (cin.fail()) {
            cout << "Wprowadź numer." << endl;
            continue;
        }
        if (choice == 1) {
            Simulation simulator;
            simulator.simulate();
        } else if (choice == 2) {
             Test test;
             test.menu();
        } else if (choice == 3) {
            cout << "Exiting..." << endl;
        } else {
            cout << "Zły wybór." << endl;
        }

    } while (choice != 3);


    return 0;
}
