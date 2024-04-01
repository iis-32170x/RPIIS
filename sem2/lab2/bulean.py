####################################################
#   Название: Булеаноинатор
#   Разработчик: Гетман Данила Русланович
#   Дата: 28.03.2024
#   Описание: программа получает из заданного текстового файла
#   множество (пример: {1,2,3,4,5} ), далее разбивает его на элементы
#   записывая каждый элемент в новую строку и затем формирует булеан
#   исходного множества и выводит его на экран. 
####################################################

def readtuple(Tuple):
    Elements = readElements(Tuple)
    result = "<"
    result += ','.join(Elements)
    result += '>'
    return result

def readsubset(Set):
    Elements = readElements(Set)
    subset = "{"
    subset += ','.join(Elements)
    subset += '}'
    return subset

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
            subset.append(readsubset(current_element))
            current_element = ""
        elif current_element.count('<') > 0:
            if (current_element[0] != '<' or current_element[-1] != '>'):
                raise ValueError("Некорректная запись элемента множества.")
            subset.append(readtuple(current_element))
            current_element = ""

        elif (subset.count(current_element) < 1):
            subset.append(current_element)
            current_element = ""

    return subset

def create_power_set(Set_elements):
    power_set = []
    for i in range (1 << len(Set_elements)):
        subset = []
        for j in range (len(Set_elements)):
            if i & (1 << j):
                subset.append(Set_elements[j])
        power_set.append(subset)
    return power_set

filename = input("Введите имя файла: ")

with open(filename, 'r') as file:
    SET = file.readline().strip()

    print(SET)
    print("-------------------------")
    result = readElements(SET)
    print(result)

power_set = create_power_set(result)

for i in range (len(power_set)):
    print(f"Подмножество {i+1}: {{{",".join(power_set[i])}}}")