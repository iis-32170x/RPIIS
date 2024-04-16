@echo off
chcp 65001 > NUL
set /p x="Введите PID"
tasklist /fi "pid eq %x%"
tasklist>newfile.txt
FINDSTR %x% newfile.txt 
if errorlevel 1 goto b
del newfile.txt
:A
set /p a=“Хотите завершить процесс? [Y/n]”
IF %a%==y taskkill /fi "pid eq %x%"
IF %a%==y echo процесс завершен
IF %a%==y TIMEOUT /T 10
IF %a%==y EXIT /B 0
IF %a%==n echo процесс не будет завершен
IF %a%==n TIMEOUT /T 10
IF %a%==n EXIT /B 0
goto a
:b
echo Процесс не найден
TIMEOUT /T 10
EXIT /B 0