from typing import List
from Photo import Photo

class Attraction:
    """Класс достопримечательности"""
    def __init__(self, name: str, description: str):
        self.name = name
        self.photo = []
        self.description = description
        self.visit = None
        self.reviews = []

    def add_review(self, review: str):
        """Добавляет отзыв"""
        if not self.visit:
            raise ValueError("Невозможно добавть отзыв ,статус: не посещено")
        else:
            self.reviews.append(review)



    def add_photo(self, photo: Photo):
        if not self.visit:
            raise ValueError("Невозможно добавть фото ,статус: не посещено")
        else:
            self.photo.append(photo)

    def change_visiting(self):
        self.visit = True

    def show_info(self):
        """Выводит информацию о достопримечательности"""
        return f"{self.name}\n{self.description}\nОтзывы: {self.reviews}\nФото: {self.photo}\nПосещено: {'да' if self.visit else 'нет'}"