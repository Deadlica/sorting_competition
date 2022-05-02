//
// Created by samuel on 3/31/22.
//

#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    Timer() = default;

    void start();
    void stop();
    const double time();

private:
    std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<long, std::ratio<1, 1000000000>>> m_start, m_stop;
    std::chrono::duration<double> m_time;
};


#endif