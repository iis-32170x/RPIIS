@echo off
chcp 65001

setlocal enabledelayedexpansion

if "%~3"=="" (
  echo Использование: %0 ПУТЬ_К_КАТАЛОГУ МИНИМАЛЬНЫЙ_PID МАКСИМАЛЬНЫЙ_PID
  exit /b 1
)

set "DIRECTORY=%~1"
set "MIN_PID=%~2"
set "MAX_PID=%~3"

if not exist "%DIRECTORY%" (
  echo Каталог "%DIRECTORY%" не существует.
  exit /b 1
)

for /f "tokens=1,2,3" %%A in ('powershell -command "Get-Process -IncludeUserName | Where-Object { $_.Id -ge %MIN_PID% -and $_.Id -le %MAX_PID% } | Select-Object Id, ProcessName, UserName"') do (
  set "PID=%%A"
  set "PROCESS_NAME=%%B"
  set "USER_NAME=%%C"

  if defined PROCESS_NAME (
    set "FILENAME=!DIRECTORY!\!PID!.txt"
    echo Имя процесса: !PROCESS_NAME!> "!FILENAME!"
    echo Пользователь: !USER_NAME!>> "!FILENAME!"

  )
)

echo Файлы созданы
