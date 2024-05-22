# <p align="center">Лабораторная работа №2</p>

Вариант 4. Реализовать программу, формирующую множество равное разности двух исходных
множеств (без учёта кратных вхождений элементов).

## <p align="center">Цели и задачи лабораторной работы:</p>
1. Разработать программу, формирующую множество, равное разности двух  исходных множеств с без учета кратных вхождений элементов.
2. Написать тестовую программу для демонстрации функциональности программы.
3. Составить отчет по выполнению работы, включая описание программы, результаты тестирования и обработку ошибок.
   
## <p align="center"> Алгоритм:</p>
```py
import random
import ast
import re

def add_commas(expression):
    expression = expression.replace(")", ",)")
    expression = expression.replace("(,)", "()")
    return expression

            

def delete_povtory(a):
    d = []
    for element in a:
        if element not in d:
            d.append(element)
    return d        

def raznost(a:list, b:list):
    d = []
    for e in a: 
        if e not in b:
            d.append(e)
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



spis_mnozestv = list()
with open('file.txt', 'r') as file: 
        content = file.read() 
        lines = content.split('\n')

        for i in range(len(lines)):

            x_new = zamena_skobok(lines[i])
            xxx = add_commas(x_new)
            branch = ast.literal_eval(xxx)
            x_per = get_list(branch)
            spis_mnozestv.append(x_per)
        spis_mnozestv = delete_povtory(spis_mnozestv)
        novoe = list()
        novoe = spis_mnozestv[0]
        
        for i in range(len(lines)-1):

            novoe = raznost(novoe, spis_mnozestv[i + 1])
            
        print('Разность',len(lines),'множеств',novoe)
```
## Саму операцию разности выполняет данная функция
```py
def raznost(a:list, b:list):
    d = []
    for e in a: 
        if e not in b:
            d.append(e)
    return d
```
Она принимает два множества a,b и проверяет наличие каждого элемента а в множестве b, если его нет, то он записывается в результирующее множество
## <p align="center">Тесты
### 1.Тест
Содержимое файла file.txt
``` txt
{<<>>,<<1,2>,<2>>,2,3,{1,{2},'s'},{<{<>}>},<{'g',<['a']>}>,{2}}
{<{<['a']>,'g'}>,<<>>,1,2,<<1,2>,<2>>,{},{1,{2},{2},'s'},11,{'s',23},{<{<>}>},{2}}
```
Результат теста [3], что является правильным ответом.
### 2.Тест
Содержимое файла file.txt
``` txt
{1,2,3,4,5,{2,3,4},{4,{6}}}
{{4,3,2},2,4,3,{6,{4}}}
```
Результат теста :[1, 5, [4, [6]]], что является правильным ответом.
## <p align="center">Анализ результатов тестов
#### Из результатов тестов следует, что программа работает исправно, и умеет различать равные между собой множества, с учётом перестановок элементов и подмножеств.
## <p align="center">Вывод
В данной лабораторной работе была реализована программа для нахождения разности двух множеств без учёта кратных вхождений.