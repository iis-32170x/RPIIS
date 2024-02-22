@echo off
setlocal enabledelayedexpansion
set /p N=%1
set /a count=0
set "max_mem_process="
set "first_line="

for /f "tokens=*" %%a in ('tasklist /fi "MEMUSAGE ge 102400" /nh ^| sort /r /+65') do (
    if not defined first_line (
        set "first_line=%%a"
    )
    echo %%a
    set /a "count+=1"
    if !count! equ %N% (
        set "max_mem_process=%%a"
        goto :done
    )
)

:done

for /f "usebackq tokens=1-3 delims=/ " %%a in (`echo %date%`) do (
    set "day=%%a"
    set "month=%%b"
    set "year=%%c"
)

set "formatted_date=!day!-!month!-!year!"
set "filename=lab_!formatted_date!_!first_line!.txt"
echo %formatted_date% > "!filename!"
echo filename



timeout /t 10 >nul
