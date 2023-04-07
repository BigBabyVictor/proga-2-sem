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
