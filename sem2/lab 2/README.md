# Лабороторная работа №2
##   Постановка задачи
1. Разработать программу для указанного задания, на любом императивном языке
программирования (Pascal, C\C++, Java, C#, Python и др.)
2. Разработать тестовую программу, которая демонстрирует
работоспособность реализованной библиотеки работы со структурой
данных.
4. По результатам выполнения задания составить отчет.
## Условие второй лабораторной работы (Вариант 1)
Реализовать программу, формирующую множество равное объединению произвольного
количества исходных множеств (без учёта кратных вхождений элементов).
 ## Определения и понятия
  Множество – простейшая информационная конструкция и математическая структура,
позволяющая рассматривать какие-то объекты как целое, связывая их.

 Объединение множеств - это операция, которая создает новое множество, содержащее все уникальные элементы из двух или более исходных множеств. В результате объединения множества содержат все элементы из каждого исходного множества, но без повторений.
  ##  *Разбор алгоритмов основных функций*
  ### 1)
  ``` c++
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
```
Функция trim выполняет удаление начальных и конечных пробелов (и других пробельных символов, таких как табуляция, новая строка и возврат каретки) из строки str, а также удаление повторяющихся пробелов внутри строки.

Вот пошаговое объяснение работы функции:

Создается копия строки str и сохраняется в переменной result.
Используя методы find_first_not_of и find_last_not_of, находятся позиции первого и последнего непробельного символа в result.
Если начальная или конечная позиция равна string::npos (константа, обозначающая невалидную позицию), это означает, что строка состоит только из пробельных символов, и функция возвращает пустую строку.
Используя позиции начала и конца, вычленяется подстрока result, несущая только существенные символы.
Ищется первое вхождение символа пробела в result с помощью метода find.
В цикле while проверяется, найден ли символ пробела. Если найден, он удаляется с помощью метода erase. Цикл продолжается, чтобы проверить наличие повторных пробелов.
В конце функции возвращается очищенная строка result.
### 2)
``` c++
int find_next_bracker(const string& s, int i) {
    int cnt = 0;
    if (s[i] == '{') {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[j] == '{') {
                cnt++;
            }
            if (s[j] == '}') {
                if (cnt) {
                    cnt--;
                }
                else {
                    return j;
                }
            }
        }
    }
    else if (s[i] == '<') {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[j] == '<') {
                cnt++;
            }
            if (s[j] == '>') {
                if (cnt) {
                    cnt--;
                }
                else {
                    return j;
                }
            }
        }
    }
}
```
Функция find_next_bracker используется для поиска позиции закрывающей скобки (} или >) соответствующей открывающей скобке ({ или <) в строке s, начиная с позиции i.
### 3
``` c++
string corteges(string s) {
    s += ',';
    string result;
    vector <string> elements;
    string element;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{') {
            int end = find_next_bracker(s, i) - 1;
            i++;
            string str = s.substr(i, end - i + 1);
            elements.push_back(sets(str));
            i = end + 2;
            element = "";
            continue;
        }
        if (s[i] == '<') {
            int end = find_next_bracker(s, i) - 1;
            i++;
            string str = s.substr(i, end - i + 1);
            elements.push_back(corteges(str));
            i = end + 2;
            element = "";
            continue;
        }

        if (s[i] != ',') {
            element += s[i];
        }
        else {
            elements.push_back(element);
            element = "";
        }
    }

    for (string i : elements) {
        result += i + ", ";
    }
    result.erase(result.size() - 2, 2);
    result = '<' + result + '>';
    return result;
}

```
Функция corteges преобразует строку s в формат кортежа и возвращает полученный кортеж в виде строки.
### 4
``` c++
string sets(string s) {
    s += ',';
    string result;
    multiset <string> elements;
    string element;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{') {
            int end = find_next_bracker(s, i) - 1;
            i++;
            string str = s.substr(i, end - i + 1);
            elements.insert(sets(str));
            i = end + 2;
            element = "";
            continue;
        }
        if (s[i] == '<') {
            int end = find_next_bracker(s, i) - 1;
            i++;
            string str = s.substr(i, end - i + 1);
            elements.insert(corteges(str));
            i = end + 2;
            element = "";
            continue;
        }

        if (s[i] != ',') {
            element += s[i];
        }
        else {
            elements.insert(element);
            element = "";
        }
    }

    for (string i : elements) {
        result += i + ", ";
    }
    result.erase(result.size() - 2, 2);
    result = '{' + result + '}';
    return result;
}
```
Функция sets преобразует строку s в формат множества и возвращает полученное множество в виде строки.
### 5
``` c++
multiset<string> unionSets(const string& file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл.";
        exit(-1);
    }

    string line;
    multiset<string> result;  
    bool firstSet = true;

    while (getline(file, line)) {
        line = trim(line);
        line = line.substr(3, line.length() - 4);

        multiset<string> currentSet;
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

        if (firstSet) {
            result = currentSet;
            firstSet = false;
        }
        else {
           
            for (const string& elem : currentSet) {
                result.insert(elem);
            }
        }
    }

    file.close();
    return result;
}
```
Функция unionSets считывает содержимое файла по указанному пути file_path и выполняет объединение множеств, представленных в файле. Она возвращает объединенное множество в виде multiset.

 ##  *Пример выполнения*
  #### 1
  ![image](test2.png)
  #### 2
   ![image](test2.png)
  #### 3
  ![image](test2.png)
  В результате выполнения данной работы были получены следующие практические навыки:

+ повторение теории множеств
+ умение работать с header-файлами
+ изучение базовых алгоритмов для работы с обьединением множеств
  # Thank you for your attention!
