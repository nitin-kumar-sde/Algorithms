#pragma once

#include <functional>

namespace mystl {

    template <typename Iterator, typename T>
    Iterator find(Iterator first, Iterator last, const T& value) {
        for (; first != last; ++first) {
            if (*first == value)
                return first;
        }
        return last;
    }

    template <typename Iterator, typename Predicate>
    Iterator find_if(Iterator first, Iterator last, Predicate pred) {
        for (; first != last; ++first) {
            if (pred(*first))
                return first;
        }
        return last;
    }

}