import random  # Импорт модуля random для генерации случайных чисел
import pygame  # Импорт библиотеки Pygame для работы с графикой
from files import *  # Импорт всех данных из модуля files (например, waves)
from enemy import BasicEnemy  # Импорт класса BasicEnemy для создания врагов
from loading_images import bg, dead_plant, maple_image, dry_tree_image, aspen_image, \
    swamp_image  # Импорт фонового изображения
from plants import Dry_tree
from player import Player  # Импорт класса Player для управления игроком
from sounds import menu_sound, enemy_sound, dead_sound  # Импорт звуков
from temporaries import game_state  # Импорт глобального состояния игры
from weapon import Pistol, Rifle, Shotgun  # Импорт классов оружия
from plants import *
from swap import Swamp

def save_record():
    """
    Сохраняет рекорды игрока в файл records.json.
    """
    with open("json/records.json", 'r+', encoding='utf-8') as file:
        # Чтение существующих данных
        existing_data = json.load(file)

        # Добавление текущего времени игры в список
        existing_data["seconds"].append(game_state.time_game)

        # Обновление общего количества убийств
        existing_data["kills"] = game_state.enemies_killed + existing_data["kills"]

        # Обновление максимального времени, если текущее время больше
        if game_state.time_game > existing_data["max_time"]:
            existing_data["max_time"] = game_state.time_game

        # Вычисление среднего времени
        average_time = 0
        for key in existing_data["seconds"]:
            average_time += key
        average_time = average_time / len(existing_data["seconds"])
        average_time = round(average_time, 2)
        existing_data["average_time"] = average_time

        # Перемещение указателя в начало файла
        file.seek(0)

        # Запись обновленных данных в файл
        json.dump(existing_data, file, ensure_ascii=False, indent=4)

        # Обрезаем файл до текущей позиции (на случай, если новые данные короче старых)
        file.truncate()


def load_record():
    """
    Загружает рекорды игрока из файла records.json.
    :return: Загруженные данные.
    """
    with open("json/records.json", 'r', encoding='utf-8') as file:
        existing_data = json.load(file)
    return existing_data


def start_timer(interval):
    """
    Запускает таймер для спавна врагов.
    :param interval: Интервал времени между спавнами врагов (в миллисекундах).
    """
    pygame.time.set_timer(game_state.TIMER_EVENT, interval)
    game_state.timer_active = True
    game_state.start_time = pygame.time.get_ticks()


def stop_timer():
    """
    Останавливает таймер спавна врагов.
    """
    pygame.time.set_timer(game_state.TIMER_EVENT, 0)  # Останавливаем таймер
    game_state.timer_active = False
    pygame.time.set_timer(game_state.TIMER_START_EVENT, 5000, 1)  # Запускаем таймер для следующей волны


def game_start():
    """
    Инициализация новой игры.
    """
    menu_sound.stop()  # Остановка музыки меню
    game_state.is_clicked = False
    game_state.GAME = True  # Установка флага игры
    game_state.LOADING = False
    game_state.MENU = False
    game_state.LOST = False
    game_state.RECORD = False
    game_state.INFO = False
    game_state.wave_num = 0  # Сброс номера волны  # Создание игрока
    game_state.all_sprites = pygame.sprite.Group()  # Группа всех спрайтов
    game_state.bullets = pygame.sprite.Group()  # Группа пуль
    game_state.enemies = pygame.sprite.Group()  # Группа врагов
    game_state.weapons = pygame.sprite.Group()  # Группа оружия  # Добавление пистолета в группу спрайтов
    start_timer(3000)  # Запуск таймера для спавна врагов
    game_state.start_game = pygame.time.get_ticks()  # Запись времени начала игры
    spawn_plants()
    game_state.player = Player()
    game_state.all_sprites.add(game_state.player)  # Добавление игрока в группу спрайтов
    pistol = Pistol((1200, 900))  # Создание пистолета
    game_state.weapons.add(pistol)  # Добавление пистолета в группу оружия
    game_state.all_sprites.add(pistol)


def game_end():
    """
    Завершение игры.
    """
    end_game = pygame.time.get_ticks()  # Время завершения игры
    game_state.time_game = (end_game - game_state.start_game) / 1000  # Вычисление времени игры в секундах
    game_state.time_game = round(game_state.time_game, 2)  # Округление времени игры
    game_state.player.weapon.kill()  # Удаление оружия игрока
    game_state.player.weapon = None
    game_state.player.kill()  # Удаление игрока
    game_state.GAME = False  # Сброс флага игры
    game_state.LOADING = False
    game_state.MENU = False
    game_state.all_sprites.empty()  # Очистка группы всех спрайтов
    game_state.bullets.empty()  # Очистка группы пуль
    game_state.enemies.empty()  # Очистка группы врагов
    enemy_sound.stop()  # Остановка звука врагов
    game_state.weapons.empty()  # Очистка группы оружия
    game_state.wave_num = 0  # Сброс номера волны
    save_record()  # Сохранение рекорда


def draw():
    """
    Отрисовка всех объектов на экране.
    """
    # Отрисовка фона (3x3 тайла)
    for i in range(3):
        for j in range(3):
            game_state.screen.blit(bg, (
                i * game_state.SCREEN_WIDTH - game_state.camera_x,
                j * game_state.SCREEN_HEIGHT - game_state.camera_y
            ))

    # Отрисовка всех спрайтов
    for sprite in game_state.all_sprites:
        game_state.screen.blit(sprite.image, (sprite.rect.x - game_state.camera_x, sprite.rect.y - game_state.camera_y))


