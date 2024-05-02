#include "pch.h"
#include "D:\university\pioivis\LABKARRRR2\Header.h"
#include "gtest/gtest.h"
using namespace std;

// Тест для функции Start, проверяющий корректность работы функции на конкретном наборе данных
TEST(TestCaseName, TestName) {
    vector <string> sets;
    sets = SetRecord("in.txt");
    Start(sets);
    EXPECT_EQ(Start(sets), "{6}"); // Проверяем результат работы функции Start
    EXPECT_TRUE(true);
}

// Тест для функции SetRecord, проверяющий обработку некорректного входного файла
TEST(SetRecordTest, IncorrectInputFile) {
    // Создаем временный файл с некорректными данными
    ofstream testfile("testfile.txt");
    testfile << "={1,2,3}" << endl;
    testfile.close();

    // Вызываем функцию SetRecord на созданном файле
    vector<string> result = SetRecord("testfile.txt");

    // Проверяем, что функция вернула пустой вектор
    ASSERT_TRUE(result.empty());
}

// Тесты для функции Intersection

// Проверяем, что результат пересечения двух пустых множеств также является пустым множеством
TEST(IntersectionTest, EmptySets) {
    vector<string> set1 = { "a", "b", "c" };
    vector<string> set2 = {};

    vector<string> result = Intersection(set1, set2);

    ASSERT_TRUE(result.empty());
}

// Проверяем, что если у двух множеств нет общих элементов, то результат пересечения также должен быть пустым
TEST(IntersectionTest, NoCommonElements) {
    vector<string> set1 = { "a", "b", "c" };
    vector<string> set2 = { "x", "y", "z" };

    vector<string> result = Intersection(set1, set2);

    ASSERT_TRUE(result.empty());
}

// Проверяем, что если у двух множеств есть общие элементы, то результат пересечения должен содержать только эти общие элементы
TEST(IntersectionTest, CommonElementsExist) {
    vector<string> set1 = { "a", "b", "c", "d" };
    vector<string> set2 = { "b", "c", "e" };

    vector<string> expected_result = { "b", "c" };
    vector<string> result = Intersection(set1, set2);

    ASSERT_EQ(expected_result, result);
}
