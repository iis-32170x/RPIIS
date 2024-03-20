@echo off
chcp 65001>nul
setlocal enabledelayedexpansion

set /p directory=

if not exist "%directory%" (
  echo Данного каталога нет.
  pause
)

for /r "%directory%" %%a in (*) do (
    set /a "xount=0"
    for /f "tokens=*"  %%b in ('type "%%a"') do (
        for %%c in (%%b) do (
            set /a "xount+=1"
        )
   	)
      set "newname=!xount!_%%~na"
      set "rush=%%~xa"
      ren "%%a" "!newname!!rush!"
)
 pause