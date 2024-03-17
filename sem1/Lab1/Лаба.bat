@echo off
chcp 65001
if exist "%1" (
set /a num=0
for /r "%1" %%i in (*.txt) do (
set /a num=num + 1
)
) else (
echo Данной папки нет
pause 
exit
) 
set /a ost=num%%2
if %ost% == 0 (
dir /O:-d %1 /b>labfile.txt
) else (
dir %1 /O:s /b>labfile.txt
)
pause
