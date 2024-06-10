# Лабораторная работа №2

## Задача:
$\textcolor{#4b0082}{\textit{Вариант 13}}$ Реализовать программу, формирующую множество равное разности двух исходных множеств (с учётом кратных вхождений элементов).
## Цель:
* Исследовать свойства структур данных и разработать библиотеку алгоритмов обработки структур данных (для нахождения разности множеств, считанных из файла).
* Разработать тесты, которые проверяют успешное выполнение всех функций

## Список ключевых понятий:
* $\textcolor{#4b0082}{\textbf{Множество}}$ — простейшая информационная конструкция и математическая структура,
позволяющая рассматривать какие-то объекты как целое, связывая их.
* $\textcolor{#4b0082}{\textbf{Разность}}$ - это множество, в которое входят все элементы первого множества, не входящие во второе множество
![Venn_A_setminus_B svg](https://github.com/iis-32170x/RPIIS/assets/110356280/0fe55f7c-13be-44ab-a770-570633c7432b)


## Алгоритмы операций над множествами

### Считывание множеств из файла и создания массива

``` c#
/// <summary>
/// Метод для чтения из файла множеств и записи их в массив.
/// </summary>
/// <param name="fileName">Строка, которая хранит полный путь к файлу.</param>
public void CreateSet(string fileName)
{
    StreamReader file = new(fileName);
    int i = -1, j = 0;
    int countMassives = 2;
    massive = new int[countMassives][];
    while(!file.EndOfStream)
    {
        string text = file.ReadLine();
        if (text.Length == 1)
        {
            i++;
            massive[i] = new int[Int32.Parse(text)];
        }
        else if (text.Length > 1)
        {
            foreach (char buff in text)
            {
                if(buff !=' ')
                {
                    massive[i][j] = (int)buff-'0';
                    j++;
                }
            }
            j = 0;
        }
    }
    file.Close();
}
```

### Обновление данных из файла

```c#
/// <summary>
/// Метод для обновления данных о множествах и перезаписи массива.
/// </summary>
/// <param name="fileName">Строка, которая хранит полный путь к файлу.</param>
public void UpdateSet(string fileName)
{
    CreateSet(fileName);
}
```

### Вывод множеств в консоль

```c#
/// <summary>
/// Метод для вывода множеств в консоль.
/// </summary>
public void OutPutSet()
{
    for(int i = 0; i < massive.Length; i++)
    {
        Console.Write("Множество {0}: ", i);
        for(int j = 0; j < massive[i].Length; j++)
        {
            Console.Write("{0} ", massive[i][j]);
        }
        Console.WriteLine();
    }
}
```

### Разность

``` c#
/// <summary>
/// Метод для нахождения разности двух множеств.
/// </summary>
/// <param name="variant">Выбор между разностью А\B или B\A.</param>
/// <returns>Множество полученное из разности.</returns>
public int[] DifferenceSet(int variant)
{
    int[] differenceMassive;
    int count=0, index = 0;
    int[] temp;
    switch (variant)
    {
        case 1:
            {
                temp = massive[0];
                for(int i = 0; i < massive[1].Length; i++)
                {
                    for(int j = 0; j < massive[0].Length; j++)
                    {
                        if (massive[0][j] == massive[1][i])
                        {
                            temp[j] = int.MaxValue;
                            count++;
                            break;
                        }
                    }
                }
                differenceMassive = new int[temp.Length - count];
                for(int i = 0; i < differenceMassive.Length; i++)
                {
                    while (temp[index]==int.MaxValue)
                    {
                        index++;
                    }
                    differenceMassive[i] = temp[index];
                    index++;
                }
                return differenceMassive;
            }
        case 2:
            {
                temp = massive[1];
                for (int i = 0; i < massive[0].Length; i++)
                {
                    for (int j = 0; j < massive[1].Length; j++)
                    {
                        if (massive[0][i] == massive[1][j])
                        {
                            temp[j] = int.MaxValue;
                            count++;
                            break;
                        }
                    }
                }
                differenceMassive = new int[temp.Length - count];
                for (int i = 0; i < differenceMassive.Length; i++)
                {
                    while (temp[index] == int.MaxValue)
                    {
                        index++;
                    }
                    differenceMassive[i] = temp[index];
                    index++;
                }
                return differenceMassive;
            }
    }
    return null;
}
``` 
### Пример выполнения программы

![Screenshot_311](https://github.com/iis-32170x/RPIIS/assets/110356280/02eeefe9-847e-4ad7-97b5-2b4b510630ed)


##  Список использованных источников 

* Л. А. Гладков, В. В. Курейчик, В. М. Курейчик   "Дискретная математика"

