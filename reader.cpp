//
// Created by samuel on 5/4/22.
//

#include "reader.h"

std::vector<double> parse_ica(std::string filename) {
    std::vector<double> data;
    std::ifstream file(filename);
    std::string current_element;
    while(!file.eof()) {
        std::getline(file, current_element, ' ');
        if(current_element.front() >= '0' && current_element.front() <= '9') {
            data.push_back(std::stod(current_element));
        }
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
        std::getline(file, current_element, ' ');

        size_t newline_pos = current_element.find('\n');
        if(newline_pos != std::string::npos) {
            std::string half_element = current_element.substr(0, newline_pos);
            current_element = current_element.substr(newline_pos + 1, current_element.size() - newline_pos);
            data.push_back(half_element);
        }
        if(!file.eof()) {
            data.push_back(current_element);
        }
    }
    file.close();
    return data;
}