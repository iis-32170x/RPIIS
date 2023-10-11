@echo off
chcp 65001 > nul

setlocal enabledelayedexpansion

echo Введите абсолютный путь:

set /p folder=
set smallestSize=99999999
set smallestFile=
set filename=

for %%F in ("%folder%\*.txt") do (
    if %%~zF lss !smallestSize! (
        set smallestSize=%%~zF
        set smallestFile=%%F
    )
)
for %%F in ("%smallestFile%") do (
    set fileName=%%~nF
)

type %smallestFile% > %folder%\copy_%filename%.txt
del %smallestFile%
echo Самый маленький txt-файл: %filename%
echo Размер: %smallestSize% байт

endlocal

pause
