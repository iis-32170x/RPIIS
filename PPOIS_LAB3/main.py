import pygame  # Импорт библиотеки Pygame для работы с графикой

from plants import Maple

pygame.init()
from loading_images import loading_image, menu_image, lost_image, win_image # Импорт изображений
from files import waves  # Импорт данных о волнах
from fonts import font_lose, font_menu, font_win, font  # Импорт шрифтов
from perk import Perk  # Импорт класса Perk для специальных способностей
from sounds import enemy_sound, menu_sound , dryfir_sound  # Импорт звуков
from temporaries import game_state  # Импорт глобального состояния игры
from utils import reload_weapon, spawn_enemy, game_end, stop_timer, start_timer, draw, check_collides, load_record, game_start  # Импорт вспомогательных функций

pygame.mixer.init()  # Инициализация звуковой системы Pygame
pygame.display.set_caption("Crimsonland")  # Установка заголовка окна

# Основной цикл игры
running = True  # Флаг для управления игровым циклом
clock = pygame.time.Clock()  # Создание объекта для управления FPS

# Основной игровой цикл
while running:
    events = pygame.event.get()  # Получение всех событий

    for event in events:
        if event.type == pygame.QUIT:  # Если событие — закрытие окна
            running = False  # Завершение игрового цикла

    # Меню загрузки
    if game_state.LOADING:
        game_state.screen.blit(loading_image, (0, 0))  # Отрисовка фонового изображения
        text = font.render(f"нажмите ENTER что бы продолжить", True, (255, 255, 255))  # Создание текста
        text_rect = text.get_rect(center=(400, 550))  # Позиционирование текста
        game_state.screen.blit(text, text_rect)  # Отрисовка текста
        pygame.display.flip()  # Обновление экрана
        for event in events:
            if event.type == pygame.KEYDOWN:  # Если нажата клавиша
                if event.key == pygame.K_RETURN:  # Если нажат ENTER
                    game_state.GAME = False
                    game_state.LOADING = False
                    game_state.MENU = True  # Переход в главное меню

    # Игровой процесс
    elif game_state.GAME:
        current_time = pygame.time.get_ticks()  # Текущее время

        for event in events:
            if event.type == pygame.QUIT:  # Если событие — закрытие окна
                running = False  # Завершение игрового цикла
            elif event.type == pygame.USEREVENT:  # Событие перезарядки
                if game_state.player.weapon:
                    reload_weapon()  # Перезарядка оружия
            elif event.type == game_state.TIMER_EVENT:  # Событие таймера
                if game_state.timer_active and current_time - game_state.start_time <= waves[game_state.wave_num]["seconds"] * 1000:
                    spawn_enemy()  # Спавн врагов
                elif game_state.timer_active and current_time - game_state.start_time >= waves[game_state.wave_num]["seconds"] * 1000:
                    if len(game_state.enemies) <= 0:  # Если все враги уничтожены
                        game_state.wave_num += 1  # Переход к следующей волне
                        if game_state.wave_num == 20:  # Если пройдены все волны
                            game_state.WIN = True  # Установка флага победы
                            game_end()  # Завершение игры
                        stop_timer()  # Остановка таймера
            elif event.type == game_state.TIMER_START_EVENT:  # Событие запуска таймера
                start_timer(3000)  # Запуск таймера для следующей волны
            elif event.type == pygame.KEYDOWN:  # Если нажата клавиша
                if event.key == pygame.K_SPACE:  # Если нажат пробел
                    game_state.player.weapon.reload()  # Перезарядка оружия
                if event.key == pygame.K_RETURN and game_state.player.perk_ready:  # Если нажат ENTER и перк готов
                    perk = Perk()  # Создание перка
                    perk.update()  # Активация перка

        # Управление звуком врагов
        if len(game_state.enemies) == 0:
            enemy_sound.stop()  # Остановка звука врагов, если их нет
        elif len(game_state.enemies) > 0:
            if not enemy_sound.get_num_channels():  # Если звук врагов не воспроизводится
                enemy_sound.play(-1)  # Воспроизведение звука врагов

        # Стрельба
        if pygame.mouse.get_pressed()[0]:  # Если нажата левая кнопка мыши
            if game_state.player.weapon.reloading:
                if not dryfir_sound.get_num_channels():
                    dryfir_sound.play()
            else:
                game_state.player.shoot()  # Выстрел из оружия

        draw()  # Отрисовка всех объектов
        check_collides()  # Проверка столкновений
        game_state.all_sprites.update()  # Обновление всех спрайтов

        # Отображение информации об оружии
        if game_state.player.weapon:
            font = pygame.font.SysFont("Arial", 24)  # Создание шрифта
            ammo_text = font.render(f"Ammo: {game_state.player.weapon.ammo}/{game_state.player.weapon.max_ammo}", True, (255, 255, 255))  # Текст с количеством патронов
            health_text = font.render(f"Heath: {game_state.player.health}", True, (255, 255, 255))  # Текст с здоровьем игрока
            wave_text = font.render(f"Wave: {game_state.wave_num + 1}", True, (255, 255, 255))  # Текст с номером волны
            perk_text = font.render(f"Perk: {'ready' if game_state.player.perk_ready else 'not ready'}", True, (255, 255, 255))  # Текст с состоянием перка
            game_state.screen.blit(ammo_text, (10, 10))  # Отрисовка текста с патронами
            game_state.screen.blit(health_text, (170, 10))  # Отрисовка текста с здоровьем
            game_state.screen.blit(wave_text, (310, 10))  # Отрисовка текста с номером волны
            game_state.screen.blit(perk_text, (420, 10))  # Отрисовка текста с состоянием перка

        pygame.display.flip()  # Обновление экрана
        clock.tick(60)  # Ограничение FPS до 60

    # Экран поражения

    elif game_state.LOST:
        game_state.screen.blit(lost_image, (0, 0))  # Отрисовка фонового изображения
        lost_text = font_lose.render(f"THE REAPER GOT YOU", True, (255, 0, 0))  # Текст поражения
        lost_rect = lost_text.get_rect(center=(400, 150))  # Позиционирование текста
        game_state.screen.blit(lost_text, lost_rect)  # Отрисовка текста
        time_text = font_lose.render(f"TIME: {game_state.time_game} sec", True, (255, 0, 0))  # Текст с временем игры
        time_rect = time_text.get_rect(center=(400, 320))  # Позиционирование текста
        game_state.screen.blit(time_text, time_rect)  # Отрисовка текста
        kill_text = font_lose.render(f"KILLS: {game_state.enemies_killed} ", True, (255, 0, 0))  # Текст с количеством убийств
        kill_rect = kill_text.get_rect(center=(400, 470))  # Позиционирование текста
        game_state.screen.blit(kill_text, kill_rect)  # Отрисовка текста
        text = font.render(f"нажмите ENTER что бы продолжить", True, (255, 255, 255))  # Текст с подсказкой
        text_rect = text.get_rect(center=(400, 550))  # Позиционирование текста
        game_state.screen.blit(text, text_rect)  # Отрисовка текста
        pygame.display.flip()  # Обновление экрана
        for event in events:
            if event.type == pygame.KEYDOWN:  # Если нажата клавиша
                if event.key == pygame.K_RETURN:  # Если нажат ENTER
                    game_state.GAME = False
                    game_state.LOADING = False
                    game_state.LOST = False
                    game_state.MENU = True  # Переход в главное меню

    # Главное меню
    elif game_state.MENU:
        if not menu_sound.get_num_channels():  # Если звук меню не воспроизводится
            menu_sound.play(-1)  # Воспроизведение звука меню
        game_state.screen.blit(menu_image, (0, 0))  # Отрисовка фонового изображения
        start_text = font_menu.render(f"START", True, (255, 255, 255))  # Текст "START"
        start_rect = start_text.get_rect(center=(100, 200))  # Позиционирование текста
        info_text = font_menu.render(f"INFO", True, (255, 255, 255))  # Текст "INFO"
        info_rect = info_text.get_rect(center=(100, 250))  # Позиционирование текста
        record_text = font_menu.render(f"RECORD", True, (255, 255, 255))  # Текст "RECORD"
        record_rect = record_text.get_rect(center=(100, 300))  # Позиционирование текста
        exit_text = font_menu.render(f"EXIT", True, (255, 255, 255))  # Текст "EXIT"
        exit_rect = exit_text.get_rect(center=(100, 350))  # Позиционирование текста

        # Отображение информации или рекордов
        if game_state.INFO:
            font = pygame.font.SysFont("Times New Roman", 20)  # Создание шрифта
            text = [
                "В начале игры игрок появляется в ",
                "центре карты с определённым ",
                "оружием, количеством здоровья.",
                " Из-за края экрана начинают появляться",
                "различные монстры, описанные в секции ",
                "«Враги». На телах только что убитых",
                "монстров иногда появляется оружие. ",
                "Соприкосновение с монстрами отнимает у",
                "игрока здоровье, и когда оно заканчивается,",
                " герой погибает. В игре 20 волн врагов,",
                "с каждой волной здоровье, количество и ",
                "время спавна врагов увеличивается."
            ]
            y_offset = 100  # Отступ сверху
            for line in text:
                text_surface = font.render(line, True, (255, 255, 255))  # Создание текста
                text_rect = text_surface.get_rect(topleft=(350, y_offset))  # Позиционирование текста
                game_state.screen.blit(text_surface, text_rect)  # Отрисовка текста
                y_offset += 30  # Увеличение отступа
        elif game_state.RECORD:
            records = load_record()  # Загрузка рекордов
            font = pygame.font.SysFont("Times New Roman", 30)  # Создание шрифта
            max_time_text = font.render(f"MAXIMUM TIME: {records['max_time']}", True, (255, 255, 255))  # Текст с максимальным временем
            max_rect = max_time_text.get_rect(center=(550, 100))  # Позиционирование текста
            kills_text = font.render(f"KILLS {records['kills']}", True, (255, 255, 255))  # Текст с количеством убийств
            kills_rect = kills_text.get_rect(center=(550, 130))  # Позиционирование текста
            average_time_text = font.render(f"AVERAGE TIME: {records['average_time']}", True, (255, 255, 255))  # Текст со средним временем
            average_rect = average_time_text.get_rect(center=(550, 160))  # Позиционирование текста
            game_state.screen.blit(max_time_text, max_rect)  # Отрисовка текста
            game_state.screen.blit(kills_text, kills_rect)  # Отрисовка текста
            game_state.screen.blit(average_time_text, average_rect)  # Отрисовка текста

        # Отрисовка кнопок меню
        game_state.screen.blit(start_text, start_rect)
        game_state.screen.blit(exit_text, exit_rect)
        game_state.screen.blit(info_text, info_rect)
        game_state.screen.blit(record_text, record_rect)

        # Обработка кликов по кнопкам
        for event in events:
            if event.type == pygame.MOUSEBUTTONDOWN:  # Если нажата кнопка мыши
                if event.button == 1:  # Если это левая кнопка мыши
                    if start_rect.collidepoint(event.pos):  # Если нажата кнопка "START"
                        game_state.is_clicked = True
                    if exit_rect.collidepoint(event.pos):  # Если нажата кнопка "EXIT"
                        game_state.is_clicked = True
                    if info_rect.collidepoint(event.pos):  # Если нажата кнопка "INFO"
                        game_state.is_clicked = True
                    if record_rect.collidepoint(event.pos):  # Если нажата кнопка "RECORD"
                        game_state.is_clicked = True
            if event.type == pygame.MOUSEBUTTONUP:  # Если кнопка мыши отпущена
                if event.button == 1:  # Если это левая кнопка мыши
                    if game_state.is_clicked and start_rect.collidepoint(event.pos):  # Если отпущена кнопка "START"
                        game_start()  # Запуск игры
                    if game_state.is_clicked and exit_rect.collidepoint(event.pos):  # Если отпущена кнопка "EXIT"
                        running = False  # Завершение игры
                    if game_state.is_clicked and record_rect.collidepoint(event.pos):  # Если отпущена кнопка "RECORD"
                        game_state.INFO = False
                        game_state.RECORD = True  # Переход к экрану рекордов
                    if game_state.is_clicked and info_rect.collidepoint(event.pos):  # Если отпущена кнопка "INFO"
                        game_state.INFO = True
                        game_state.RECORD = False  # Переход к экрану информации

        pygame.display.flip()  # Обновление экрана

    # Экран победы
    elif game_state.WIN:
        game_state.screen.blit(win_image, (0, 0))  # Отрисовка фонового изображения
        win_text = font_win.render(f"YOU WIN", True, (255, 255, 255))  # Текст победы
        win_rect = win_text.get_rect(center=(400, 300))  # Позиционирование текста
        game_state.screen.blit(win_text, win_rect)  # Отрисовка текста
        time_text = font.render(f"TIME: {game_state.time_game} sec", True, (255, 255, 255))  # Текст с временем игры
        time_rect = time_text.get_rect(center=(100, 50))  # Позиционирование текста
        game_state.screen.blit(time_text, time_rect)  # Отрисовка текста
        kill_text = font.render(f"KILLS: {game_state.enemies_killed} ", True, (255, 255, 255))  # Текст с количеством убийств
        kill_rect = kill_text.get_rect(center=(100, 100))  # Позиционирование текста
        game_state.screen.blit(kill_text, kill_rect)  # Отрисовка текста
        text = font.render(f"нажмите ENTER что бы продолжить", True, (255, 255, 255))  # Текст с подсказкой
        text_rect = text.get_rect(center=(400, 550))  # Позиционирование текста
        game_state.screen.blit(text, text_rect)  # Отрисовка текста
        pygame.display.flip()  # Обновление экрана
        for event in events:
            if event.type == pygame.KEYDOWN:  # Если нажата клавиша
                if event.key == pygame.K_RETURN:  # Если нажат ENTER
                    game_state.GAME = False
                    game_state.LOADING = False
                    game_state.LOST = False
                    game_state.WIN = False
                    game_state.MENU = True  # Переход в главное меню

# Завершение игры
pygame.quit()  # Закрытие Pygame