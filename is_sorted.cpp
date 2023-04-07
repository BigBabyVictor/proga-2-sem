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

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    bool sorted = is_sorted(v.begin(), v.end(), [](int a, int b) { return a > b; });
    std::cout << (sorted ? "Yes" : "No") << std::endl;
    return 0;
}
