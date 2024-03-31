#include "pch.h"
//#include "C:\Users\victus\source\repos\ll\ll\func.h"
#include "Header.h"
 // Предположим, что вам нужно вставить сюда заголовочный файл с вашим классом дерева

// Тест для проверки создания узла
TEST(NodeTest, CreateNode) {
    node* testNode = new node;
    EXPECT_EQ(testNode->key, 0); // По умолчанию ключ узла должен быть нулевым
    EXPECT_EQ(testNode->children.size(), 0); // У нового узла не должно быть дочерних узлов
}

// Тест для проверки добавления дочернего узла
TEST(TreeTest, AddChild) {
    node* parent = new node;
    int value = 5;
    add(parent, value);

    // Проверяем, что у родительского узла появился дочерний узел с правильным значением
    EXPECT_EQ(parent->children.size(), 1);
    EXPECT_EQ(parent->children[0]->key, value);
}

// Тест для проверки удаления узла
TEST(TreeTest, DeleteNode) {
    node* parent = new node;
    int value = 5;
    add(parent, value);

    // Удаляем добавленный узел
    deleteNode(parent, parent->children[0]);

    // Проверяем, что дочерний узел удален
    EXPECT_EQ(parent->children.size(), 0);
}

// Тест для проверки удаления дерева
TEST(TreeTest, DeleteTree) {
    node* parent = new node;
    int value = 5;
    add(parent, value);

    // Удаляем всё дерево
    deleteTree(parent);

    // Проверяем, что дерево удалено
    EXPECT_EQ(parent, nullptr);
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "RU");
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
