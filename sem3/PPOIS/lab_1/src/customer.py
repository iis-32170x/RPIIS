from product import Product
from typing import List, Optional


class Customer:
    def __init__(self, name: str, money: int, products: Optional[List[Product]] = None) -> None:
        self.__name: str = name
        self.__money: int = money
        self.__products: List[Product] = products if products else []

    def get_name(self) -> str:
        return self.__name
    
    def add_product(self, product: Product) -> None:
        self.__products.append(product)

    def remove_product(self, product: Product) -> None:
        self.__products.remove(product)

    def print_info(self) -> None:
        product_info = ", ".join(product.get_name() for product in self.__products)
        print(f"Имя покупателя: {self.__name}\nБаланс: {self.__money}\nТовары: {product_info if product_info else 'Нет покупок'}")

    def set_money(self, money: int) -> None:
        self.__money = money
    
    def get_money(self) -> int:
        return self.__money
    
    def get_customer_products(self) -> list[Product]:
        return self.__products
    
    def set_customer_products(self, products: list[Product]) -> None:
        self.__products = products