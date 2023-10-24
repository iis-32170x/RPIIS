@echo off
chcp 65001 > nul

setlocal enabledelayedexpansion

set /p "directory=Введите путь к папке: "
set /p "extension=Введите расширение файла: "
set /p "max_length=Введите максимальную длину имени файла: "

set "output_file=FileList.txt"

cd /d "%directory%"

> "%output_file%" (
  for /r %%F in (*.%extension%) do (
    set "filename=%%~nxF"
    set "filename=!filename:~0,%max_length%!"
    if "!filename!"=="%%~nxF" echo %%~nxF
  )
)

sort "%output_file%" > nul

echo Список файлов, удовлетворяющих критериям, сохранен в файле: %output_file%

pause
exit /b
