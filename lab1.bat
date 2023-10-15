@echo off
chcp 65001
set /p input=Введите абсолютный путь к папке: 
if not exist %input% (
    echo Данной папки нет.
    pause
    exit /b
) else (
    for /l %input% %%i in (*.doc) do (
        echo %%~nxi
        del %%i
    )
) > %input%\log.txt
sort %input%\log.txt

echo Файлы с расширением .doc удалены и их названия записаны в log.txt.
pause
