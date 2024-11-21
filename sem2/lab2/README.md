# Лабораторная работа №2

- `Цель` - нахождение объединения(без учета кратных вхождений)
- `Задача` - реализовать алгоритм объединения исходных множеств
- `Вариант` - $\textcolor{grey}{\textit{1}}$

## Список ключевых понятий (определения)

- `Объединение множеств` - это множество элементов, принадлежщих множеству A, или множеству B, или обоим множествам.

- `Элментом множества` может являться число, кортеж, отдельное множество, сочетание буквы и числа.

## Алгоритм

В данном коде используется алгоритм объединения множеств. Он выполняется следующим образом:

Этот код сначала считывает данные из файла input.txt, представляющие различные множества. Затем он разбирает каждое множество на его отдельные элементы, учитывая вложенные множества и кортежи. После этого он выполняет операцию объединения для каждой пары множеств, используя хэш-таблицу для хранения уникальных элементов. Результатом является строка, представляющая объединение всех множеств, которая выводится на экран.

### Функция vector<string> readSets(const string& path):

```c++
vector<string> readSets(const string& path) {
    ifstream f(path);
    if (!f.is_open()) {
        cout << "Error while opening file!" << endl;
        exit(EXIT_FAILURE);
    }

    vector<string> sets;
    string buff;

    while (getline(f, buff)) {
        size_t found = buff.find('=');
        if (found != string::npos) {
            string dataAfterEqualSign = buff.substr(found + 1);
            int open = 0, close = 0;

            for (char c : dataAfterEqualSign) {
                if (c == '{' || c == '<') open++;
                if (c == '}' || c == '>') close++;
            }

            if (open != close) {
                cout << "Code is wrong" << endl;
                cout << "Count of '{' not = '}'" << endl;
                exit(EXIT_FAILURE);
            }

            sets.push_back(dataAfterEqualSign);
        }
    }

    return sets;
}
```

### Функция string unionSets(vector<string>& set1, vector<string>& set2)  :

```c++
string unionSets(vector<string>& set1, vector<string>& set2) {
    unordered_set<string> unionSet;

    for (const auto& element : set1) {
        unionSet.insert(element);
    }

    for (const auto& element : set2) {
        unionSet.insert(element);
    }

    string result = "{";
    bool isFirstElement = true;

    for (const auto& element : unionSet) {
        if (!isFirstElement) {
            result += ",";
        }
        result += element;
        isFirstElement = false;
    }

    result += "}";
    return result;
}
```

## Вывод

Реализовала программу, которая выполняет объединение множеств и возвращает итоговое объединение.

