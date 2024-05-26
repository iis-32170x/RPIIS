import ast

def perestanovki(a:list, pamyat=None):
    if pamyat is None:
        pamyat = []

    results = []

    for i in range(len(a)):
        element = a.pop(i)
        if len(a) == 0:
            results.append(pamyat + [element])
        results.extend(perestanovki(a[:], pamyat + [element]))
        a.insert(i, element)
    return results

def delete_povtory(a):
    d = []
    for element in a: 
        if element not in d:
            d.append(element)
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



x = input("Введите множество\n")
x_new = x.replace('{', '[')
x_got = x_new.replace('}', ']')
x_new_1 = x_got.replace('<', '(')
x_got_2 = x_new_1.replace('>', ')')
branch = ast.literal_eval(x_got_2)
x_per = get_list(branch)
results = perestanovki(x_per)
for element in results:
    print(element,"\n")