def check_collides():
    """
    Проверка столкновений между объектами.
    """
    # Проверка столкновений игрока с оружием
    for weapon in game_state.weapons:
        if pygame.sprite.collide_rect(game_state.player, weapon):
            game_state.player.equip_weapon(weapon)  # Экипировка оружия
            game_state.weapons.remove(weapon)  # Удаление оружия с карты

    # Проверка столкновений игрока с врагами
    if game_state.player in game_state.all_sprites:
        for enemy in game_state.enemies:
            if game_state.player.rect.collidepoint(
                    enemy.rect.center) and game_state.player.health > 0 and enemy.health > 0:
                enemy.hit_player()  # Нанесение урона игроку
                if game_state.player.health <= 0:  # Если здоровье игрока <= 0
                    game_state.LOST = True  # Установка флага поражения
                    dead_sound.play()  # Воспроизведение звука смерти
                    game_end()  # Завершение игры

    # Проверка столкновений пуль с врагами
    for bullet in game_state.bullets:
        for plant in game_state.plants:
            if plant.rect.collidepoint(bullet.rect.center):
                bullet.kill()
        for enemy in game_state.enemies:
            if enemy.rect.collidepoint(bullet.rect.center) and enemy.health > 0:
                enemy.get_hit(bullet)  # Нанесение урона врагу
                if bullet.damage < 200:
                    game_state.player.hit_enemy(bullet.damage)  # Начисление урона для активации перка
                if enemy.health <= 0:  # Если здоровье врага <= 0
                    if random.random() < 0.15:  # 15% шанс выпадения оружия
                        options = ["pistol", "rifle", "shotgun"]
                        selected_option = random.choice(options)  # Случайный выбор оружия
                        if selected_option == "pistol":
                            pistol = Pistol((enemy.rect.centerx, enemy.rect.centery))
                            game_state.weapons.add(pistol)
                            game_state.all_sprites.add(pistol)
                        elif selected_option == "rifle":
                            rifle = Rifle((enemy.rect.centerx, enemy.rect.centery))
                            game_state.weapons.add(rifle)
                            game_state.all_sprites.add(rifle)
                        elif selected_option == "shotgun":
                            shotgun = Shotgun((enemy.rect.centerx, enemy.rect.centery))
                            game_state.weapons.add(shotgun)
                            game_state.all_sprites.add(shotgun)
                bullet.kill()  # Удаление пули после попадания


def reload_weapon():
    """
    Перезарядка оружия игрока.
    """
    game_state.player.weapon.ammo = game_state.player.weapon.max_ammo  # Восстановление патронов
    game_state.player.weapon.reloading = False  # Сброс флага перезарядки


def spawn_enemy():
    """
    Спавн врагов в зависимости от текущей волны.
    """
    for j in range(waves[game_state.wave_num]["enemies"]):  # Количество врагов в текущей волне
        enemy = BasicEnemy(waves[game_state.wave_num]["health"], (
            random.randint(0, game_state.SCREEN_WIDTH * 3),  # Случайная позиция по X
            random.randint(0, game_state.SCREEN_HEIGHT * 3)  # Случайная позиция по Y
        ))
        game_state.all_sprites.add(enemy)  # Добавление врага в группу спрайтов
        game_state.enemies.add(enemy)  # Добавление врага в группу врагов

def is_colliding(new_rect, existing_rects):
    """Проверяет, пересекается ли новый прямоугольник с уже существующими."""
    for existing_rect in existing_rects:
        if new_rect.colliderect(existing_rect):
            return True
    return False


def spawn_plant(plant_class, image, existing_rects, game_state, count=20):
    """Спавнит растения заданного типа."""
    for _ in range(count):
        while True:
            random_number_x = random.randint(100, game_state.MAP_WIDTH - 100)
            random_number_y = random.randint(100, game_state.MAP_HEIGHT - 100)
            temp_rect = image.get_rect(center=(random_number_x, random_number_y))

            if not is_colliding(temp_rect, existing_rects):
                plant = plant_class(x=random_number_x, y=random_number_y, health=1000, image=image,
                                    dead_image=dead_plant)
                game_state.plants.add(plant)
                game_state.all_sprites.add(plant)
                existing_rects.append(temp_rect)
                break


def spawn_swamp(image, existing_rects, game_state, count=20):
    """Спавнит болота."""
    for _ in range(count):
        while True:
            random_number_x = random.randint(100, game_state.MAP_WIDTH - 100)
            random_number_y = random.randint(100, game_state.MAP_HEIGHT - 100)
            temp_rect = image.get_rect(center=(random_number_x, random_number_y))

            if not is_colliding(temp_rect, existing_rects):
                swamp = Swamp(x=random_number_x, y=random_number_y, image=image)
                game_state.swamps.add(swamp)
                game_state.all_sprites.add(swamp)
                existing_rects.append(temp_rect)
                break


def spawn_plants():
    """Основная функция для спавна всех растений и болот."""
    existing_rects = []

    # Спавн кленов
    spawn_plant(Maple, maple_image, existing_rects, game_state)

    # Спавн сухих деревьев
    spawn_plant(Dry_tree, dry_tree_image, existing_rects, game_state)

    # Спавн осин
    spawn_plant(Aspen, aspen_image, existing_rects, game_state)

    # Спавн болот
    spawn_swamp(swamp_image, existing_rects, game_state)