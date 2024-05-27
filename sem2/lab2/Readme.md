# Лабораторная работа №2

- `Цель` - 13. Реализовать программу, формирующую множество равное разности двух исходных
множеств (с учётом кратных вхождений элементов).
- `Вариант` - $\textcolor{grey}{\textit{13}}$

## Список ключевых понятий (определения)

- `Разность двух множеств` -  теоретико-множественная операция, результатом которой является множество, в которое входят все элементы первого множества, не входящие во второе множество.

- `Элментом множества` может являться число, кортеж, отдельное множество, сочетание буквы и числа.

## Алгоритм

## Сегодня я узнал: Разность множеств с вложенными множествами

Эта программа принимает на вход два множества, `A` и `B`, представленные в виде строк, где элементы разделены запятыми, а вложенные множества заключены в фигурные скобки. Например: `{1, 2, {3, 4}, 5}`.

## Функции

### `parseString(str, start, finish)`

Эта функция анализирует входную строку и преобразует ее в вектор строк, где каждый элемент вектора представляет отдельный элемент множества. Она корректно обрабатывает вложенные множества.

### `vectorToString(set)`

Эта функция выполняет обратную операцию: принимает вектор строк и преобразует его в строковое представление множества.

### `sortNestedSets(nestedSet)`

Эта функция сортирует элементы вложенного множества в лексикографическом порядке. Она рекурсивно обрабатывает вложенные множества внутри вложенных множеств.

### `setDifference(set1, set2)`

Эта функция вычисляет разность между множествами `A` и `B`, то есть находит все элементы, которые принадлежат `A`, но не принадлежат `B`. Она использует следующий алгоритм:

1. Создается вспомогательная структура данных `unordered_map`, где ключами являются элементы множества `B`, а значениями - количество вхождений этого элемента в `B`.
2. Для каждого элемента `x` из множества `A` выполняются следующие действия:
   - Если `x` является вложенным множеством, то оно сортируется с помощью `sortNestedSets`, и программа проверяет, есть ли такое же вложенное множество в `B`. Если есть, то счетчик вхождений этого вложенного множества в `B` уменьшается на 1.
   - Если `x` не является вложенным множеством, то программа проверяет, есть ли такой же элемент в `B`. Если есть, то счетчик вхождений этого элемента в `B` уменьшается на 1.
   - Если счетчик вхождений элемента `x` в `B` стал равен 0, то `x` добавляется в результирующее множество разности.

### `main()`

В функции `main` происходит чтение содержимого файлов `input_A.txt` и `input_B.txt`, которые содержат строковое представление множеств `A` и `B` соответственно.

Вызываются функции `parseString` для преобразования строк в векторы строк, `vectorToString` для вывода исходных множеств, `setDifference` для нахождения разности множеств, и результат выводится на экран.

Таким образом, программа корректно обрабатывает вложенные множества и вычисляет их разность, учитывая кратность элементов во втором множестве.

### Код реализации для разности

```c++


void checkForBrackets(const std::string& str)
{
    int curlyB = 0;
    int tupleB = 0;
    for (char ch : str)
    {
        if (ch == '{') curlyB++;
        else if (ch == '}') curlyB--;
        else if (ch == '<') tupleB++;
        else if (ch == '>') tupleB--;
    }

    if (curlyB > 0 || tupleB > 0)
    {
        throw std::runtime_error("Не удалось разобрать: есть незакрытые скобки");
    }

    if (curlyB < 0 || tupleB < 0)
    {
        throw std::runtime_error("Не удалось разобрать: есть нераскрытые скобки");
    }
}

std::vector<std::string> parseString(std::string str, const int start, int finish)
{
    if (finish == -1)
    {
        finish = str.size() - 1;
    }

    if (str[start] != '{')
    {
        throw std::runtime_error("Не удалось проанализировать: нет открывающейся скобки в " + std::to_string(start));
    }

    if (str[finish] != '}')
    {
        throw std::runtime_error("Не удалось проанализировать: нет закрывающей скобки в " + std::to_string(finish));
    }

    checkForBrackets(str);

    // Удаляем пробелы
    str.erase(
        std::remove_if(
            str.begin(), str.end(), [](char ch) { return ch == ' '; }
        ), str.end()
    );

    // Удаляем внешние скобки из строки
    str = str.substr(1, str.size() - 2);

    std::string content;
    std::vector<std::string> elements;
    int depth = 0;
    for (int i = 0; i <= str.size(); i++)
    {
        if (str[i] == '<' || str[i] == '{')
        {
            depth++;
            content += str[i];
        }
        else if (str[i] == '>' || str[i] == '}')
        {
            depth--;
            content += str[i];
        }
        else if (depth != 0 || (str[i] != ',' && str[i] != '\0'))
        {
            content += str[i];
        }
        else
        {
            elements.emplace_back(content);
            content = "";
        }
    }

    return elements;
}

std::string vectorToString(std::vector<std::string> set)
{
    std::string str = "{";

    for (int i = 0; i < set.size(); i++)
    {
        str += set[i];
        if (i != set.size() - 1)
        {
            str += ", ";
        }
    }
    str += "}";
    return str;
}

std::string sortNestedSets(const std::string& nestedSet)
{
    std::string sortedSet = nestedSet;
    sortedSet.erase(std::remove(sortedSet.begin(), sortedSet.end(), '{'), sortedSet.end());
    sortedSet.erase(std::remove(sortedSet.begin(), sortedSet.end(), '}'), sortedSet.end());

    std::vector<std::string> elements;
    std::stringstream ss(sortedSet);
    std::string item;
    while (std::getline(ss, item, ','))
    {
        elements.push_back(item);
    }

    // Рекурсивная сортировка элементов вложенных множеств
    for (auto& element : elements)
    {
        if (element.substr(0, 1) == "{" && element.substr(element.length() - 1, 1) == "}")
        {
            element = sortNestedSets(element);
        }
    }

    // Удаляем пустые множества из элементов
    elements.erase(std::remove_if(elements.begin(), elements.end(),
        [](const std::string& element)
        {
            return element.empty();
        }),
        elements.end());

    std::sort(elements.begin(), elements.end());

    sortedSet = "{";
    for (const auto& element : elements)
    {
        sortedSet += element + ",";
    }
    sortedSet.pop_back();
    sortedSet += "}";

    return sortedSet;
}

std::vector<std::string> setDifference(const std::vector<std::string>& set1, const std::vector<std::string>& set2)
{
    std::unordered_map<std::string, int> countMap;

    for (const auto& elem : set2)
    {
        countMap[elem]++;
    }

    std::vector<std::string> difference;

    for (const auto& elem : set1)
    {
        if (elem.substr(0, 1) == "{" && elem.substr(elem.length() - 1, 1) == "}")
        {
            bool isSubset = false;
            std::string sortedElem = sortNestedSets(elem);

            for (const auto& subsetElem : set2)
            {
                if (subsetElem.substr(0, 1) == "{" && subsetElem.substr(subsetElem.length() - 1, 1) == "}")
                {
                    std::string sortedSubsetElem = sortNestedSets(subsetElem);

                    if (sortedElem == sortedSubsetElem && countMap[subsetElem] > 0)
                    {
                        countMap[subsetElem]--;
                        isSubset = true;
                        break;
                    }
                }
            }

            if (!isSubset)
            {
                difference.push_back(elem);
            }
        }
        else
        {
            if (countMap[elem] > 0)
            {
                countMap[elem]--;
            }
            else
            {
                difference.push_back(elem);
            }
        }
    }

    return difference;
}
```

## Вывод

Реализовал программу, которая выполняет разность двух множеств с учетом их кратности
