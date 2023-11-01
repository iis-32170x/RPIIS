@chcp 65001
@echo off
setlocal enabledelayedexpansion
set /p directory_file="Введите относительный путь папки: "
set MIN=-32768
set MAX=32768
set /a range=MAX-MIN+1
set /a First_number=%random% %% range + MIN
set /a Second_number=%random% %% range + MIN
set /a Third_number=%random% %% range + MIN
set /a summa = %First_number%+%Second_number%+%Third_number%
set /a proverka = %summa% %% 2
If Exist "%directory_file%\*.*" (
    Echo %First_number%, %Second_number%, %Third_number% > Numbers.txt
    If %proverka% == 0 (    
        set > Enviroment.txt
        grep -o "a" C:\Users\derne\Desktop\Enviroment.txt | grep -c .>>Enviroment.txt
    ) Else (
        for /f "tokens=1,2,3 delims=." %%a in ("%date%") do (
            set day=%%a
            set month=%%b
            set /a year=%%c
        )
        if !month! LSS 10 (
            set "month=!month:~1!"
        )
        if !day! LSS 10 (
            set "day=!day:~1!"
        )
        set /a sum=!day!+!month!+!year!   
        Echo !sum! > Date.txt
    )
) Else (
   Echo Данной папки нет 
)
pause


