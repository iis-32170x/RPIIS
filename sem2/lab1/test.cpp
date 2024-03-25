#include "pch.h"
#include "../lr 1 sem 2/library.cpp"

TEST(CreateNodeTest, NewNodeIsNotNull) {
	int value = 10;
	// Вызываем функцию createNode
	Node* node = createNode(value);
	// Проверяем, что указатель на новый узел не равен nullptr
	EXPECT_NE(node, nullptr);

	// Освобождаем память, выделенную для узла
	delete node;
}

TEST(BuildTreeTest, TestName) {
    // Создание массива для построения дерева
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // Вызов функции buildTree для построения дерева
    Node* root = buildTree(arr, 0, n - 1);

    // Освобождение памяти после выполнения теста
    clearTree(root);
}

TEST(InsertNodeTest, TestName) {
    // Создание корня дерева
    Node* root = nullptr;
    // Вставка элементов в дерево
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    // Проверка корректности вставки элементов
    EXPECT_EQ(root->key, 4);
    EXPECT_EQ(root->left->key, 2);
    EXPECT_EQ(root->right->key, 6);
    EXPECT_EQ(root->left->left->key, 1);
    EXPECT_EQ(root->left->right->key, 3);

    // Освобождение памяти после выполнения теста
    clearTree(root);
}

TEST(SearchTest, TestName) {
    // Создание корня дерева
    Node* root = createNode(4);
    // Вставка элементов в дерево
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    // Поиск существующих элементов
    EXPECT_TRUE(search(root, 4));
    EXPECT_TRUE(search(root, 2));
    EXPECT_TRUE(search(root, 6));
    EXPECT_TRUE(search(root, 1));
    EXPECT_TRUE(search(root, 3));
    // Поиск несуществующего элемента
    EXPECT_TRUE(search(root, 5));

    // Освобождение памяти после выполнения теста
    clearTree(root);
}

TEST(FindMinNodeTest, TestName) {
    // Создание корня дерева
    Node* root = createNode(4);
    // Вставка элементов в дерево
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    // Поиск наименьшего элемента
    Node* minNode = findMinNode(root);
    EXPECT_EQ(minNode->key, 1);

    // Освобождение памяти после выполнения теста
    clearTree(root);
}

TEST(PreOrderTraversalTest, TestName) {
    // Создание корня дерева
    Node* root = createNode(4);
    // Вставка элементов в дерево
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    // Подготовка ожидаемого результата
    std::stringstream expected;
    expected << "4 2 1 3 6 ";
    // Подготовка вывода в строковый поток
    std::stringstream output;
    // Перенаправление стандартного вывода в строковый поток
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    // Вызов функции preOrderTraversal
    preOrderTraversal(root);
    // Восстановление стандартного вывода
    std::cout.rdbuf(oldCoutBuffer);
    // Сравнение ожидаемого вывода с фактическим
    EXPECT_EQ(output.str(), expected.str());

    // Освобождение памяти после выполнения теста
    clearTree(root);
}

TEST(InOrderTraversalTest, TestName) {
    // Создание корня дерева
    Node* root = createNode(4);
    // Вставка элементов в дерево
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    // Подготовка ожидаемого результата
    std::stringstream expected;
    expected << "1 2 3 4 6 ";
    // Подготовка вывода в строковый поток
    std::stringstream output;
    // Перенаправление стандартного вывода в строковый поток
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    // Вызов функции inOrderTraversal
    inOrderTraversal(root);
    // Восстановление стандартного вывода
    std::cout.rdbuf(oldCoutBuffer);
    // Сравнение ожидаемого вывода с фактическим
    EXPECT_EQ(output.str(), expected.str());

    // Освобождение памяти после выполнения теста
    clearTree(root);
}

TEST(PostOrderTraversalTest, TestName) {
    // Создание корня дерева
    Node* root = createNode(4);
    // Вставка элементов в дерево
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    // Подготовка ожидаемого результата
    std::stringstream expected;
    expected << "1 3 2 6 4 ";
    // Подготовка вывода в строковый поток
    std::stringstream output;
    // Перенаправление стандартного вывода в строковый поток
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    // Вызов функции postOrderTraversal
    postOrderTraversal(root);
    // Восстановление стандартного вывода
    std::cout.rdbuf(oldCoutBuffer);
    // Сравнение ожидаемого вывода с фактическим
    EXPECT_EQ(output.str(), expected.str());

    // Освобождение памяти после выполнения теста
    clearTree(root);
}

// Запускаем тесты
int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}