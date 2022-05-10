//
// Created by samuel on 3/29/22.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <algorithm>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <limits>

enum pivot {MEDIAN_OF_THREE, RIGHT_ELEMENT};

template<typename T>
size_t count_float_digits(T number) {
    size_t nr_of_digits = 0;
    size_t nr_of_floats = 0;
    T floats = number - int(number);
    while(std::abs(floats) > 0.0000001) {
        floats *= 10;
        nr_of_floats++;
        floats -= int(floats);
    }
    while(int(number) > 0) {
        number /= 10;
        nr_of_digits++;
    }
    return nr_of_digits + nr_of_floats;
}

template<typename T>
size_t count_float_int_digits(T number) { //Kinda hard coded for the specific data :/
    size_t nr_of_digits = 0;
    while(number > 1) {
        number /= 10;
        nr_of_digits++;
    }
    return nr_of_digits;
}

template<typename T>
struct find_median {
public:
    find_median(T first, T middle, T last): m_first(first), m_middle(middle), m_last(last), finished(false) {}

    operator T() {
        return m_middle;
    }

    bool compare(T e1, T e2, T e3) { //Comparing element 1, 2, 3
        if((*e1 < *e2 && *e2 < *e3) || (*e3 < *e2 && *e2 < *e1)) {
            if(*e1 > *e3) {
                std::iter_swap(e1, e3);
            }
            finished = true;
            return true;
        }
        return false;
    }

    find_median& first() {
        if(!finished) {
            if(compare(m_middle, m_first, m_last)) {
                std::iter_swap(m_first, m_middle);
            }
        }
        return *this;
    }

    find_median& middle() {
        if(!finished) {
            compare(m_first, m_middle, m_last);
        }
        return *this;
    }

    find_median& last() {
        if(!finished) {
            if(compare(m_first, m_last, m_middle)) {
                std::iter_swap(m_middle, m_last);
            }
        }
        return *this;
    }

private:
    T m_first, m_middle, m_last;
    bool finished;
};

template<typename T>
T partition(T first, T last) {
    T pivot = last;
    T it = first - 1; //outside of array
    for (T current = first; current != last; current++) {
        if (*current < *pivot) { //Iterating, checking if elements are less that pivot
            it++;
            std::iter_swap(it, current); //Puts lower than pivot elements at the front of the array
        }
    }
    std::iter_swap(++it, pivot);
    return it;
}

template<typename T>
T find_median_pivot(T first, T middle, T last) {
    find_median<T> comparer(first, middle, last);
    return comparer.first().middle().last();
}

template<typename T>
void insertion_sort(T first, T last) {
    if(first < last) {
        T key, prev;
        for (auto current = first + 1; current != last; current++) {
            key = current;
            prev = current - 1;
            for (; *key < *prev && prev != first - 1; key--, prev--) {
                std::iter_swap(key, prev);
            }
        }
    }
}

template<typename T>
void selection_sort(T first, T last) {
    for(;first !=  last; first++) {
        auto min = std::min_element(first, last);
        std::iter_swap(first, min);
    }
}

template<typename T>
void quick_sort(T first, T last, pivot method) {
    if (first == last || first == last - 1) { return; }
    T pivot;
    switch (method) {
        case RIGHT_ELEMENT:
            pivot = last - 1; //Furthest right element
            break;
        case MEDIAN_OF_THREE:
            T middle = first + (last - first) / 2;
            pivot = find_median_pivot(first, middle, last - 1); //Find the median of first, middle, last and sets it as the pivot
            std::iter_swap(pivot, last - 1);
            break;
    }
    pivot = partition(first, last - 1);

    quick_sort(first, pivot, method); //Partitions the left side of pivot point

    quick_sort(pivot + 1, last, method); //Partitions the right side of the pivot point
}

namespace alg {
    template<typename T>
    void sort(T first, T last) {
        std::sort(first, last);
    }

    template<typename T>
    bool is_sorted(T first, T last) {
        for (; first != last - 1; first++) {
            if (*first > *(first + 1)) {
                std::cout << "Not sorted" << std::endl;
                return false;
            }
        }
        std::cout << "Sorted" << std::endl;
        return true;
    }
}

