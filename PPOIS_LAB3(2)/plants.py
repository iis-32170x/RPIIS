import pygame

class Plant(pygame.sprite.Sprite):
    def __init__(self, x, y, health, image, dead_image):
        super().__init__()
        self.x = x
        self.y = y
        self.health = health
        self.image = image
        self.dead_image = dead_image
        self.rect = self.image.get_rect(center=(self.x, self.y))

    def update(self):
        if self.health <= 0:
            self.image = self.dead_image
            self.rect = self.image.get_rect(center=(self.x, self.y))  # Обновляем rect

class Maple(Plant):
    def __init__(self, x, y, health, image, dead_image):
        super().__init__(x, y, health, image, dead_image)

class Dry_tree(Plant):
    def __init__(self, x, y, health, image, dead_image):
        super().__init__(x, y, health, image, dead_image)

class Aspen(Plant):
    def __init__(self, x, y, health, image, dead_image):
        super().__init__(x, y, health, image, dead_image)