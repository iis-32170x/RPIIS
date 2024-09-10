from collections import Counter

class CustomSet(set):
    def add(self, element):
        """Переопределенный метод add для поддержки вложенных множеств."""
        if isinstance(element, CustomSet):
            # Преобразуем вложенное CustomSet в frozenset для хэшируемости
            super().add(frozenset(element))
        else:
            super().add(element)
    
    def remove(self, element):
        """Переопределенный метод remove для поддержки вложенных множеств."""
        if isinstance(element, CustomSet):
            # Преобразуем вложенное CustomSet в frozenset для хэшируемости
            super().remove(frozenset(element))
        else:
            super().remove(element)

    def __contains__(self, element):
        """Переопределенный метод __contains__ для проверки наличия элемента."""
        if isinstance(element, CustomSet):
            # Проверяем наличие frozenset (вложенного множества)
            return frozenset(element) in super().__contains__(element)
        else:
            return super().__contains__(element)

    def flatten(self):
        """Метод для получения всех элементов в виде списка, включая элементы из вложенных множеств."""
        flat_list = []
        for item in self:
            if isinstance(item, frozenset):
                # Рекурсивное распаковывание вложенного множества
                flat_list.extend(CustomSet(item).flatten())
            else:
                flat_list.append(item)
        return flat_list

    def __repr__(self):
        """Переопределяем __repr__ для корректного отображения вложенных множеств."""
        def set_repr(s):
            elements = [set_repr(e) if isinstance(e, frozenset) else repr(e) for e in s]
            return '{' + ', '.join(elements) + '}'
        return set_repr(self)

def parse_set_from_string(s):
    """Парсинг строки в CustomSet с учетом вложенных структур."""
    stack = []  # Стек для отслеживания вложенных множеств
    current_set = CustomSet()  # Текущее множество для добавления элементов
    
    i = 0
    while i < len(s):
        if s[i] == '{':
            # Начало нового вложенного множества
            stack.append(current_set)
            current_set = CustomSet()
            i += 1
        elif s[i] == '}':
            # Конец текущего множества
            if stack:
                parent_set = stack.pop()
                parent_set.add(current_set)
                current_set = parent_set
            i += 1
        elif s[i].isdigit() or (s[i] == '-' and s[i+1].isdigit()):
            # Обработка чисел
            j = i
            while j < len(s) and (s[j].isdigit() or s[j] == '-'):
                j += 1
            num = int(s[i:j])
            current_set.add(num)
            i = j
        else:
            i += 1  # Пропуск символов (например, пробелов)

    return current_set

def union_with_multiplicity(*sets):
    """Объединение множеств с учетом кратности элементов и вложенных структур."""
    combined_set = CustomSet()  # Итоговое множество для объединения всех входных множеств
    combined_counter = Counter()  # Счетчик для учета кратности элементов

    for s in sets:
        flattened_elements = s.flatten()
        combined_counter.update(flattened_elements)
    
    for element, count in combined_counter.items():
        for _ in range(count):
            combined_set.add(element)
    
    return combined_set

def read_sets_from_file(file_path):
    """Чтение множеств из файла и преобразование строк в объекты CustomSet."""
    sets = []
    with open(file_path, 'r') as file:
        for line in file:
            cleaned_line = line.strip()  # Убираем лишние пробелы и символы перевода строки
            # Преобразуем строку в CustomSet
            set_from_line = parse_set_from_string(cleaned_line)
            sets.append(set_from_line)
    return sets

# Пример использования
sets = read_sets_from_file('sets.txt')

result = union_with_multiplicity(*sets)

print(result)