from guarantee import Guarantee


class Product:
    def __init__(self, name, price: int, term : float) -> None:
        self.__name = name
        self.__price = price
        self.__guarantee = Guarantee(term)

    def get_name(self) -> str:
        return self.__name
        
    def get_price(self) -> int:
        return self.__price
        
    def get_guarantee(self) -> float:
        return self.__guarantee.get_term()    
    
    def print_info(self) -> None:
        print(f"Название: {self.__name}  Цена: {self.__price}  Гарантия: {self.__guarantee.get_term()}\n")
      