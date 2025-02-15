from Attraction import Attraction

class Route:
    """Класс маршрута"""
    def __init__(self, name: str):
        self.name = name
        self.attractions = []

    def add_attraction(self, attraction: Attraction):
        """Добавляет достопримечательность в маршрут"""
        self.attractions.append(attraction)

    def show_route(self):
        """Выводит маршрут"""
        return f"Маршрут {self.name}: " + " -> ".join([a.name for a in self.attractions])