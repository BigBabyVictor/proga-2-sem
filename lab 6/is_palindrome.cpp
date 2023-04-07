#include <iostream>
#include <vector>

template <typename Iterator, typename Equal>
bool is_palindrome(Iterator first, Iterator last, Equal eq) {
    while (first != last) {
        --last;
        if (first == last) {
            break;
        }
        if (!eq(*first, *last)) {
            return false;
        }
        ++first;
    }
    return true;
}

int main() {
    std::vector<int> v = {1, 2, 3, 2, 1};
    bool palindrome = is_palindrome(v.begin(), v.end(), [](int a, int b) { return a == b; });
    std::cout << (palindrome ? "Yes" : "No") << std::endl;
    return 0;
}
