# Лабораторная работа №2
- `Цель` - нахождение булеана любого множества
- `Задача` - реализовать алгоритм создания булеана исходного множества
- `Вариант` - $\textcolor{grey}{\textit{5}}$
## Список ключевых понятий (определения)
- `Булеан` множества, также известный как множество подмножеств или множество всех подмножеств, определяется как множество, содержащее все возможные подмножества данного исходного множества.

- `Элментом множества` может являться буквольный символ, число, кортеж, отдельное множество, пустое множество, сочетание буквы и числа.
## Алгоритм 
Данный код состоит из двух функций и основной части программы.Разберем каждую часть по отдельности
Функция parse_set(input_set):
```python
ef parse_set(input_set):
input_set = input_set.strip()
if not input_set.startswith('{') or not input_set.endswith('}'):
raise ValueError("Множество должно быть заключено в фигурные скобки.")


input_set = input_set[1:-1]  # Удаление первой и последней скобки
elements = set()
stack = []
current_element = ""

for char in input_set:
    if char == ',' and not stack:
        elements.add(current_element.strip())
        current_element = ""
    elif char == ' ':
        raise ValueError("Между элементами множества должна быть запятая.")
    elif char == '{':
        stack.append('{')
        current_element += char
    elif char == '}':
        if not stack or stack[-1] != '{':
            raise ValueError("Некорректная закрывающая скобка '}'.")
        stack.pop()
        current_element += char
    elif char == '<':
        stack.append('<')
        current_element += char
    elif char == '>':
        if not stack or stack[-1] != '<':
            raise ValueError("Некорректная закрывающая скобка '>'.")
        stack.pop()
        current_element += char
    else:
        current_element += char

if current_element.strip():
    elements.add(current_element.strip())

if stack:
    raise ValueError("Некорректное количество открывающих и закрывающих скобок.")

return elements
```
