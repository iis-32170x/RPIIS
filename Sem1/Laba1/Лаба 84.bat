@chcp 1251
@echo off
md d:\folder1
md d:\folder2
md d:\folder3
md d:\tempfolder
Echo %date%> D:\folder1\Text1.txt
copy d:\folder1\Text1.txt d:\folder2
ren d:\folder2\Text1.txt %date:~,2%.txt
FOR %%a IN (%date:~,2%.txt) DO set strvar=%%a 
ECHO %strvar%> d:\tempfolder\tempfile.txt
FOR %%n IN (d:\tempfolder\tempfile.txt) DO ( SET /A strlength=%%~zn - 3 )
Echo %strlength% >> D:\folder2\%date:~,2%.txt
copy d:\folder2\%date:~,2%.txt d:\folder3
ver >> D:\folder3\%date:~,2%.txt
RD /S /Q D:\tempfolder
pause
