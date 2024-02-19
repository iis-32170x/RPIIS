import bibla
from tests import mnozh_num
from tests import mnozh_unit
from tests import mnozh_3
from tests import first_set
from tests import second_set
from tests import first_set1
from tests import second_set1
from tests import first_set2
from tests import second_set2

# num1 = int(input('Введите кол-во элементов первого массива '))
# print('Введите элементы первого массива')
# mnozh1=bibla._set()._init_(num1)
#
# num2 = int(input('Введите кол-во элементов второго массива '))
# print('Введите элементы второго массива')
# mnozh2 = bibla._set()._init_(num2)
# print(mnozh2, mnozh1)
# mnozh3 = bibla._set().unite( mnozh1,mnozh2)
# print(mnozh3)
# bibla._set().is_in([1,2,3,4,5],[1,2,3],[1,2],3)
print("Тест1:")
print(mnozh_num)
print("Тест пройден")
print("Тест2:")
print(mnozh_unit)
print("Тест3:")
bibla._set().is_in(mnozh_3,3)
print("Тест4:")
print(first_set)
print(second_set)
mnozh_unit2 = bibla._set().unite(first_set, second_set)
print(mnozh_unit2)
print("Тест5")
print(first_set1)
print(second_set1)
mnozh_unit2 = bibla._set().unite(first_set1, second_set1)
print(mnozh_unit2)
print("Тест6:")
print(first_set2)
print(second_set2)
mnozh_unit2 = bibla._set().unite(first_set2, second_set2)
print(mnozh_unit2)
print("Тест7")
mnozh_unit3 =bibla._set().unite([],[])
print(mnozh_unit3)

