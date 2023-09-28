## БГУИР Лабораторная работа №1
<br />
Условия предоставляемой задачи(вариант 37):
<br />
<br />
Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит файл (как параметр пакетного файла), содержащий некоторый список строк. Отсортировать указанный файл. Создать два файла, в первом из которых будут содержаться нечетные строки из входного файла, во втором - четные
<br />
<br />
## Работа файла bat
<br />
Как выглядит код:
<br />
<br />
```bash
@echo off
chcp 65001
setlocal enabledelayedexpansion

cd /d "D:\PIOIVIS\LR1"

set inputFile=%~1

if exist %inputFile% (
    sort %inputFile% /O %inputFile%
) else (
    echo Такого файла не существует или что-то введено неверно. Повторите попытку.
	pause
	exit /b 1
)

set oddFile=odd_file_bat.txt
set evenFile=even_file_bat.txt

set "numberLine=1"

for /f "usebackq delims=" %%a in ("%inputFile%") do (
  set /a "remainder=numberLine %% 2"
  if !remainder! equ 0 (
    echo %%a >> "%evenFile%"
  ) else (
    echo %%a >> "%oddFile%"
  )
    set /a "numberLine+=1"
)

pause
```
