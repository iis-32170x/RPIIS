# Лабораторная работа 2
## Цель
Написать программу, которая реализует функцию *пересечение множеств* с учетом кратных вхождений корней.
## Реализация
Программа использует библиотеки <unordered_map> и <unordered_set> для реализации мультимножеств.
## Листинг кода
```
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
std::unordered_map<int, int> symmetricDifference(const std::unordered_multiset<int>& set1, const std::unordered_multiset<int>& set2)
{
    unordered_map<int, int> result;
    // Подсчитываем кратность элементов в set1 и set2
    unordered_map<int, int> count1, count2;
    for (int element : set1)
    {
        count1[element]++;
    }
    for (int element : set2)
    {
        count2[element]++;
    }
    // Находим разницу в кратности элементов
    for (const auto& pair : count1)
    {
        int element = pair.first;
        int freq1 = pair.second;
        int freq2 = count2[element];
        result[element] = abs(freq1 - freq2);
    }
    for (const auto& pair : count2)
    {
        int element = pair.first;
        int freq2 = pair.second;
        if (count1.count(element) == 0)
        {
            result[element] = freq2;
        }
    }
    return result;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    unordered_multiset<int> set1, set2;
    int n, num;
    cout << "Введите количество элементов 1 мультимножества: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Введите элемент: " << endl;
        cin >> num;
        set1.insert(num);
    }
    cout << "Введите количество элементов 2 мультимножества: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Введите элемент: " << endl;
        cin >> num;
        set2.insert(num);
    }
    unordered_map<int, int> result = symmetricDifference(set1, set2);
    cout << "Симметрическая разность: ";
    for (const auto& pair : result)
    {
        int element = pair.first;
        int freq = pair.second;
        for (int i = 0; i < freq; i++)
        {
            cout << element << " ";
        }
    }
    cout << endl;
    return 0;
}
```
## Пример использования

Введите количество элементов 1 мультимножества: 5

Введите элемент:

1

Введите элемент:

2

Введите элемент:

1

Введите элемент:

0

Введите элемент:

3

Введите количество элементов 2 мультимножества: 5

Введите элемент:

1

Введите элемент:

2

Введите элемент:

6

Введите элемент:

3

Введите элемент:

3

Симметрическая разность: 1 0 3 6

## Вывод
Бвли изучены способы представления и обработки мультимножеств
