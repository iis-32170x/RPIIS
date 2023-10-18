@echo off
setlocal enabledelayedexpansion

if "%~1"=="" (
  echo Usage: %0 ^<directory^>
  exit 1
)

set "directory=%~1"
set "output_file=result.txt"

del "%output_file%" 2>nul

for /r "%directory%" %%f in (*s*) do (
  set "last_line="
  for /f %%a in ('type "%%f"') do set "last_line=%%a"
  if defined last_line (
    echo !last_line!>>"%output_file%"
  )
)

echo Last lines of files containing 's' saved in %output_file%

