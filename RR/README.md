# Расчетная работа ПиОИвИС

## Цель: 

Изучить основы теории графов, способы представления графов, базовые алгоритмы для работы с графами.

## Задание:

1.8 (нг ми)

Реализовать на С++ код, определяющий двусвязный граф. Граф представлен в виде матрицы инцидентности.

## Основные понятия:

*Граф* -  математическая абстракция реальной системы любой природы, объекты которой обладают парными связями.
(совокупность точек, соединенных линиями. Точки называются вершинами, или узлами, а линии – ребрами, или дугами.)

*Неориентированный граф* — Граф, ни одному ребру которого не присвоено направление.

*Матрица инцедентности графа* — это матрица, количество строк в которой соответствует числу вершин, а количество столбцов – числу рёбер. В ней указываются связи между инцидентными элементами графа (ребро(дуга) и вершина). (В неориентированном графе если вершина инцидентна ребру то соответствующий элемент равен 1, в противном случае элемент равен 0)

*Двусвязный граф* - связный и неделимый граф в том смысле, что удаление любой вершины не приведёт к потере связности.

## Алгоритм реешения:

На вход алгоритму подаётся матрица инцидентности. По ней необходимо проверить, инцидентна ли каждая вершина как минимум двум рёбрам. 

## Реализация на С++:
```C++
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	string path = "matrix.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Файл не найлен\n";
	}
	else
	{
        int count = 0;
        int temp;

        while (!fin.eof())
        {
            fin >> temp;
            count++;
        }
        
        fin.seekg(0, ios::beg);
        fin.clear();

        
        int count_space = 0;
        char symbol;
        while (!fin.eof())
        {           
            fin.get(symbol);
            if (symbol == ' ') 
                count_space++;
            if (symbol == '\n')
                break;
        }
        

        
        fin.seekg(0, ios::beg);
        fin.clear();

        

        int rows = count / (count_space + 1);
        int columns = count_space + 1;

        double** matrix;
        matrix = new double* [rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new double[columns];

        
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                fin >> matrix[i][j];

        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
                cout << matrix[i][j] << "\t";
            cout << "\n";
        }


        bool check2sv = true;        
        for (int i = 0; i < rows; i++) 
        {
            int count1 = 0;
            for (int j = 0; j < columns; j++)
            {
                if (matrix[i][j] == 1)
                {
                    count1++;                   
                }
                
            }
            if (count1 < 2) {
                
                check2sv = false;
            }
        }

        if (check2sv != false)
        {
            cout << "Граф двусвязный\n";
        }
        else
        {
            cout << "Граф не двусвязный\n";
        }
        

        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;

        fin.close();
        
	}

}
```
## Разбор кода:

Подключаем библиотеку для работы с файлами и пространство имён std 
```C++
#include <iostream>
#include <fstream>
using namespace std;
```

Устанавливаем русскую локализацию, создаём переменную для пути к файлу и для самого файла
```C++
setlocale(LC_ALL, "RUSSIAN");
string path = "matrix.txt";
ifstream fin;
fin.open(path);
```

Если файл не удалось найти, выводим в консоль сообщение об ошибке
```C++
if (!fin.is_open())
{
	cout << "Файл не найлен\n";
}
```

Последующий код оборачиваем в условие else.

Создаём переменную для счёта количества символов и временную переменную. Пока файл не проверен до конца, записываем символ во временную переменную и увеличиваем счётчик символов
```C++
int count = 0;
int temp;

while (!fin.eof())
{
    fin >> temp;
    count++;
}
```

Переходим обратно в начало файла
```C++
fin.seekg(0, ios::beg);
fin.clear();
```

Создаём переменную для счёта количества пробелов и для символов. Пока файл не проверен до конца, получаем символ. Если этот символ - пробел, то увеличиваем счётчик пробелов. Если доходим до конца строки, то выходим из цикла.
```C++
int count_space = 0;
char symbol;
while (!fin.eof())
{           
    fin.get(symbol);
    if (symbol == ' ') 
        count_space++;
    if (symbol == '\n')
        break;
}
```

Снова возвращаемся в начало файла
```C++
fin.seekg(0, ios::beg);
fin.clear();
```

Создаём переменные и вычисляем количество строк и столбцов
```C++
int rows = count / (count_space + 1);
int columns = count_space + 1;
```

Создаём двумерный динамческий массив 
```C++
double** matrix;
matrix = new double* [rows];
for (int i = 0; i < rows; i++)
    matrix[i] = new double[columns];
```

Записываем в этот массив данные из матрицы
```C++
for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
        fin >> matrix[i][j];
```

Выводим матрицу на экран
```C++
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < columns; j++)
        cout << matrix[i][j] << "\t";
    cout << "\n";
}
```

Создаём переменную, где будет записан ответ, является ли граф двусвязным
```C++
bool check2sv = true;
```

Выполняем проверку на двусвязность. Если встречаем в строке матрицы единицу, то увеличиваем переменную count1. Если в строке меньше двух единиц, то записываем в check2sv значение false.
```C++
for (int i = 0; i < rows; i++) 
{
    int count1 = 0;
    for (int j = 0; j < columns; j++)
    {
        if (matrix[i][j] == 1)
        {
            count1++;                   
        }
        
    }
    if (count1 < 2) {
        
        check2sv = false;
    }
}
```

Выводим на экран результат. Если check2sv не было изменено на false, то граф двусвязный. В ином случае граф не двусвязный.
```C++
if (check2sv != false)
{
    cout << "Граф двусвязный\n";
}
else
{
    cout << "Граф не двусвязный\n";
}
```

Очищаем память, удаляя двумерный массив и закрывая файл. 
```C++
for (int i = 0; i < rows; i++)
    delete[] matrix[i];
delete[] matrix;

fin.close();
```

## Тесты:
Граф 1:

![Граф1](https://github.com/iis-32170x/RPIIS/blob/Давыдов_Р/RR/Tests/graph1.PNG)

Матрица 1:
```
1 0 1 0
1 1 0 0
0 1 0 1
0 0 1 1
```

Результат 1:

![result1](https://github.com/iis-32170x/RPIIS/blob/Давыдов_Р/RR/Tests/output1.PNG)

Граф 2:

![Граф2](https://github.com/iis-32170x/RPIIS/blob/Давыдов_Р/RR/Tests/graph2.PNG)

Матрица 2:
```
1 0 1 0 0 0 0 1 0
1 1 0 0 1 0 0 0 1
0 1 0 1 0 1 0 0 0
0 0 1 1 0 0 1 0 0
0 0 0 0 0 0 0 1 1
0 0 0 0 1 1 1 0 0
```

Результат 2:

![result2](https://github.com/iis-32170x/RPIIS/blob/Давыдов_Р/RR/Tests/output2.PNG)

Граф 3:

![Граф3](https://github.com/iis-32170x/RPIIS/blob/Давыдов_Р/RR/Tests/graph3.PNG)

Матрица 3:
```
1 1 0 1
1 0 1 0
0 1 1 0
0 0 0 1
```

Результат 3:

![result3](https://github.com/iis-32170x/RPIIS/blob/Давыдов_Р/RR/Tests/output3.PNG)

## Выводы
В результате выполнения расчётной работы приобрёл следующие навыки:

* Изучил основы теории графов

* Изучил способы представления графов

* Изучил базовые алгоритмы для работы с графами

* Изучил базовые алгоритмы работы с файлами в C++