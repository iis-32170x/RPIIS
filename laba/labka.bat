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