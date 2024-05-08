# Лабораторная работа №2

## Цель работы 
Изучить основы теории множеств и операции над ними.

## Задача

#### Вариант индивидуального задания №3
Реализовать программу, формирующую множество равное симметрической разности
произвольного количества исходных множеств (без учёта кратных вхождений элементов).

## Определения
**Разность** - это множество, в котором содержатся элементы множества А, которых нету во множестве В (Записывается как А / В)

**Симметрическая разность** - это множество, полученное взаимным вычитанием множеств друг из друга (А / В + В / А)

## Алгоритм
Для того, чтобы найти симметрическую разность нескольких множеств нам необходимо следовать данному алгоритму:
1. Фиксируем переменную `cur` - номер цикла.
2. Находим разность множеств под номерами `cur` и `cur+1`: 

    2.1. Сравниваем каждый элемент первого множества с каждым элементом второго.
	
    2.2. Если элемент встречается только в первом множестве, записываем его во множество симметрической разности `symdiff`.
3. Находим разность множеств под номерами `cur+1` и `cur`: 

    3.1. Сравниваем каждый элемент первого множества с каждым элементом второго.
	
    3.2. Если элемент встречается только в первом множестве, записываем его во множество симметрической разности `symdiff`.
4. Проверяем равно ли `cur` значению `количество множеств - 2`:

    4.1. Если значения равны, заканчиваем алгоритм.
	
    4.2. Если нет, то:
	
        4.2.1. Очищаем множество `cur+1`.
		
        4.2.2. Перезаписываем множество `symdiff` в `cur+1`.
		
		4.2.3. Очищаем множество `symdiff`.
		
		4.2.4. Увеличиваем значение `cur` на 1.
		
		4.2.5. Переходим к пункту 2.
   
## Реализация алгоритма

``` C++
void symDiff(vector<vector<string>>& sets, int cur, int& num_sets, vector<string>& symdiff) {
    for (int i = 0; i < sets[cur].size(); i++) {
        int k = 0;
        for (int j = 0; j < sets[cur + 1].size(); j++) {
            if (sets[cur][i] != sets[cur + 1][j])
                k++;
        }
        if (k == sets[cur + 1].size())
            symdiff.push_back(sets[cur][i]);
    }
    for (int i = 0; i < sets[cur + 1].size(); i++) {
        int k = 0;
        for (int j = 0; j < sets[cur].size(); j++) {
            if (sets[cur + 1][i] != sets[cur][j])
                k++;
        }
        if (k == sets[cur].size())
            symdiff.push_back(sets[cur + 1][i]);
    }
    if (cur != num_sets - 2) {
        sets.at(cur + 1) = symdiff;
        symdiff.clear();
        symDiff(sets, cur + 1, num_sets, symdiff);
    }
}
```

## Тестирование

##### 1-й тест
Исходные данные:

![test1](https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D0%B5%D1%80%D0%BC%D0%B8%D0%BD%D0%BE%D0%B2%D0%B0_%D0%92/sem2/images/test1.png)

Результат:

![result1](https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D0%B5%D1%80%D0%BC%D0%B8%D0%BD%D0%BE%D0%B2%D0%B0_%D0%92/sem2/images/result1.png)

##### 2-й тест
Исходные данные:

![test2](https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D0%B5%D1%80%D0%BC%D0%B8%D0%BD%D0%BE%D0%B2%D0%B0_%D0%92/sem2/images/test2.png)

Результат:

![result2](https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D0%B5%D1%80%D0%BC%D0%B8%D0%BD%D0%BE%D0%B2%D0%B0_%D0%92/sem2/images/result2.png)

##### 3-й тест
Исходные данные:

![test3](https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D0%B5%D1%80%D0%BC%D0%B8%D0%BD%D0%BE%D0%B2%D0%B0_%D0%92/sem2/images/test3.png)

Результат:

![result3](https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D0%B5%D1%80%D0%BC%D0%B8%D0%BD%D0%BE%D0%B2%D0%B0_%D0%92/sem2/images/result3.png)

##### 4-й тест
Исходные данные:

![test4](https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D0%B5%D1%80%D0%BC%D0%B8%D0%BD%D0%BE%D0%B2%D0%B0_%D0%92/sem2/images/test4.png)

Результат:

![result4](https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D0%B5%D1%80%D0%BC%D0%B8%D0%BD%D0%BE%D0%B2%D0%B0_%D0%92/sem2/images/result4.png)

##### 5-й тест
Исходные данные:

![test5](https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D0%B5%D1%80%D0%BC%D0%B8%D0%BD%D0%BE%D0%B2%D0%B0_%D0%92/sem2/images/test5.png)

Результат:

![result5](https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D0%B5%D1%80%D0%BC%D0%B8%D0%BD%D0%BE%D0%B2%D0%B0_%D0%92/sem2/images/result5.png)

## Вывод
В результате выполнения данной работы были получены следующие практические навыки:
- изучение теории множеств и выполнения операций над ними;
- умение работать с header-файлами.

## Источники
[ЛР 2](https://drive.google.com/drive/folders/1SLcF9njDTaNUacXMA9Nrqm7FUS7MnNsI)