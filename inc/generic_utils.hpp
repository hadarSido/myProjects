#ifndef GENERIC_UNTILS_HPP_205
#define GENERIC_UNTILS_HPP_205
#include <cstddef>
#include <iostream>
#include <ostream>
namespace advcpp {

template<class C, class T, typename Container>
std::basic_ostream<C, T>& operator<<(std::basic_ostream<C, T>& a_ostream, Container const& a_container);

template<typename Iterator>
void print(Iterator a_it, Iterator a_end);

template<typename Iterator>
Iterator minimal(Iterator a_begin, Iterator a_end);

template<typename T, typename Iterator>
T sum (Iterator a_begin, Iterator a_end);

template<typename Iterator>
Iterator firstUnique(Iterator a_begin, Iterator a_end);

template<typename T, typename Iterator>
size_t count (Iterator a_begin, Iterator a_end, const T& a_value);
/**********************************************************************/
// template<typename Iter>
// void reverse(Iter a_p, Iter a_q);

} // advcpp


#include "inl/generic_utils.hxx"

#endif //GENERIC_UNTILS_HPP_205
