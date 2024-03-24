

# Лабораторная работа №2
**Вариант №12**    
12. Реализовать программу, формирующую множество равное симметрической разности
произвольного количества исходных множеств (с учётом кратных вхождений элементов).
## Цели лабораторной работы:
1. Разработать библиотеку для считывания из файла и работы с несколькими мультимножествами на выбранном императивном языке программирования (например, C++, Java, Python).
2. Создать тестовую программу для демонстрации функциональности разработанной библиотеки.
3. Разработать систему тестов для проверки работоспособности и корректности библиотеки, учитывая требования полноты, адекватности и непротиворечивости.
4. Обеспечить обработку некорректных данных, предусмотрев корректное завершение программы при возникновении ошибок.
5. Составить отчет по выполнению лабораторной работы.
   
## Задачи лабораторной работы
1. Изучить спецификацию задачи по работе с множествами.
2. Выбрать язык программирования для реализации библиотеки (например, C++, Java, Python) в соответствии с индивидуальным заданием.
3. Разработать и реализовать библиотеку для считывания из файла и нахождения симметрической разности нескольких мультимножеств.
4. Написать тестовую программу, которая демонстрирует основные сценарии использования библиотеки.
5. Разработать систему тестов, включающую тест-кейсы для проверки различных аспектов работы библиотеки, включая корректность, производительность и обработку ошибок.
6. Провести тестирование разработанной библиотеки, убедившись в ее правильной работе на различных входных данных.
7. Составить подробный отчет, включая описание решения задачи, архитектуры библиотеки, результаты тестирования и выводы.

## Список используемых понятий:
1. **Множество** — набор, совокупность каких-либо объектов
2. **Мультимножество**   — модификация понятия множества, допускающая включение одного и того же элемента в совокупность по нескольку раз.
3. **Симметрическая разность** — это теоретико-множественная операция, результатом которой является новое множество, включающее все элементы исходных множеств, не принадлежащие одновременно обоим исходным множествам.




## <p align="center">Описание используемых алгоритмов:</p>
1. **Структура множеств/мультимножеств**
Эта структура является представлением множеств/мультимножеств на бинарном дереве.
```cpp
template <typename T>
struct Node {
    T data;

    int count;

    Node* left;

    Node* right;
};
```
2. **Алгоритм обхода и вывода элементов множества**
```cpp
template<typename T>
void inorder(Node<T>* r)
{
    if (r == NULL) {
        return;
    }
    inorder(r->left);
    for (int i = 0; i < r->count; ++i) {
        cout << r->data << ", ";
    }
    inorder(r->right);
}
```
3. **Алгоритм проверки на нахождение элемента во множестве**
```cpp
template<typename T>
int containsNode(Node<T>* r, T d)
{
    if (r == NULL) {
        return 0;
    }
    int x = r->data == d ? r->count : 0;
    return x + containsNode(r->left, d) + containsNode(r->right, d);
}
```
4.**Алгоритм вставки элемента во множество**
```cpp
template<typename T>
Node<T>* insert(Node<T>* r, T d)
{
    if (r == NULL) {
        Node<T>* tmp = new Node<T>;
        tmp->data = d;
        tmp->count = 1;
        tmp->left = tmp->right = NULL;
        return tmp;
    }

    if (d < r->data) {
        r->left = insert(r->left, d);
    }
    else if (d > r->data) {
        r->right = insert(r->right, d);
    }
    else {
        r->count++;
    }
    return r;
}
```
5.**Алгоритм вычисления размера множества**
```cpp
template<typename T>
int getSize(Node<T>* root)
{
    if (root == nullptr)
        return 0;
    return getSize(root->left) + getSize(root->right) + root->count;
}
```




6. **Алгоритм считывания из файла**
   
   Этот алгоритм добавляет множества из файла в структуру с помощью функции `insert`.
```cpp
void addFromFile(Node<T>*& root, const string& filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename <<endl;
        return;
    }

    T element;
    while (file >> element) {
        // Removing trailing comma if present
        if (element[element.size() - 1] == ',')
            element = element.substr(0, element.size() - 1);
        root = insert(root, element);
    }

    file.close();
}
```
7. **Вывод множеств на экран**
   Вывод множества с помощью функции `inorder`.
```cpp
template<typename T>
void displaySet(Node<T>* root)
{
    cout << "{ ";
    inorder(root);
    cout << "}" << endl;
}
```

8. **Алгоритм симметрической разности**
```cpp
Node<T>* symmetricDifference(Node<T>* root1, Node<T>* root2)
{
    stack<Node<T>*> nodeStack1;
    nodeStack1.push(root1);
    stack<Node<T>*> nodeStack2;
    nodeStack2.push(root2);

    Node<T>* diff = nullptr;

    while (!nodeStack1.empty()) {
        Node<T>* node1 = nodeStack1.top();
        nodeStack1.pop();

        int diffCount = node1->count - containsNode(root2, node1->data);
        for (int i = 0; i < diffCount; ++i) {
            diff = insert(diff, node1->data);
        }

        if (node1->right)
            nodeStack1.push(node1->right);
        if (node1->left)
            nodeStack1.push(node1->left);
    }

    while (!nodeStack2.empty()) {
        Node<T>* node2 = nodeStack2.top();
        nodeStack2.pop();

        int diffCount = node2->count - containsNode(root1, node2->data);
        for (int i = 0; i < diffCount; ++i) {
            diff = insert(diff, node2->data);
        }

        if (node2->right)
            nodeStack2.push(node2->right);
        if (node2->left)
            nodeStack2.push(node2->left);
    }

    return diff;
}
```

*****
## <p align="center">Тесты:</p>
![результат тестов]()
******
## <p align="center">Вывод:</p>
В ходе выполнения работы познакомился с понятием "Множество" и операцией над множествами "Симметрическая разность. Создал библиотеку, реализующую структуру данных множество и выполняющую операцию симметрической разности.Также была создана тестовая программа, демонстрирующая работоспобность библиотеки

## <p align="center">Используемые источники:</p>
1. [Создание библиотеки](https://www.youtube.com/watch?v=pAxEfF2yVlM&t=1s)
2. [Считывание из файла](https://youtu.be/CBnB2fvfu_I?si=9NhPBXS0RgMw2gTC)
3. [Помощь в реализации множества](https://www.geeksforgeeks.org/implementing-sets-without-c-stl-containers/)
****
