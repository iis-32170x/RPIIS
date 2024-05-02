# Лабораторная работа №2

## Задача:
$\textcolor{#4b0082}{\textit{Вариант 11}}$ Реализовать программу, формирующую множество равное пересечению произвольного
количества исходных множеств (с учётом кратных вхождений элементов).
## Цель:
* Исследовать свойства структур данных и разработать библиотеку алгоритмов обработки структур данных (для нахождения симм разности мультимножеств, считанных из файла).
* Разработать Гугл Тесты, которые проверяют успешное выполнение всех функций

## Список ключевых понятий:
* $\textcolor{#4b0082}{\textbf{Множество}}$ — простейшая информационная конструкция и математическая структура,
позволяющая рассматривать какие-то объекты как целое, связывая их.
* $\textcolor{#4b0082}{\textbf{Мультимножество (множество с учётом кратных вхождений элементов}}$ модификация понятия множества, допускающая включение одного и того же элемента в совокупность по нескольку раз. Число элементов в мультимножестве, с учётом повторяющихся элементов, называется его размером или мощностью.различаются не более, чем на единицу.
* $\textcolor{#4b0082}{\textbf{Пересечение}}$ - это множество, которому принадлежат те и только те элементы, которые одновременно принадлежат всем данным множествам.

![image](https://github.com/iis-32170x/RPIIS/assets/144939580/accadbf4-9f33-4ebf-998a-83f19273dff1)

## Алгоритмы операций над множествами

### Считывание множеств из файла

* Если файл указан некорректно или  его не существует, вылетает сообщение "Ошибка открытия файла!" и выполнение программы завершается (связано с функцией запуска программы ниже)).
``` c++
//-----------------------------------------ЧИТАЕМ_ФАЙЛИК---------------------------------------------------

vector<string> SetRecord(string path) {
    f.open(path);
    if (!f.is_open())
        cout << "Error while opening file!" << endl;
    vector<string> sets;
    int line = 0;
    while (!f.eof()) {
        line++;
        string buff;
        getline(f, buff);
        cout << buff << endl;
        if ((buff[2] == '{') && (buff[1] == '=') && (buff[buff.length() - 1] == '}')) {
            int open = 0;
            int close = 0;
            for (int i = 0; i < buff.length(); i++) {
                if (buff[i] == OPENSET_SYMBOL)
                    open++;
                if (buff[i] == CLOSESET_SYMBOL)
                    close++;
            }
            if (open != close) {
                cout << "Check input for correctness!" << endl;
                cout << "Number of '{' is not equal to number of '}'" << endl;
                exit(0);
            }
            sets.push_back(buff);
        }
        else {
            cout << "Check input for correctness!" << endl;
            exit(0);
            break;
        }
    }
    return sets;
}
```

###  Забираем имена множеств 

``` c++
//-----------------------------------------ЗАБИРАЕМ_ИМЕНА---------------------------------------------------

vector<string> CopyingNames(vector<string> sets) {
    int numberSets = sets.size();
    vector<string> Names_of_sets(numberSets);
    for (int i = 0; i < numberSets; i++) {
        Names_of_sets[i] = sets[i][0];
    }
    return Names_of_sets;
}
```

### Читаем множества полностью


``` c++
//--------------------------------------------ЧИТАЕМ_МНОСТВА------------------------------------------------

vector<string> FullRecord(vector<string> sets) {
    int numberSets = sets.size();
    vector<string> FULLset(numberSets);
    for (int i = 0; i < numberSets; i++) {
        FULLset[i] = sets[i].substr(2, sets[i].length() - 3);
    }
    return FULLset;
}

```


### Выделяем элементы в каждом множестве


``` c++
//--------------------------------------------ВЫДЕЛЯЕМ_ЭЛЕМЕНТЫ------------------------------------------------

vector<vector<string>> MakeElements(vector<string> sets, char delimiter) {
    int numberSets = sets.size();
    vector<vector<string>> elements(numberSets);
    for (auto i = 0; i < numberSets; i++) {
        string buff;

        buff = sets[i].substr(3, sets[i].length() - 4); // убираем скобки
        stringstream potok(buff); //для разбиения строки на отдельные токены с использованием разделителя
        string token;
        string element = "";
        int setOpened = 0;
        while (getline(potok, token, delimiter)) { //до тех пор, пока из потока potok можно извлечь следующий токен
            element += token + DELIMITER_SYMBOL;
        }
        element.pop_back(); //строка
        stringstream element_potok(element);
        while (getline(element_potok, token, DELIMITER_SYMBOL)) {
            elements[i].push_back(token); //вектор
        }
    }

    vector<string> Names = CopyingNames(sets);
    vector<string> FULLMN = FullRecord(sets);
    int numSetsName = Names.size();
    for (int i = 0; i < numberSets; i++) {                          //проверка наличия совпадений между элементами каждого подмножества 
        for (int k = 0; k < elements[i].size(); k++) {              //и именами вектора Nsmes. Если найдено совпадение 
            for (int j = 0; j < numSetsName; j++) {                 //и это не текущий индекс, то элемент заменяется 
                if ((Names[j] == elements[i][k]) && (j != i)) {     //на соответствующий элемент из вектора FULLMN.
                    elements[i][k] = FULLMN[j];
                }
            }
        }
    }
    return elements;
}
```

### Пересечение
   

``` c++
//--------------------------------------------НАХОДМ_ПЕРЕСЕЧЕНИЕ------------------------------------------------

vector<string> Intersection(const vector<string>& set1, const vector<string>& set2) {
    vector<string> result;

    for (const auto& elem : set1) {
        if (find(set2.begin(), set2.end(), elem) != set2.end()) {
            result.push_back(elem);
        }
    }

    return result;
}
``` 
### Оформляем красивый вывод и запускаем все функции


``` c++
string Improove(const vector<string>& set) {
    string result(1, OPENSET_SYMBOL);

    for (int i = 0; i < set.size(); i++) {
        result += set[i];
        if (i != set.size() - 1) {
            result += DELIMITER_SYMBOL;
        }
    }
    result += CLOSESET_SYMBOL;
    return result;
}

string Start(vector<string> sets) {
    CopyingNames(sets);

    vector<vector<string>> elements;
    elements = MakeElements(sets, DELIMITER_SYMBOL);

    if (elements.size() < 2) {
        cout << "Error: Need at least two sets to compute intersection!" << endl;
        return "";
    }

    vector<string> result = Intersection(elements[0], elements[1]);

    cout << "\nIntersection: ";
    cout << Improove(result) << endl;
    return Improove(result);
    f.close();
}

#endif
```
### работу прграммы проверяем на тестах

![image](https://github.com/iis-32170x/RPIIS/assets/144939580/138228c6-aa54-4aa6-b571-eb53738bed93)


##  Список использованных источников 

* [Мультимножества](https://ru.wikipedia.org/wiki/%D0%9C%D1%83%D0%BB%D1%8C%D1%82%D0%B8%D0%BC%D0%BD%D0%BE%D0%B6%D0%B5%D1%81%D1%82%D0%B2%D0%BE)
* Л. А. Гладков, В. В. Курейчик, В. М. Курейчик   "Дискретная математика"
* [Обработка исключений](https://learn.microsoft.com/ru-ru/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-170)
* [Считывание из файла](https://purecodecpp.com/archives/2751)

