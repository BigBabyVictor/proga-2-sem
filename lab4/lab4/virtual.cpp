// Подключение математической библиотеки для использования функции sqrt и константы M_PI
#include <cmath>
// Подключение заголовочного файла "virtual.h" с описанием классов Hexagon и IsoscelesTrapezoid
#include "virtual.h"

// Реализация конструктора класса Hexagon
Hexagon::Hexagon(double side) : side_(side) {}

// Реализация метода Area для класса Hexagon
double Hexagon::Area() {
    return (3 * sqrt(3) * side_ * side_) / 2;
}

// Реализация метода Perimeter для класса Hexagon
double Hexagon::Perimeter() {
    return 6 * side_;
}

// Реализация метода Mass для класса Hexagon
double Hexagon::Mass() {
    return Area(); // Масса = Площадь, т.к. плотность равна 1
}

// Реализация метода Center для класса Hexagon
std::pair<double, double> Hexagon::Center() {
    double apothem = side_ / (2 * tan(M_PI / 6));
    return std::make_pair(side_ * sqrt(3) / 2, apothem);
}

// Реализация метода Print для класса Hexagon
void Hexagon::Print() {
    std::cout << "Hexagon: side = " << side_ << std::endl;
}

// Реализация конструктора класса IsoscelesTrapezoid
IsoscelesTrapezoid::IsoscelesTrapezoid(double a, double b, double h) : a_(a), b_(b), h_(h) {}

// Реализация метода Area для класса IsoscelesTrapezoid
double IsoscelesTrapezoid::Area() {
    return ((a_ + b_) * h_) / 2;
}

// Реализация метода Perimeter для класса IsoscelesTrapezoid
double IsoscelesTrapezoid::Perimeter() {
    double c = sqrt(h_ * h_ + pow((b_ - a_) / 2, 2));
    return a_ + b_ + 2 * c;
}

// Реализация метода Mass для класса IsoscelesTrapezoid
double IsoscelesTrapezoid::Mass() {
    return Area(); // Масса = Площадь, т.к. плотность равна 1
}

// Реализация метода Center для класса IsoscelesTrapezoid
std::pair<double, double> IsoscelesTrapezoid::Center() {
    double cx = (a_ + b_) / 2;
    double cy = h_ / 2;
    return std::make_pair(cx, cy);
}

// Реализация метода Print для класса IsoscelesTrapezoid
void IsoscelesTrapezoid::Print() {
    std::cout << "IsoscelesTrapezoid: a = " << a_ << ", b = " << b_ << ", h = " << h_ << std::endl;
}
