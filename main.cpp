#include <algorithm>
#include <iostream>
#include "algorithms.h"
#include <vector>
#include "timer.h"
#include <numeric>
#include "reader.h"
//#include "../ips4o/ips4o.hpp"

void sort_ica();
void sort_jst();
void sort_new_plates();

int main() {
    sort_ica();
    sort_jst();
    sort_new_plates();
}

void sort_ica() {
    auto content = parse_ica("data/ICA.txt");
    Timer timer;
    std::vector<double> time_measurements;
    std::cout << "ICA.txt" << std::endl;
    for(int i = 0; i < 5; i++) { //ICA.txt sorting
        auto temp = content;
        timer.start();
        radix_sort(temp.begin(), temp.end());
        timer.stop();
        time_measurements.push_back(timer.time());
        std::is_sorted(temp.begin(), temp.end())? std::cout << "Sorted" << std::endl : std::cout << "Not sorted" << std::endl;
    }
    double average_time = std::accumulate(time_measurements.begin(), time_measurements.end(), 0.0) / time_measurements.size();
    std::cout << "Average time: " << average_time << "s" << std::endl;

    time_measurements.clear();

    for(int i = 0; i < 5; i++) {
        auto temp = content;
        timer.start();
        std::sort(temp.begin(), temp.end());
        timer.stop();
        time_measurements.push_back(timer.time());
    }
    average_time = std::accumulate(time_measurements.begin(), time_measurements.end(), 0.0) / time_measurements.size();
    std::cout << "Average time for std::sort: " << average_time << "s" << std::endl << std::endl;

}

void sort_jst() {
    auto content = parse_jst("data/JST.txt");
    Timer timer;
    std::vector<double> time_measurements;
    std::cout << "JST.txt" << std::endl;
    for(int i = 0; i < 5; i++) { //JST.txt sorting
        auto temp = content;
        timer.start();
	    intro_sort(temp.begin(), temp.end());
        timer.stop();
        time_measurements.push_back(timer.time());
        std::is_sorted(temp.begin(), temp.end())? std::cout << "Sorted" << std::endl : std::cout << "Not sorted" << std::endl;
    }
    double average_time = std::accumulate(time_measurements.begin(), time_measurements.end(), 0.0) / time_measurements.size();
    std::cout << "Average time: " << average_time << "s" << std::endl;

    time_measurements.clear();

    for(int i = 0; i < 5; i++) {
        auto temp = content;
        timer.start();
        std::sort(temp.begin(), temp.end());
        timer.stop();
        time_measurements.push_back(timer.time());
    }
    average_time = std::accumulate(time_measurements.begin(), time_measurements.end(), 0.0) / time_measurements.size();
    std::cout << "Average time for std::sort: " << average_time << "s" << std::endl << std::endl;
}

void sort_new_plates() {
    auto content = parse_new_plates("data/new_plates.txt");
    Timer timer;
    std::vector<double> time_measurements;
    std::cout << "new_plates.txt" << std::endl;
    for(int i = 0; i < 5; i++) { //new_plates.txt sorting
        auto temp = content;
        timer.start();
        radix_sort(temp.begin(), temp.end());
        timer.stop();
        time_measurements.push_back(timer.time());
        std::is_sorted(temp.begin(), temp.end())? std::cout << "Sorted" << std::endl : std::cout << "Not sorted" << std::endl;
    }
    double average_time = std::accumulate(time_measurements.begin(), time_measurements.end(), 0.0) / time_measurements.size();
    std::cout << "Average time: " << average_time << "s" << std::endl;

    time_measurements.clear();

    for(int i = 0; i < 5; i++) {
        auto temp = content;
        timer.start();
        std::sort(temp.begin(), temp.end());
        timer.stop();
        time_measurements.push_back(timer.time());
    }
    average_time = std::accumulate(time_measurements.begin(), time_measurements.end(), 0.0) / time_measurements.size();
    std::cout << "Average time for std::sort: " << average_time << "s" << std::endl << std::endl;
}
