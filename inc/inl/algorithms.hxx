#ifndef ALGORITHMS_HXX
#define ALGORITHMS_HXX

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "algorithms.hpp"

namespace advcpp {   

template <typename BidIter,
typename = std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag,
typename std::iterator_traits<BidIter>::iterator_category>::value>>
void reverse(BidIter a_first, BidIter a_last) {
    while (a_first != a_last && a_first != --a_last) {
        std::iter_swap(a_first, a_last);
        ++a_first;
    }
}
template <typename T, typename Iter, typename BiOp>
T reduce(Iter a_first, Iter a_last, T a_val, BiOp a_op) {
    while (a_first != a_last ) {
        a_val = a_op(a_val, *a_first);
        ++a_first;
    }
    return a_val;
}

template <typename T>
T Adder::operator()(const T& a_a, const T& a_b) const {
    return a_a + a_b;
}


}//advcpp

#endif // ALGORITHMS_HXX