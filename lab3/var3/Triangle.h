// Защита от повторного включения
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

// Определение класса Triangle (треугольник на плоскости)
class Triangle {
public:
    // Конструктор с координатами вершин
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);

    // Функция для вычисления площади треугольника
    double area() const;
    // Функция для смещения треугольника на dx, dy
    void translate(double dx, double dy);

    // Операторы сравнения треугольников по площади
    bool operator==(const Triangle& other) const;
    bool operator!=(const Triangle& other) const;
    bool operator<(const Triangle& other) const;
    bool operator>(const Triangle& other) const;

    // Оператор для смещения треугольника на вектор
    Triangle& operator+=(const std::pair<double, double>& vector);

private:
    // Координаты вершин треугольника
    double m_x1, m_y1, m_x2, m_y2, m_x3, m_y3;

    // Вспомогательная функция для вычисления расстояния между двумя точками
    double distance(double x1, double y1, double x2, double y2) const;
};

// Завершение защиты от повторного включения
#endif // TRIANGLE_H

