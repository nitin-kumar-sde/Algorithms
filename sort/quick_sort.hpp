#pragma once

#include <iterator>
#include <functional>
#include <utility>

namespace mystl {

template<
    typename CustomIterator,
    typename Compare = std::less<typename std::iterator_traits<CustomIterator>::value_type>
>
class QuickSorter {
public:
    static void sort(CustomIterator begin, CustomIterator end, Compare comp = Compare()) {
        if (begin == end || std::next(begin) == end) return;

        auto pivot = *std::prev(end);
        auto mid = std::partition(begin, std::prev(end),
                                  [&](const auto& elem) { return comp(elem, pivot); });
        std::iter_swap(mid, std::prev(end));

        sort(begin, mid, comp);
        sort(std::next(mid), end, comp);
    }
};

}
