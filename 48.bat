@echo off
set /p number="input any number: "
set /p path="Input a path: "

call :checkNumber
call :checkPath
goto :passed

rem "function that validates input 'number' variable"
:checkNumber
if "%number%"=="" (echo the "number" variable isn't defined & goto :exit)
for /f "tokens=* delims=0" %%a in ("%number%") do (set number=%%a)
if "%number%" == "" (set number=0 & exit /b)
set /a "isInteger=number*1"
if NOT %isInteger% == %number% (echo the input number doesn't have number type & goto :exit)
exit /b

rem "function that validates input 'path' variable"
:checkPath
if "%path%"=="" (echo the "path" variable isn't defined & goto :exit)
if not exist "%path%" (echo the entered path doesn't exist & goto :exit)
exit /b


:passed
set dateStr=%date%
type nul > %dateStr%.txt
for /f "tokens=1,2 delims= " %%i in (%path%) do (if %%i geq %number% (echo %%i %%j >> %dateStr%.txt))

:exit
pause




