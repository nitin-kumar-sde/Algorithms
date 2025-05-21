#pragma once

#include <iterator> 
#include <functional> 
#include <utility>

namespace mystl {

template<
    typename CustomIterator,
    typename Compare = std::less<typename std::iterator_traits<CustomIterator>::value_type>
>
class InsertionSorter {
    public:
        static void sort(CustomIterator begin, CustomIterator end, Compare comp = Compare()) {

        if (begin == end) return;

        for (auto it = std::next(begin); it != end; ++it) {
            auto key = std::move(*it);
            auto insert_pos = it;

            while (insert_pos != begin && comp(key, *std::prev(insert_pos))) {
                  *insert_pos = std::move(*std::prev(insert_pos));
                  --insert_pos;
            }
            *insert_pos = std::move(key);
        }
    }
};
}