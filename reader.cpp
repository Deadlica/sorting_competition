//
// Created by samuel on 5/4/22.
//

#include "reader.h"

std::vector<double> parse_ica(std::string filename) {
    std::vector<double> data;
    std::ifstream file(filename);
    double number;
    std::string kr;
    while(!file.eof()) {
        file >> number >> kr;
        if(file.eof()) {
            break;
        }
        data.push_back(number);
    }
    file.close();
    return data;
}

std::vector<long double> parse_jst(std::string filename) {
    std::vector<long double> data;
    std::ifstream file(filename);
    long double current_element;
    while(!file.eof()) {
        file >> current_element;
        if(file.eof()) {
            break;
        }
        data.push_back(current_element);
    }
    file.close();
    return data;
}

std::vector<std::string> parse_new_plates(std::string filename) {
    std::vector<std::string> data;
    std::ifstream file(filename);
    std::string current_element;
    while(!file.eof()) {
        file >> current_element;
        if(file.eof()) {
            break;
        }
        data.push_back(current_element);
    }
    file.close();
    return data;
}