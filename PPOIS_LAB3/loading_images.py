import pygame  # Импорт библиотеки Pygame для работы с графикой
from temporaries import game_state  # Импорт глобального состояния игры

def load_image(path, size=None):
    """
    Загружает изображение из файла и, при необходимости, изменяет его размер.

    :param path: Путь к файлу изображения.
    :param size: Кортеж (ширина, высота) для изменения размера изображения. Если None, размер не изменяется.
    :return: Загруженное изображение.
    """
    image = pygame.image.load(path)  # Загрузка изображения из файла
    if size:
        image = pygame.transform.scale(image, size)  # Изменение размера изображения, если указан параметр size
    return image  # Возвращение изображения

# Загрузка фонового изображения
bg = load_image("images/backgrounddetailed5.png", (game_state.SCREEN_WIDTH, game_state.SCREEN_HEIGHT))

# Загрузка изображения игрока
player_image = load_image("images/player.png", (35, 35))

# Загрузка изображения пули
bullet_image = load_image("images/bullet.png", (7, 7))

# Загрузка изображений оружия
pistol_image = load_image("images/pistol.png", (30, 10))
automat_image = load_image("images/automat.png", (30, 10))
drob_image = load_image("images/drob.png", (30, 10))

# Загрузка изображения для экрана загрузки
loading_image = load_image("images/crimsonland.jpg", (800, 600))
loading = loading_image.get_rect(center=(game_state.SCREEN_WIDTH / 2, game_state.SCREEN_HEIGHT / 2))

# Загрузка изображения для меню
menu_image = load_image("images/menu_image.jpg", (800, 600))
menu = menu_image.get_rect(center=(game_state.SCREEN_WIDTH, game_state.SCREEN_HEIGHT / 2))

# Загрузка изображения для экрана поражения
lost_image = load_image("images/lost.jpg", (800, 600))
lost = lost_image.get_rect(center=(game_state.SCREEN_WIDTH / 2, game_state.SCREEN_HEIGHT / 2))

# Загрузка изображения для экрана победы
win_image = load_image("images/WIN.jpg", (800, 600))
win = win_image.get_rect(center=(game_state.SCREEN_WIDTH / 2, game_state.SCREEN_HEIGHT / 2))

dead_plant = load_image("images/dead_plant1.png", (30, 30))
maple_image = load_image("images/tree1.png", (60, 80))
dry_tree_image = load_image("images/tree3.png", (60, 80))
aspen_image = load_image("images/tree2.png", (60, 80))
swamp_image = load_image("images/swamp.png", (80, 30))
# Загрузка изображений врагов
enemy_images = []
for enemy_type in ["enemy1.png", "enemy2.png", "enemy3.png", "enemy4.png", "enemy5.png"]:
    enemy_images.extend([load_image(f"images/{enemy_type}", (55, 30))] * 25)  # 25 копий каждого изображения врага

# Загрузка изображений для анимации смерти врагов
enemy_dead_images = []
for enemy_type in ["enemy_dead.png", "enemy_dead2.png", "enemy_dead3.png", "enemy_dead4.png", "enemy_dead5.png", "blood.png"]:
    # 10 копий каждого изображения смерти, кроме blood.png, для которого 120 копий
    enemy_dead_images.extend([load_image(f"images/{enemy_type}", (55, 30))] * (120 if enemy_type == "blood.png" else 10))