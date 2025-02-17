import random


class Share:

    def lottery() -> bool:
        choice = int(input("Введите число от 1 до 5: "))
        if choice < 1 or choice > 5:
            raise ValueError("Число должно быть от 1 до 5.")    
        random_number = random.randint(1, 5)  
        return choice == random_number
    
