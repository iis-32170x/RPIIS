# Лабораторная работа №2
## Цель работы

Изучить основы теории множеств.

## Задача

Реализовать программу, формирующую без повторений всевозможные ориентированные множества из элементов исходного неориентированного множества, количество элементов в сформированных множествах должно быть равно исходному натуральному `n`.

## Список ключевых понятий

- `Множество` — простейшая информационная конструкция и математическая структура,
позволяющая рассматривать какие-то объекты как целое, связывая их.
- `Неориентированное ножество` — множество, порядок элементов которого не имеет значения(связи между элементами ненаправленные)
- `Ориентированное ножество` — Ориентированное множество — это множество, на котором задано отношение порядка, которое удовлетворяет определенным условиям. В частности, для любых двух элементов a и b из ориентированного множества должно выполняться одно из следующих условий:

    1) a = b,
    2) a и b сравнимы по отношению порядка (т.е. либо a < b, либо b < a),
    3) существует элемент c, который одновременно больше или одновременно меньше как a, так и b.

## Алгоритм

Рассмотрим алгоритм решения задачи. Дана исходная последовательность чисел.

1. Считать исходное неориентированное множество.
2. Создать функцию для генерации всех возможных перестановок элементов множества длиной n.
3. Внутри функции использовать рекурсию для формирования всех уникальных комбинаций элементов множества длиной n.
4. Проверять каждую сгенерированную комбинацию на наличие повторяющихся элементов и исключать их.
5. Возвращать список всех уникальных ориентированных множеств, удовлетворяющих условию задачи.

## Реализация
```python
import ast

def perestanovki(a:list, pamyat=None):
    if pamyat is None:
        pamyat = []

    results = []

    for i in range(len(a)):
        element = a.pop(i)
        if len(a) == 0:
            results.append(pamyat + [element])
        results.extend(perestanovki(a[:], pamyat + [element]))
        a.insert(i, element)
    return results

def delete_povtory(a):
    d = []
    for element in a:
        if element not in d:
            d.append(element)
    return d     

def get_list(branch):
    se = []
    kor = []
    new_branch = []
    string_set = set()
    nums_set = set()
    bool_set = set()
    for i in branch:
        if type(i) == list:
            se.append(get_list(i))
        elif type(i) == str:
            string_set.add(i)
        elif type(i) == bool:
            bool_set.add(i)
        elif type(i) == tuple:
            kor.append(get_list(i))
        else:
            nums_set.add(i)
    nums_set = list(nums_set)
    nums_set.sort()
    string_set = list(string_set)
    string_set.sort()
    new_branch.extend(nums_set)
    new_branch.extend(string_set)
    bool_set = list(bool_set)
    bool_set.sort()
    new_branch.extend(bool_set)
    if se:
        sorted_list = sorted(se, key=lambda x:  repr(x))
       
        se1 = delete_povtory(sorted_list)
        new_branch.extend(se1)
    if kor:
        sorted_kor = sorted(kor, key=lambda x: repr(x))
        
        kor1 = delete_povtory(sorted_kor)
        new_branch.extend(kor1)
    return new_branch

def zamena_skobok(a:list):
    x_new = a.replace('{', '[')
    x_got = x_new.replace('}', ']')
    x_new_1 = x_got.replace('<', '(')
    x_got_2 = x_new_1.replace('>', ')')
    return x_got_2



x = input("Введите множество\n")
x_new = x.replace('{', '[')
x_got = x_new.replace('}', ']')
x_new_1 = x_got.replace('<', '(')
x_got_2 = x_new_1.replace('>', ')')
branch = ast.literal_eval(x_got_2)
x_per = get_list(branch)
results = perestanovki(x_per)
for element in results:
    print(element,"\n")
```

## Вывод

В ходе выполнения работы был реализован алгоритм формирования неповторяющихся ориентированных множеств исходного неориентированного множества.

## Источники

- [Алгоритмы комбинаций]([https://prog-cpp.ru/permutation/](https://thecode.media/all-combo/))
- [Условие работы](https://drive.google.com/drive/folders/1SLcF9njDTaNUacXMA9Nrqm7FUS7MnNsI)
