#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class LessThan {
private:
    T threshold;
public:
    LessThan(const T &threshold) : threshold(threshold) {}

    bool operator()(const T &value) const {
        return value < threshold;
    }
};

namespace my{

    template<typename ForwardIterator>
    ForwardIterator min_element(ForwardIterator first, ForwardIterator last) {
        if (first == last) return last;
        ForwardIterator min_it = first;
        while (++first != last) {
            if (*first < *min_it)
                min_it = first;
        }
        return min_it;
    }

}

template<typename ForwardIterator, typename Predicate>
ForwardIterator min_element_if(ForwardIterator first, ForwardIterator last, Predicate pred) {
    if (first == last) return last;
    ForwardIterator min_it = last;
    while (first != last) {
        if (pred(*first) && (min_it == last || *first < *min_it))
            min_it = first;
        ++first;
    }
    return min_it;
}
