@chcp 1251
@echo off
set /p divisor=Введите число, на которое необходимо разделить PID:
tasklist /nh /fo csv > tasks.txt
setlocal enabledelayedexpansion
set /a count=0
for /f "tokens=1,2 delims=," %%a in (tasks.txt) do (
set /a pid=%%b
set /a remainder=!pid! %% !divisor!
if !remainder! equ 0 (
echo process=
echo %%a
echo pid=
echo %%b
set /a count+=1
)
)
timeout 30
del tasks.txt
if !count! equ 1 (
echo процесс не найден. программа закроется через 3 сек
timeout  3 
)
