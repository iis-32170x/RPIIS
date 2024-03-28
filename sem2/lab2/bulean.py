####################################################
#   Название: Булеаноинатор
#   Разработчик: Гетман Данила Русланович
#   Дата: 28.03.2024
#   Описание: программа получает из заданного текстового файла
#   множество (пример: {1,2,3,4,5} ), далее разбивает его на элементы
#   записывая каждый элемент в новую строку и затем формирует булеан
#   исходного множества и выводит его на экран. 
####################################################

def create_power_set(Set_elements):
    power_set = []
    for i in range (1 << len(Set_elements)):
        subset = []
        for j in range (len(Set_elements)):
            if i & (1 << j):
                subset.append(Set_elements[j])
        power_set.append(subset)
    return power_set

def read_set(filename):
    with open(filename, 'r') as file:
        Set = file.readline().strip()
        print(Set)
        
        if (Set[0] != '{' or Set[-1] != '}'):
            raise ValueError("Множество не заключено в фигурные скобки.")
        
        Set_elements = [] #Множество строк, в которое будут записываться элементы исходного множества
        current_element = "" #Переменная для хранения обрабатываемого элемента
        Set = Set[1: -1]  #Обрезает крайние скобки у строки множества
        i = 0
        while(i < len(Set)):
            if ( Set[i] == ' '):
                raise ValueError("Некорректная запись множества. Элементы множества не должны быть разделены пробелами.")        
            elif Set[i] == '{':                
                isInside = True
                current_element += Set[i]
                i += 1

                while i < len(Set):
                    if Set[i] == ',' and not isInside:
                        Set_elements.append(current_element)
                        current_element = ""
                        break
                    elif Set[i] == ' ':
                        raise ValueError("Некорректная запись множества. Элементы множества не должны быть разделены пробелами.")   
                    current_element += Set[i] 
                    
                    if current_element.count('<') < current_element.count('>'):
                        raise ValueError("Некорректная запись элемента множества")
                            
                    if current_element.count('{') == current_element.count('}'):
                        if current_element[0] != '{' or current_element[-1] != '}':
                            raise ValueError("Некорректная запись элемента множества")
                        isInside = False    
                    i += 1
            elif Set[i] == '<':
                isInside = True
                current_element += Set[i]
                i += 1
                while i < len(Set):
                    if Set[i] == ',' and not isInside:
                        Set_elements.append(current_element)
                        current_element = ""
                        break
                    if Set[i] == ' ':
                        raise ValueError("Некорректная запись множества. Элементы множества не должны быть разделены пробелами.")   
                    current_element += Set[i] 
                    
                    if current_element.count('{') < current_element.count('}'):
                        raise ValueError("Некорректная запись элемента множества")
                    
                    elif current_element.count('<') == current_element.count('>'):
                        if current_element[0] != '<' or current_element[-1] != '>':
                            raise ValueError("Некорректная запись элемента множества")
                        isInside = False
                    i += 1

            elif (Set[i] == ','): 
                Set_elements.append(current_element)
                current_element = ""
            else:
                current_element += Set[i]
            i += 1
        
        if (current_element != ""):
            if (current_element[0] == '{' and current_element[-1] != '}') or (current_element.count('{') != current_element.count('}')):
                raise ValueError("Некорректная запись элемента множества")
            if (current_element[0] == '<' and current_element[-1] != '>') or (current_element.count('<') != current_element.count('>')):
                raise ValueError("Некорректная запись элемента множества")

            Set_elements.append(current_element)
            current_element = ""
        return Set_elements

filename = input("Введите имя файла: ")

Set_elements = read_set(filename)
power_set = create_power_set(Set_elements)

for i in range (len(power_set)):
    print(f"Подмножество {i+1}: {{{",".join(power_set[i])}}}")