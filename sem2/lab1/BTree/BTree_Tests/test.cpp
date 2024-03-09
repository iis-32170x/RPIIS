#include "pch.h"
#include "gtest/gtest.h" 
#include "BTREE.hpp" 

// Тестирование функции поиска в B-дереве
TEST(BTreeTest, SearchTest) {
    BTree tree(4);

    tree.insert(4);
    tree.insert(8);

    ASSERT_TRUE(tree.search(7) == nullptr); // Ожидаем, что элемент 7 НЕ найден
    tree.insert(7);
    ASSERT_TRUE(tree.search(7) != nullptr); // Ожидаем, что элемент 7 найден

    tree.insert(10);
    tree.insert(15);
    tree.insert(22);
    tree.insert(18);

    ASSERT_TRUE(tree.search(15) != nullptr); // Ожидаем, что элемент 15 найден
    ASSERT_TRUE(tree.search(20) == nullptr); // Ожидаем, что элемент 20 не найден
    ASSERT_TRUE(tree.search(4) != nullptr); // Ожидаем, что элемент 15 найден
    ASSERT_TRUE(tree.search(30) == nullptr); // Ожидаем, что элемент 20 не найден
}

// Тестирование функции вставки в B-дерево
TEST(BTreeTest, InsertTest) {
    BTree tree(4);

    tree.insert(1);
    tree.insert(4);
    tree.insert(7);
    tree.insert(10);
    tree.insert(15);
    tree.insert(22);
    tree.insert(18);
    tree.insert(16);
    tree.insert(2);
    tree.insert(38);

    // Проверяем, что элементы действительно вставлены
    ASSERT_TRUE(tree.search(1) != nullptr);
    ASSERT_TRUE(tree.search(4) != nullptr);
    ASSERT_TRUE(tree.search(10) != nullptr);
    ASSERT_TRUE(tree.search(15) != nullptr);
    ASSERT_TRUE(tree.search(22) != nullptr);
    ASSERT_TRUE(tree.search(18) != nullptr);
    ASSERT_TRUE(tree.search(16) != nullptr);
    ASSERT_TRUE(tree.search(2) != nullptr);
    ASSERT_TRUE(tree.search(38) != nullptr);
}

// Тестирование функции удаления из B-дерева
TEST(BTreeTest, RemoveTest) {
    BTree tree(4);

    tree.insert(1);
    tree.insert(4);
    tree.insert(7);
    tree.insert(10);
    tree.insert(15);
    tree.insert(22);
    tree.insert(18);
    tree.insert(25);
    tree.insert(30);
    tree.insert(8);

    //Проверяем, есть ли элемент 15 в дереве
    ASSERT_TRUE(tree.search(15) != nullptr);
    // Удаляем элемент из дерева
    tree.remove(15);
    // Проверяем, что элемент действительно удален
    ASSERT_TRUE(tree.search(15) == nullptr);

    //Проверяем, есть ли элемент 18 в дереве
    ASSERT_TRUE(tree.search(18) != nullptr);
    // Удаляем элемент из дерева
    tree.remove(18);
    // Проверяем, что элемент действительно удален
    ASSERT_TRUE(tree.search(18) == nullptr);
}

// Запуск всех тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
