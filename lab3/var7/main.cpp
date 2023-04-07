#include <iostream>
#include "IntegerSet.h"

int main() {
    // Создание двух множеств
    IntegerSet set1, set2;

    // Добавление чисел в множества
    set1 += 1;
    set1 += 3;
    set1 += 5;

    set2 += 2;
    set2 += 3;
    set2 += 5;

    // Вывод множеств на экран
    std::cout << "Set 1: " << set1 << std::endl;
    std::cout << "Set 2: " << set2 << std::endl;

    // Объединение множеств и вывод результата на экран
    IntegerSet unionSet = set1 + set2;
    std::cout << "Union of Set 1 and Set 2: " << unionSet << std::endl;

    // Сравнение множеств на равенство и вывод результата на экран
    if (set1 == set2) {
        std::cout << "Set 1 is equal to Set 2" << std::endl;
    } else {
        std::cout << "Set 1 is not equal to Set 2" << std::endl;
    }

    return 0;
}
