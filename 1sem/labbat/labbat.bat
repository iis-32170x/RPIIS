@echo off
If "%~1"=="" (
    echo No input folder 
    pause 
    exit /b 2
)

rem "Команда If... используется для проверки, существует ли первый аргумент (папка). Двойка-код возврата, указывающий на ошибку." 

if exist "D:\study\batniki\alotoffiles" (
    echo Directory exists
) else (
    echo Directory not exists 
    pause
    exit
)

pause 

rem "Определяем переменные в пакетном файле"
set "searchDir=alotoffiles"
set "outputFile=result.txt"

rem "Нижняя команда создаёт пустой файл или очищает содержимое существующего."
type nul > "%outputFile%" 

rem "Инициируем перебор всех файлов в спискe"
for /r "%searchDir%" %%A in (*) do (
    for /r "%searchDir%" %%B in (*) do (
       if /I "%%A" neq "%%B" (
          rem "/I задает сравнение текстовых строк без учета регистра; neq - неактуален ли один одному"
          fc /b "%%A" "%%B" > nul
          rem "nul - отказ от вывода данных в терминал"  
          if errorlevel 1 (
          echo "files are different" > nul 
          ) else (
          echo %%A >> "%outputFile%"
          echo %%B >> "%outputFile%"
          echo %%--------------------------------------------------------- >> "%outputFile%"
          )
      )
   )
)

echo "Results in result.txt"
pause










