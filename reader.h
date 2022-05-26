//
// Created by samuel on 5/4/22.
//

#ifndef READER_H
#define READER_H

#include <vector>
#include <string>
#include <fstream>

template<typename T>
std::vector<T> parse_ica(std::string filename) {
    std::ifstream file(filename);
    std::string kr;
    std::vector<T> data;
    if(std::is_same<T, double>::value) {
        double number;
        while(!file.eof()) {
            file >> number >> kr;
            if(file.eof())
                break;
            data.push_back(number);
        }
    }
    else if(std::is_same<T, int>::value) {
        int number;
        char dot;
        int decimals;
        while(!file.eof()) {
            file >> number >> dot >> decimals >> kr;
            if(file.eof())
                break;
            data.push_back(number * 100 + decimals);
        }
    }
        file.close();
        return data;
}
std::vector<double> parse_jst(std::string filename);
std::vector<std::string> parse_new_plates(std::string filename);

#endif