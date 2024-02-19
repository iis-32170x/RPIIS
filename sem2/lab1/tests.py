import bibla
#Тест1 - проверка на создание множества со 100 элементами от 0 до 1000
mnozh_num = bibla._set()._init_from_one_number_to_your_second_number(0, 1000)
#Тест2 - проверка на объединение множеств с одинаковыми элементами
mnozh1 = bibla._set()._init_from_one_number_to_your_second_number(0,10)
mnozh2 = bibla._set()._init_from_one_number_to_your_second_number(0,10)
mnozh_unit = bibla._set().unite(mnozh1,mnozh2)
#Тест3- проверка на нахождение элемента 3 в множестве(1,2,3)
mnozh_3 = bibla._set()._init_from_one_number_to_your_second_number(0,3)
#Тест4 - проверка на объединение множеств элементами c абсолютно различными элементами
first_set = bibla._set()._init_from_one_number_to_your_second_number(0,10)
second_set = bibla._set()._init_from_one_number_to_your_second_number(11,20)
#Тест5 - проверка на объединение множеств с некоторыми различными элементами
first_set1 = bibla._set()._init_from_one_number_to_your_second_number(0,10)
second_set1 = bibla._set()._init_from_one_number_to_your_second_number(5,15)
#Тест6 - объединение пустого множества с другим множеством
first_set2 =[]
second_set2 = bibla._set()._init_from_one_number_to_your_second_number(0,10)