# Лабораторная работа №1 

## Задача:
Двумерный массив. Сортировка массива. Вставка элемента в
отсортированный массив. Поиск элемента в отсортированном массиве.
Объединение двух отсортированных массивов. Пересечение двух
отсортированных массивов.
## Цель:
Исследовать свойства структур данных и разработать
библиотеку алгоритмов обработки структур данных.

## Список ключевых понятий:

Ступенчатый массив — это структура данных, которая представляет собой коллекцию элементов, расположенных в виде ступенек или уровней. Каждый уровень массива содержит набор элементов одного типа данных, и каждый уровень может иметь различную длину. В отличие от обычного массива, ступенчатый массив позволяет гибко изменять размеры каждого уровня независимо от других уровней.

Если попроще, то ступенчатый массив - массив массивов, где каждый вложенный массив имеет различную длину.

Пример ступенчатого массива:

![mnm](https://github.com/iis-32170x/RPIIS/assets/110356280/c9101f79-6e4e-46a1-881c-6a3695115d2a)

## Алгоритм 

**Описанные методы:**
- *NewArray*- метод, который создаёт совсем новый массив
- *AddElement* - метод, с помощью которого вы добавляете все элементы в пустой массив
- *Sort* - метод, который сортирует ваш массив
- *OutPut* - метод, который выводит ваш массив
- *InsertElement* - метод, который добавляет один элемент в ваш массив
- *FindElement* - метод, который находит элемент, находящийся в определенной строке и определенном столбце, или же находит строку и столбец искомого элемента(зависит от введённых аргументов)
- *Merge* - метод, который меняет наш массив на объединение нашего массива и вводимого
- *Intersect* - метод, который меняет наш массив на пересечение нашего массива и вводимого

### NewArray:
Просим ввести размер создаваемого массива. Размер находится в рамках [1,5]
Создаём массив размером NxN

```c#

public void NewArray(ref int[][] massive)
{
    int massSize;
    Console.Write("Введите размер массива NxN. N не должен превышать 5 элементов и должен быть больше нуля: ");
    try
    {
        massSize = Int32.Parse(Console.ReadLine());
    }
    catch
    {
        massSize = 0;
    }
    while (massSize > 5 || massSize <= 0)
    {
        Console.Write("N введён неверно, введите ещё раз: ");
        try
        {
            massSize = Int32.Parse(Console.ReadLine());
        }
        catch
        {
            massSize = 0;
        }
    }
    massive = new int[massSize][];
    for (int i = 0; i < massive.Length; i++)
    {
        massive[i] = new int[massSize];
    }
}

```

### AddElement 
Полностью заполняем пустой массив, делая запрос на ввод элемента пользователю

```c#
public void AddElement(ref int[][]massive)
{
    int count = 0;
    for(int i = 0; i < massive.Length; i++)
    {
        for(int j = 0; j < massive[i].Length; j++)
        {
            Console.Write("Введите элемент {0} ",(count+1));
        again:
            try
            {
                massive[i][j] = Int32.Parse(Console.ReadLine());
            }
            catch
            {
                Console.Write("Неправильный ввод, попробуйте ещё раз: ");
                goto again;
            }
            count++;
        }
    }
}
```

### Sort
Создаёт одномерный массив из нашего двумерного и сортирует его встроенной сортировкой. Дальше заполняет наш двумерный массив отсортированным одномерным

```c#
public void Sort(ref int[][] massive)
{
    var flattenedArray = massive.SelectMany(x => x).ToArray();

    Array.Sort(flattenedArray);

    int currentIndex = 0;
    for (int i = 0; i < massive.Length; i++)
    {
        for (int j = 0; j < massive[i].Length; j++)
        {
            massive[i][j] = flattenedArray[currentIndex++];
        }
    }
}
```

### OutPut
Выводим двумерный массив в консоль

```c#
public void OutPut(ref int[][] massive)
{
    for(int i = 0; i < massive.Length; i++)
    {
        for(int j = 0; j < massive[i].Length;j++)
        {
            if (massive[i][j] == 0) continue;
            Console.Write("| {0,3}  ", massive[i][j]);
        }
        Console.WriteLine("|");
    }
}
```

### InsertElement 
Создаём резервный массив, для того, чтобы хранить изначальный, дальше проверям на то, сколько в нём элементов, если элементов 5, то мы переходим к следующей строке, если меньше, то на месте этой строки вместо изначальной создаём новый массив на количество элементов большее на единицу, чем в изначальной строке, и после заполняем массив из резерва, приписываем тот элемент, который мы вставляем и сортируем этот массив. Если во всех строках количество элементов равно 5, то создаём еще одну строку с тем элементом, который нужно вставить, переписываем все значения из резерва и сортируем массив

```c#
public void InsertElement(ref int[][] massive, int element)
{
    int count = 0;
    int[][] reserve=new int[massive.Length][];
    massive.CopyTo(reserve, 0);
    for (int i = 0; i < massive.Length; i++)
    {
        if (massive[i].Length >= 5)
        {
            count++;
        }
        else
        {
            massive[i] = new int[massive[i].Length + 1];
            massive[i][massive[i].Length - 1] = element;
            break;
        }
    }
    if (count == massive.Length)
    {
        massive = new int[reserve.Length + 1][];
        reserve.CopyTo(massive, 0);
        massive[massive.Length-1] = new int[1];
        massive[massive.Length-1][0] = element;
    }
    else
    for(int i = 0; i < reserve.Length; i++)
    {
        for(int j = 0; j < reserve[i].Length;j++)
        {
            massive[i][j] = reserve[i][j];
        }
    }
    Sort(ref massive);
}
```

### FindElement
Используем перегрузку метода, чтобы с одним именем можно было вызвать методы с одним названием, но разными передаваемыми аргументами.
1. Аргументами являются два числа: строка и столбец. По этим данным мы находим, какой элемент стоит в конкретном месте

```c#
 public int FindElement(ref int[][] massive,int row, int column)
 {
     int element = -1;
     try
     {
         element = massive[row][column];
     }
     catch
     {
         Console.WriteLine("Индекс вышел за границы массива.");
     }
     return element;
 }
```

2. Аргументами передаётся одно число, являющимся элементом, который нужно найти. Выводим в консоль строку и столбец, где находится этот элемент

```c#
public void FindElement(ref int[][] massive, int element)
{
    bool isElement = true;
    for(int i = 0; i < massive.Length; i++)
    {
        for(int j = 0; j < massive[i].Length; j++)
        {
            if (massive[i][j] == element)
            {
                Console.WriteLine("Строка: {0}. Столбец: {1}", i, j);
                isElement = false;
            }
        }
    }
    if(isElement) Console.WriteLine("Элемент не найден");
}
```

### Merge
Проверяем на то, есть ли этот элемент в изначальном массиве. Если элемента нет, то использовать метод InsertElement, если элемент уже есть, то ничего не добавлять.

```c#
public void Merge(ref int[][] massive, ref int[][]secondMass)
{
    bool isInMass = true;
    for(int i = 0; i < secondMass.Length; i++)
    {
        for(int j = 0; j < secondMass[i].Length;j++)
        {
            for(int k = 0; k < massive.Length; k++)
            {
                for(int m = 0; m < massive[k].Length; m++)
                {
                    if (secondMass[i][j] == massive[k][m]) isInMass = false;
                }
            }
            if (isInMass) InsertElement(ref massive,secondMass[i][j]);
            isInMass = true;
        }
    }
}
```

### Intersect
Создаём одномерный массив и в него записываем элементы, которые есть и в первом, и во втором массиве, после заново инициализируем основной массив и записываем вставляем в него элементы из одномерного массива с помощью InsertElement

```c#
public void Intersect(ref int[][] massive, ref int[][] secondMass)
{
    var flatMass = new int[1000];
    bool isRepeat = false;
    int countIndex = 0;
    for(int i = 0; i < massive.Length; i++)
    {
        for(int j = 0; j < massive[i].Length;j++)
        {
            for(int k = 0; k < secondMass.Length;k++)
            {
                for(int m = 0; m < secondMass[k].Length;m++)
                {
                    if (massive[i][j] == secondMass[k][m])
                    {
                        for(int s = 0; s < countIndex; s++)
                        {
                            if (flatMass[s] == massive[i][j]) isRepeat = true;
                        }
                        if (isRepeat) break;
                        flatMass[countIndex++] = massive[i][j];
                        break;
                    }
                }
                if (isRepeat) break;
            }
            if (isRepeat)
            {
                isRepeat = false;
                continue;
            }
        }
    }
    if (countIndex == 0) Console.WriteLine("Пересечения нет");
    else
    {
        massive = new int[1][];
        massive[0] = new int[0];
        for(int i = 0; i < countIndex; i++)
        {
            InsertElement(ref massive, flatMass[i]);
        }
    }
}
```

## Пример выполнения:
Создаём новый проект, где подключаем нашу библиотеку. В главном методе используем описанные в библиотеке методы. 

Например, 
![Screenshot_120](https://github.com/iis-32170x/RPIIS/assets/110356280/f334f888-61b3-4eb2-a112-2ca32e0257e0)

И введя то, что требует программа, мы получим:
![Screenshot_121](https://github.com/iis-32170x/RPIIS/assets/110356280/4a8d518c-dafd-4b36-94f5-0af97aa8ec80)

## Вывод
Реализовал структуру данных двумерный ступенчатый массив.
