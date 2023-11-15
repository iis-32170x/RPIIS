
@echo off

if not exist "%~1" (
  echo %~1: No such directory
  exit /b 1
)

forfiles /p "%~1" /s /m * /d %~2 /c "cmd /c if @isdir==FALSE echo @path" >> result.txt