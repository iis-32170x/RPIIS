import  pygame

class Swamp(pygame.sprite.Sprite):
    def __init__(self, x, y, image):
        super().__init__()
        self.x=x
        self.y=y
        self.image = image
        self.rect = self.image.get_rect(center=(x,y))
    def update(self):
        pass