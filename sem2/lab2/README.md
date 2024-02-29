# Лабораторная работа №2



- `Цель` - Реализовать программу, формирующую множество равное разности двух исходных
  множеств (без учёта кратных вхождений элементов).
- `Задача` - реализовать алгоритм разности
- `Вариант` - 4

## Список ключевых понятий (определения) ❓
- ` Множество`  - это любая определенная совокупность объектов. Объекты, из которых составлено множество, называются его элементами. Элементы множества различны и отличны друг от друга.
- `Разность множеств A и B ` - это множество, которое состоит из тех элементов, которые одновременно принадлежат множеству A и не принадлежат множеству B.
## Алгоритм
Дя того, чтоб посчитать разность n-ого количества множеств, нужно чтоб в нашу функцию разности передавалосись значения элементов всех множеств.
Поэтому для начала нам нужно считать из файла все наши множества(проверяя корректность их), извлечь содержимое каждого множества, разделить каждое множество на элементы. И, внимание, передать эти элементы в в функцию, которая высчитывает разность  
## Реализация алгоритма

### Считывание из файла + проверка на корректность входных данных

``` C++
vector<string> getSets(string inputpath) {
    fin.open(inputpath);
    if (!fin.is_open())
        cout << "Error while opening file (" + inputpath + ")!" << endl; //объединение с ошибкой
    vector<string> sets; //добавляться строки, представляющие множества.
    int line = 0; //Создается переменная line, которая будет использоваться для отслеживания номера строки в файле.
    while (!fin.eof()) {
        line++;
        string buff;
        getline(fin, buff); // считывает строку из файла и сохраняет ее в переменной buff.
        cout << buff << endl;
        if ((buff[2] == '{') && (buff[1] == '=') && (buff[buff.length() - 1] == '}')) {
            int opens = 0;
            int closes = 0;
            for (int i = 0; i < buff.length(); i++) { //подсчитывается, чтоб кол-во скобок было правильное
                if (buff[i] == OPENSET_SYMBOL)
                    opens++;
                if (buff[i] == CLOSESET_SYMBOL)
                    closes++;
            }
            if (opens != closes) { //проверяет, совпадает ли количество открывающих и закрывающих скобок в строке. Если нет, выводится сообщение об ошибке
                cout << "Check input for correctness! Line: " + to_string(line) + ", File: " + inputpath << endl; //, плюсики используются для конкатенации (соединения) строк и чисел
                cout << "Number of '{' is not equal to number of '}'" << endl;
                exit(0);
            }
            sets.push_back(buff); //используется для добавления строки buff в конец вектора sets.
        }
        else {
            cout << "Check input for correctness! Line: " + to_string(line) + ", File: " + inputpath << endl;
            exit(0);
            break;
        }
    }
    return sets;
}
```

### Извлечение содержимого каждого множества из вектора sets и сохранения этого содержимого

``` c++

vector<string> saveFillPlenty(vector<string> sets) {
    int numSets = sets.size(); //определяет размер, кол-во множеств
    vector<string> fillPlenty(numSets); //хранить содержимое каждого множества.
    for (int i = 0; i < numSets; i++) {
        fillPlenty[i] = sets[i].substr(2, sets[i].length() - 3); //substr() используется для извлечения подстроки из строки.
    }
    return fillPlenty;
}
```

### Разделение множеств на отдельные элементы


``` c++
vector<vector<string>> splitSets(vector<string> sets, char delimiter) {
    int numSets = sets.size();
    vector<vector<string>> elements(numSets); //Создает двумерный вектор строк elements с размером, равным количеству множеств в sets.
    // Каждый внутренний вектор будет хранить отдельные элементы множества.
    for (auto i = 0; i < numSets; i++) {
        string buff;

        buff = sets[i].substr(3, sets[i].length() - 4); // Изменено с учетом символов { и }
        stringstream ss(buff); //Создается строковый поток ss, который позволит разбивать строку buff на элементы.
        string token; //для временного хранения элементов множества
        string element = ""; //хранения строки элементов множества.
        int setOpened = 0; //отслеживания, сколько раз открывается множество
        while (getline(ss, token, delimiter)) {
            element += token + ',';
        }
        element.pop_back(); // Убираем лишнюю запятую в конце строки
        stringstream element_ss(element);
        while (getline(element_ss, token, ',')) {
            elements[i].push_back(token); // Добавляем элементы вектора
        }
    }
```

### Разность всех данных множеств

``` c++
vector<string> setDifference(const vector<string>& set1, const vector<string>& set2) {
    vector<string> result;

    // Копируем все элементы из первого множества
    result = set1;

    // Удаляем элементы второго множества из результата
    for (const auto &elem : set2) {
        auto it = find(result.begin(), result.end(), elem);
        if (it != result.end()) {
            result.erase(it);
        }
    }

    return result;
}
```
## Пример запуска
При таких входных данных(как пример):
<img width="1728" alt="Снимок экрана 2024-02-29 в 13 02 33" src="https://github.com/iis-32170x/RPIIS/assets/145375460/2bc7a83e-d39a-48ba-bee1-b18b1e7ed46e">


Программа работает корректно:

<img width="1728" alt="Снимок экрана 2024-02-29 в 13 02 22" src="https://github.com/iis-32170x/RPIIS/assets/145375460/a922f753-2066-43d7-839e-9235748ebedf">


## Тесты
Тесты были пройдено успешно:
<img width="1728" alt="Снимок экрана 2024-02-29 в 13 04 19" src="https://github.com/iis-32170x/RPIIS/assets/145375460/96b9f441-9bad-49b4-9805-53f68f7fc836">

<img width="1728" alt="Снимок экрана 2024-02-29 в 13 04 37" src="https://github.com/iis-32170x/RPIIS/assets/145375460/d853f263-f973-46d2-8598-9dd35ac94bef">


## Вывод
Реализовал алгоритм `симметрической разности`
## Источники
В ходе лабораторной работы никакие источники не были использованы
