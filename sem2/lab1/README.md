# Лабораторная работа №1

Вариант 19. Двумерный массив. Сортировка массива. Вставка элемента в отсортированный массив. Поиск элемента в отсортированном массиве. Объединение двух отсортированных массивов. Пересечение двух отсортированных массивов.

## Цели лабораторной работы:
1. Разработать библиотеку для работы с двумерным массивом на выбранном императивном языке программирования (например, C++, Java, Python).
2. Создать тестовую программу для демонстрации функциональности разработанной библиотеки.
3. Разработать систему тестов для проверки работоспособности и корректности библиотеки, учитывая требования полноты, адекватности и непротиворечивости.
4. Обеспечить обработку некорректных данных, предусмотрев корректное завершение программы при возникновении ошибок.
5. Составить отчет по выполнению лабораторной работы.
   
## Задачи лабораторной работы
1. Изучить спецификацию задачи по работе с двумерным массивом.
2. Выбрать язык программирования для реализации библиотеки (например, C++, Java, Python) в соответствии с индивидуальным заданием.
3. Разработать и реализовать библиотеку для работы с  двумерным массивом, включая операции описанные в индивидуальном задании.
4. Написать тестовую программу, которая демонстрирует работоспособность библиотеки.
5. Разработать систему тестов, включающую тест-кейсы для проверки различных аспектов работы библиотеки, включая корректность, производительность и обработку ошибок.
6. Провести тестирование разработанной библиотеки, убедившись в ее правильной работе на различных входных данных.
7. Составить подробный отчет, включая описание решения задачи, архитектуры библиотеки, результаты тестирования и выводы.

## Список используемых понятий
1. `Библиотека программного обеспечения (Библиотека кода):` в программировании библиотека представляет собой совокупность программного кода, предназначенного для решения определенных задач. Этот код может содержать функции, классы, процедуры или другие компоненты, которые разработчики могут повторно использовать в своих программных проектах. Библиотеки упрощают разработку, так как они предоставляют готовые решения для типовых задач.
2. `Библиотека random:` содержит инструменты для генерации случайных чисел.
3. `Библиотека ctime:` предоставляет функции и определения, связанные со временем и датой.
4. `Библиотека gtest/gtest.h:` библиотека для модульного тестирования на языке С++.
5. `Двумерный массив:` массив, элементами которого выступают другие массивы с данными.
6. `Сортировка двумерного массива:` операция, в результате выполнения которой получается отсортированный (по определенному полю) массив, в котором строки (или столбцы) расположены в определенном порядке,

## Описание используемых алгоритмов:
### Метод сортировки (`Sort(bool key, int nomerkey, bool napravlen)`)
Этот метод принимает три параметра:
1. key (отвечает за объект сортировки):
   - `True` --- сортировка строк.
   - `False` --- сортировка столбцов.
2. nomerkey (отвечает за номер конкретного столбца/строки по котороу будет идти сортировка)
3. napravlen (отвечает за направление сортировки):
   - `True` --- от большего к меньшему.
   - `False` --- от меньшего к большему.

