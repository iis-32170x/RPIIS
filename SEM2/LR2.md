# Лабораторная работа №2

- `Цель` - нахождение пересечения множеств(с учетом кратных вхождений)
- `Задача` - реализовать алгоритм пересечения исходных множеств
- `Вариант` - $\textcolor{grey}{\textit{11}}$

## Список ключевых понятий (определения)

- `Пересечение множеств` - это множество, которому принадлежат те и только те элементы, которые одновременно принадлежат всем данным множествам.

- `Элментом множества` может являться число, кортеж, отдельное множество, сочетание буквы и числа.
- `Множество` - простейшая информационная конструкция и математическая структура,
позволяющая рассматривать какие-то объекты как целое, связывая их.

## Пояснение работы


## функции 

### `display(vector<Element> elements)`
Эта функция отвечает за вывод количества и имени элемента для каждого объекта Element в векторе

### `getMin(Element a, Element b)`
Эта функция отвечает за сравнение двух элементов. 

### `processCount(Element* element)`
Эта функция отвечает за извлечение чисел из строки. 


### `parseElements(string str, vector<Element>* result)`
Эта функция отвечает за разбиение строки.

---

## Тесты 

![Img1](https://github.com/iis-32170x/RPIIS/blob/Ходосов_Т/SEM2/one.png)
![Img1](https://github.com/iis-32170x/RPIIS/blob/Ходосов_Т/SEM2/two.png)
![Img1](https://github.com/iis-32170x/RPIIS/blob/Ходосов_Т/SEM2/thr.png)
![Img1](https://github.com/iis-32170x/RPIIS/blob/Ходосов_Т/SEM2/fou.png)
## Код программы
```
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Element {
    string elementName;
    int count = 0;
};


void display(vector<Element> elements) {
    if (!elements.empty()) {
        cout << "{ ";
        for (int i = 0; i < elements.size(); ++i) {
            if (i != elements.size() - 1) {
                cout << elements[i].count << elements[i].elementName << ", ";
            }
            else {
                cout << elements[i].count << elements[i].elementName << " }" << endl;
            }
        }
    }
}

int getMin(Element a, Element b) {
    return a.count >= b.count ? b.count : a.count;
}

string processName(Element* element) {
    string newName;
    bool digitsFinished = false;
    for (int i = 0; i < (*element).elementName.size(); ++i) {
        if (digitsFinished == true)
        {
            newName += (*element).elementName[i];
        }

        if (!isdigit((*element).elementName[i]) && digitsFinished == false) {
            newName += (*element).elementName[i];
            digitsFinished = true;
        }
    }

    (*element).elementName = newName;
    return newName;
}

int processCount(Element* element) {
    int count = 0;
    vector<int> numbers;
    for (int i = 0; isdigit((*element).elementName[i]) && i < (*element).elementName.length(); ++i) {
        numbers.push_back(static_cast<int>((*element).elementName[i]) - '0');
    }
    for (int i = 0; i < numbers.size(); ++i) {
        count += numbers[i] * (int)pow(10, numbers.size() - 1 - i);
    }
    return count;
}

int countElements(string str)
{
    int totalElements = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ',' || str[i] == '{' || str[i] == '<')
        {
            i++;
            int j = i;
            int unclosedSets = 0;
            totalElements++;
            string foundElement;
            while (str[j] != ',' && str[j] != '}' && str[j] != '>')
            {
                if (((str[j] == '{' && (str[j - 1] == ',' || str[j - 1] == '{')) || (str[j] == '<' && (str[j - 1] == ',' || str[j - 1] == '{'))))
                {
                    do
                    {
                        if (str[j] == '{' || str[j] == '<')
                            unclosedSets++;
                        else if (str[j] == '}' || str[j] == '>')
                            unclosedSets--;
                        foundElement += str[j];
                        j++;

                    } while ((str[j - 1] != '}' && str[j - 1] != '>') || unclosedSets != 0);
                    break;
                }
                foundElement += str[j];
                j++;
            }
            i = j - 1;
        }
    }
    return totalElements;
}

void parseElements(string str, vector<Element>* result)
{
    int totalElements = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ',' || str[i] == '{' || str[i] == '<')
        {
            i++;
            int j = i;
            int unclosedSets = 0;
            string foundElement;

            while (str[j] != ',' && str[j] != '}' && str[j] != '>')
            {
                if (((str[j] == '{' && (str[j - 1] == ',' || str[j - 1] == '{' || isdigit(str[j - 1]) || str[j - 1] == '<')) || (str[j] == '<' && (str[j - 1] == ',' || str[j - 1] == '{' || isdigit(str[j - 1]) || str[j - 1] == '<'))))
                {
                    do
                    {
                        if (str[j] == '{' || str[j] == '<')
                            unclosedSets++;
                        else if (str[j] == '}' || str[j] == '>')
                            unclosedSets--;
                        foundElement += str[j];
                        j++;

                    } while ((str[j - 1] != '}' && str[j - 1] != '>') || unclosedSets != 0);
                    break;
                }
                foundElement += str[j];
                j++;
            }

            (*result)[totalElements].elementName = foundElement;
            (*result)[totalElements].elementName = processName(&(*result)[totalElements]);
            string saveName = (*result)[totalElements].elementName;
            (*result)[totalElements].elementName = foundElement;
            (*result)[totalElements].count = processCount(&(*result)[totalElements]);
            if ((*result)[totalElements].count == 0)
            {
                (*result)[totalElements].count = 1;
            }
            (*result)[totalElements].elementName = saveName;

            foundElement = "";
            i = j - 1;
            totalElements++;
        }
    }
}

bool areEqual(Element first, Element second) {
    if (first.elementName[0] == '<' && second.elementName[0] == '<') {
        vector<Element> p(countElements(first.elementName)), t(countElements(second.elementName));
        parseElements(first.elementName, &p);
        parseElements(second.elementName, &t);
        for (int i = 0; i < p.size(); ++i) {
            bool wasIntersectioned = false;
            for (int k = 0; k < t.size(); ++k) {
                if (p[i].elementName == t[k].elementName && p[i].count == t[k].count && k == i) {
                    p.erase(p.begin() + i);
                    t.erase(t.begin() + k);
                    --k;
                    wasIntersectioned = true;
                }
                else if (areEqual(p[i], t[k]) && k == i) {
                    p.erase(p.begin() + i);
                    t.erase(t.begin() + k);
                    --k;
                    wasIntersectioned = true;
                }
            }
            if (wasIntersectioned == true)  --i;
        }
        return p.size() == 0 && t.size() == 0;
    }
    else if (first.elementName[0] == '{' && second.elementName[0] == '{') {
        vector<Element> p(countElements(first.elementName)), t(countElements(second.elementName));
        parseElements(first.elementName, &p);
        parseElements(second.elementName, &t);
        for (int i = 0; i < p.size(); ++i) {
            bool wasIntersectioned = false;
            for (int k = 0; k < t.size(); ++k) {
                if (p[i].elementName == t[k].elementName && p[i].count == t[k].count) {
                    p.erase(p.begin() + i);
                    t.erase(t.begin() + k);
                    --k;
                    wasIntersectioned = true;
                }
                else if (areEqual(p[i], t[k])) {
                    p.erase(p.begin() + i);
                    t.erase(t.begin() + k);
                    --k;
                    wasIntersectioned = true;
                }
                if (wasIntersectioned == true)  --i;
            }
        }
        return p.size() == 0 && t.size() == 0;
    }
    else {
        return first.elementName == second.elementName;
    }
}

vector<Element> findIntersection(vector<Element> first, vector<Element> second) {
    vector<Element> temp1 = first;
    vector<Element> temp2 = second;
    vector<Element> intersectionResult;

    for (int i = 0; i < temp1.size(); ++i) {
        bool wasIntersectioned = false;
        for (int k = 0; k < temp2.size(); ++k) {
            if (areEqual(temp1[i], temp2[k])) {
                Element p;
                p.elementName = temp1[i].elementName;
                p.count = getMin(temp1[i], temp2[k]);
                intersectionResult.push_back(p);
                temp1.erase(temp1.begin() + i);
                temp2.erase(temp2.begin() + k);
                --k;
                wasIntersectioned = true;
            }
        }
        if (wasIntersectioned == true)  --i;
    }
    return intersectionResult;
}

int main(void) {
    int setCount;
    cout << "enter the value of multisets: ";
    cin >> setCount;
    cin.ignore();

    string inputStr;
    getline(cin, inputStr);

    vector<Element> firstSet(countElements(inputStr));
    parseElements(inputStr, &firstSet);

    for (int i = 1; i < setCount; ++i) {
        getline(cin, inputStr);
        vector<Element> nextSet(countElements(inputStr));
        parseElements(inputStr, &nextSet);
        firstSet = findIntersection(firstSet, nextSet);
        nextSet.clear();
    }

    display(firstSet);

    return 0;
}

```
##Вывод
Реализовал программу, которая находит пересечение множеств и возвращает итоговое пересечение.
