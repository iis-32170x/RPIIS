@echo off
setlocal enabledelayedexpansion
set target_folder=%2
set keywords=%1
set search_number=%3
set number=0
CD\%target_folder%
set search_folder_name=%target_folder%_search
mkdir %search_folder_name%
for %%f in (*) do (
for /f "tokens=*" %%A in ('findstr /i "%keywords%" "%%f"') do (
for %%W in (%%A) do (
set /a number+=1
)
echo !number!
if !number! geq %search_number% (
copy %%f %search_folder_name%
)
set number=0
)
)
pause
endlocal
