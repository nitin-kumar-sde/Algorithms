#pragma once

#include <functional>

namespace mystl {
    
    template <typename BidirectionalIterator>
    void reverse(BidirectionalIterator first, BidirectionalIterator last) {
        if (first == last) return;
        --last;

        while (first < last) {
            std::iter_swap(first, last);
            ++first;
            --last;
        }
    }

}