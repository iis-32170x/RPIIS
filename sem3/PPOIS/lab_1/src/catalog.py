from product import Product
from typing import List, Optional


class Catalog:
    def __init__(self, products: Optional[List[Product]] = None) -> None:
        self.__products: List[Product] = products if products else []

    def add_product(self, name: str, price: int, term: float) -> None:
        if any(product.get_name().lower() == name.lower() for product in self.__products):
            print(f"Товар с названием {name} уже существует\n")
        else:
            self.__products.append(Product(name, price, term))
            print(f"Продукт {name} добавлен в каталог\n")

    def remove_product(self, name: str) -> None:
        for product in self.__products:
            if product.get_name().lower() == name.lower():
                self.__products.remove(product)
                print(f"Продукт {name} удалён из каталога\n")
                return
        print(f"Продукта с названием {name} не найдено\n")

    def display_catalog(self) -> None:
        if self.__products:
            print("\n----------Каталог----------\n")
            for index, product in enumerate(self.__products, start=1):
                product.print_info()
        else:
            print("Покупателей нет")

    def find_product(self, name: str) -> Optional[Product]:
        for product in self.__products:
            if product.get_name().lower() == name.lower():
                return product
        return None
    
    def get_catalog(self) -> List[Product]:
        return self.__products