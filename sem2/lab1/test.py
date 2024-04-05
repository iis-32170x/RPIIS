from hash_lib_lab1 import HashTable

table = HashTable(10)
table.put("apple", 1)
table.put("banana", 2)
print(table.get("apple"))  # Выведет 1
print(table.get("orange"))  # Выведет None
table.remove("apple")
print(table.get("apple"))  # Выведет None
