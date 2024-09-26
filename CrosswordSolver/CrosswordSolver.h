#ifndef CROSSWORD_SOLVER_H
#define CROSSWORD_SOLVER_H

#include <vector>
#include <string>

/**
 * @brief Проверяет, содержит ли строка допустимые символы (буквы и '?')
 *
 * @param pattern Шаблон искомого слова
 * @return true Если строка валидна
 * @return false Если строка содержит недопустимые символы
 */

bool isValidPattern(const std::string& pattern);

/**
 * @brief Функция разгадывания кроссвордов (перегрузка для const char*)
 *
 * @param pattern Шаблон искомого слова
 * @return Вектор указателей на строки, подходящие под шаблон
 */

std::vector<const char*> solveCrossword(const char* pattern);

/**
 * @brief Функция разгадывания кроссвордов (перегрузка для std::string)
 *
 * @param pattern Шаблон искомого слова
 * @return Вектор строк, подходящих под шаблон
 */

std::vector<std::string> solveCrossword(const std::string& pattern);

#endif // CROSSWORD_SOLVER_H
