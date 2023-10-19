# ЛАБОРАТОРНАЯ РАБОТА №2

# Условие:

![image](Images/Условие.png)

## .bat file

@echo off
if exist "C:\PiOIvIS" (
chcp 1251>nul
echo Atrib=RA: >>result.txt
dir /b/a:r >>result.txt
echo Atrib=HA: >>result.txt
dir /b/a:h >>result.txt
echo Atrib=A: >>result.txt
dir /b/a:-r-h >>result.txt
) else (
echo Dannoi papki net
)
pause
