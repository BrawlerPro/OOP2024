#include <gtest/gtest.h>
#include "../CrosswordSolver.h"

TEST(CrosswordSolverTest, ValidPatternTest) {
    EXPECT_TRUE(isValidPattern("apple"));
    EXPECT_TRUE(isValidPattern("?pple"));
    EXPECT_TRUE(isValidPattern("?????"));
    EXPECT_FALSE(isValidPattern("app1e"));
    EXPECT_FALSE(isValidPattern("app e"));
    EXPECT_FALSE(isValidPattern(""));
}

TEST(CrosswordSolverTest, SolveCrosswordString) {
    std::string pattern = "?ppl?";
    auto results = solveCrossword(pattern);
    std::cout << "Результаты для шаблона '?pple':\n";
    for (const auto& word : results) {
        std::cout << word << std::endl;
    }

    EXPECT_NE(std::find(results.begin(), results.end(), "apple"), results.end());
    EXPECT_NE(std::find(results.begin(), results.end(), "apply"), results.end());
}

TEST(CrosswordSolverTest, SolveCrosswordCString) {
    const char* pattern = "?ppl?";
    auto results = solveCrossword(pattern);

    bool foundApple = false;
    bool foundApply = false;

    std::cout << "Результаты для шаблона '?pple' (C-строки):\n";
    for (const auto& word : results) {
        std::cout << word << std::endl;

        if (std::string(word) == "apple") foundApple = true;
        if (std::string(word) == "apply") foundApply = true;

        delete[] word;
    }

    EXPECT_TRUE(foundApple);
    EXPECT_TRUE(foundApply);
}

TEST(CrosswordSolverTest, InvalidPatternTest) {
    std::string pattern = "app1e";
    EXPECT_THROW(solveCrossword(pattern), std::invalid_argument);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
