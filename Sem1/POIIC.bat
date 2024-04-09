@echo off
setlocal

if "%1"=="" ( 
	echo vvedi chislo svoe, pojalusta, ochen nada
	exit 1
)
 for /f "tokens=2" %%y in ('tasklist /fo table /nh') do (
 
	echo %%y | findstr  "%1"  >nul 2>nul && ( tasklist /fo table /nh /fi "PID eq  %%y" >> filepid.txt) 






)
echo sohraneno







endlocal
