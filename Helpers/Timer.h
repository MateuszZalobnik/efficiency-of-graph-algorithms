
#ifndef AIZO2_TIMER_H
#define AIZO2_TIMER_H
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <iostream>

using namespace std;


class Timer {
private:
    double PCFreq = 0.0;
    __int64 CounterStart = 0;
public:
    // metoda inicjalizuje licznik
    void StartCounter();
    // metoda zwraca czas od inicjalizacji licznika (milisekundy)
    double GetCounter();
};


#endif //AIZO2_TIMER_H
