import math  # Импорт модуля math для математических операций (например, вычисления углов)
from loading_images import bullet_image  # Импорт изображения пули из модуля loading_images
from temporaries import *  # Импорт всех объектов из модуля temporaries (например, game_state)

class Bullet(pygame.sprite.Sprite):
    """
    Класс Bullet представляет пулю, которую выпускает игрок или враги.
    Наследуется от pygame.sprite.Sprite для интеграции с группами спрайтов.
    """
    def __init__(self, position, angle, speed, damage):
        """
        Инициализация пули.

        :param position: Кортеж (x, y) с начальной позицией пули.
        :param angle: Угол направления пули в радианах.
        :param speed: Скорость движения пули.
        :param damage: Урон, который наносит пуля.
        """
        super().__init__()  # Инициализация родительского класса (Sprite)
        self.original_image = bullet_image  # Изображение пули
        # Поворот изображения пули в соответствии с углом направления
        self.image = pygame.transform.rotate(self.original_image, -math.degrees(angle))
        # Прямоугольник, описывающий положение и размер пули
        self.rect = self.image.get_rect(center=position)
        self.speed = speed  # Скорость пули
        self.angle = angle  # Угол направления пули
        self.damage = damage  # Урон пули

    def update(self):
        """
        Обновление состояния пули на каждом кадре.
        Пуля движется в направлении заданного угла.
        Если пуля выходит за пределы карты, она удаляется.
        """
        # Движение пули по оси X и Y в соответствии с углом и скоростью
        self.rect.x += self.speed * math.cos(self.angle)
        self.rect.y += self.speed * math.sin(self.angle)

        # Проверка, находится ли пуля в пределах карты
        if not pygame.Rect(0, 0, game_state.MAP_WIDTH, game_state.MAP_HEIGHT).colliderect(self.rect):
            self.kill()  # Удаление пули, если она вышла за пределы карты