@echo off

chcp 65001

set /p folder="Введите путь к папке: "

if not exist "%folder%" (
    echo Данной папки нет
    exit
)

type nul > DA.txt

copy /b "%folder%\*.txt" DA.txt > nul

for %%A in (DA.txt) do (
    if %%~zA GTR 102400 (
        findstr /N "^" DA.txt | findstr /V /B "[02468]:" > temp.txt
        del DA.txt
        ren temp.txt DA.txt
    ) else if %%~zA LSS 102400 (
        findstr /N "^" DA.txt | findstr /B "[02468]:" > temp.txt
        del DA.txt
        ren temp.txt DA.txt
    ) else (
        echo File is 100 Kb
    )
)
move DA.txt D:\folder1\
