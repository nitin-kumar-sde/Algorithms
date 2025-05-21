#pragma once

#include <iterator>
#include <functional>
#include <utility>
#include <stdexcept>

#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"

namespace mystl {

enum class Algorithm {
    Insertion,
    Merge,
    Quick
};

template<
    typename CustomIterator,
    typename Compare = std::less<typename std::iterator_traits<CustomIterator>::value_type>
>
class Sorter {

static void sort(CustomIterator begin, CustomIterator end, Algorithm algo, Compare comp = Compare()) {
    switch (algo) {
        case Algorithm::Insertion:
            InsertionSorter<CustomIterator, Compare>::sort(begin, end, comp);
            break;
        case Algorithm::Merge:
            MergeSorter<CustomIterator, Compare>::sort(begin, end, comp);
            break;
        case Algorithm::Quick:
            QuickSorter<CustomIterator, Compare>::sort(begin, end, comp);
            break;
        default:
            throw std::invalid_argument("Unknown sorting algorithm");
    }
}

static void sort(CustomIterator begin, CustomIterator end, Compare comp = Compare()) {
    
    auto size = std::distance(begin, end);
    Algorithm selected;
    if (size < 16) {
        selected = Algorithm::Insertion;
    } else if (size < 1000) {
        selected = Algorithm::Quick;
    } else {
        selected = Algorithm::Merge;
    }

}

};

}
