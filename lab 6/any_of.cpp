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

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    bool has_even = any_of(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    std::cout << (has_even ? "Yes" : "No") << std::endl;
    return 0;
}