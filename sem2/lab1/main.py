import bibla

# Создание множества в системе
print('Test1')
bibla._set()._init_(1)
print(bibla._set.system)
# Создание второго такого же множества в системе
print('Test2')
bibla._set()._init_(1)
print(bibla._set.system)
# Нахождение элемента в системе
print('Test3')
bibla._set()._init_(2)
bibla._set()._init_(3)


print(bibla._set().is_in(3))
# Объединение множеств с определенными элементами
print('Test4')
print('Система до объединения',bibla._set().system)
bibla._set().unite(2,3)
print('Система после объединения',bibla._set().system)

