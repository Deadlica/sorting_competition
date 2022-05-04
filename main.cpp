#include <iostream>
#include "algorithms.h"
#include <vector>
#include "timer.h"
#include <numeric>
#include "reader.h"

int main() {
    Timer timer;
    std::vector<double> time_measurements;
    std::string file1 = "data/ICA.txt", file2 = "data/JST.txt", file3 = "data/new_plates.txt";

    auto a = parse_ica(file1);
    //auto b = parse_jst(file2);
    //auto c = parse_new_plates(file3);

    for(int i = 0; i < 5; i++) { //ICA.txt sorting
        auto temp = a;
        timer.start();
        radix_sort(temp.begin(), temp.end());
        timer.stop();
        time_measurements.push_back(timer.time());
        std::cout << std::is_sorted(temp.begin(), temp.end()) << std::endl;
    }
    double average_time = std::accumulate(time_measurements.begin(), time_measurements.end(), 0.0) / time_measurements.size();
    std::cout << average_time << std::endl;

}