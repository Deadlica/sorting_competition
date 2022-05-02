#include <iostream>
#include "algorithms.h"
#include <vector>

int main() {
	std::vector<int> arr = {4, 9, 5, 8, 34, 23, 3, 69, 7};
	auto c = merge_sort(arr.begin(), arr.end());
    for(auto e: c) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;

    radix_sort(arr.begin(), arr.end());

    std::cout << std::endl;
    for(auto e: arr) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;

}
