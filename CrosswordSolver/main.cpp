#include "CrosswordSolver.h"
#include <iostream>
#include <string>
#include <vector>


int main() {
    try {
        std::cout << "Программа для разгадывания кроссвордов.\n";
        std::cout << "Введите шаблон слова (используйте '?' для неизвестных букв).\n";
        std::cout << "Для выхода введите 'exit'.\n";

        std::string input;
        while (true) {
            std::cout << "\nВведите шаблон: ";
            std::getline(std::cin, input);

            if (input == "exit" || std::cin.eof()) {
                std::cout << "Завершение программы.\n";
                break;
            }

            try {
                auto results = solveCrossword(input);

                if (results.empty()) {
                    std::cout << "Слов не найдено.\n";
                } else {
                    std::cout << "Найденные слова:\n";
                    for (const auto& word_ptr : results) {
                        std::cout << word_ptr.data() << '\n'; // Выводим строку
                    }
                }
            } catch (const std::exception& ex) {
                std::cerr << "error: " << ex.what() << '\n';
            }
        }
    } catch (const std::exception& ex) {
        std::cerr << "Fatal error: " << ex.what() << '\n';
        return 1;
    }

    return 0;
}
