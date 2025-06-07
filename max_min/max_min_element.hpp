#pragma once

#include <functional>

namespace mystl {

    template <typename Iterator, typename Compare = std::less<>>
    Iterator min_element(Iterator first, Iterator last, Compare comp = Compare{}) {
        if (first == last) return last;
        Iterator smallest = first;
        ++first;
        for (; first != last; ++first) {
            if (comp(*first, *smallest)) {
                smallest = first;
            }
        }
        return smallest;
    }

    template <typename Iterator, typename Compare = std::less<>>
    Iterator max_element(Iterator first, Iterator last, Compare comp = Compare{}) {
        if (first == last) return last;
        Iterator largest = first;
        ++first;
        for (; first != last; ++first) {
            if (comp(*largest, *first)) {
                largest = first;
            }
        }
        return largest;
    }

}