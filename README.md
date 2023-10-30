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
![Снимок экрана 2023-10-19 134007](https://github.com/iis-32170x/RPIIS/assets/144949092/6a7dea3c-83bc-4013-90bc-8195af672a98)



