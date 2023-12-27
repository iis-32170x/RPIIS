<h1 align="center">Расчетная работа</h1>
<h2 align="left">### Цель</h2>

<h3 align="left">Изучить основы теории графов, способы представления графов, базовые алгоритмы для работы с графами.</h3>
<h2 align="left">###Задание</h2>

<h3 align="left">2. Определить числовую характеристику графа:</h3>
<h3 align="left">14. (2) Число компонентов связности неориентированного графа (список смежности)</h3>
<h2 align="left">Ключевые понятия</h2>
<h3 align="left">Граф- математическая абстракция, представляющая системы любой природы, объекты которых обладают парными связями.</h3>
<h3 align="left">Неориентированными графами- называются графы, в которых все ребра являются звеньями, то есть порядок двух концов ребра графа не существует</h3>
<h3 align="left">писок смежности - это структура данных, используемая для представления графа. Она состоит из списка вершин графа и для каждой вершины содержит список ее смежных вершин.</h3>
<h3 align="left">Числовая характеристика графа - это числовое значение или параметр, который отображает определенные свойства или характеристики графа. Она предоставляет количественную информацию о структуре или свойствах графа.</h3>
<h3 align="left">Компоненты связности в неориентированном графе - это группы вершин, в которых каждая вершина имеет путь до любой другой вершины внутри этой группы. Внутри каждой компоненты связности можно достичь любую вершину из любой другой вершины, используя только ребра графа.</h3>
<h2 align="left">###Алгоритм решения задачи</h2>
<h3 align="left">Рассмотрим возможный пример выполнения по рисунку ниже:</h3>
 <img src="images/5fdb29926c89c057338196.png"/>
 <h3 align="left">№1 Вначале нам нужно задать количество точек (в нашем случае 5)</h3>
 <h3 align="left">№2 Теперь нам нужно узнать между какими точками имеется связь (в нашем случае олна точка может иметь от 1 до 3 связей, или же вообще не иметь)</h3>
 <h3 align="left">№3 Конечная цель-узнать сколько отдельных "кластеров" вершин (связанных подграфов) содержит граф. (в нашем случае 2)</h3>
<h2 align="left">###Реализация</h2>
#include <iostream>

using namespace std;

void FindConnectedDots(bool* matrix, bool* canBeUsedAsBase, int index, int dotCount)
{
    
    for (int i = index + 1; i < dotCount; i++)
    {
        if (matrix[index * dotCount + i] == true)  // Используем одномерный массив для представления двумерной матрицы
        {
            canBeUsedAsBase[i] = false;
            FindConnectedDots(matrix, canBeUsedAsBase, i, dotCount);
        }
    }
}

int main() {
    setlocale(LC_ALL,"RU");
    cout << "Введите количество точек" << endl;
    int dotCount;
    cin >> dotCount;
    bool* matrix;
    bool* canBeUsedAsBase;
    canBeUsedAsBase = new bool[dotCount];
    matrix = new bool[dotCount * dotCount];  // Используем одномерный массив для представления двумерной матрицы
    for (int i = 0; i < dotCount - 1; i++)
    {
        for (int j = i + 1; j < dotCount; j++)
        {
            int temp;
            cout << "Связаны ли " << i + 1 << " and " << j + 1 << "? (1 - да, 0 - нет): ";
            cin >> temp;
            if (temp == 1)
            {
                matrix[i * dotCount + j] = true;  // Преобразуем индексы двумерной матрицы в одномерный индекс
                matrix[j * dotCount + i] = true;
            }
            else
            {
                matrix[i * dotCount + j] = false;
                matrix[j * dotCount + i] = false;
            }
        }
    }

    for (int i = 0; i < dotCount; i++)
    {
        canBeUsedAsBase[i] = true;
    }

    int NumberOf = 0;

    for (int i = 0; i < dotCount; i++)
    {
        if (canBeUsedAsBase[i] == false) continue;
        FindConnectedDots(matrix, canBeUsedAsBase, i, dotCount);
        NumberOf++;
    }

    cout << "Количество отдельных вершин: " << NumberOf << endl;

    delete[] matrix;
    delete[] canBeUsedAsBase;

    return 0;
}
