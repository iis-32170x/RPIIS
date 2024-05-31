@echo off
setlocal
chcp 868
set "directory=%~1"
set "size=%~2"

if not exist "%directory%" (
  echo Данной папки нет
  exit /b 1
)

set "output_file=laboratornaya.txt"

for /r "%directory%" %%F in (*) do (
  if %%~zF LSS %size% (
    echo %%~nxF >> "%output_file%"
  )
)

echo Файлы размером меньше %size% байт:
type "%output_file%"

endlocal