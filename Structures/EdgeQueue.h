
#ifndef AIZO2_EDGEQUEUE_H
#define AIZO2_EDGEQUEUE_H


#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "SimpleStructures.h"

class EdgeQueue {
private:
    Edge* array{};
    int size = 0;
    int capacity = 0;
public:
    EdgeQueue() = default;

    // zwiększ rozmiar
    void resize() {
        if(capacity == 0){
            capacity = 1;
        }else{
            capacity *= 2;
        }
        Edge* newArray = new Edge[capacity];
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }


    // dodawanie krawedzi
    void addEdge(const Edge& val) {
        if (size == capacity) {
            resize();
        }
        array[size++] = val;
    }

    void sortByWeight(){
        std::sort(array, array + size, [](const Edge& a, const Edge& b) {
            return a.weight < b.weight; // Sort in ascending order of weight
        });
    }

    // uzyskaj pierwszy element
    Edge getFront() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot get front element." << std::endl;
            exit(EXIT_FAILURE);
        }
        return array[0];
    }

    // sprawdz czy kolejka jest pusta
    bool isEmpty() {
        return size == 0;
    }

    // zaaktulizuj kolejke - usuń krawędzie prowadzące do wierzchołka v
    void updateQueue(int v) {
        int newSize = 0;
        for (int i = 0; i < size; i++) {
            if (array[i].dest != v) {
                array[newSize++] = array[i];
            }
        }
        size = newSize;
        sortByWeight();
    }

    void printQueue() {
        for (int i = 0; i < size; i++) {
            std::cout << "Edge " << i << ": (" << array[i].src << ", "
                      << array[i].dest << ", " << array[i].weight << ")\n";
        }
    }
};


#endif //AIZO2_EDGEQUEUE_H
