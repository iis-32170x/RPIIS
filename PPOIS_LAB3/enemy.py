import math  # Импорт модуля math для математических операций (например, вычисления углов)
import pygame  # Импорт библиотеки Pygame для работы с графикой и игровыми объектами
from files import *  # Импорт всех данных из модуля files (например, enemy_stat)
from loading_images import enemy_images, enemy_dead_images  # Импорт изображений врагов
from sounds import hit_zombie_sound  # Импорт звука попадания по врагу
from temporaries import game_state  # Импорт глобального состояния игры

class Enemy(pygame.sprite.Sprite):
    """
    Базовый класс для врагов. Наследуется от pygame.sprite.Sprite для интеграции с группами спрайтов.
    """
    def __init__(self, player, health, coordinates, speed, damage, images, dead_images):
        """
        Инициализация врага.

        :param player: Объект игрока, за которым будет следовать враг.
        :param health: Здоровье врага.
        :param coordinates: Кортеж (x, y) с начальной позицией врага.
        :param speed: Скорость движения врага.
        :param damage: Урон, который наносит враг.
        :param images: Список изображений для анимации врага.
        :param dead_images: Список изображений для анимации смерти врага.
        """
        super().__init__()  # Инициализация родительского класса (Sprite)
        self.player = player  # Объект игрока
        self.image_number = 0  # Текущий кадр анимации
        self.speed = speed  # Скорость врага
        self.original_image = images[self.image_number]  # Текущее изображение врага
        self.image = self.original_image  # Изображение для отрисовки
        self.rect = self.image.get_rect(center=coordinates)  # Прямоугольник, описывающий положение и размер врага
        self.angle = 0  # Угол поворота врага
        self.health = health  # Здоровье врага
        self.damage = damage  # Урон врага
        self.hitting = False  # Флаг, указывающий, атакует ли враг игрока
        self.start = 0  # Время начала атаки
        self.current = 0  # Текущее время
        self.images = images  # Список изображений для анимации
        self.dead_images = dead_images  # Список изображений для анимации смерти

    def update(self):
        """
        Обновление состояния врага на каждом кадре.
        В зависимости от здоровья врага, он либо жив, либо мёртв.
        """
        if self.health <= 0:
            self.handle_death()  # Обработка смерти врага
        else:
            self.handle_alive()  # Обработка поведения живого врага

        # Если враг жив или находится в процессе анимации смерти, он движется к игроку
        if self.health > 0 or (self.health <= 0 and self.image_number <= 24):
            self.move_towards_player()

    def handle_death(self):
        """
        Обработка смерти врага.
        Включает анимацию смерти и удаление врага после завершения анимации.
        """
        self.image_number = (self.image_number + 1) % len(self.dead_images)  # Переход к следующему кадру анимации
        self.image = self.dead_images[self.image_number]  # Обновление изображения
        self.original_image = self.image  # Обновление оригинального изображения
        # Если анимация смерти завершена, враг удаляется
        if self.image_number >= len(self.dead_images) - 1:
            game_state.enemies_killed += 1  # Увеличение счётчика убитых врагов
            self.kill()  # Удаление врага

    def handle_alive(self):
        """
        Обработка поведения живого врага.
        Включает анимацию движения.
        """
        self.image_number = (self.image_number + 1) % len(self.images)  # Переход к следующему кадру анимации
        self.image = self.images[self.image_number]  # Обновление изображения
        self.original_image = self.image  # Обновление оригинального изображения

    def move_towards_player(self):
        """
        Движение врага в направлении игрока.
        """
        player_x, player_y = self.player.rect.centerx, self.player.rect.centery  # Позиция игрока
        enemy_x, enemy_y = self.rect.centerx, self.rect.centery  # Позиция врага
        rel_x, rel_y = player_x - enemy_x, player_y - enemy_y  # Разница в координатах
        self.angle = math.degrees(math.atan2(-rel_y, rel_x))  # Вычисление угла поворота

        # Поворот изображения врага
        self.image = pygame.transform.rotate(self.original_image, int(self.angle))
        self.rect = self.image.get_rect(center=self.rect.center)

        # Движение врага в направлении игрока
        angle = math.atan2(rel_y, rel_x)
        self.rect.x += self.speed * math.cos(angle)
        self.rect.y += self.speed * math.sin(angle)

    def get_hit(self, bullet):
        """
        Обработка попадания пули во врага.
        :param bullet: Объект пули, которая попала во врага.
        """
        self.health -= bullet.damage  # Уменьшение здоровья врага
        hit_zombie_sound.play()  # Воспроизведение звука попадания
        if self.health <= 0:
            self.image_number = 0  # Сброс анимации
            self.speed = 0  # Остановка движения

    def hit_player(self):
        """
        Обработка атаки врага на игрока.
        """
        self.current = pygame.time.get_ticks()  # Текущее время
        # Если враг не атаковал или прошло достаточно времени с последней атаки
        if not self.hitting or self.current - self.start >= 2000:
            self.hitting = True  # Враг начинает атаку
            self.start = self.current  # Время начала атаки
            self.current = pygame.time.get_ticks()  # Обновление текущего времени
            self.player.health -= self.damage  # Уменьшение здоровья игрока


class BasicEnemy(Enemy):
    """
    Класс для базового врага. Наследуется от Enemy.
    """
    def __init__(self, health, coordinates):
        """
        Инициализация базового врага.
        :param health: Здоровье врага.
        :param coordinates: Кортеж (x, y) с начальной позицией врага.
        """
        super().__init__(
            player=game_state.player,  # Объект игрока
            health=health,  # Здоровье врага
            coordinates=coordinates,  # Начальная позиция
            speed=enemy_stat["speed"],  # Скорость врага
            damage=enemy_stat["damage"],  # Урон врага
            images=enemy_images,  # Изображения для анимации
            dead_images=enemy_dead_images  # Изображения для анимации смерти
        )