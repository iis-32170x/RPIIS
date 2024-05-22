# Лабораторная работа №2

- `Цель` - нахождение объединения(без учета кратных вхождений)
- `Задача` - реализовать алгоритм объединения исходных множеств
- `Вариант` - $\textcolor{grey}{\textit{1}}$

## Список ключевых понятий (определения)

- `Объединение множеств` - это множество элементов, принадлежщих множеству A, или множеству B, или обоим множествам.

- `Элментом множества` может являться число, кортеж, отдельное множество, сочетание буквы и числа.

## Алгоритм

В данном коде используется алгоритм объединения множеств. Он выполняется следующим образом:

-Открывается файл с указанным путем.

-Инициализируются переменные, включая пустое множество result, флаг firstSet для отслеживания первого множества.

-Читается каждая строка из файла.

-Строка подвергается обрезке пробельных символов с помощью функции trim().

-Если строка содержит символ <, то она представляет собой кортеж множества. Внутри цикла происходит сборка элементов кортежа до тех пор, пока не встретится символ >. Затем собранный кортеж добавляется в текущее множество currentSet.

-Если строка не является кортежем, то элементы разделяются по запятой и добавляются в currentSet.

-Если это первое множество, оно становится результатом result.

-Если это не первое множество, происходит объединение текущего множества currentSet с предыдущим результатом result. Результат объединения сохраняется в union_sets.

-После обработки всех строк в файле, результат пересечения union_sets становится новым значением result.

-Файл закрывается, и возвращается итоговое пересечение множеств в виде result.

### Функция trim(const string& str):

```c++
string trim(const string& str) {
    string result = str;

    size_t start = result.find_first_not_of(" \t\n\r");
    size_t end = result.find_last_not_of(" \t\n\r");
    if (start == string::npos || end == string::npos) {
        return "";
    }
    result = result.substr(start, end - start + 1);

    size_t pos = result.find(" ");
    while (pos != string::npos) {
        result.erase(pos, 1);
        pos = result.find(" ", pos);
    }

    return result;
}
}
```

### Функция union_sets(const string& file_path) :

```c++
set<string> union_sets(const string& file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл.";
        exit(-1);
    }

    string line;
    set<string> result;

    while (getline(file, line)) {
        line = trim(line);
        line = line.substr(3, line.length() - 4);

        set<string> currentSet;
        string element;
        line += ',';
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '{') {
                int end = find_next_bracker(line, i) - 1;
                i++;
                string str = line.substr(i, end - i + 1);
                currentSet.insert(sets(str));
                i = end + 2;
                element = "";
                continue;
            }
            if (line[i] == '<') {
                int end = find_next_bracker(line, i) - 1;
                i++;
                string str = line.substr(i, end - i + 1);
                currentSet.insert(corteges(str));
                i = end + 2;
                element = "";
                continue;
            }

            if (line[i] != ',') {
                element += line[i];
            }
            else {
                currentSet.insert(element);
                element = "";
            }
        }

        for (const string& elem : currentSet) {
            result.insert(elem);
        }
    }
```

## Вывод

Реализовала программу, которая выполняет объединение множеств и возвращает итоговое объединение.

