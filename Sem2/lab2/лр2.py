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

def perecezenie(a:list, b:list):
    d = []
    for e in a: 
        if e in b:
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


     
vybor_2 = int(input('''
        1 - Ввод через файл
        2 - Другое     
                        \n'''))

if vybor_2 == 1:
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

            novoe = perecezenie(novoe, spis_mnozestv[i + 1])
            
        print('Пересечение',len(lines),'множеств',novoe)
else:
    y = int(input('Введите количество множеств которые желаете пересечь\n'))
    while y !=0:
        vybor = int(input('''
        1 - Ввод автоматически
        2 - Ввод самому              
                        \n'''))
                        
        spis_mnozestv = list()
        for i in range(y):
            mnozestvo = list()
            if vybor == 1:
                kol_elementov = random.randint(1, 10)
                for i in range(kol_elementov):
                    mnozestvo.append(random.randint(1,10))
                spis_mnozestv.append(mnozestvo)
            if vybor == 2:
                x = input("Введите множество")
                x_new = x.replace('{', '[')
                x_got = x_new.replace('}', ']')
                x_new_1 = x_got.replace('<', ')')
                x_got_2 = x_new_1.replace('>', ')')
                branch = ast.literal_eval(x_got_2)
                x_per = get_list(branch)
                spis_mnozestv.append(x_per)
                
        print(spis_mnozestv)

        novoe = list()
        novoe = spis_mnozestv[0]
        for i in range(y):
            novoe = perecezenie(novoe, spis_mnozestv[i + 1])
            
        print('Пересечение',y,'множеств',novoe)

        y = int(input('''Если желаете пересечь еще произвольные множества тогда:
    Введите количество множеств которые желаете пересечь
    Иначе введите 0 для завершения программы\n'''))