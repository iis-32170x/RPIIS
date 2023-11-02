md c:\Hu
tasklist /fi "PID ge 99" /fi "PID le 999" > c:\Hu\Homa.txt
set T=1
setlocal enabledelayedexpansion
for /f "skip=3" %%i in (c:\Hu\Homa.txt) do (
echo %%i>c:\Hu\Tao!T!.txt 
set /a T+=1)
del c:\Hu\Homa.txt