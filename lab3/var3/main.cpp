#include <iostream>
#include "Triangle.h"

int main() {
    Triangle t1(0, 0, 3, 0, 0, 4);
    Triangle t2(1, 1, 4, 1, 1, 5);

    std::cout << "Triangle 1 area: " << t1.area() << std::endl;
    std::cout << "Triangle 2 area: " << t2.area() << std::endl;

    if (t1 == t2) {
        std::cout << "Triangles have equal areas." << std::endl;
    } else if (t1 != t2) {
        std::cout << "Triangles have different areas." << std::endl;
    }

    if (t1 < t2) {
        std::cout << "Triangle 1 has smaller area than Triangle 2." << std::endl;
    } else if (t1 > t2) {
        std::cout << "Triangle 1 has larger area than Triangle 2." << std::endl;
    }

    t1 += std::make_pair(2.0, 2.0); // Смещаем треугольник 1 на вектор (2, 2)
    std::cout << "Triangle 1 area after translation: " << t1.area() << std::endl;

    return 0;
}

