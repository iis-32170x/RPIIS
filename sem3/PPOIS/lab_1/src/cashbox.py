from product import Product
from customer import Customer


class Cashbox:
    @staticmethod
    def buy_product(customer: Customer, product: Product) -> None:
        price: int = product.get_price()
        current_money: int = customer.get_money()
        
        if price > current_money:
            print("Недостаточно средств для совершения покупки\n")
        else:
            new_balance: int = current_money - price  
            customer.set_money(new_balance)  
            customer.add_product(product)
            print(f"Вами был приобретен товар {product.get_name()}. Спасибо за покупку!\n")

    @staticmethod
    def return_product(customer: Customer, product: Product) -> None:
        price: int = product.get_price()
        current_money: int = customer.get_money()
        
        new_balance: int = current_money + price  
        customer.set_money(new_balance)  
        customer.remove_product(product)
        print(f"За товар {product.get_name()} вам было возвращено {price} BYN. Хорошего дня!\n")