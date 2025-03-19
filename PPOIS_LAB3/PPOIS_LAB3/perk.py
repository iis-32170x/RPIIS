from bullet import Bullet  # Импорт класса Bullet для создания пуль
from sounds import perk_sound  # Импорт звука для активации перка
from temporaries import game_state  # Импорт глобального состояния игры


class Perk:
    """
    Класс Perk представляет специальную способность (перк), которая активируется игроком.
    При активации создаёт множество пуль, летящих во всех направлениях.
    """

    def __init__(self):
        """
        Инициализация перка.
        """
        self.damage = 250  # Урон, который наносят пули, созданные перком
        self.angle = 0  # Угол, под которым выпускается пуля (в градусах)
        self.speed = 10  # Скорость пуль, созданных перком

    def update(self):
        """
        Активация перка. Создаёт пули, летящие во всех направлениях.
        """
        perk_sound.play()  # Воспроизведение звука активации перка

        # Цикл для создания пуль под разными углами (от 0 до 360 градусов)
        while self.angle <= 360:
            # Создание пули в позиции игрока с текущим углом, скоростью и уроном
            game_state.bullet = Bullet(game_state.player.rect.center, self.angle, self.speed, self.damage)

            # Добавление пули в группы спрайтов для отрисовки и обработки
            game_state.all_sprites.add(game_state.bullet)
            game_state.bullets.add(game_state.bullet)

            self.angle += 3  # Увеличение угла для следующей пули
        else:
            # После завершения цикла сбрасываем флаг готовности перка
            game_state.player.perk_ready = False