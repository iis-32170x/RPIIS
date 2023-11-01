@echo off

chcp 65001 > nul


set /p input_time=Введите время в формате ЧЧ:ММ:СС:

:wait
set current_time=%time%
set current_time=%current_time:~0,8%

if "%input_time%"=="%current_time%" (
 MD C:\Users\bebra\Desktop\Laba1pivovovovoo
 ipconfig > C:\Users\bebra\Desktop\Laba1pivovovovoo\network_parameters.txt
 systeminfo > C:\Users\bebra\Desktop\Laba1pivovovovoo\system_parameters.txt
 tasklist > C:\Users\bebra\Desktop\Laba1pivovovovoo\processes.txt
 pause
) else (
    timeout /t 1 >nul
    goto wait
)
