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
1. Функция readSetsFromUser запрашивает у пользователя количество множеств и их содержимое. Пользователю предлагается ввести количество множеств, затем для каждого множества вводится его мощность (количество элементов) и сами элементы. Введенные множества сохраняются в векторе множеств и возвращаются из функции.
``` C++
vector<set<int>> readSetsFromUser() {
    int numSets;
    cout << "Количество множеств: ";
    cin >> numSets;
    vector<set<int>> sets;
    for (int i = 0; i < numSets; ++i) {
        int setSize;
        cout << "Мощность множества " << (i + 1) << ": ";
        cin >> setSize;
        set<int> s;
        int num;
        cout << "Введите элементы множества " << (i + 1) << " разделенные пробелами: ";
        for (int j = 0; j < setSize; ++j) {
            cin >> num;
            s.insert(num);
        }
        sets.push_back(s);
    }
    return sets;
}
``` 

2. Функция calculateSetDifference вычисляет разность между множествами. Она принимает вектор множеств и находит разность между первым множеством и остальными. Для этого она создает копию первого множества и удаляет из него элементы, которые присутствуют в остальных множествах. Результат сохраняется в виде множества и возвращается из функции.
``` C++
set<int> calculateSetDifference(const vector<set<int>>& sets) {
    if (sets.empty()) {
        return {};
    }
    set<int> result = sets[0];
    for (size_t i = 1; i < sets.size(); ++i) {
        for (int num : sets[i]) {
            result.erase(num);
        }
    }
    return result;
}
```

3. Основная функция main вызывает readSetsFromUser для получения множеств от пользователя. Затем она проверяет, что было введено как минимум два множества, и если это не так, выводит сообщение об ошибке. Если все в порядке, основная функция вызывает calculateSetDifference для вычисления разности между множествами и выводит результат в консоль.
``` C++
int main() {
    setlocale(LC_ALL, "Russian");
    vector<set<int>> sets = readSetsFromUser();
    if (sets.size() < 2) {
        cerr << "Необходимо минимум два множества" << endl;
        return 1;
    }
    set<int> difference = calculateSetDifference(sets);
    cout << "Разность множеств: ";
    for (int num : difference) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
``` 
Программа предусматривает обработку ошибок при вводе данных пользователем, например, если было введено менее двух множеств, программа выведет сообщение об ошибке.

## Вывод
Реализовал алгоритм `симметрической разности`
## Источники
В ходе лабораторной работы никакие источники не были использованы








