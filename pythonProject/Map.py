from Attraction import Attraction

class Map:
    def __init__(self):
        self.attractions = []

    def add_attraction(self, attraction:Attraction):
        self.attractions.append(attraction)

    def show_attractions(self):
        for attraction in self.attractions:
            print(attraction.name," Посещено: " , "Да" if attraction.visit else "Нет")