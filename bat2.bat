@echo off
Setlocal EnableDelayedExpansion
set /p num= Enter number: 
if defined num (echo Number of random numbers = %num%) else (
echo The parameter is not set
pause
exit
)
for /L %%i in (1, 1, %num%) do (
	set /a i = !random!
	echo !i! >> 1.txt
)
pause