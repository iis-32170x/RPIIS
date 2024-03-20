@echo off
cd Desktop
start first.txt
start second.txt
taskkill /im notepad.exe
set /a _rand = (%random%*100/32767)+1
set /a i=0
:loop
if %i%==%_rand% goto end
set /a r = 100+(999-100+1)*%random%/32768
echo %r% >> C:\Users\yaroslave\Desktop\first.txt
set /a i=i+1
goto loop
:end
findstr /r /c:"23" first.txt >> second.txt
cd Desktop
sort /r second.txt /o second.txt
start second.txt
start first.txt 
pause
