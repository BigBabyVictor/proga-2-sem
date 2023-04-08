// Подключаем необходимые библиотеки и заголовочные файлы
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include "virtual.h"

int main() {
    // Создаем вектор умных указателей для хранения фигур
    std::vector<std::shared_ptr<Figure>> figures;
    // Объявляем переменные для выбора пользователя и ввода параметров фигур
    char choice;
    double side, a, b, h;

    // Цикл для получения ввода пользователя
    do {
        // Выводим предложение выбора фигуры
        std::cout << "Choose a figure (H - Hexagon, T - Isosceles Trapezoid, Q - Quit): ";
        std::cin >> choice;

        // Обрабатываем выбор пользователя
        switch (toupper(choice)) {
            case 'H':
                // Запрашиваем длину стороны шестиугольника и добавляем его в вектор
                std::cout << "Enter side length: ";
                std::cin >> side;
                figures.push_back(std::make_shared<Hexagon>(side));
                break;
            case 'T':
                // Запрашиваем длины оснований и высоту равнобедренной трапеции и добавляем ее в вектор
                std::cout << "Enter lengths of bases (a, b) and height (h): ";
                std::cin >> a >> b >> h;
                figures.push_back(std::make_shared<IsoscelesTrapezoid>(a, b, h));
                break;
            case 'Q':
                // Завершаем цикл
                break;
            default:
                // Обрабатываем некорректный ввод
                std::cout << "Invalid input, try again." << std::endl;
                break;
        }
    } while (toupper(choice) != 'Q');

    // Выводим информацию о всех фигурах
    std::cout << "\nDisplaying all figures:" << std::endl;
    for (const auto &figure : figures) {
        figure->Print();
    }

    // Вычисляем суммарную площадь всех фигур
    double total_area = std::accumulate(figures.begin(), figures.end(), 0.0, [](double acc, const auto &figure) {
        return acc + figure->Area();
    });
    std::cout << "\nTotal area of all figures: " << total_area << std::endl;

    // Вычисляем суммарный периметр всех фигур
    double total_perimeter = std::accumulate(figures.begin(), figures.end(), 0.0, [](double acc, const auto &figure) {
        return acc + figure->Perimeter();
    });
    std::cout << "Total perimeter of all figures: " << total_perimeter << std::endl;

    // Вычисляем суммарную массу всех фигур
    double total_mass = std::accumulate(figures.begin(), figures.end(), 0.0, [](double acc, const auto &figure) {
        return acc + figure->Mass();
    });
    std::cout << "Total mass of all figures: " << total_mass << std::endl;

 // Вычисляем центр масс всей системы
    auto mass_center = std::accumulate(figures.begin(), figures.end(), std::make_pair(0.0, 0.0), [&](std::pair<double, double> acc, const auto &figure) {
        auto center = figure->Center();
        return std::make_pair(acc.first + figure->Mass() * center.first, acc.second + figure->Mass() * center.second);
    });
    mass_center.first /= total_mass;
    mass_center.second /= total_mass;
    std::cout << "Center of mass of the system: (" << mass_center.first << ", " << mass_center.second << ")\n";

    // Выводим общий объем памяти, занимаемый всеми экземплярами классов фигур
    std::cout << "Total memory occupied by figures: " << sizeof(Figure) * figures.size() << " bytes" << std::endl;

    // Сортируем фигуры по массе и выводим отсортированный список
    std::cout << "\nSorting figures by mass:" << std::endl;
    std::sort(figures.begin(), figures.end(), [](const auto &figure1, const auto &figure2) {
        return figure1->Mass() < figure2->Mass();
    });

    for (const auto &figure : figures) {
        figure->Print();
    }

    return 0;
}
