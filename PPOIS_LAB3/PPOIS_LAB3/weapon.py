import pygame  # Импорт библиотеки Pygame для работы с графикой
from bullet import Bullet  # Импорт класса Bullet для создания пуль
from loading_images import pistol_image, automat_image, drob_image  # Импорт изображений оружия
from sounds import reload_sound, pistol_sound, rifle_sound, shotgun_sound  # Импорт звуков оружия
from temporaries import game_state  # Импорт глобального состояния игры
from files import *  # Импорт данных из файлов (например, weapon_stat)

class Weapon(pygame.sprite.Sprite):
    """
    Базовый класс для оружия. Наследуется от pygame.sprite.Sprite для интеграции с группами спрайтов.
    """
    def __init__(self, position, image, max_ammo, reload_time, speed, damage, fire_rate):
        """
        Инициализация оружия.

        :param position: Кортеж (x, y) с начальной позицией оружия.
        :param image: Изображение оружия.
        :param max_ammo: Максимальное количество патронов.
        :param reload_time: Время перезарядки (в миллисекундах).
        :param speed: Скорость пули.
        :param damage: Урон пули.
        :param fire_rate: Задержка между выстрелами (в миллисекундах).
        """
        super().__init__()  # Инициализация родительского класса (Sprite)
        self.image = image  # Изображение оружия
        self.original_image = self.image  # Оригинальное изображение (для поворота)
        self.rect = self.image.get_rect(center=position)  # Прямоугольник, описывающий положение и размер оружия
        self.max_ammo = max_ammo  # Максимальное количество патронов
        self.ammo = max_ammo  # Текущее количество патронов
        self.reload_time = reload_time  # Время перезарядки
        self.speed = speed  # Скорость пули
        self.damage = damage  # Урон пули
        self.fire_rate = fire_rate  # Задержка между выстрелами
        self.last_shot = 0  # Время последнего выстрела
        self.reloading = False  # Флаг перезарядки
        self.equiped = False  # Флаг экипировки оружия
        self.angle = 5  # Угол поворота оружия (для анимации)

    def load_weapon_image(self):
        """
        Возвращает изображение оружия.
        :return: Изображение оружия.
        """
        return self.image

    def shoot(self, angle):
        """
        Выстрел из оружия.
        :param angle: Угол, под которым выпускается пуля.
        """
        if self.ammo <= 0:  # Если патроны закончились
            self.reload()  # Начинаем перезарядку
            return
        current_time = pygame.time.get_ticks()  # Текущее время
        # Проверка, прошло ли достаточно времени с последнего выстрела и не идёт ли перезарядка
        if current_time - self.last_shot > self.fire_rate and not self.reloading:
            self.create_bullet(angle)  # Создание пули
            self.ammo -= 1  # Уменьшение количества патронов
            self.last_shot = current_time  # Обновление времени последнего выстрела
            self.play_shoot_sound()  # Воспроизведение звука выстрела

    def create_bullet(self, angle):
        """
        Создание пули.
        :param angle: Угол, под которым выпускается пуля.
        """
        bullet = Bullet(self.rect.center, angle, self.speed, self.damage)  # Создание пули
        game_state.all_sprites.add(bullet)  # Добавление пули в группу всех спрайтов
        game_state.bullets.add(bullet)  # Добавление пули в группу пуль

    def reload(self):
        """
        Перезарядка оружия.
        """
        if not self.reloading:  # Если перезарядка ещё не началась
            reload_sound.play()  # Воспроизведение звука перезарядки
            pygame.time.set_timer(pygame.USEREVENT, self.reload_time, 1)  # Установка таймера для перезарядки
            self.reloading = True  # Установка флага перезарядки

    def play_shoot_sound(self):
        """
        Воспроизведение звука выстрела. Дочерние классы переопределяют этот метод.
        """
        pass

    def update(self):
        """
        Обновление состояния оружия на каждом кадре.
        """
        if not self.equiped:  # Если оружие не экипировано
            # Поворот оружия для анимации
            self.image = pygame.transform.rotate(self.original_image, self.angle)
            self.rect = self.image.get_rect(center=self.rect.center)
            self.angle += 5  # Увеличение угла поворота


class Pistol(Weapon):
    """
    Класс для пистолета. Наследуется от Weapon.
    """
    def __init__(self, position):
        """
        Инициализация пистолета.
        :param position: Кортеж (x, y) с начальной позицией пистолета.
        """
        super().__init__(
            position=position,
            image=pistol_image,  # Изображение пистолета
            max_ammo=weapon_stat["pistol"]["max_ammo"],  # Максимальное количество патронов
            reload_time=weapon_stat["pistol"]["reload_time"],  # Время перезарядки
            speed=weapon_stat["pistol"]["speed"],  # Скорость пули
            damage=weapon_stat["pistol"]["damage"],  # Урон пули
            fire_rate=500  # Задержка между выстрелами (в миллисекундах)
        )

    def play_shoot_sound(self):
        """
        Воспроизведение звука выстрела из пистолета.
        """
        pistol_sound.play()


class Rifle(Weapon):
    """
    Класс для автомата. Наследуется от Weapon.
    """
    def __init__(self, position):
        """
        Инициализация автомата.
        :param position: Кортеж (x, y) с начальной позицией автомата.
        """
        super().__init__(
            position=position,
            image=automat_image,  # Изображение автомата
            max_ammo=weapon_stat["rifle"]["max_ammo"],  # Максимальное количество патронов
            reload_time=weapon_stat["rifle"]["reload_time"],  # Время перезарядки
            speed=weapon_stat["rifle"]["speed"],  # Скорость пули
            damage=weapon_stat["rifle"]["damage"],  # Урон пули
            fire_rate=100  # Задержка между выстрелами (в миллисекундах)
        )

    def play_shoot_sound(self):
        """
        Воспроизведение звука выстрела из автомата.
        """
        rifle_sound.play()


class Shotgun(Weapon):
    """
    Класс для дробовика. Наследуется от Weapon.
    """
    def __init__(self, position):
        """
        Инициализация дробовика.
        :param position: Кортеж (x, y) с начальной позицией дробовика.
        """
        super().__init__(
            position=position,
            image=drob_image,  # Изображение дробовика
            max_ammo=weapon_stat["shotgun"]["max_ammo"],  # Максимальное количество патронов
            reload_time=weapon_stat["shotgun"]["reload_time"],  # Время перезарядки
            speed=weapon_stat["shotgun"]["speed"],  # Скорость пули
            damage=weapon_stat["shotgun"]["damage"],  # Урон пули
            fire_rate=350  # Задержка между выстрелами (в миллисекундах)
        )

    def shoot(self, angle):
        """
        Выстрел из дробовика. Дробовик выпускает несколько пуль с разбросом.
        :param angle: Угол, под которым выпускаются пули.
        """
        if self.ammo <= 0:  # Если патроны закончились
            self.reload()  # Начинаем перезарядку
            return
        current_time = pygame.time.get_ticks()  # Текущее время
        # Проверка, прошло ли достаточно времени с последнего выстрела и не идёт ли перезарядка
        if current_time - self.last_shot > self.fire_rate and not self.reloading:
            for angle_offset in [-0.17, 0, 0.17]:  # Разброс пуль
                self.create_bullet(angle + angle_offset)  # Создание пули с разбросом
            self.ammo -= 1  # Уменьшение количества патронов
            self.last_shot = current_time  # Обновление времени последнего выстрела
            self.play_shoot_sound()  # Воспроизведение звука выстрела

    def play_shoot_sound(self):
        """
        Воспроизведение звука выстрела из дробовика.
        """
        shotgun_sound.play()