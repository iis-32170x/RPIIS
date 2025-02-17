import json
from catalog import Catalog
from cashbox import Cashbox
from customer import Customer
from consultant import Consultant
from electroshop import Electroshop
from share import Share
from product import Product
from typing import Optional, List


def save_state(catalog: Catalog, electroshop: Electroshop) -> None:
    data = {
        'products': [{'name': p.get_name(), 'price': p.get_price(), 'guarantee': p.get_guarantee()} for p in catalog.get_catalog()],
        'customers': [{'name': c.get_name(), 'money': c.get_money(), 'purchases': [p.get_name() for p in c.get_customer_products()]} for c in electroshop.get_customers()]
    }
    
    with open('state.json', 'w') as f:
        json.dump(data, f)


def load_state(catalog: Catalog, electroshop: Electroshop) -> None:
    try:
        with open('state.json', 'r') as f:
            data = json.load(f)
            for product in data['products']:
                catalog.add_product(product['name'], product['price'], product['guarantee'])
            for customer in data['customers']:
                purchases = [catalog.find_product(p) for p in customer['purchases']]
                update_customer(electroshop, customer['name'], customer['money'], purchases)
    except FileNotFoundError:
        print("Файл состояния не найден, начинается новая сессия.")


def update_customer(electroshop: Electroshop, name: str, money: int, purchases: List[Product]) -> None:
    customer_found = False
    
    for customer in electroshop.get_customers():
        if customer.get_name() == name:
            customer_found = True
            customer.set_money(money)  
            customer.set_customer_products(purchases)
            break
    
    if not customer_found:
        electroshop.add_customer(name, money, purchases)


def find_product_by_name(catalog: Catalog) -> Optional[Product]:
    name: str = input("Введите название продукта: ")
    product: Optional[Product] = catalog.find_product(name)
    
    if product:
        product.print_info()
        return product
    else:
        print("Такого у нас нет")
        return None


def buy_product_by_customer(electroshop: Electroshop, catalog: Catalog) -> None:
    electroshop.show_customers()
    customer: Customer = electroshop.get_customer()
    catalog.display_catalog()
    product: Optional[Product] = find_product_by_name(catalog)
    
    if not product:
        print("Всё заново")
        return
    
    Cashbox.buy_product(customer, product)


def return_product_by_customer(electroshop: Electroshop, catalog: Catalog) -> None:
    electroshop.show_customers()
    customer: Customer = electroshop.get_customer()
    customer.print_info()
    product: Optional[Product] = find_product_by_name(catalog)
    
    if not product:
        print("Всё заново")
        return
    
    Cashbox.return_product(customer, product)


def customer_lottary(electroshop: Electroshop) -> None:
    electroshop.show_customers()
    customer: Customer = electroshop.get_customer()
    
    if Share.lottery():
        print("Вы выиграли 20 BYN!!!! ")
        money: int = customer.get_money()
        new_balance: int = money + 20
        customer.set_money(new_balance)
    else:
        print("Вы проиграли :(")


def display_menu() -> None:
    print("\nМеню:")
    print("1. Поиск товара в каталоге")
    print("2. Часто задаваемые вопросы")
    print("3. Купить товар")
    print("4. Вернуть товар")
    print("5. Участвовать в акции")
    print("6. Выход\n")


def main_menu() -> None:
    catalog: Catalog = Catalog()
    electroshop: Electroshop = Electroshop()
    
    load_state(catalog, electroshop)

    if not catalog.get_catalog():
        catalog.add_product("Iphone 15 pro", 4000, 1)
        catalog.add_product("Пылесос Sumsung 2374", 1745, 2)
        catalog.add_product("Холодильник Атлант", 2740, 5)
        catalog.add_product("Xiaomi", 1350, 2)
        catalog.add_product("Notebook Lenovo", 2840, 5)
        catalog.add_product("Душесос 3000", 9999, 0)
        catalog.add_product("Семантический компьтер", 777, 30)

        list1: List[Product] = [catalog.find_product("Iphone 15 pro"), catalog.find_product("Xiaomi")]
        list2: List[Product] = [catalog.find_product("Душесос 3000"), catalog.find_product("Холодильник Атлант")]
        list3: List[Product] = [catalog.find_product("Семантический компьтер")]

        electroshop.add_customer("Bob", 7000, list1)
        electroshop.add_customer("Lesli", 2000, list2)
        electroshop.add_customer("Jessika", 30, list3)

    consultant: Consultant = Consultant()

    while True:
        display_menu()

        try:
            choice: int = int(input("Выберите действие (1-6): "))
            if choice == 1:
                find_product_by_name(catalog)
            elif choice == 2:
                consultant.show_questions()
                consultant.choice_question()
            elif choice == 3:
                buy_product_by_customer(electroshop, catalog)
            elif choice == 4:
                return_product_by_customer(electroshop, catalog)
            elif choice == 5:
                customer_lottary(electroshop)
            elif choice == 6:
                print("Выход из программы.")
                save_state(catalog, electroshop)  # Сохранение состояния перед выходом
                break
            else:
                print("Введите верное число от 1 до 6")
        except ValueError:
            print("Введите верное число от 1 до 6")


if __name__ == "__main__":
    main_menu()