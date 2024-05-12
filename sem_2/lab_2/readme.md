# Лабораторная работа №2 (Вариант 9)

- `Цель` - Реализовать программу, определяющую является ли одно, либо оба из двух исходных
множеств подмножеством или элементом другого.

## Список ключевых понятий (определения) ❓
- ` Множество`  - это любая определенная совокупность объектов. Объекты, из которых составлено множество, называются его элементами. Элементы множества различны и отличны друг от друга.
- `Подмножеством` данного множества называется множество, все элементы которого принадлежат данному множеству.

## Алгоритм
# Алгоритм работы программы

1. **Начало программы:**
   - Программа начинается с включения необходимых заголовочных файлов.
   - Устанавливается локаль для корректной работы с русским текстом.

2. **Основная функция `main`:**
   - Создаются переменные:
     - `int c` для выбора способа ввода (1 - вручную, 2 - из файла).
     - `vector<vector<int>> A` и `vector<vector<int>> B` для хранения множеств.

3. **Выбор способа ввода:**
   - Выводится сообщение с просьбой выбрать способ ввода (вручную или из файла).
   - Программа ожидает ввод от пользователя и проверяет его корректность (должно быть введено либо 1, либо 2).

4. **Обработка выбранного способа:**
   - Если выбран ввод из файла (`c == 2`):
     - Запрашивается путь к файлу с данными.
     - Файл открывается для чтения (`ifstream`).
     - Если файл успешно открыт, его содержимое выводится на экран с помощью функции `File`.
     - Файл закрывается после окончания чтения.
   - Если выбран ввод вручную (`c == 1`):
     - Вызывается функция `ADD` для ввода множества `A` и `B` с клавиатуры.

5. **Вывод введенных множеств на экран:**
   - После завершения ввода множеств или чтения из файла, программа выводит на экран введенные множества `A` и `B`.

6. **Проверка на подмножество:**
   - Программа запускает цикл, чтобы проверить каждое множество из `B` на то, является ли оно подмножеством какого-либо множества из `A`.
   - Для этого используется функция `Check`, которая сравнивает элементы множеств на включение одного множества в другое.
   - Если найдено подмножество, устанавливается флаг `check` в `true`.

7. **Вывод результата:**
   - После завершения проверки, программа выводит соответствующее сообщение о том, является ли множество `B` подмножеством какого-либо множества из `A`.

8. **Конец программы:**
   - Программа возвращает 0 и завершает свою работу.


## Код

``` C++
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <sstream>
#include <cctype>

using namespace std;

int input(const string& message) {
    int num;
    cout << message;
    while (!(cin >> num)) {
        cout << "\033[1;31mОшибка ввода! Введите число: \033[0m";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

void ADD(vector<vector<int>>& V) {
    string inputStr;
    cout << "Введите множество в виде {{A1, A2, ...}, {B1, B2, ...}, ...}: ";
    getline(cin, inputStr);

    inputStr = inputStr.substr(1, inputStr.size() - 2);

    vector<int> innerVector;
    stringstream ss(inputStr);
    char ch;
    bool Brackets = false;
    while (ss >> ch) {
        if (ch == '{') {
            innerVector.clear();
            Brackets = true;
        } else if (ch == '}') {
            V.push_back(innerVector);
            Brackets = false;
        } else if (isdigit(ch)) {
            ss.putback(ch);
            int num;
            ss >> num;
            if (Brackets) {
                innerVector.push_back(num);
            } else {
                V.push_back(vector<int>{num});
                if (ss.peek() == ',')
                    ss.ignore();
            }
        }
    }
}

void File(const string& filename) {
    ifstream file(filename); // Открываем файл для чтения

    if (!file.is_open()) {
        cerr << "Невозможно открыть файл." << endl;
        return;
    }

    string line;
    cout << "Содержимое файла " << filename << ":" << endl;
    while (getline(file, line)) { // Читаем файл построчно и выводим на экран
        cout << line << endl;
    }

    file.close();
}

void read(vector<vector<int>>& V, const string& filename) {
    ifstream file(filename);
    string inputStr;
    cout << "Введите множество в виде {{A1, A2, ...}, {B1, B2, ...}, ...}: ";
    getline(cin, inputStr);

    inputStr = inputStr.substr(1, inputStr.size() - 2);

    vector<int> innerVector;
    stringstream ss(inputStr);
    char ch;
    bool Brackets = false;


    cout << "Чтение данных из файла: " << filename << endl;

    string line;
    while (getline(file, line)) {
        inputStr = inputStr.substr(1, inputStr.size() - 2);

        while (ss >> ch) {
            if (ch == '{') {
                innerVector.clear();
                Brackets = true;
            } else if (ch == '}') {
                V.push_back(innerVector);
                Brackets = false;
            } else if (isdigit(ch)) {
                ss.putback(ch);
                int num;
                ss >> num;
                if (Brackets) {
                    innerVector.push_back(num);
                } else {
                    V.push_back(vector<int>{num});
                    if (ss.peek() == ',')
                        ss.ignore();
                }
            }
        }
    }
    cout << "Чтение данных из файла завершено." << endl;
    file.close();
}

bool Check(const vector<int>& A, const vector<int>& B) {
    vector<int> copyA = A;
    vector<int> copyB = B;
    sort(copyA.begin(), copyA.end());
    sort(copyB.begin(), copyB.end());

    return includes(copyA.begin(), copyA.end(), copyB.begin(), copyB.end());
}


int main() {
    setlocale(LC_ALL, "RU");
    int c;
    vector<vector<int>> A;
    vector<vector<int>> B;

    do {
        c = input("Выберите способ ввода (1 - вручную)(2 - из файла): ");
        if (!(c == 1 || c == 2)) {
            cout << "\033[1;31mПовторите ввод: \033[0m";
        }
    } while (!(c == 1 || c == 2));

    cin.ignore();
    if (c == 1) {
        cout << "Ввод множества A:" << endl;
        ADD(A);
        cout << "Ввод множества B:" << endl;
        ADD(B);
    } else if (c == 2) {
        string filename;
        ifstream file;
        bool fileOpened = false;
        do {
            cout << "Введите путь к файлу: ";
            cin >> filename;
            file.open(filename);
            if (!file.is_open()) {
                cout << "\033[1;31mОшибка открытия файла\033[0m" << endl;
            } else {
                fileOpened = true;
            }
        } while (!fileOpened);

        File(filename);
        //read(A, filename);
        //read(B, filename);
        file.close();
    }

    cout << "Результат:" << endl;
    for (const auto& innerVec : A) {
        cout << "{ ";
        for (const auto& num : innerVec) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    cout << "Результат:" << endl;
    for (const auto& innerVec : B) {
        cout << "{ ";
        for (const auto& num : innerVec) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    bool check = false;
    for (const auto& bVector : B) {
        for (const auto& aVector : A) {
            if (aVector.size() == bVector.size()) {
                if (Check(aVector, bVector) || Check(bVector, aVector)) {
                    check = true;
                }
            }
        }
    }

    if (check) {
        cout << "Множество B является подмножеством множества A" << endl;
    } else {
        cout << "Множество B не является подмножеством множества A" << endl;
    }

    return 0;
}
```

## Пример запуска
<img width="754" alt="Снимок экрана 2024-05-12 в 15 51 56" src="https://github.com/iis-32170x/RPIIS/assets/105926921/8ff6500c-6ae7-4698-bd6f-8b2f0e3d07ce">

## Вывод
Разработанная программа успешно выполняет задачу определения того, являются ли исходные множества подмножествами друг друга или содержат их элементы. Это делает программу полезным инструментом для работы с множествами в различных сценариях.
