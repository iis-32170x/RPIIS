@echo off

set "directory=D:\PZH\pivas"

if not exist "%directory%" (
    echo Papka dont found
	pause
    exit /b
	
)

set count=0
for /r "%directory%" %%F in (*) do (
    set /a "count+=1"
)

set /a "result=count * %NUMBER_OF_PROCESSORS%"

for /f "tokens=1-3 delims=:," %%A in ("%TIME%") do (
    set "fileName=%%A_%%B_%%C"
)

echo %result% > "%directory%\%fileName%.txt"