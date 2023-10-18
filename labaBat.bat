@echo off
chcp 65001
:A
echo Vvedi papky
set /p a="" 
if not exist %a% echo Takoi papki net & goto A
dir /a: /b /s "%a%" | find /c ":\"
Set sum=0
Set papka=%a% 
For /r "%papka%" %%i In (*) Do Set /a sum+=1
tasklist >>  C:\log.txt
set  "file=C:\Log.txt"
for %%i in (%file%) do @set count=%%~zi
for /F "usebackq tokens=3 delims=:" %%L in (`find /v /c "" %file%`) do set lines=%%L
set /a "res=%sum%*(%count%-(%lines%-1)*2)"
echo %res% >> C:\%date%.txt
pause