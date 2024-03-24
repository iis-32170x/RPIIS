class HashTable:
    def __init__(self, bucket_count):
        self.bucket_count = bucket_count
        self.buckets = [ [] for _ in range(bucket_count)]

    def hash(self, key):
        return hash(key) % self.bucket_count

    def add_element(self, key, value):
        hash_value = self.hash(key)
        bucket = self.buckets[hash_value]
        for item in bucket:
            if item[0] == key:
                print("Коллизия! Элемент с таким ключом уже существует.")
                choice = input("Хотите перезаписать элемент? (да/нет): ")
                if choice.lower() == "да":
                    item[1] = value
                return
        bucket.append([key, value])

    def remove_element(self, key):
        hash_value = self.hash(key)
        bucket = self.buckets[hash_value]
        for item in bucket:
            if item[0] == key:
                bucket.remove(item)
                return
        print("Элемент с таким ключом не найден.")

    def print_table(self):
        for i, bucket in enumerate(self.buckets):
            print(f"Бакет {i}:")
            for item in bucket:
                print(f"  {item[0]}: {item[1]}")