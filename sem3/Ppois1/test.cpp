#include "pch.h"
#include "C:\Users\user\source\repos\Ppois1\Ppois1\functions.cpp"

vector<int> in_game_map(SIZE);
vector<vector<int>> game_map(SIZE, in_game_map);

vector<int> in_right_map(SIZE);
vector<vector<int>> right_map(SIZE, in_right_map);

coordinate zero;

TEST(CreateRightMapTest, ValidInitialization) {
    create_right_map();

    unsigned expected_value = 1;
    for (unsigned i = 0; i < SIZE; i++) {
        for (unsigned j = 0; j < SIZE; j++) {
            if (i == SIZE - 1 && j == SIZE - 1) {
                EXPECT_EQ(right_map[i][j], 0); // Последний элемент должен быть 0
            }
            else {
                EXPECT_EQ(right_map[i][j], expected_value++); // Проверяем последовательные значения
            }
        }
    }
}

TEST(CreateGameMapTest, ValidInitialization) {
    create_game_map();

    // Проверяем, что все числа от 0 до SIZE*SIZE-1 присутствуют
    vector<int> found(SIZE * SIZE, 0);
    for (unsigned i = 0; i < SIZE; i++) {
        for (unsigned j = 0; j < SIZE; j++) {
            found[game_map[i][j]]++;
        }
    }

    for (unsigned i = 0; i < SIZE * SIZE; i++) {
        EXPECT_EQ(found[i], 1); // Каждое число должно появляться только один раз
    }
}

TEST(CheckMapTest, GameMapMatchesRightMap) {
    create_right_map();
    game_map = right_map;

    EXPECT_TRUE(check_map()); // Карты совпадают
}

TEST(CheckMapTest, GameMapDoesNotMatchRightMap) {
    create_right_map();
    create_game_map();

    EXPECT_FALSE(check_map()); // Карты не совпадают
}

TEST(MoveTests, UpMove) {
    create_game_map();
    zero = { 1, 1 }; // Устанавливаем "ноль" на позиции (1, 1)
    game_map[1][1] = 0;
    game_map[2][1] = 5; // Устанавливаем значение ниже "нуля"

    up_move();

    EXPECT_EQ(game_map[1][1], 5); // Значение должно переместиться вверх
    EXPECT_EQ(game_map[2][1], 0); // Ноль должен переместиться вниз
    EXPECT_EQ(zero.y, 2);         // Координата y увеличивается
    EXPECT_EQ(zero.x, 1);         // Координата x остается прежней
}

TEST(MoveTests, DownMove) {
    create_game_map();
    zero = { 1, 2 }; // Устанавливаем "ноль" на позиции (1, 2)
    game_map[2][1] = 0;
    game_map[1][1] = 5; // Устанавливаем значение выше "нуля"

    down_move();

    EXPECT_EQ(game_map[1][1], 0); // Ноль должен переместиться вверх
    EXPECT_EQ(game_map[2][1], 5); // Значение должно переместиться вниз
    EXPECT_EQ(zero.y, 1);         // Координата y уменьшается
    EXPECT_EQ(zero.x, 1);         // Координата x остается прежней
}

TEST(MoveTests, RightMove) {
    create_game_map();
    zero = { 1, 1 }; // Устанавливаем "ноль" на позиции (1, 1)
    game_map[1][1] = 0;
    game_map[1][0] = 5; // Устанавливаем значение слева от "нуля"

    right_move();

    EXPECT_EQ(game_map[1][1], 5); // Значение должно переместиться вправо
    EXPECT_EQ(game_map[1][0], 0); // Ноль должен переместиться влево
    EXPECT_EQ(zero.x, 0);         // Координата x уменьшается
    EXPECT_EQ(zero.y, 1);         // Координата y остается прежней
}

TEST(MoveTests, LeftMove) {
    create_game_map();
    zero = { 1, 1 }; // Устанавливаем "ноль" на позиции (1, 1)
    game_map[1][1] = 0;
    game_map[1][2] = 5; // Устанавливаем значение справа от "нуля"

    left_move();

    EXPECT_EQ(game_map[1][1], 5); // Значение должно переместиться влево
    EXPECT_EQ(game_map[1][2], 0); // Ноль должен переместиться вправо
    EXPECT_EQ(zero.x, 2);         // Координата x увеличивается
    EXPECT_EQ(zero.y, 1);         // Координата y остается прежней
}

TEST(ScreenTest, OutputFormat) {
    create_game_map();

    testing::internal::CaptureStdout();
    screen();
    string output = testing::internal::GetCapturedStdout();

    // Проверяем, что вывод содержит правильное количество строк и столбцов
    unsigned rows = count(output.begin(), output.end(), '\n');
    EXPECT_EQ(rows, SIZE);

    unsigned cols = 0;
    for (unsigned i = 0; i < output.size(); i++) {
        if (output[i] == '\n') {
            break;
        }
        if (output[i] == ' ') {
            cols++;
        }
    }
    EXPECT_EQ(cols / 2, SIZE); // Учитываем, что каждая ячейка отделяется пробелом
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}