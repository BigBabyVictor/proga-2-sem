#include <iostream>
#include "Triangle.h"

int main() {
    // Создание треугольников
    Triangle t1(Point(0, 0), Point(3, 0), Point(0, 4));
    Triangle t2(Point(0, 0), Point(6, 0), Point(0, 8));

    // Вывод треугольников на экран
    std::cout << "Triangle 1: " << t1 << std::endl;
    std::cout << "Triangle 2: " << t2 << std::endl;

    // Сравнение площадей треугольников
    if (t1 > t2) {
        std::cout << "Triangle 1 has a larger area than Triangle 2." << std::endl;
    } else if (t1 < t2) {
        std::cout << "Triangle 1 has a smaller area than Triangle 2." << std::endl;
    } else {
        std::cout << "Triangle 1 has the same area as Triangle 2." << std::endl;
    }

    // Создание вектора смещения
    Vector v(1, 1);

    // Смещение треугольника t1 на вектор v
    t1 += v;

    // Вывод смещенного треугольника на экран
    std::cout << "Triangle 1 after translation: " << t1 << std::endl;

    return 0;
}


