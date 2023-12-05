@echo off
echo>Dev.txt
ipconfig > Dev.txt
md 1
copy Dev.txt 1
ren C:\Users\Igorco\Desktop\1\Dev.txt Dev1.txt
echo count of lines:
find /c " " < "C:\Users\Igorco\Desktop\1\Dev1.txt" 
pause
rd /s "C:\Users\Igorco\Desktop\1"
del Dev.txt