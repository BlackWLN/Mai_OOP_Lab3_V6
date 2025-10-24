# cmake_minimum_required(VERSION 3.10)
# project(Lab03)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # Включить тестирование
# enable_testing()

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )
# FetchContent_MakeAvailable(googletest)

# # Найти GoogleTest
# find_package(GTest REQUIRED)

# # Исходные файлы для основной программы
# set(MAIN_SOURCES
#     src/main.cpp
#     src/array.cpp
#     src/figure.cpp
#     src/pentagon.cpp
#     src/hexagon.cpp
#     src/octagon.cpp
# )

# # Исходные файлы для тестов
# set(TEST_SOURCES
#     tests/tests_01.cpp
#     src/array.cpp
#     src/figure.cpp
#     src/pentagon.cpp
#     src/hexagon.cpp
#     src/octagon.cpp
# )

# # Основная программа
# add_executable(main ${MAIN_SOURCES})
# target_include_directories(main PUBLIC include)

# # Тесты
# add_executable(tests ${TEST_SOURCES})
# target_include_directories(tests PUBLIC include)
# target_link_libraries(tests GTest::GTest GTest::Main)

# # Добавить тесты в систему тестирования CMake
# add_test(NAME FiguresTests COMMAND tests)

cmake_minimum_required(VERSION 3.14)
project(GeometryProject VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Download and setup Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Create library from your source files
add_library(geometry_lib
    src/array.cpp
    src/figure.cpp
    src/hexagon.cpp
    src/octagon.cpp
    src/pentagon.cpp
)

# Main executable
add_executable(main src/main.cpp)
target_link_libraries(main geometry_lib)
target_include_directories(main PRIVATE include)

# Test executable
add_executable(tests tests/tests_01.cpp)
target_link_libraries(tests geometry_lib gtest gtest_main)
target_include_directories(tests PRIVATE include)

# Enable testing
enable_testing()
add_test(NAME GeometryTests COMMAND tests)