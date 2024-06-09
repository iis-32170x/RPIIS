@echo off
chcp 65001 > nul

echo Введите относительный путь 1:
set /p folder1=
echo Введите относительный путь 2:
set /p folder2=

if not exist "%cd%\%folder1%" (
    echo Данной папки нет - "%cd%\%folder1%"
    exit /b
)
if not exist "%cd%\%folder2%" (
    echo Данной папки нет - "%cd%\%folder2%"
    exit /b
)
for %%f in ("%cd%\%folder1%"\*) do (
    if /i not "%%~xf"==".txt" (
        attrib +r "%%f"
    )
)
move "%cd%\%folder1%"\*.txt "%cd%\%folder2%"\

echo Программа выполнена.

pause
