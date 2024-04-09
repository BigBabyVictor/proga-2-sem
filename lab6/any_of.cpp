#include <iostream>
#include <vector>
#include <algorithm>

template<typename Iterator, typename Predicate>
bool any_of(Iterator begin, Iterator end, Predicate pred) {
    for (Iterator it = begin; it != end; ++it) {
        if (pred(*it)) {
            return true;
        }
    }
    return false;
}

