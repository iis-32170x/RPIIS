@echo off
chcp 65001
setlocal enabledelayedexpansion

set inputFile=%~1
if exist LR1 (
    cd LR1
	if exist odd_file_bat.txt (
	    del odd_file_bat.txt
	    del even_file_bat.txt
	)
) else (
    mkdir LR1
	cd LR1
)

if exist %inputFile% (
    sort %inputFile% /O %inputFile%
) else (
    echo Такого файла не существует или что-то введено неверно. Повторите попытку.
	pause
	exit /b 1
)

set oddFile=odd_file_bat.txt
set evenFile=even_file_bat.txt

set "numberLine=1"

for /f "usebackq delims=" %%a in ("%inputFile%") do (
  set /a "remainder=numberLine %% 2"
  if !remainder! equ 0 (
    echo %%a >> "%evenFile%"
  ) else (
    echo %%a >> "%oddFile%"
  )
    set /a "numberLine+=1"
)

pause