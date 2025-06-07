#pragma once

#include <functional>

namespace mystl {

    template <typename Iterator, typename Predicate>
    bool all_of(Iterator first, Iterator last, Predicate pred) {
        for (; first != last; ++first) {
            if (!pred(*first))
                return false;
        }
        return true;
    }

    template <typename Iterator, typename Predicate>
    bool any_of(Iterator first, Iterator last, Predicate pred) {
        for (; first != last; ++first) {
            if (pred(*first))
                return true;
        }
        return false;
    }

    template <typename Iterator, typename Predicate>
    bool none_of(Iterator first, Iterator last, Predicate pred) {
        for (; first != last; ++first) {
            if (pred(*first))
                return false;
        }
        return true;
    }

    template <typename Iterator, typename Function>
    Function for_each(Iterator first, Iterator last, Function func) {
        for (; first != last; ++first)
            func(*first);
        return func;
    }

}