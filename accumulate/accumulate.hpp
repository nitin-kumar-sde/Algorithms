#pragma once

#include <functional>

namespace mystl {

    template <typename InputIt, typename T, typename BinaryOp = std::plus<>>
    T accumulate(InputIt first, InputIt last, T init, BinaryOp op = BinaryOp{}) {
        while (first != last) {
            init = op(init, *first);
            ++first;
        }
        return init;
    }

}