// Подключение стандартной библиотеки для работы с потоками ввода/вывода
#include <iostream>
// Подключение библиотеки для работы с std::pair
#include <utility>

// Определение абстрактного класса Figure
class Figure {
public:
    // Виртуальный деструктор, необходим для корректного удаления объектов производных классов через указатель на базовый класс
    virtual ~Figure() = default;
    
    // Виртуальные методы для вычисления площади, периметра, массы и центра масс фигуры
    virtual double Area() = 0;
    virtual double Perimeter() = 0;
    virtual double Mass() = 0;
    virtual std::pair<double, double> Center() = 0;
    
    // Виртуальный метод для вывода информации о фигуре
    virtual void Print() = 0;
};

// Определение класса Hexagon, наследующего от абстрактного класса Figure
class Hexagon : public Figure {
public:
    // Конструктор с одним аргументом - длиной стороны шестиугольника
    explicit Hexagon(double side);
    
    // Переопределение виртуальных методов для класса Hexagon
    double Area() override;
    double Perimeter() override;
    double Mass() override;
    std::pair<double, double> Center() override;
    void Print() override;

private:
    // Сторона шестиугольника
    double side_;
};

// Определение класса IsoscelesTrapezoid, наследующего от абстрактного класса Figure
class IsoscelesTrapezoid : public Figure {
public:
    // Конструктор с тремя аргументами - длинами оснований и высотой равнобедренной трапеции
    IsoscelesTrapezoid(double a, double b, double h);
    
    // Переопределение виртуальных методов для класса IsoscelesTrapezoid
    double Area() override;
    double Perimeter() override;
    double Mass() override;
    std::pair<double, double> Center() override;
    void Print() override;

private:
    // Основания и высота равнобедренной трапеции
    double a_;
    double b_;
    double h_;
};
