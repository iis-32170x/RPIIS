@echo off
setlocal enabledelayedexpansion

REM Очищаем файл result.txt перед выполнением скрипта
echo. > result.txt

REM Получаем список всех процессов
for /f "skip=3 tokens=1,2 delims=," %%a in ('tasklist /nh /fo csv') do (
    REM Проверяем, есть ли уже такой процесс в списке
    set "found=false"
    for %%b in (!processes!) do (
        if "%%a"=="%%b" (
            set "found=true"
            REM Увеличиваем счетчик для найденного процесса
            set /a "count[%%a]+=1"
        )
    )
    REM Если процесс не найден, добавляем его в список и устанавливаем счетчик в 1
    if not "!found!"=="true" (
        set "processes=!processes! %%a"
        set /a "count[%%a]=1"
    )
)

REM Находим максимальное количество процессов и записываем результат в файл result.txt
set "max_count=0"
for /f "tokens=2,3 delims=[]=" %%a in ('set count[') do (
    if %%b gtr !max_count! (
        set "max_count=%%b"
        set "max_process=%%a"
    )
    REM Записываем каждый процесс и его количество в файл result.txt
   
)
 REM выводим процесс с наибольшим количеством повторений 
echo %max_process% %max_count% >> result.txt 

endlocal
