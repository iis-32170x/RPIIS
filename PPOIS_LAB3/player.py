import math  # Импорт модуля math для математических операций (например, вычисления углов)
import pygame  # Импорт библиотеки Pygame для работы с графикой
from pygame import rect

from files import *  # Импорт всех данных из модуля files (например, player_stat)
from loading_images import player_image, automat_image, pistol_image, drob_image  # Импорт изображений
from temporaries import game_state  # Импорт глобального состояния игры
from weapon import Rifle, Pistol, Shotgun  # Импорт классов оружия

class Player(pygame.sprite.Sprite):
    """
    Класс Player представляет игрока. Наследуется от pygame.sprite.Sprite для интеграции с группами спрайтов.
    """
    def __init__(self):
        """
        Инициализация игрока.
        """
        super().__init__()  # Инициализация родительского класса (Sprite)
        self.original_image = player_image  # Оригинальное изображение игрока
        self.image = self.original_image  # Текущее изображение игрока (может быть повёрнуто)
        self.rect = self.image.get_rect(center=(game_state.MAP_WIDTH // 2, game_state.MAP_HEIGHT // 2))  # Прямоугольник, описывающий положение и размер игрока
        self.angle = 0  # Угол поворота игрока
        self.speed = player_stat["speed"]  # Скорость игрока (из player_stat)
        self.health = player_stat["health"]  # Здоровье игрока (из player_stat)
        self.weapon = None  # Текущее оружие игрока
        self.perk_ready = False  # Флаг готовности перка
        self.damages = 0  # Счётчик полученного урона для активации перка

    def update(self):
        """
        Обновление состояния игрока на каждом кадре.
        Включает поворот, движение и обновление оружия.
        """
        self.check_angle()  # Обновление угла поворота игрока
        self.move()  # Обновление позиции игрока

        # Обновление камеры (слежение за игроком)
        game_state.camera_x = max(0, min(self.rect.centerx - game_state.SCREEN_WIDTH // 2,
                                     game_state.MAP_WIDTH - game_state.SCREEN_WIDTH))
        game_state.camera_y = max(0, min(self.rect.centery - game_state.SCREEN_HEIGHT // 2,
                                     game_state.MAP_HEIGHT - game_state.SCREEN_HEIGHT))

        # Обновление оружия, если оно есть
        if self.weapon:
            self.update_weapon()

    def check_angle(self):
        """
        Обновление угла поворота игрока в зависимости от позиции мыши.
        """
        # Получаем позицию мыши
        mouse_x, mouse_y = pygame.mouse.get_pos()
        screen_player_x = self.rect.centerx - game_state.camera_x  # Позиция игрока на экране
        screen_player_y = self.rect.centery - game_state.camera_y

        # Вычисляем угол между игроком и курсором
        rel_x, rel_y = mouse_x - screen_player_x, mouse_y - screen_player_y
        self.angle = (180 / math.pi) * -math.atan2(rel_y, rel_x)

        # Поворачиваем изображение игрока
        self.image = pygame.transform.rotate(self.original_image, int(self.angle))
        self.rect = self.image.get_rect(center=self.rect.center)

    def move(self):
        """
        Обновление позиции игрока в зависимости от нажатых клавиш.
        """
        keys = pygame.key.get_pressed()  # Получаем состояние всех клавиш

        # Движение вверх
        if keys[pygame.K_w] or keys[pygame.K_UP]:
            if self.check_col_swamp():
                new_rect = self.rect.move(0, -self.speed/2)
                if not self.check_col_plant(new_rect):
                    self.rect = new_rect
            else:
                new_rect = self.rect.move(0, -self.speed)
                if not self.check_col_plant(new_rect):
                    self.rect = new_rect
        # Движение вниз
        if keys[pygame.K_s] or keys[pygame.K_DOWN]:
            if self.check_col_swamp():
                new_rect = self.rect.move(0, self.speed/2)
                if not self.check_col_plant(new_rect):
                    self.rect = new_rect
            else:
                new_rect = self.rect.move(0, self.speed)
                if not self.check_col_plant(new_rect):
                    self.rect = new_rect

        # Движение влево
        if keys[pygame.K_a] or keys[pygame.K_LEFT]:
            if self.check_col_swamp():
                new_rect = self.rect.move(-self.speed/2, 0)
                if not self.check_col_plant(new_rect):
                    self.rect = new_rect
            else:
                new_rect = self.rect.move(-self.speed, 0)
                if not self.check_col_plant(new_rect):
                    self.rect = new_rect

        # Движение вправо
        if keys[pygame.K_d] or keys[pygame.K_RIGHT]:
            if self.check_col_swamp():
                new_rect = self.rect.move(self.speed/2, 0)
                if not self.check_col_plant(new_rect):
                    self.rect = new_rect
            else:
                new_rect = self.rect.move(self.speed, 0)
                if not self.check_col_plant(new_rect):
                    self.rect = new_rect

        # Ограничение движения в пределах карты
        self.rect.centerx = max(0, min(self.rect.centerx, game_state.MAP_WIDTH))
        self.rect.centery = max(0, min(self.rect.centery, game_state.MAP_HEIGHT))

    def update_weapon(self):
        """
        Обновление позиции и поворота оружия игрока.
        """
        offset_distance = 10  # Расстояние от центра игрока до оружия
        offset_x = math.cos(math.radians(self.angle)) * offset_distance  # Смещение по X
        offset_y = -math.sin(math.radians(self.angle)) * offset_distance  # Смещение по Y

        weapon_pos = (
            self.rect.centerx + offset_x,  # Позиция оружия по X
            self.rect.centery + offset_y   # Позиция оружия по Y
        )

        # Поворот и позиционирование оружия
        self.weapon.image = pygame.transform.rotate(self.weapon.original_image, int(self.angle))
        self.weapon.rect = self.weapon.image.get_rect(center=weapon_pos)

        # Отрисовка оружия на экране с учётом камеры
        game_state.screen.blit(
            self.weapon.image,
            (self.weapon.rect.x - game_state.camera_x, self.weapon.rect.y - game_state.camera_y)
        )

    def equip_weapon(self, weapon):
        """
        Экипировка оружия игроком.
        :param weapon: Объект оружия (Pistol, Rifle или Shotgun).
        """
        if self.weapon:
            self.weapon.kill()  # Удаляем текущее оружие, если оно есть
        self.weapon = weapon  # Устанавливаем новое оружие
        self.weapon.equiped = True  # Устанавливаем флаг экипировки
        self.weapon.rect.center = self.rect.center  # Позиционируем оружие в центре игрока

        # Устанавливаем изображение оружия в зависимости от его типа
        if type(self.weapon) == Rifle:
            self.weapon.original_image = automat_image
        elif type(self.weapon) == Pistol:
            self.weapon.original_image = pistol_image
        elif type(self.weapon) == Shotgun:
            self.weapon.original_image = drob_image

    def shoot(self):
        """
        Выстрел из текущего оружия игрока.
        """
        if self.weapon:
            # Получаем позицию мыши
            mouse_x, mouse_y = pygame.mouse.get_pos()
            screen_player_x = self.rect.centerx - game_state.camera_x  # Позиция игрока на экране
            screen_player_y = self.rect.centery - game_state.camera_y

            # Вычисляем угол между игроком и курсором
            rel_x, rel_y = mouse_x - screen_player_x, mouse_y - screen_player_y
            angle = math.atan2(rel_y, rel_x)

            # Выстрел из оружия
            self.weapon.shoot(angle)

    def hit_enemy(self, damages):
        """
        Обработка получения урона от врага.
        :param damages: Количество полученного урона.
        """
        self.damages += damages  # Увеличиваем счётчик полученного урона
        if self.damages >= 1000:  # Если накоплено достаточно урона
            self.damages = 0  # Сбрасываем счётчик
            self.perk_ready = True  # Активируем перк

    def check_col_plant(self, rect) -> bool:
        for plant in game_state.plants:
            if rect.collidepoint(plant.rect.center):  # Проверяем столкновение
                return True
        return False

    def check_col_swamp(self) -> bool:
        for swamp in game_state.swamps:
            if swamp.rect.collidepoint(self.rect.center):
                return True
        return False