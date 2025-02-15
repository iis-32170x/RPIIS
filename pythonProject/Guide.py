from typing import List

from Attraction import Attraction
from Route import Route
from Map import Map

class Guide:
    """Электронный гид"""
    def __init__(self):
        self.attractions = []
        self.routes = []

    def add_attraction(self, attraction: Attraction,map:Map):
        """Добавляет достопримечательность"""
        self.attractions.append(attraction)
        map.add_attraction(attraction)

    def create_route(self, name: str, attraction_names: List[str]):
        """Создаёт маршрут по достопримечательностям"""
        route = Route(name)
        for name in attraction_names:
            attraction = next((a for a in self.attractions if a.name == name), None)
            if attraction:
                route.add_attraction(attraction)
        self.routes.append(route)

    def find_attraction(self, name: str):
        """Поиск достопримечательности"""
        return next((a for a in self.attractions if a.name == name), None)

    def show_map(self,map: Map):
        map.show_attractions()

    def show_attraction_info(self,map : Map,number):
        try:
            map.attractions[number].show_info()
        except ValueError:
            print("Не правильно введен номер")



