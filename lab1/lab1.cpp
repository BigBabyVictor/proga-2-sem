#include <iostream>
#include "lab1.h"

void discardIntegerPart(float* number) {
    *number -= static_cast<int>(*number);
}

void discardIntegerPart(float& number) {
    number -= static_cast<int>(number);
}

void invertFloat(float* number) {
    *number = -(*number);
}

void invertFloat(float& number) {
    number = -number;
}

void moveSquare(float* square, float vector) {
    *square += vector;
}

void moveSquare(float& square, float vector) {
    square += vector;
}

void swapRows(int* matrix, int size, int row1, int row2) {
    for (int i = 0; i < size; i++) {
        int temp = *(matrix + row1 * size + i);
        *(matrix + row1 * size + i) = *(matrix + row2 * size + i);
        *(matrix + row2 * size + i) = temp;
    }
}

void swapRows(int (&matrix)[3][3], int row1, int row2) {
    int* ptr1 = &(matrix[row1][0]);
    int* ptr2 = &(matrix[row2][0]);
    for (int i = 0; i < 3; i++) {
        int temp = *(ptr1 + i);
        *(ptr1 + i) = *(ptr2 + i);
        *(ptr2 + i) = temp;
    }
}

int main() {
    // Пример использования процедур

    // Пример работы с указателями
    float number = 12.34;
    float square = 5.0;
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    std::cout << "Initial values:" << std::endl;
    std::cout << "Number: " << number << std::endl;
    std::cout << "Square: " << square << std::endl;
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    discardIntegerPart(&number);
    invertFloat(&number);
    moveSquare(&square, 2.5);
    swapRows(&matrix[0][0], 3, 0, 2);

    std::cout << "Modified values (using pointers):" << std::endl;
    std::cout << "Number: " << number << std::endl;
    std::cout << "Square: " << square << std::endl;
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Пример работы с ссылками
    number = 12.34;
    square = 5.0;
    int matrix2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    discardIntegerPart(number);
    invertFloat(number);
    moveSquare(square, 2.5);
    swapRows(matrix2, 0, 2);

    std::cout << "Modified values (using references):" << std::endl;
    std::cout << "Number: " << number << std::endl;
    std::cout << "Square: " << square << std::endl;
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix2[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
