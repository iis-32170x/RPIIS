# Лабораторная работа №2

## Задача
Реализовать программу, формирующую множество равное булеану исходного множества.

## Цель
Практика в работе с алгоритмами обработки множеств.

## Список ключевых понятий
* ***Множество*** – простейшая информационная конструкция и математическая структура, позволяющая рассматривать какие-то объекты как целое, связывая их.
* ***Булеан множества*** - множество, элементами которого являются все возможные подмножества исходного множества.
* ***Кортеж*** - упорядоченный набор элементов фиксированной длины.

## Функции программы
### 1. Функция `def readElements(Set)`. Разбиение входящей строки-множества на элементы.

* Принимает на вход строку-множество.
* Разбивает входящую строку на элементы множества и возвращает в виде массива строк - элементов множества.
* Если элементом множества оказывается другое множество или кортеж, то вызывает функции для обработки таких случаев: ```readsubset``` и ```readtuple``` соответственно.
* Возвращает ошибку в случае некорректной записи множества.

#### Код функции:
   ```python
def readElements(Set):
    Set = Set[1:-1]
    isTuple = False
    isSubset = False
    subset = []
    current_element = ""
    for char in Set:
        if ( char == ' '):
            raise ValueError("Некорректная запись множества. Элементы множества не должны быть разделены пробелами.")
        
        if isSubset and current_element.count('{') == current_element.count('}'):
            isSubset = False
        elif isTuple and current_element.count('<') == current_element.count('>'):
            isTuple = False

        if char == ',' and not (isTuple or isSubset):
            if (current_element.count('{') > 0):
                if current_element[0] != '{' or current_element[-1] != '}' or current_element.count('{') != current_element.count('}'):
                    raise ValueError("Некорректная запись элемента множества.")
                subset.append(readsubset(current_element))
                current_element = ""
            elif current_element.count('<') > 0:
                if current_element[0] != '<' or current_element[-1] != '>' or current_element.count('<') != current_element('>'):
                    raise ValueError("Некорректная запись элемента множества.")
                subset.append(readtuple(current_element))
                current_element = ""
            else:
                subset.append(current_element)
                current_element = ""

        elif char == '<':
            isTuple = True
            current_element += char  
        elif char == '{':
            isSubset = True
            current_element += char       
        else:
            current_element += char
    
    if current_element != "":
        if current_element.count('{') != current_element.count('}') or current_element.count('<') != current_element.count('>'):
            raise ValueError("Некорректная запись элемента множества.")
        
        if current_element.count('{') > 0:
            if (current_element[0] != '{' or current_element[-1] != '}'):
                raise ValueError("Некорректная запись элемента множества.")
            current_element=readsubset(current_element)
            if (subset.count(current_element) < 1):
                subset.append(current_element)
            current_element = ""
        elif current_element.count('<') > 0:
            if (current_element[0] != '<' or current_element[-1] != '>'):
                raise ValueError("Некорректная запись элемента множества.")
            current_element=readtuple(current_element)
            if (subset.count(current_element) < 1):
                subset.append(current_element)
            current_element = ""

        elif (subset.count(current_element) < 1):
            subset.append(current_element)
            current_element = ""

    return subset
   ```

### 2. Функция `def create_power_set(Set_elements)`. Создание булеана множества.

* Создаёт пустое множество `power_set` - будущий булеан.
* Принимает на вход множество состоящее из строк - элементов исходного множества.
* Далее, при помощи побитовых сдвигов, в первом цикле создаёт так называемые "маски подмножества" (например: "00000001" - маска подмножества, согласно которой, данному подмножеству принадлежит только первый элемент исходного множества).
* Во втором цикле перебирается каждый элемент исходного множества и если он есть в "маске", то он добавляется в подмножество `subset`.
* Возвращает булеан исходного множества.

#### Код функции:
   ```python
   def create_power_set(Set_elements):
       power_set = []
       for i in range (1 << len(Set_elements)):
           subset = []
           for j in range (len(Set_elements)):
               if i & (1 << j):
                   subset.append(Set_elements[j])
           power_set.append(subset)
       return power_set
   ```
### 3. Функция `def readsubset(Set):`. Чтение подмножества.
* Принимает на вход строку-множество.
* Запускает фунцию ```readElements```.
* Cчитывает элементы входящего множества.
* Устраняет повторы во входящем множестве.
* Сортирует и возвращает множество в виде строки.

#### Код функции:
```python
def readsubset(Set):
    Elements = readElements(Set)
    Elements.sort()
    subset = "{"
    subset += ','.join(Elements)
    subset += '}'
    return subset
```

### 4. Функция `def readtuple(Tuple)`. Чтение кортежа.
* Принимает на вход строку-множество.
* Запускает фунцию ```readElements```.
* Cчитывает элементы входящего множества.
* Устраняет повторы во входящем множестве.
* Сортирует и возвращает множество в виде кортежа.

#### Код функции:
```python
def readtuple(Tuple):
    Elements = readElements(Tuple)
    result = "<"
    result += ','.join(Elements)
    result += '>'
    return result
```
## Вывод
Написал программу для считывания множества из заданного файла, записи его в массив поэлементно и создания его булеана.
