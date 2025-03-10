import pygame

from loading_images import loading_image, menu_image, lost_image, win_image

pygame.init()
from files import waves
from fonts import font_lose, font_menu, font_win,font
from perk import Perk
from sounds import enemy_sound, menu_sound
from temporaries import game_state
from utils import reload_weapon, spawn_enemy, game_end, stop_timer, start_timer, draw, check_collides, load_record, \
    game_start

# Инициализация Pygame


pygame.mixer.init()



pygame.display.set_caption("Crimsonland")


# Основной цикл игры
running = True
clock = pygame.time.Clock()
# Основной игровой цикл
while running:
    events = pygame.event.get()

    for event in events:
        if event.type == pygame.QUIT:
            running = False

    # Меню
    if game_state.LOADING:
        game_state.screen.blit(loading_image, (0, 0))
        text = font.render(f"нажмите ENTER что бы продолжить", True, (255, 255, 255))
        text_rect = text.get_rect(center=(400, 550))
        game_state.screen.blit(text, text_rect)
        pygame.display.flip()
        for event in events:
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    game_state.GAME = False
                    game_state.LOADING = False
                    game_state.MENU = True

    # Игра
    elif game_state.GAME:
        current_time = pygame.time.get_ticks()

        for event in events:
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.USEREVENT:  # Перезарядка
                if game_state.player.weapon:
                    reload_weapon()
            elif event.type == game_state.TIMER_EVENT:
                if game_state.timer_active and current_time - game_state.start_time <= waves[game_state.wave_num]["seconds"] * 1000:
                    spawn_enemy()
                elif game_state.timer_active and current_time - game_state.start_time >= waves[game_state.wave_num]["seconds"] * 1000:
                    if len(game_state.enemies) <= 0:
                        game_state.wave_num += 1
                        if game_state.wave_num == 20:
                            game_state.WIN = True
                            game_end()
                        stop_timer()
            elif event.type == game_state.TIMER_START_EVENT:
                start_timer(3000)
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    game_state.player.weapon.reload()
                if event.key == pygame.K_RETURN and game_state.player.perk_ready:
                    perk = Perk()
                    perk.update()


        if len(game_state.enemies)==0:
            enemy_sound.stop()
        elif len(game_state.enemies)>0:
            if not enemy_sound.get_num_channels():
                enemy_sound.play(-1)

        # Стрельба
        if pygame.mouse.get_pressed()[0]:
            game_state.player.shoot()

        draw()
        check_collides()
        # Обновление спрайтов
        game_state.all_sprites.update()

        # Отображение информации об оружии
        if game_state.player.weapon:
            font = pygame.font.SysFont("Arial", 24)
            ammo_text = font.render(f"Ammo: {game_state.player.weapon.ammo}/{game_state.player.weapon.max_ammo}", True, (255, 255, 255))
            health_text=font.render(f"Heath: {game_state.player.health}", True, (255, 255, 255))
            wave_text = font.render(f"Wave: {game_state.wave_num+1}", True, (255, 255, 255))
            perk_text = font.render(f"Perk: {'ready'if game_state.player.perk_ready else 'not ready'}", True, (255, 255, 255))
            game_state.screen.blit(ammo_text, (10, 10))
            game_state.screen.blit(health_text, (170, 10))
            game_state.screen.blit(wave_text, (290, 10))
            game_state.screen.blit(perk_text, (390, 10))
        # Обновление экрана
        pygame.display.flip()
        clock.tick(60)


    elif game_state.LOST:
        game_state.screen.blit(lost_image, (0, 0))
        lost_text = font_lose.render(f"THE REAPER GOT YOU", True, (255, 0, 0))
        lost_rect = lost_text.get_rect(center=(400, 150))
        game_state.screen.blit(lost_text, lost_rect)
        time_text = font_lose.render(f"TIME: {game_state.time_game} sec", True, (255, 0, 0))
        time_rect = time_text.get_rect(center=(400, 320))
        game_state.screen.blit(time_text, time_rect)
        kill_text = font_lose.render(f"KILLS: {game_state.enemies_killed} ", True, (255, 0, 0))
        kill_rect = kill_text.get_rect(center=(400, 470))
        game_state.screen.blit(kill_text, kill_rect)
        text = font.render(f"нажмите ENTER что бы продолжить", True, (255, 255, 255))
        text_rect = text.get_rect(center=(400, 550))
        game_state.screen.blit(text, text_rect)
        pygame.display.flip()
        for event in events:
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    game_state.GAME = False
                    game_state.LOADING = False
                    game_state.LOST = False
                    game_state.MENU = True
        pygame.display.flip()


    elif game_state.MENU:
        if not menu_sound.get_num_channels():
            menu_sound.play(-1)
        game_state.screen.blit(menu_image,(0,0))
        start_text = font_menu.render(f"START", True, (255, 255, 255))
        start_rect = start_text.get_rect(center=(100, 200))
        info_text = font_menu.render(f"INFO", True, (255, 255, 255))
        info_rect = info_text.get_rect(center=(100, 250))
        record_text = font_menu.render(f"RECORD", True, (255, 255, 255))
        record_rect = record_text.get_rect(center=(100, 300))
        exit_text = font_menu.render(f"EXIT", True, (255, 255, 255))
        exit_rect = exit_text.get_rect(center=(100,350))
        if game_state.INFO:
            font = pygame.font.SysFont("Times New Roman", 20)

            # Многострочный текст
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

            # Начальная позиция для отрисовки текста
            y_offset = 100  # Отступ сверху

            # Отрисовка каждой строки текста
            for line in text:
                text_surface = font.render(line, True, (255, 255, 255))  # Создаем поверхность с текстом
                text_rect = text_surface.get_rect(topleft=(350, y_offset))  # Позиционируем текст
                game_state.screen.blit(text_surface, text_rect)  # Отрисовываем текст на экране
                y_offset += 30  # Увеличиваем отступ для следующей строки
        elif game_state.RECORD:
            records = load_record()
            font = pygame.font.SysFont("Times New Roman", 30)
            max_time_text = font.render(f"MAXIMUM TIME: {records['max_time']}", True, (255, 255, 255))
            max_rect = max_time_text.get_rect(center=(550, 100))
            kills_text = font.render(f"KILLS {records['kills']}", True, (255, 255, 255))
            kills_rect = kills_text.get_rect(center=(550, 130))
            average_time_text = font.render(f"AVERAGE TIME: {records['average_time']}", True, (255, 255, 255))
            average_rect = average_time_text.get_rect(center=(550, 160))
            game_state.screen.blit(max_time_text, max_rect)
            game_state.screen.blit(kills_text, kills_rect)
            game_state.screen.blit(average_time_text, average_rect)

        game_state.screen.blit(start_text, start_rect)
        game_state.screen.blit(exit_text, exit_rect)
        game_state.screen.blit(info_text, info_rect)
        game_state.screen.blit(record_text, record_rect)
        for event in events:
            if event.type == pygame.MOUSEBUTTONDOWN:  # Нажатие мыши
                if event.button == 1:  # Проверка, что нажата левая кнопка мыши
                    if start_rect.collidepoint(event.pos):  # Проверка, нажата ли надпись
                        game_state.is_clicked = True
                    if exit_rect.collidepoint(event.pos):  # Проверка, нажата ли надпись
                        game_state.is_clicked = True
                    if info_rect.collidepoint(event.pos):  # Проверка, нажата ли надпись
                        game_state.is_clicked = True
                    if record_rect.collidepoint(event.pos):  # Проверка, нажата ли надпись
                        game_state.is_clicked = True
            if event.type == pygame.MOUSEBUTTONUP:  # Отпускание мыши
                if event.button == 1:  # Проверка, что отпущена левая кнопка мыши
                    if game_state.is_clicked and start_rect.collidepoint(event.pos):
                        game_start()
                    if game_state.is_clicked and exit_rect.collidepoint(event.pos):
                        running=False
                    if game_state.is_clicked and record_rect.collidepoint(event.pos):
                        game_state.INFO=False
                        game_state.RECORD=True
                    if game_state.is_clicked and info_rect.collidepoint(event.pos):
                        game_state.INFO=True
                        game_state.RECORD=False

        pygame.display.flip()
    elif game_state.WIN:
        game_state.screen.blit(win_image, (0, 0))
        win_text = font_win.render(f"YOU WIN", True, (255, 255, 255))
        win_rect = win_text.get_rect(center=(400, 300))
        game_state.screen.blit(win_text, win_rect)
        time_text = font.render(f"TIME: {game_state.time_game} sec", True, (255, 255, 255))
        time_rect = time_text.get_rect(center=(100, 50))
        game_state.screen.blit(time_text, time_rect)
        kill_text = font.render(f"KILLS: {game_state.enemies_killed} ", True, (255, 255, 255))
        kill_rect = kill_text.get_rect(center=(100, 100))
        game_state.screen.blit(kill_text, kill_rect)
        text = font.render(f"нажмите ENTER что бы продолжить", True, (255, 255, 255))
        text_rect = text.get_rect(center=(400, 550))
        game_state.screen.blit(text, text_rect)
        pygame.display.flip()
        for event in events:
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    game_state.GAME = False
                    game_state.LOADING = False
                    game_state.LOST = False
                    game_state.WIN=False
                    game_state.MENU = True
        pygame.display.flip()

# Завершение игры
pygame.quit()