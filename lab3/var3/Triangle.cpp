#include "Triangle.h" // Подключаем заголовочный файл Triangle.h
#include <cmath> // Подключаем заголовочный файл cmath, который содержит математические функции, такие как sqrt и pow
#include <stdexcept> // Подключаем заголовочный файл stdexcept, который содержит стандартные исключения

// Определение конструктора класса Triangle
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
    : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_x3(x3), m_y3(y3) {}

// Определение метода класса Triangle для вычисления площади треугольника
double Triangle::area() const {
    double a = distance(m_x1, m_y1, m_x2, m_y2);
    double b = distance(m_x2, m_y2, m_x3, m_y3);
    double c = distance(m_x3, m_y3, m_x1, m_y1);

    double s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

// Определение метода класса Triangle для сдвига треугольника на заданные значения
void Triangle::translate(double dx, double dy) {
    m_x1 += dx;
    m_y1 += dy;
    m_x2 += dx;
    m_y2 += dy;
    m_x3 += dx;
    m_y3 += dy;
}

// Перегрузка оператора == для сравнения площадей двух треугольников
bool Triangle::operator==(const Triangle& other) const {
    return area() == other.area();
}

// Перегрузка оператора != для сравнения площадей двух треугольников
bool Triangle::operator!=(const Triangle& other) const {
    return area() != other.area();
}

// Перегрузка оператора < для сравнения площадей двух треугольников
bool Triangle::operator<(const Triangle& other) const {
    return area() < other.area();
}

// Перегрузка оператора > для сравнения площадей двух треугольников
bool Triangle::operator>(const Triangle& other) const {
    return area() > other.area();
}

// Перегрузка оператора += для сдвига треугольника на заданные значения
Triangle& Triangle::operator+=(const std::pair<double, double>& vector) {
    translate(vector.first, vector.second);
    return *this;
}

// Вспомогательный метод для вычисления расстояния между двумя точками
double Triangle::distance(double x1, double y1, double x2, double y2) const {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}
