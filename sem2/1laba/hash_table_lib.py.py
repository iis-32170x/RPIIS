    
    class HashTable: 
    def add_element(self, key, value):
        self.hash_table[key] = value

    def remove_element(self, key):
        if key in self.hash_table:
            del self.hash_table[key]

    def print_table(self):
        for key, value in self.hash_table.items():
            print(f"{key}: {value}")