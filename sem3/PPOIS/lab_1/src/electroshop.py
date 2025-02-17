from customer import Customer
from product import Product
from typing import Optional, List


class Electroshop:
    def __init__(self, customers: Optional[List[Customer]] = None) -> None:
        self.__customers: List[Customer] = customers if customers else []

    def show_customers(self) -> None:
        if self.__customers:
            for index, customer in enumerate(self.__customers, start=1):
                print(f"{index}. ", end="")
                customer.print_info()
                print()
        else:
            print("Покупателей нет")

    def add_customer(self, name: str, money: int, products: Optional[List[Product]] = None) -> None:
        if any(customer.get_name().lower() == name.lower() for customer in self.__customers):
            print(f"Покупатель {name} уже существует\n")
        else:
            self.__customers.append(Customer(name, money, products))
            print(f"Покупатель {name} добавлен\n")

    def remove_customer(self, name: str) -> None:
        for customer in self.__customers:
            if customer.get_name().lower() == name.lower():
                self.__customers.remove(customer)
                print(f"Покупатель {name} удалён\n")
                return
        print(f"Покупателя {name} не найдено\n")

    def get_customer(self) -> Optional[Customer]:
        while True:
            try:
                choice = int(input("Введите номер в списке покупателей: "))
                if 1 <= choice <= len(self.__customers):
                    return self.__customers[choice - 1]
                else:
                    print("Такого номера нет")
            except ValueError:
                print("Пожалуйста, введите целое число\n")

    def get_customers(self) -> List[Customer]:
        return self.__customers