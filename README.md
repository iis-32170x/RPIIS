# Лабороторная работа №1
##   Постановка задачи
1. Разработать библиотеку для работы со структурой данных, указанной в
индивидуальном задании, на любом императивнойм языке
программирования (Pascal, C\C++, Java, C#, Python и др.)
2. Разработать тестовую программу, которая демонстрирует
работоспособность реализованной библиотеки работы со структурой
данных.
3. Разработать систему тестов, которые продемонстрировали бы
работоспособность реализованной библиотеки. Система тестов должна
отвечать требованиям полноты, адекватности и непротиворечивости.
Система тестов должна учитывать не только корректную работу на
правильных данных, но и предусматривать корректное завершение
программы в случае некорректных данных.
4. По результатам выполнения задания составить отчет.
## Условие первой лабораторной работы (Вариант 20)
Дерево сумм. Поиск суммы чисел на отрезке массива. Изменение всех
чисел на отрезке массива на какое-то значение.
 ## Определения и понятия
  Дерево представляет собой набор объектов, называемых узлами. Узлы соединены ребрами. Каждый узел содержит значение или данные, и он может иметь или не иметь дочерний узел.Первый узел дерева называется корнем. Если этот корневой узел соединен с другим узлом, тогда корень является родительским узлом, а связанный с ним узел — дочерним. Лист — узел, не имеющий дочерних узлов на дереве.

  Дерево суммы (Sum Tree) - это структура данных, которая позволяет эффективно решать задачи по работе с отрезками массива или других последовательностей. Оно представляет собой бинарное дерево, в котором каждый узел содержит информацию о сумме значений на определенном отрезке массива. Сумма элементов на отрезке массива - это количество легко считается, как разность правой и левой границы интервала плюс единица.
  ##  *Разбор алгоритмов основных функций*
  ### 1)
   struct Node {
    int l, r;  // Левая и правая границы отрезка
    int sum;   // Сумма чисел на отрезке
    int add;   // Значение, на которое нужно изменить элементы на отрезке
    Node* left;
    Node* right;

    Node(int left, int right) : l(left), r(right), sum(0), add(0), left(nullptr), right(nullptr) {}
}
Структура Node представляет узел дерева и содержит следующие поля:

l и r - левая и правая границы отрезка, соответствующего данному узлу.
sum - сумма чисел на отрезке, задаваемом данным узлом.
add - значение, на которое нужно изменить элементы на отрезке.
left и right - указатели на левого и правого потомка узла.
### 2)
 class SumTree {
private:
    Node* root;

    void buildTree(Node* node, vector<int>& arr) {
        if (node->l == node->r) {
            node->sum = arr[node->l - 1];
            return;
        }

        int mid = (node->l + node->r) / 2;
        node->left = new Node(node->l, mid);
        node->right = new Node(mid + 1, node->r);

        buildTree(node->left, arr);
        buildTree(node->right, arr);

        node->sum = node->left->sum + node->right->sum;
    }

   

public:
    SumTree(vector<int>& arr) {
        int n = arr.size();
        root = new Node(1, n);
        buildTree(root, arr);
    }

}
Класс SumTree реализует операции построения дерева и выполнения запросов на изменение и получение суммы на отрезке. В нём присутствуют следующие методы:

buildTree: рекурсивно строит дерево суммы на основе заданного массива arr.
updateRange: изменяет значения элементов на заданном отрезке [left, right] на значение value.
queryRange: возвращает сумму значений на заданном отрезке [left, right].
propagate: проталкивает изменения значения add по дереву, обновляя суммы значений.
### 3
void modify(int left, int right, int value) {
updateRange(root, left, right, value);
}

int query(int left, int right) {
return queryRange(root, left, right);
} 
Данный участок кода представляет две функции modify и query, которые используются для изменения значений на заданном отрезке и выполнения запроса на получение суммы значений на заданном отрезке соответственно.

  ##  *Пример выполнения*
  #### 1
 <img src="Снимок экрана (35).png">
  #### 2
  <img src="Снимок экрана (36).png">
  #### 3
  <img src="Снимок экрана (37).png">
  В результате выполнения данной работы были получены следующие практические навыки:

+ изучение структуры дерево суммы
+ умение работать с header-файлами
+ изучение базовых алгоритмов для работы со структурами типа дерево суммы
  # Thank you for your attention!
