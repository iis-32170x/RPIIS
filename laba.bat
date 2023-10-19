@echo off
set a=D:\batha
set month=%date:~3,2%
set day=%date:~0,2%
powershell.exe -Command "Get-Process | Select-Object NPM | Sort-Object NPM -Descending | Out-File -Encoding UTF8 -FilePath "%a%\tempfile.txt""
for /f "UseBackQ skip=3 Delims=" %%a in ("%a%\tempfile.txt") do (
	set max=%%a
	goto :2
)
:2
echo max = %max%
powershell.exe -Command "Get-Process | Select-Object NPM | Sort-Object NPM | Out-File -Encoding UTF8 -FilePath "%a%\tempfile.txt""
for /f "UseBackQ skip=4 Delims=" %%a in ("%a%\tempfile.txt") do (
	set min=%%a
	goto :3
)
:3
del %a%\tempfile.txt
echo min = %min%
set /a raznost=max-min
echo Raznost = %raznost%
set /A ost=raznost %% 2
if %ost% equ 0 (
	echo Raznost chetnaya
    for /L %%i in (1,1,%day%) do (
        type nul > "%a%\file%%i.txt"
    )
) else (
	echo Raznost nechetnaya
    for /L %%i in (1,1,%month%) do (
        start notepad.exe
    )
)
pause