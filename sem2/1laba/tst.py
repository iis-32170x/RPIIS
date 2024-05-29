from hash_table_lib import HashTable


bucket_count = 10  # Количество бакетов
hash_table = HashTable(bucket_count)

# Ввод данных пользователем
n = int(input("Введите количество элементов для добавления в хэш-таблицу: "))

for i in range(n):
    key = input("Введите ключ элемента: ")
    value = input("Введите значение элемента: ")
    hash_table.add_element(key, value)

# Вывод хэш-таблицы
print("Хэш-таблица:")
hash_table.print_table()

# Добавление дополнительных элементов
choice = input("Хотите добавить еще элементы? (да/нет): ")
while choice.lower() == "да":
    key = input("Введите ключ элемента: ")
    value = input("Введите значение элемента: ")
    hash_table.add_element(key, value)
    choice = input("Хотите добавить еще элементы? (да/нет): ")




# Вывод окончательной хэш-таблицы
print("Окончательная хэш-таблица:")
hash_table.print_table()

# Удаление элемента
choice = input("Хотите удалить элемент из хэш-таблицы? (да/нет): ")
while choice.lower() == "да":
    key = input("Введите ключ элемента для удаления: ")
    hash_table.remove_element(key)
    choice = input("Хотите удалить еще элемент? (да/нет): ")

# Вывод окончательной хэш-таблицы после удаления
print("Окончательная хэш-таблица после удаления:")
hash_table.print_table()