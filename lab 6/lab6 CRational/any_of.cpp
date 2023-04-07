#include <iostream>
#include <vector>

template <typename Iterator, typename Predicate>
bool any_of(Iterator first, Iterator last, Predicate pred) {
    for (; first != last; ++first) {
        if (pred(*first)) {
            return true;
        }
    }
    return false;
}



