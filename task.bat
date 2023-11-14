echo off
setlocal enableextensions
chcp 65001

set /P path="Enter the path to a directory: "
if not exist "%path%" (
     echo this directory does not exist.
     exit /B 1
)
set /P num1="Enter the first smaller number: " 
set /P num2="Enter the second bigger number: "

if /I "%num1%" GEQ "%num2%" (
 set big=%num1%
 set sml=%num2%
) 
if /I "%num2%" GEQ "%num1%" (
 set big=%num2%
 set sml=%num1%
)
set minb=%sml%
set maxb=%big%

echo. 2> "output.txt"
FOR /f "delims=" %%I IN ('dir %path% /A:-D /B /O:N') DO (
 if %%~zI GEQ %minb% if %%~zI LEQ %maxb% echo %%I %%~tI >> "output.txt"
)