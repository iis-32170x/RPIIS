# Условие (5 вариант)
Создать файл sh и bat, который выполняет следующее:
Генератор паролей. На вход пакетному файлу приходит число (как параметр пакетного файла). Создать файл pwd.txt и записать в него 6 вариантов сгенерированных комбинаций, длина которых будет равна параметру пакетного файла. Каждая строка должна начинаться с новой строки и может содержать цифры, большие и маленькие буквы латинского алфавита, и спецсимволы @!%$#^.
## Реализация на batch:

```bat
@echo off
set /p password_length="Length: "
setlocal enabledelayedexpansion
set password_file=pwd.txt
set simvoli=0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@!%%$#^
if exist %password_file% (
    del %password_file%
)
for /l %%i in (1, 1, 6) do (
    set "password="
    for /l %%j in (1, 1, %password_length%) do (
        set /a "char_index=!random! %% 63"
        for /l %%k in (!char_index!, 1, !char_index!) do (
            set "char=!simvoli:~%%k,1!"
            set "password=!password!!char!"
        )
    )
    echo !password! >> %password_file%
)
echo Smotrite
pause
```
## ___Переменные___
* password_length-длина пароля,задаваемая пользователем
* simvoli-набор символов для генерации паролей
  ### Пример работы программы
![Снимок экрана 2023-10-19 134007](https://github.com/iis-32170x/RPIIS/assets/144949092/6a7dea3c-83bc-4013-90bc-8195af672a98)
![Снимок экрана 2023-10-19 133856](https://github.com/iis-32170x/RPIIS/assets/144949092/6c5b8e45-6b0b-44db-bcd8-2b7cbbb29310)
## Реализация на batch:
```
#!/bin/bash
read -p "Length: " password_length
password_file="pwd.txt"
simvoli="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@!%%$#^"

if [ -f "$password_file" ]; then
    rm "$password_file"
fi

for i in {1..6}; do
    password=""
    for j in $(seq 1 "$password_length"); do
        char_index=$((RANDOM % 69))
        char="${simvoli:char_index:1}"
        password="$password$char"
    done
    echo "$password" >> "$password_file"
done
```
## ___Переменные___
* password_length-длина пароля,задаваемая пользователем
* simvoli-набор символов для генерации паролей
  ### Пример работы программы
  ![Снимок экрана 2023-10-19 134022](https://github.com/iis-32170x/RPIIS/assets/144949092/8fe9f16b-82eb-4cb0-b46c-a786b7f9af5b)
  ![Снимок экрана 2023-10-19 133938](https://github.com/iis-32170x/RPIIS/assets/144949092/987b82d0-514f-4d59-975a-358017e9b9db)







