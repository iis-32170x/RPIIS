

@echo off
setlocal enabledelayedexpansion
chcp 65001
for /f "tokens=2 delims==" %%G in ('wmic OS Get localdatetime /value') do set "datetime=%%G" 
set "timestamp=%datetime:~8,2%_%datetime:~10,2%_%datetime:~12,2%"
MD test
cd test
set count = 0 
SET /P kolichestvo=
for /l %%i in (1,1,%kolichestvo%) do (
                   echo %timestamp% > %%i.txt
                   set /a count += 1
                   if !count! equ 3 (
                           echo .>"%%i.txt"
                           ren "%%i.txt" "%%~ni.doc"
                           set count=0
                           )
) 
echo. > hahhahaahahh.txt
for %%l in (*.txt) do (
    findstr /m "04" "%%l" > nul
    if not errorlevel 1 (
        echo %%~nxl >> hahhahaahahh.txt
    )
)
endlocal
pause
