import pygame

class GameState:
    def __init__(self):

        self.SCREEN_WIDTH = 800
        self.SCREEN_HEIGHT = 600
        self.screen = pygame.display.set_mode((self.SCREEN_WIDTH, self.SCREEN_HEIGHT))
        self.MAP_WIDTH = self.SCREEN_WIDTH * 3
        self.MAP_HEIGHT = self.SCREEN_HEIGHT * 3
        self.camera_x = 0
        self.camera_y = 0
        self.LOADING = True
        self.GAME = False
        self.LOST = False
        self.MENU = False
        self.RECORD = False
        self.INFO = False
        self.WIN = False
        self.is_hovered = False
        self.is_clicked = False
        self.player = None
        self.all_sprites = pygame.sprite.Group()
        self.bullets = pygame.sprite.Group()
        self.enemies = pygame.sprite.Group()
        self.weapons = pygame.sprite.Group()
        self.weapon = None
        self.wave_num = 0
        self.perk = None
        self.TIMER_EVENT = pygame.USEREVENT + 2
        self.TIMER_START_EVENT = pygame.USEREVENT + 3
        self.HIT_PLAYER_EVENT = pygame.USEREVENT + 4
        self.timer_active = False
        self.start_time = 0
        self.end_game = 0
        self.time_game = 0
        self.start_game = 0
        self.enemies_killed = 0

# Использование
game_state = GameState()