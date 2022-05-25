//
// Created by samuel on 3/29/22.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <algorithm>
#include <string>
#include <thread>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <limits>

namespace alg {

    enum pivot {
        MEDIAN_OF_THREE, RIGHT_ELEMENT
    };

    template<typename T>
    size_t count_digits(T element) { //Integers
        size_t digits = 0;
        while (element > 1) {
            element /= 10;
            digits++;
        }
        return digits;
    }

    template<>
    size_t count_digits<double>(double element) { //Doubles
        size_t digits = 0;
        size_t float_digits = 0;
        double floats = element - int(element);
        while (std::abs(floats) > 0.0000001) {
            floats *= 10;
            float_digits++;
            floats -= int(floats);
        }
        while (int(element) > 0) {
            element /= 10;
            digits++;
        }
        return digits + float_digits;
    }

    template<typename T>
    struct find_median {
    public:
        find_median(T first, T middle, T last) : m_first(first), m_middle(middle), m_last(last), finished(false) {}

        operator T() {
            return m_middle;
        }

        bool compare(T e1, T e2, T e3) { //Comparing element 1, 2, 3
            if ((*e1 < *e2 && *e2 < *e3) || (*e3 < *e2 && *e2 < *e1)) {
                if (*e1 > *e3) {
                    std::iter_swap(e1, e3);
                }
                finished = true;
                return true;
            }
            return false;
        }

        find_median &first() {
            if (!finished) {
                if (compare(m_middle, m_first, m_last)) {
                    std::iter_swap(m_first, m_middle);
                }
            }
            return *this;
        }

        find_median &middle() {
            if (!finished) {
                compare(m_first, m_middle, m_last);
            }
            return *this;
        }

