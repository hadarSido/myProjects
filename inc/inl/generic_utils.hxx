#ifndef GENERIC_UTILS_INL_HXX
#define GENERIC_UTILS_INL_HXX
#include <vector>
#include <string>
#include <map>

#include "generic_utils.hpp"

namespace advcpp {

template<class C, class T, typename Container>
std::basic_ostream<C, T>& operator<<(std::basic_ostream<C, T>& a_ostream, Container const& a_container) {
    typename Container::const_iterator it = a_container.begin();
    typename Container::const_iterator end = a_container.end();
    print(it, end);
    return a_ostream;
}

template<typename Iterator>
void print(Iterator a_it, Iterator a_end) {
    while(a_it != a_end){
        std::cout << *a_it << ' ';
        ++a_it;
    }
}

template<typename Iterator>
Iterator minimal(Iterator a_begin, Iterator a_end) {
    Iterator minItr = a_begin;
    ++a_begin;
    while (a_begin != a_end) {
        if(*a_begin < *minItr) {
            minItr = a_begin;
        }
        ++a_begin;
    }
    return minItr;
}

template<typename T, typename Iterator>
T sum (Iterator a_begin, Iterator a_end) {
    T sum = T();
    while (a_begin != a_end) {
        sum += *a_begin;
        ++a_begin;
    }
    return sum;
}

template<typename Iterator>
Iterator firstUnique(Iterator a_begin, Iterator a_end) {
    while(a_begin != a_end) {
        if(count(a_begin, a_end, *a_begin) == 1) {
            return a_begin;
        }
        ++a_begin;
    }
    return a_end;
}

template<typename T, typename Iterator>
size_t count (Iterator a_begin, Iterator a_end, const T& a_value) {
    size_t counter = 0;
    while (a_begin != a_end) {
        if(*a_begin == a_value) {
            ++counter;
        }
        ++a_begin;
    }
    return counter;
}

} // advcpp

#endif // GENERIC_UTILS_INL_HXX