# лабораторная работа 2
## условие лабораторной работы
Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит относительный путь к папке. В данной папке найти все 
файлы с расширением *.txt и переименовать их последовательно (названия 1.txt, 2.txt, 3.txt и 
т.д.), начиная с наибольшего файла и заканчивая наименьшим

## *алгоритм выполнения bat файла*

setlocal enabledelayedexpansion
@echo off

set /a number=0
::cd "%folder%"


for /r folder %%i in (*.txt) do (
echo %%i
set /a number += 1
echo !number!
ren %%i "!number!.txt"
) 

echo %number%
echo renamed successfully
pause

1. оивуруруа
2. вствствствст
3. вввссавуаа
