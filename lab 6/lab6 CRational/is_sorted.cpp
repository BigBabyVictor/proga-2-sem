#include <iostream>
#include <vector>

template <typename Iterator, typename Compare>
bool is_sorted(Iterator first, Iterator last, Compare comp) {
    if (first == last) {
        return true;
    }
    Iterator next = first;
    ++next;
    for (; next != last; first = next, ++next) {
        if (comp(*next, *first)) {
            return false;
        }
    }
    return true;
}

