#include "pch.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

Branch* root4 = nullptr;
Branch* root3 = nullptr;
Branch* root = nullptr;
Branch* root2 = nullptr;

// Рекурсивная функция для обхода дерева в порядке "inorder" и сохранения значений в вектор
void inorderTraversal(Branch* root, vector<int>& values) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left, values);
    values.push_back(root->data);
    inorderTraversal(root->right, values);
}

// Функция для получения всех значений дерева в виде вектора
vector<int> getTreeValues(Branch* root) {
    vector<int> values;
    inorderTraversal(root, values);
    return values;
}

vector<int> treeIntersection(Branch* tree1, Branch* tree2)
{
    vector<int> result;
    vector<int> values1 = getTreeValues(tree1); // Функция getTreeValues возвращает все значения дерева в виде вектора
    vector<int> values2 = getTreeValues(tree2);
    sort(values1.begin(), values1.end());
    sort(values2.begin(), values2.end());
    set_intersection(values1.begin(), values1.end(), values2.begin(), values2.end(), back_inserter(result));
    return result;
}

#include <gtest/gtest.h>

//Тест по добавлению элементов
TEST(MnozAddElemTest, Mnoz) {
    Branch* mnozh = nullptr;
    Add(mnozh, 5);
    Add(mnozh, 15);
    Add(mnozh, 52);
    vector<int> expectedResult{ 5, 15, 52 };
    EXPECT_EQ(getTreeValues(mnozh), expectedResult);
}

// Тест проверяет наличие общих значений между двумя пустыми множествами
TEST(MnozIntersectionTest, EmptyMnoz) {
    Branch* tree1 = nullptr;
    Branch* tree2 = nullptr;
    Branch* peres = nullptr;
    Intersection(tree1, tree2, peres);
    EXPECT_EQ(peres, nullptr);
}

// Тест проверяет результат, когда оба множества одинаковые
TEST(MnozIntersectionTest, IdenticalMnoz) {
    Branch* tree1 = root;
    Branch* tree2 = root;
    Branch* peres = nullptr;
    Intersection(tree1, tree2, peres);
    EXPECT_EQ(getTreeValues(peres), getTreeValues(root)); // Ожидаем, что результат будет содержать все значения из обоих деревьев
}

// Тест проверяет наличие общих значений между двумя множествами
TEST(MnozIntersectionTest, DifferentMnoz) {
    vector<int> expectedResult{ 15, 52 };
    EXPECT_EQ(getTreeValues(root3), expectedResult);
}

// Тест проверяет объединение двух множеств
TEST(MnozUnificationTest, DifferentMnoz) {
    vector<int> expectedResult{ 5, 15, 52, 67 };
    EXPECT_EQ(getTreeValues(root4), expectedResult);
}

// Тест по поиску элемента
TEST(MnozFindElemTest, Mnoz) {
    EXPECT_EQ(FindElem(root4, 67)->data, 67);
}

// Тест по удалению элемента
TEST(MnozDelElTest, Mnoz) {
    vector<int> expectedResult{ 5, 15, 52 };
    removeNode(root4, 67);
    EXPECT_EQ(getTreeValues(root4), expectedResult);
}
int main(int argc, char* argv[]) {

    setlocale(0, "");

    Add(root, 5);
    Add(root, 15);
    Add(root, 52);

    Add(root2, 52);
    Add(root2, 15);
    Add(root2, 67);
    Intersection(root, root2, root3);
    Union(root, root2, root4);

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
