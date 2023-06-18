#ifndef ALGORITHMS_HPP_206
#define ALGORITHMS_HPP_206


namespace advcpp {

template <typename BidIter,
typename = std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag,
typename std::iterator_traits<BidIter>::iterator_category>::value>>
void reverse(BidIter a_first, BidIter a_last);


template <typename T, typename Iter, typename BiOp>
T reduce(Iter a_first, Iter a_last, T a_val, BiOp a_op);

struct Adder {
    template <typename T>
    T operator()(const T& a_a, const T& a_b) const;
};


}//advcpp

#include "inl/algorithms.hxx"
#endif //ALGORITHMS_HPP_206