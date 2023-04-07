#include <algorithm>
#include <iostream>
#include <vector>
#include "CRational.h"

template <typename T>
bool is_palindrome(const std::vector<T>& vec) {
    auto it_begin = vec.begin();
    auto it_end = vec.end();
    while (it_begin < it_end) {
        if (*it_begin != *(--it_end)) {
            return false;
        }
        ++it_begin;
    }
    return true;
}

int main() {
    std::vector<CRational> rationals = {
        CRational(1, 2),
        CRational(2, 3),
        CRational(1, 4),
        CRational(2, 5),
        CRational(1, 6),
    };

    // any_of
    bool any_positive = std::any_of(rationals.begin(), rationals.end(),
                                     [](const CRational& r) { return r.getNumerator() > 0; });
    std::cout << "Any positive rationals: " << (any_positive ? "Yes" : "No") << std::endl;

    // is_sorted
    bool sorted = std::is_sorted(rationals.begin(), rationals.end());
    std::cout << "Rationals are sorted: " << (sorted ? "Yes" : "No") << std::endl;

    // is_palindrome
    std::vector<CRational> palindromic_rationals = {
        CRational(1, 2),
        CRational(2, 3),
        CRational(3, 4),
        CRational(2, 3),
        CRational(1, 2),
    };
    bool palindrome = is_palindrome(palindromic_rationals);
    std::cout << "Palindromic rationals: " << (palindrome ? "Yes" : "No") << std::endl;

    return 0;
}
