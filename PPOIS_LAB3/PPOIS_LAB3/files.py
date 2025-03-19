import json  # Импорт модуля json для работы с JSON-файлами

# Загрузка данных о волнах врагов из файла waves.json
with open("json/waves.json", "r", encoding="utf-8") as file:
    data = json.load(file)  # Загрузка JSON-данных из файла
    waves = data["waves"]  # Извлечение списка волн из данных

# Загрузка характеристик врагов из файла enemy.json
with open("json/enemy.json", "r", encoding="utf-8") as file:
    enemy_stat = json.load(file)  # Загрузка JSON-данных из файла

# Загрузка характеристик игрока из файла player.json
with open("json/player.json", "r", encoding="utf-8") as file:
    player_stat = json.load(file)  # Загрузка JSON-данных из файла

# Загрузка характеристик оружия из файла weapon.json
with open("json/weapon.json", "r", encoding="utf-8") as file:
    weapon_stat = json.load(file)  # Загрузка JSON-данных из файла