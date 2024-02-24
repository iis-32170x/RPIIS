@echo off
 set /p folder=Введите путь к папке: 
set /p format=Введите формат файлов: 
set /a count=0
for /f %%i in ('dir /b /a-d "%folder%\*.%format%" ^| find /c /v ""') do set "count=%%i"

echo Число файлов формата %format%: %count%
for /f %%P in ('tasklist /NH /FO CSV ^| find /c /v ""') do set "process_count=%%P"
set /a "remainder=count %% 2"
if %remainder% equ 0 echo Количество активных процессов: %process_count%
if %remainder% equ 0 pause
if %remainder% neq 0 echo Завершение программы через 7 секунд...
    timeout /t 7 >nul