        find_median &last() {
            if (!finished) {
                if (compare(m_first, m_last, m_middle)) {
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
        if (first < last) {
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

    template<typename it>
    void shell_sort(it first, it last, int gap = 2) {
        int shell = (last - first) / gap;
        for (int shell = (last - first) / gap; shell > 0; shell /= gap) {
            for (it pos = first; pos + shell < last; pos++) {
                if (*pos < *(pos + shell)) {
                    std::iter_swap(pos, pos + shell);
                }
            }
        }
        insertion_sort(first, last);
    }

    template<typename T>
    void selection_sort(T first, T last) {
        for (; first != last; first++) {
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
                pivot = find_median_pivot(first, middle,
                                          last - 1); //Find the median of first, middle, last and sets it as the pivot
                std::iter_swap(pivot, last - 1);
                break;
        }
        pivot = partition(first, last - 1);

        quick_sort(first, pivot, method); //Partitions the left side of pivot point

        quick_sort(pivot + 1, last, method); //Partitions the right side of the pivot point
    }

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

    template<typename it>
    void counting_sort(it first, it last, int index) {
        unsigned int remove_decimal = std::pow(10, 2);
        size_t size = last - first, bucket_size = 10;
        typename it::value_type* output = new typename it::value_type[size];
        int bucket[10] = {0};
        it current = first;

        for (; current != last; current++) {
            bucket[int(((*current) * remove_decimal) / index) % 10]++;
        }

        for (int index = 1; index < bucket_size; index++) {
            bucket[index] += bucket[index - 1];
        }
        for (current = last - 1; current >= first; current--) {
            output[bucket[int(((*current) * remove_decimal) / index) % 10] - 1] = *current;
            bucket[int(((*current) * remove_decimal) / index) % 10]--;
        }
        std::copy(output, output + size, first);
        delete[] output;
    }

    template<>
    void counting_sort<std::vector<std::string>::iterator>(std::vector<std::string>::iterator first,
                                                           std::vector<std::string>::iterator last, int index) {
        size_t size = last - first;
        std::string *output = new std::string[size];
        int bucket[255] = {0};
        auto current = first;

        for (; current != last; current++) {
            bucket[(*current)[index]]++;
        }

        for (int i = 0; i < 254; i++) {
            bucket[i + 1] += bucket[i];
        }

        for (current = last - 1; current >= first; current--) {
            output[bucket[(*current)[index]] - 1] = *current;
            bucket[(*current)[index]]--;
        }
        std::copy(output, output + size, first);
        delete[] output;
    }

    template<typename it>
    void radix_sort(it first, it last) {
        it max = std::max_element(first, last);
        //size_t iterations = count_digits(*max);
        for (unsigned long nr_pos = 1, i = 0; i < 7; i++, nr_pos *= 10) { //The 7 is hardcoded for a specific file
            counting_sort(first, last, nr_pos);
        }
    }

    template<>
    void radix_sort<std::vector<std::string>::iterator>(std::vector<std::string>::iterator first,
                                                        std::vector<std::string>::iterator last) {
        auto max = std::max_element(first, last);
        size_t iterations = (*max).size();
        for (int i = iterations - 1; i >= 0; i--) {
            counting_sort(first, last, i);
        }
    }

    template<typename it>
    void bucket_sort(it first, it last) {
        size_t size = last - first;
        auto max = std::max_element(first, last);
        auto min = std::min_element(first, last);
        auto range = (*max - *min) / size;
        //std::vector<typename it::value_type>* bucket = new std::vector<typename it::value_type>[size];
        std::vector<std::vector<typename it::value_type>> bucket(size, std::vector<typename it::value_type>(0));

        for (auto i = first; i != last; i++) {
            bucket[(*i - *min) / range].push_back(*i);
        }

        for (auto &b: bucket) {
            std::sort(b.begin(), b.end());
            std::cout << std::is_sorted(b.begin(), b.end());
        }

        auto current = first;
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < bucket[i].size(); j++) {
                *current = bucket[i][j];
                current++;
            }
        }
    }

    template<typename it>
    void heap_sort(it first, it last) {
        std::make_heap(first, last);
        std::sort_heap(first, last);
    }

    template<typename it, typename container = std::vector<typename it::value_type>>
    container merge(it first1, it last1, it first2, it last2) {
        container output;
        while (first1 != last1 && first2 != last2) {
            if (*first1 < *first2) {
                output.push_back(*first1);
                first1++;
            } else {
                output.push_back(*first2);
                first2++;
            }
        }
        while (first1 != last1) {
            output.push_back(*first1);
            first1++;
        }
        while (first2 != last2) {
            output.push_back(*first2);
            first2++;
        }
        return output;
    }

    template<typename it, typename container = std::vector<typename it::value_type>>
    container merge_sort(it first, it last) {
        if (first == last || first == last - 1) {
            return container(first, last);
        }
        ptrdiff_t half = (last - first) / 2;
        it middle = first + half;

        auto left = merge_sort(first, middle);
        auto right = merge_sort(middle, last);
        return merge(left.begin(), left.end(), right.begin(), right.end());
    }

    template<typename it>
    void bogo_sort(it first, it last) {
        while (!std::is_sorted(first, last)) {
            std::random_shuffle(first, last);
        }
    }

    template<typename it>
    void __intro_sort_helper(it first, it last, int depth_limit) {
        size_t size = last - first;
        if (size < 16) {
            insertion_sort(first, last);
            return;
        }
        if (depth_limit == 0) {
            heap_sort(first, last);
            return;
        }
        it pivot = find_median_pivot(first, first + size / 2, last - 1);
        std::iter_swap(pivot, last - 1);
        pivot = partition(first, last - 1);
        __intro_sort_helper(first, pivot, depth_limit - 1);
        __intro_sort_helper(pivot + 1, last, depth_limit - 1);
    }

    template<typename it>
    void intro_sort(it first, it last) {
        __intro_sort_helper(first, last, 2 * std::log2(last - first));
    }

    template<typename it>
    void tim_sort(it first, it last) {
        const int subarray_size = 32;
        const int size = last - first;

        for (int i = 0; i < size; i += subarray_size) {
            insertion_sort(first + i, first + std::min((i + subarray_size), size));
        }

        for (int i = subarray_size; i < size; i = 2 * i) {
            for (int left = 0; left < size; left += 2 * i) {
                int mid = left + i - 1;
                int right = std::min(left + 2 * i, size);

                if (mid < right) {
                    std::inplace_merge(first + left, first + mid + 1, first + right);
                }
            }
        }
    }



    template<typename function, typename it>
    void thread_sort(function func, it first, it last, int nr_of_threads) {
        std::vector<std::thread> threads;
        int size = last - first;
        int range = size / nr_of_threads;
        it left = first;
        it right = left + range;
        for(int i = 0; i < nr_of_threads; i++, left = right, right += range) {
            threads.push_back(std::thread(func, left, std::min(right, last)));
        }

        for(auto &thread: threads) {
            thread.join();
        }

        int i = nr_of_threads;
        left = first, right = left + 2 * range;
        for(it middle = left + range; nr_of_threads >= 2; nr_of_threads /= 2, left = right, middle = left + range, right = left + 2* range) {
            //Sub merges
            threads.push_back(std::thread(std::inplace_merge<decltype(left)>, left, middle, right));
        }

        for(; i < threads.size(); i++) {
            threads[i].join();
        }

        std::inplace_merge(first, first + size / 2, last);

    }

};

#endif
