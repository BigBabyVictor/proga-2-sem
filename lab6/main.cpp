#include <iostream>
#include <vector>
#include <functional>

template<typename Iterator, typename Predicate>
bool any_of(Iterator begin, Iterator end, Predicate pred) {
    for (Iterator it = begin; it != end; ++it) {
        if (pred(*it)) {
            return true;
        }
    }
    return false;
}

template<typename Iterator, typename Comparator>
bool is_sorted(Iterator begin, Iterator end, Comparator comp) {
    Iterator prev = begin;
    for (Iterator it = ++begin; it != end; ++it) {
        if (!comp(*prev, *it)) {
            return false;
        }
        prev = it;
    }
    return true;
}

template<typename Iterator, typename Equality>
bool is_palindrome(Iterator begin, Iterator end, Equality equal) {
    Iterator it1 = begin;
    Iterator it2 = end;
    --it2;

    while (it1 < it2) {
        if (!equal(*it1, *it2)) {
            return false;
        }
        ++it1;
        --it2;
    }
    return true;
}

struct CPoint {
    int x;
    int y;
};

bool compare_points(const CPoint& a, const CPoint& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool equal_points(const CPoint& a, const CPoint& b) {
    return a.x == b.x && a.y == b.y;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << any_of(numbers.begin(), numbers.end(), [](int x) { return x % 2 == 0; }) << std::endl;
    std::cout << is_sorted(numbers.begin(), numbers.end(), std::less<int>()) << std::endl;
    std::cout << is_palindrome(numbers.begin(), numbers.end(), std::equal_to<int>()) << std::endl;

    std::vector<CPoint> points = { {1, 2}, {3, 4}, {5, 6} };
    std::cout << any_of(points.begin(), points.end(), [](const CPoint& p) { return p.x % 2 == 0; }) << std::endl;
    std::cout << is_sorted(points.begin(), points.end(), compare_points) << std::endl;
    std::cout << is_palindrome(points.begin(), points.end(), equal_points) << std::endl;

    return 0;
}
