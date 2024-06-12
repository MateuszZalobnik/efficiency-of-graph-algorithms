
#ifndef AIZO2_TIMER_H
#define AIZO2_TIMER_H

#include <iostream>
#include <chrono>

using namespace std;


class Timer {
private:
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<Clock>;

    TimePoint start_time;

public:
    void StartCounter() {
        start_time = Clock::now();
    }

    double GetCounter() {
        auto end_time = Clock::now();
        std::chrono::duration<double, std::milli> elapsed = end_time - start_time;
        return elapsed.count();
    }
};


#endif //AIZO2_TIMER_H
