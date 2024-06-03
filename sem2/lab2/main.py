def parse_set(input_set):
    input_set = input_set.strip()
    if not input_set.startswith('{') or not input_set.endswith('}'):
        raise ValueError("Множество должно быть заключено в фигурные скобки.")

    input_set = input_set[1:-1]  # Удаление первой и последней скобки
    elements = set()
    stack = []
    current_element = ""

    for char in input_set:
        vlozh = set()
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

filename ='test1.txt'
with open(filename, "r") as file:
    lines = file.readlines()

if len(lines) >= 1:
    first_line = lines[0].strip()
else:
    first_line = ""

if len(lines) >= 2:
    second_line = lines[1].strip()
else:
    second_line = ""

print("Первая строка:", first_line)
print("Вторая строка:", second_line)


input_set1 = first_line
input_set2 = second_line
mas1 = parse_set(input_set1)
mas2 = parse_set(input_set2)


def pars(s):
    result = set()
    for item in s:
        if isinstance(item, str) and item.startswith('{') and item.endswith('}'):
            inner_items = []
            level = 0
            current_item = ''
            for char in item[1:-1]:
                if char == '{':
                    level += 1
                elif char == '}':
                    level -= 1
                if char == ',' and level == 0:
                    inner_items.append(current_item.strip())
                    current_item = ''
                else:
                    current_item += char
            if current_item:
                inner_items.append(current_item.strip())
            inner_set = set()
            for inner_item in inner_items:
                if inner_item.startswith('{') and inner_item.endswith('}'):
                    inner_set.add(frozenset(pars({inner_item})))
                else:
                    inner_set.add(inner_item)
            if len(inner_set) == 1 and isinstance(list(inner_set)[0], str):
                result.add(list(inner_set)[0])
            else:
                result.add(frozenset(inner_set))
        else:
            result.add(item)
    return result
mas1 = pars(mas1)
mas2 = pars(mas2)



difference = mas1 - mas2
def my_repr(obj):
    if isinstance(obj, (set, frozenset)):
        return '{{{}}}'.format(', '.join(map(my_repr, obj)))
    else:
        return repr(obj)


print({my_repr(item) for item in difference})
