#pragma once

#include <functional>

namespace mystl {

    template <typename Iterator, typename T>
    size_t count(Iterator first, Iterator last, const T& value) {
        size_t cnt = 0;
        for (; first != last; ++first) {
            if (*first == value)
                ++cnt;
        }
        return cnt;
    }

    template <typename Iterator, typename Predicate>
    size_t count_if(Iterator first, Iterator last, Predicate pred) {
        size_t cnt = 0;
        for (; first != last; ++first) {
            if (pred(*first))
                ++cnt;
        }
        return cnt;
    }
    
}