template<typename it>
void counting_sort_float(it first, it last, unsigned long int nr_pos) {
    unsigned int remove_decimal = std::pow(10, 2);
    size_t size = last - first, bucket_size = 10;
    double* output = new double[size];
    int bucket[10] = {0};
    it current = first;

    for(;current != last; current++) {
        bucket[int(((*current) * remove_decimal) / nr_pos) % 10]++;
    }

    for(int index = 1; index < bucket_size; index++) {
        bucket[index] += bucket[index - 1];
    }
    for(current = last - 1; current >= first; current--) {
        output[bucket[int(((*current) * remove_decimal) / nr_pos) % 10] - 1] = *current;
        bucket[int(((*current) * remove_decimal) / nr_pos) % 10]--;
    }
    std::copy(output, output + size, first);
}

template<typename it>
void radix_float(it first, it last) {
    it max = std::max_element(first, last);
    size_t iterations = count_float_digits(*max);
    for(unsigned long nr_pos = 1, i = 0; i < iterations; i++, nr_pos *= 10) {
        counting_sort_float(first, last, nr_pos);
    }
}

template<typename it>
void counting_sort_string(it first, it last, int index) {
    size_t size = last - first;
    std::vector<std::string> output(size);
    int bucket[255] = {0};
    it current = first;

    for(;current != last; current++) {
        bucket[(*current)[index]]++;
    }

    for(int i = 0; i < 254; i++) {
        bucket[i + 1] += bucket[i];
    }

    for(current = last - 1; current >= first; current--) {
        output[bucket[(*current)[index]] - 1] = *current;
        bucket[(*current)[index]]--;
    }
    std::copy(output.begin(), output.end(), first);
}

template<typename it>
void radix_string(it first, it last) {
    it max = std::max_element(first, last);
    size_t iterations = (*max).size();
    for(int i = iterations - 1; i >= 0; i--) {
        counting_sort_string(first, last, i);
    }
}

template<typename it>
void heap_sort(it first, it last) {
    std::make_heap(first, last);
    std::sort_heap(first, last);
}

template<typename it, typename container = std::vector<typename it::value_type>>
container merge_sort(it first, it last) {
   if(first == last || first == last - 1) {
       return container(first, last);
   }
   ptrdiff_t half = (last - first) / 2;
   it middle = first + half;

   auto left = merge_sort(first, middle);
   auto right = merge_sort(middle, last);

   container merged(left.size() + right.size());
   std::merge(left.begin(), left.end(), right.begin(), right.end(), merged.begin());
   return merged;
}

template<typename it>
void bogo_sort(it first, it last) {
    while(!std::is_sorted(first, last)) {
        std::random_shuffle(first, last);
    }
}

template<typename it>
void intro_sort_helper(it first, it last, int depth_limit) {
   size_t size = last - first;
   if(size < 16) {
       insertion_sort(first, last);
       return;
   }
   if(depth_limit == 0) {
       heap_sort(first, last);
       return;
   }
   it pivot = find_median_pivot(first, first + size / 2, last - 1);
   std::iter_swap(pivot, last - 1);
   pivot = partition(first, last - 1);
   intro_sort_helper(first, pivot, depth_limit - 1);
   intro_sort_helper(pivot + 1, last, depth_limit - 1);
}

template<typename it>
void intro_sort(it first, it last) {
    intro_sort_helper(first, last, 2 * std::log2(last - first));
}

template<typename it>
void tim_sort(it first, it last) {
    const int subarray_size = 32;
    const int size = last - first;

    for(int i = 0; i < size; i += subarray_size) {
        insertion_sort(first + i, first + std::min((i + subarray_size - 1), (size - 1)));
    }

    for(int i = subarray_size; i < size; i = 2 * i) {
        for(int left = 0; left < size; left += 2 * i) {
            int mid = left + i - 1;
            int right = std::min(left + 2 * i - 1, size - 1);

            if(mid < right) {
                std::inplace_merge(first + left, first + mid, first + right);
            }
        }
    }
}

#endif
