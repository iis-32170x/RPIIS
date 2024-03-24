# Определение корректности введённой строки (до перевода в формат множества)
def hasCorrectFormat1(string):
    # Удаление пробельных символов в начале и в конце строки
    string = string.strip()
    # Удаление пробелов внутри строки
    string = string.replace(' ', '')
    
    # Строка не может состоять исключительно из фигурных скобок или быть пустой
    if string == '{}' or string == '':
        return False
    
    # Строка обязана начинаться и заканчиваться фигурными скобками
    if string[0] != '{' or string[-1] != '}':
        return False
    
    # Удаление фигурных скобок из строки для удобства дальнейшей проверки на корректность
    string = string[1:-1]
    
    # Выражение внутри фигурных скобок не может начинаться или заканчиваться запятой
    if string[-1] == ',' or string[0] == ',':
        return False
    
    # Если происходит ошибка при делении строки по запятым, строка явно имеет неверный формат
    try:
        list1 = string.split(',')
    except:
        return False
    else:
        open_br = False
        for i in range(len(string)):
            # Членами множества могут быть исключительно одиночные латинские буквы
            if i != len(string)-1 and string[i].isalpha() and string[i+1].isalpha():
                return False
            if not string[i].isalpha() and not string[i] in ['{','}',',']:
                return False
            
            if string[i] == '{' and not open_br:
                open_br = True
            # Не позволяется иметь больше одного вложенного множества
            elif string[i] == '{' and open_br:
                return False
            elif string[i] == '}' and open_br:
                open_br = False
            # Закрывающая фигурная скобка обязана идти после открывающей
            elif string[i] == '}' and not open_br:
                return False
            # Открытая фигурная скобка должна закрыться
            elif open_br and i == len(string)-1:
                return False
        return True

# Определение корректности введённой строки (после перевода в формат множества)
def hasCorrectFormat2(set1):
    # В полученном множестве не должны содержаться фигурные скобки и пустые элементы
    if len(set1) > 1:
        if ('' in set1) or ('{' in set1) or ('}' in set1):
            return False
    return True


# Перевод строки в множество
def strToSet(string):
    # Если формат строки некорректный, выводим сообщение об ошибке вместо множества
    if not hasCorrectFormat1(string):
        return 'Error'
    
    # Удаление пробелов из строки
    string = string.strip()
    string = string.replace(' ','')
    # Разделение строки по запятым
    string = string[1:-1]
    list1 = string.split(',')
    
    # Объявление списка, который после обработки будет возвращён как значение функции
    list2 = []
    in_set = False
    for i in list1:
        is_long = (len(i)>=2)
        # Если подсписок содержит один элемент, он сразу добавляется в список
        if is_long and i[0]=='{' and i[-1]=='}':
            list2.append(i)
        # Если в подсписке два и более элемента
        elif is_long and i[0]=='{':
            # Объявление строки, в которой содержится начало подсписка
            a = i
            # Вхождение в состояние записи подсписка
            in_set = True
        # Если мы в состоянии записи подсписка и рассматриваемый элемент - конец подсписка
        elif is_long and in_set and i[-1]=='}':
            # Выход из состояния записи подсписка
            in_set = False
            # Добавление подсписка в список
            list2.append(a + ',' + i)
        # Если мы в состоянии записи подсписка и рассматриваемый элемент находится посреди подсписка
        elif in_set:
            # Добавляем элемент в строку с подсписком
            a += ','
            a += i
        # Если мы не в подсписке, сразу добавляем элемент в список
        else:
            list2.append(i)
            
    # Если формат получившегося списка некорректный, выводим сообщение об ошибке вместо множества
    if not hasCorrectFormat2(list2):
        return 'Error'
    
    # Обработка подсписков
    for i in range(len(list2)):
        # Если подсписок проходит первую проверку на корректность
        if hasCorrectFormat1(list2[i]):
            # Переводим подсписок из формата строки в формат списка
            p = strToSet(list2[i])
            # Если перевод прошёл успешно, подсписок заменяется на отсортированную версию
            if p != 'Error':
                list2[i] = Mnozh.setToStr(p)
            # В противном случае, вместо множества выводим сообщение об ошибке
            else:
                return 'Error'
    # Переводим список в формат множества, сортируем и
    # возвращаем как значение функции
    return sorted(set(list2))


class Mnozh:
    # Перевод множества в строку
    def setToStr(sett):
        string = '{'
        string += ','.join(sett)
        string += '}'
        return string
    # Является ли множество A подмножеством данного множества?
    def isSubset(a,sett):
        # Проверка на корректность обоих множеств
        c = strToSet(Mnozh.setToStr(a))
        d = strToSet(Mnozh.setToStr(sett))
        if c != 'Error' and d != 'Error':
            # Множество A является подмножеством множества B тогда и только тогда, когда каждый элемент из A принадлежит B
            for element in c:
                if element not in d:
                    return False
            return True
        else:
            return 'Error'
    # Является ли множество A элементом данного множества?
    def isElement(a,sett):
        # Проверка на корректность обоих множеств
        c = strToSet(Mnozh.setToStr(a))
        d = strToSet(Mnozh.setToStr(sett))
        if c != 'Error' and d != 'Error':
            return (Mnozh.setToStr(c) in d)
        else:
            return 'Error'
    