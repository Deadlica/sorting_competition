//
// Created by samuel on 3/31/22.
//

#include "timer.h"

void Timer::start() {
    m_start = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
    m_stop = std::chrono::high_resolution_clock::now();
}

const double Timer::time() {
    m_time = std::chrono::duration<double>(m_stop - m_start);
    return m_time.count();
}