алгоритм(при key = true, napravlen = true):
```cpp
int temp;
  for (int i{0}; i < sizeN-1;i++)
    for (int j{i+1}; j < sizeN; j++)
      if (mas[i][nomerkey] < mas[j][nomerkey])
        for (int k{0}; k < sizeM; k++){
          temp = mas[i][k];
          mas[i][k] = mas[j][k];
          mas[j][k] = temp;
        }
```
Пример работы:
![Снимок экрана от 2024-02-23 15-42-49](https://github.com/iis-32170x/RPIIS/assets/146863499/f24656c1-f4c1-4c0b-aca5-9cc76021021a)
### Метод вставки элемента в отсортированный массив (`void PushInSort(Masiv arr)`):
Метод принимает один параметр --- одномерный массив.

алгоритм(при key = true, napravlen = true):
```cpp
int **newmas;
newmas = new int*[sizeN + 1];
for (int i{0}; i <= sizeN; i++)
    newmas[i] = new int [sizeM];
int res_search{search(arr.ElementG(NOMERKEY))};
for (int i{0}; i <= res_search; i++)
    for (int j{0}; j < sizeM; j++)
        newmas[i][j] = mas[i][j];
for (int j{0}; j < sizeM; j++)
    newmas[res_search + 1][j] = arr.ElementG(j);

for (int i{res_search + 2}; i <= sizeN; i++)
    for (int j{0}; j < sizeM; j++)
        newmas[i][j]=mas[i-1][j];

for (int i = 0; i < sizeN; i++)
    delete[] mas[i];
sizeN++;
delete[] mas;
mas = newmas;
```
Пример работы:
![Снимок экрана от 2024-02-23 15-54-27](https://github.com/iis-32170x/RPIIS/assets/146863499/88c8e147-7fd0-4cb0-9251-6c143d60523f)
### Метод поиска элемента в отсортированном массиве (`SearchInSort(int x)`):
Метод принимает один параметр --- число.

алгоритм(при key = true, napravlen = true):
```cpp
int res_search{search(x)};
if ((res_search >= 0 ) && (mas[res_search][NOMERKEY] == x))
    return res_search;
if ((res_search < sizeN -1) && (mas[res_search + 1][NOMERKEY] == x))
    return res_search + 1;
return -1;
```
`res_search(int x):`
```cpp
int sosed, start{0}, end;
end = sizeN - 1;
if (mas[0][NOMERKEY] <= x)
    return -1;
if (mas[end][NOMERKEY] >= x)
    return end;
while(start < end){
sosed = (start + end)/2;
if (NAPRAVLEN && mas[sosed][NOMERKEY] < x)
end = sosed;
if (NAPRAVLEN && mas[sosed][NOMERKEY] >= x){
    if (start == sosed)
        start = sosed + 1;
    else
        start = sosed;
}
if (!NAPRAVLEN && mas[sosed][NOMERKEY] <= x){
    if (start == sosed)
        start = sosed + 1;
    else
        start = sosed;
}
if (!NAPRAVLEN && mas[sosed][NOMERKEY] > x)
    end = sosed;
}
return sosed;
```
### Метод объединения двух отсортированных массивов(`UnionSort(Masiv2 arr1, Masiv2 arr2)`):
Метод принимает два параметра --- два двумерных массива.

алгоритм(при key = true, napravlen = true(сонаправлены)):
```cpp
int **newmas;
KEY = arr1.KEYG();
newmas = new int*[arr1.SizeNG() + arr2.SizeNG()];
for (int i{0}; i < arr1.SizeNG() + arr2.SizeNG(); i++)
    newmas[i] = new int [arr1.SizeMG()];
NOMERKEY = arr1.NOMERKEYG();
int k{0},j{0};
for (int i{0}; i < arr1.SizeNG(); i++){
    while((j < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) < arr2.ElementG(j,NOMERKEY))){
        for (int c{0}; c < arr2.SizeMG(); c++)
            newmas[k][c] = arr2.ElementG(j,c); 
        j++;
        k++;
    }
    for (int c{0}; c < arr1.SizeMG(); c++)
        newmas[k][c] = arr1.ElementG(i,c); 
    k++;
}
for (int i{j}; i < arr2.SizeNG(); i++){
    for (int c{0}; c < arr2.SizeMG(); c++)
        newmas[k][c] = arr2.ElementG(i,c);
    k++;
}
for (int i = 0; i < sizeN; i++)
  delete[] mas[i];
sizeN = k;
sizeM = arr1.sizeM;
delete[] mas;
mas = newmas;
NAPRAVLEN = arr1.NAPRAVLENG();
sort = true;
```
Пример работы:
![Снимок экрана от 2024-02-23 16-35-52](https://github.com/iis-32170x/RPIIS/assets/146863499/882460ef-740f-4674-a5f8-d6ee110bb0bc)
### Метод пересечения двух отсортированных массивов(`IntersectionSort(Masiv2 arr1, Masiv2 arr2)`):
Метод принимает два параметра --- два двумерных массива.

алгоритм(при key = true, napravlen = true(сонаправлены)):
```cpp
for (int i = 0; i < sizeN; i++)
    delete[] mas[i];
delete[] mas;
int **newmas;
int m{0};
NOMERKEY = arr1.NOMERKEYG();
NAPRAVLEN = arr1.NAPRAVLENG();
KEY = arr1.KEYG();
sort = true;
int l{0};
for (int i{0}; i < arr1.SizeNG(); i++){
    while((l < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) < arr2.ElementG(l,NOMERKEY)))
        l++;
    if ((l < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) == arr2.ElementG(l,NOMERKEY)))
        m++,l++;
}
newmas = new int*[m];
for (int i{0}; i < m; i++)
    newmas[i] = new int[arr1.SizeMG()];
for (int i{0},k{0},j{0}; i < arr1.SizeNG(); i++){
    while((j < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) < arr2.ElementG(j,NOMERKEY)))
        j++;
    if ((j < arr2.SizeNG()) && (arr1.ElementG(i,NOMERKEY) == arr2.ElementG(j,NOMERKEY))){
        for (int c{0}; c < arr1.SizeMG(); c++)
            newmas[k][c] = arr1.ElementG(i,c); 
        k++;
        j++;
    }
}
sizeN = m;
sizeM = arr1.SizeMG();
mas = newmas;
```
Пример работы:
![Снимок экрана от 2024-02-23 16-47-55](https://github.com/iis-32170x/RPIIS/assets/146863499/9b2fe421-d1b8-4c54-99d6-40f34ee6f486)
### Другие методы:
- Метод `mkmas(int OT, int DO)` --- заполняет массив рандомными числами(в диапазоне от OT до DO).
- Метод `SizeNG()` --- возвращает количетсво строк массива.
- Метод `SizeMG()` --- возвращает количетсво сттолбцов массива.
- Метод `SortG()` --- возвращает значение переменной sort.
- Метод `KEYG()` --- возвращает значение переменной key.
- Метод `NAPRAVLENG()` --- возвращает значение пременной napravlen.
- Метод `NOMERKEYG()` --- возвращает номер конкретного столбца/строки по которому отсортирован массив.
- Метод `ElementG(int nomerN, int nomerM)` --- возвращает элемент с номером NxM.
- Метод `ShowProperties()` --- выводит на экран все свойства объекта.
- Метод `ShowMas()` --- выводит массив на экран.

Аналогичные методы(кроме метода `IntersectionSort`) присутвуют в классе `Masiv` для работы с одномерным массивом. Кроме этого есть класс `Time`, при необходимости заполнять массивы случайными числами, нужно создать объект этого класса перед созданием первого объекта классов `Masiv2` и `Masiv`.

## Результаты тестирования:
Тестирование проводилось с помощью `gtest.h`.
Результат выполнения:
![Снимок экрана от 2024-02-23 17-16-07](https://github.com/iis-32170x/RPIIS/assets/146863499/4ad3318c-0f0a-4aa2-8ed2-ef71f1e9b511)

## Вывод:
В ходе выполнения работы познакомился созданием библиотек в С++, познакомился с концепцией реализация в .срр файлах, декларация -- в .hpp, познакомился с классами в С++, познакомился с Google C++ Testing Framework, реализоавал библиотеку для работы c одномерными и двумерными массивами,а также создал систему тестов,которая проверяет корректность созданной библиотеки, собрал проект с помощью cmake.
## Используемые источники:
честно не помню...
