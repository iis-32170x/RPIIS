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

::for /r folder %%i in (*.txt) do (

::set /a number -= 1
::ren %%i "%number%.txt"
::)
    :: if %i% > 0 (
::ren "%%i" "%number%.txt"
::)
echo Files renamed successfully.
pause