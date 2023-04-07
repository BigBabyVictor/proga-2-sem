#include <iostream>
#include "IntegerSet.h"

int main() {
    IntegerSet set1, set2;

    set1 += 1;
    set1 += 3;
    set1 += 5;

    set2 += 2;
    set2 += 3;
    set2 += 5;

    std::cout << "Set 1: " << set1 << std::endl;
    std::cout << "Set 2: " << set2 << std::endl;

    IntegerSet unionSet = set1 + set2;
    std::cout << "Union of Set 1 and Set 2: " << unionSet << std::endl;

    if (set1 == set2) {
        std::cout << "Set 1 is equal to Set 2" << std::endl;
    } else {
        std::cout << "Set 1 is not equal to Set 2" << std::endl;
    }

    return 0;
}
