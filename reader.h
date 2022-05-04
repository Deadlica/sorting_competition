//
// Created by samuel on 5/4/22.
//

#ifndef READER_H
#define READER_H

#include <vector>
#include <string>
#include <fstream>

std::vector<double> parse_ica(std::string filename);
std::vector<long double> parse_jst(std::string filename);
std::vector<std::string> parse_new_plates(std::string filename);

#endif