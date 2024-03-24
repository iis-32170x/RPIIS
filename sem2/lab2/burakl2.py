from buraksets import Mnozh, strToSet

infile = input('Из какого файла вы хотите прочитать множества? ')

try:
    file = open(infile, mode='r', encoding='utf-8')
except:
    print('Ошибка при чтении файла!')
else:
    string1 = file.readline()
    string2 = file.readline()

    set1 = strToSet(string1)
    set2 = strToSet(string2)

    print()

    if set1 == 'Error' and set2 == 'Error':
        print('Ошибка при чтении обоих множеств!')
        
    elif set1 == 'Error':
        print('Ошибка при чтении первого множества!')
        
    elif set2 == 'Error':
        print('Ошибка при чтении второго множества!')
        
    else:
        print('Первое множество:', Mnozh.setToStr(set1))
        print('Второе множество:', Mnozh.setToStr(set2))
        
        print()
        
        print('Первое множество -',end=' ')
        if not Mnozh.isElement(set1, set2):
            print('не', end=' ')
        print('элемент второго.')
        
        print('Второе множество -', end=' ')
        if not Mnozh.isElement(set2, set1):
            print('не',end=' ')
        print('элемент первого.')
        
        print('Первое множество -',end=' ')
        if not Mnozh.isSubset(set1, set2):
            print('не', end=' ')
        print('подмножество второго.')
        
        print('Второе множество -',end=' ')
        if not Mnozh.isSubset(set2, set1):
            print('не', end=' ')
        print('подмножество первого.')

    file.close()