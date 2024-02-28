def parse_set(input_set):
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

def powerset(s):
    n = len(s)
    masks = [1 << i for i in range(n)]
    for i in range(2**n):
        yield {x for mask, x in zip(masks, s) if i & mask}

filename = input("Введите имя файла: ")
with open(filename, 'r') as file:
    input_set = file.read().strip()

try:
    result = parse_set(input_set)
    boolean_set = list(powerset(result))
    print("Булеан множества:")
    for i, subset in enumerate(boolean_set, start=1):
        print(f"Подмножество {i}: {subset if subset else '{{}}'}")
except ValueError as e:
    print(f"Ошибка: {str(e)}")