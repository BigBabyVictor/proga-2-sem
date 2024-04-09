#include <iostream>
#include "fixed_array.h"
#include "max_element.h"

int main() {
    try {
        FixedArray<5, int> int_array;
        int_array[0] = 1;
        int_array[1] = 3;
        int_array[2] = 7;
        int_array[3] = 2;
        int_array[4] = 5;

        std::cout << "Max element in int_array: " << max_element(int_array) << std::endl;

        FixedArray<4, double> double_array;
        double_array[0] = 1.5;
        double_array[1] = 4.2;
        double_array[2] = 3.7;
        double_array[3] = 2.9;

        std::cout << "Max element in double_array: " << max_element(double_array) << std::endl;

        // Это вызовет исключение IndexError, так как индекс выходит за пределы массива.
        std::cout << int_array[5] << std::endl;
    } catch (const IndexError& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
