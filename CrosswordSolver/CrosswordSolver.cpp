#include "CrosswordSolver.h"
#include <fstream>
#include <cctype>
#include <stdexcept>
#include <filesystem>

std::vector<std::string> dictionary;


void loadDictionary() {
    if (!dictionary.empty()) return;

    std::ifstream file("words.txt");
    if (!file.is_open()) {
        throw std::runtime_error("The dictionary file could not be opened.");
    }

    std::string word;
    while (std::getline(file, word)) {
        word.erase(std::remove_if(word.begin(), word.end(), ::isspace), word.end());
        if (!word.empty()) {
//            std::cout << word << std::endl;
            dictionary.push_back(word);
        }
    }
    file.close();
}


bool matchesPattern(const std::string& word, const std::string& pattern) {
    if (word.length() != pattern.length()) return false;

    return std::equal(word.begin(), word.end(), pattern.begin(),
                      [](char w, char p) {
        return p == '?' || std::tolower(static_cast<unsigned char>(w)) == std::tolower(static_cast<unsigned char>(p));
    });
}

bool isValidPattern(const std::string& pattern) {
    if (pattern.empty()) {
        return false;
    }
    return std::all_of(pattern.begin(), pattern.end(), [](char c) {
        return std::isalpha(static_cast<unsigned char>(c)) || c == '?';
    });
}


std::vector<const char*> solveCrossword(const char* pattern) {
    if (pattern == nullptr) {
        throw std::invalid_argument("The template must not be nullptr.");
    }

    std::string patternStr(pattern);

    if (!isValidPattern(patternStr)) {
        throw std::invalid_argument("The template contains invalid characters.");
    }

    loadDictionary();

    std::vector<const char*> result;
    std::for_each(dictionary.begin(), dictionary.end(), [&](const std::string& word) {
        if (matchesPattern(word, patternStr)) {
            char* cstr = new char[word.size() + 1];
            std::copy(word.begin(), word.end(), cstr);
            cstr[word.size()] = '\0';
            result.push_back(cstr);
        }
    });

    return result;
}

std::vector<std::string> solveCrossword(const std::string& pattern) {
    if (!isValidPattern(pattern)) {
        throw std::invalid_argument("The template contains invalid characters.");
    }

    loadDictionary();

    std::vector<std::string> result;
    std::copy_if(dictionary.begin(), dictionary.end(), std::back_inserter(result),
                 [&](const std::string& word) {
        return matchesPattern(word, pattern);
    });

    return result;
}
