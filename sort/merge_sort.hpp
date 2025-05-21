#pragma once

#include <iterator>
#include <functional>
#include <vector>
#include <utility>

namespace mystl {

template<
    typename CustomIterator,
    typename Compare = std::less<typename std::iterator_traits<CustomIterator>::value_type>
>
class MergeSorter {
public:
    static void sort(CustomIterator begin, CustomIterator end, Compare comp = Compare()) {
        auto dist = std::distance(begin, end);
        if (dist <= 1) return;

        CustomIterator mid = std::next(begin, dist / 2);

        // Recursively sort
        sort(begin, mid, comp);
        sort(mid, end, comp);

        // Merge step
        std::vector<typename std::iterator_traits<CustomIterator>::value_type> temp;
        auto it1 = begin;
        auto it2 = mid;

        while (it1 != mid && it2 != end) {
            if (comp(*it2, *it1)) {
                temp.push_back(std::move(*it2));
                ++it2;
            } else {
                temp.push_back(std::move(*it1));
                ++it1;
            }
        }

        while (it1 != mid) {
            temp.push_back(std::move(*it1));
            ++it1;
        }
        while (it2 != end) {
            temp.push_back(std::move(*it2));
            ++it2;
        }
        // Move back into original range
        std::move(temp.begin(), temp.end(), begin);
    }
};

}
