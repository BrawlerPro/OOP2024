# tests/CMakeLists.txt

include(FetchContent)


FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(Tests test_CrosswordSolver.cpp ../CrosswordSolver.cpp)

target_include_directories(Tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(Tests gtest_main)

include(GoogleTest)
gtest_discover_tests(Tests)
