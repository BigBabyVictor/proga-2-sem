#include <iostream>
#include "queue.h"

void print_menu() {
    std::cout << "1. Добавьте элемент в очередь\n"
              << "2. Удалить элемент из очереди\n"
              << "3. Показать передний элемент\n"
              << "4. Показать задний элемент\n"
              << "5. Показать длину очереди\n"
              << "6. Показать очередь\n"
              << "7. Выход\n"
              << "Выберите: ";
}

int main() {
    int max_size;
    std::cout << "Введите максимальный размер очереди: ";
    std::cin >> max_size;
    Queue queue(max_size);

    int choice;
    std::string input;

    while (true) {
        print_menu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Введите строку для добавления: ";
                std::cin.ignore();
                std::getline(std::cin, input);
                if (queue.enqueue(input)) {
                    std::cout << "Элемент успешно добавлен.\n";
                } else {
                    std::cout << "Очередь заполнена.\n";
                }
                break;
            case 2:
                input = queue.dequeue();
                if (!input.empty()) {
                    std::cout << "Элемент удален: " << input << '\n';
                } else {
                    std::cout << "Очередь пуста.\n";
                }
                break;
            case 3:
                input = queue.front();
                if (!input.empty()) {
                    std::cout << "Передний элемент: " << input << '\n';
                } else {
                    std::cout << "Очередь пуста.\n";
                }
                break;
            case 4:
                input = queue.back();
                if (!input.empty()) {
                    std::cout << "Последний элемент: " << input << '\n';
                } else {
                    std::cout << "Очередь пуста.\n";
                }
                break;
            case 5:
                std::cout << "Длина очереди " << queue.length() << '\n';
                break;
            case 6:
                std::cout << "Отображение очереди:\n";
                queue.display();
                break;
            case 7:
                std::cout << "Выход...\n";
                return 0;
            default:
                std::cout << "Неверный выбор.\n";
        }
    }
}
