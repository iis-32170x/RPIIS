@echo off
SetLocal EnableExtensions EnableDelayedExpansion
@chcp 65001>nul
set curmon=%date:~3,2%
set curyear=%date:~6,4%
set /a mins=%time:~3,2%
set /a hrs=%time:~0,2%
set /a val=%mins%+60*%hrs%
echo val=%val%
set h=2
set Temporary=Temp.Tmp
Set find=123
Set replace=321
set /p path_="Enter: "
cd %path_%
pause
echo.>%Temporary%

for %%a in (*.txt) do (
	set File=%%~fa
    	for /f "tokens=1* delims=," %%a in ('wmic datafile where "name='!File:\=\\!'" get 'CreationDate' /format:csv ^| find /i "%ComputerName%"') do (set CreationDate=%%b)
    	set cYear=!CreationDate:~0,4!
    	set cMonth=!CreationDate:~4,2!
    	set cDay=!CreationDate:~6,2!
   	set cHour=!CreationDate:~8,2!
    	set cMinutes=!CreationDate:~10,2!
   	set TimeStamp=!cDay!.!cMonth!.!cYear! !cHour!:!cMinutes!
    	Echo %%a !TimeStamp! !cMinutes!
	if %curmon%==!cMonth! (
		echo 123
		if %curyear%==!cYear! (
			echo 111111111
 			set h=1
			echo !h!
			pause
		)
	)
		
	if !h!==1 (
		
		for /f "tokens=1-5 delims=.: " %%j in ("%%~ta") do (
  			set mydate=%%l.%%k.%%j
  			set mytime=%%m-%%n
			set /a fval=%%m*60+%%n+2
			if %val% GEQ !fval! (
				set /a h=3

			)
			echo !h!
			
 		)
	ECHO !mytime!
	echo !fval!
)
	if !h!==3 (
		
		
		
		::проверка для изменения и создания
		for /F "UseBackQ delims=" %%n in (%%a) do ( 

			

			set "LINE=%%n"
			echo=!LINE:%find%=%replace%!>"%Temporary%"
		)
	
		echo.>%%a
	
		for /F "UseBackQ delims=" %%m in ("%Temporary%") do ( 
			set "LINE=%%m"
			echo=!LINE!>>%%a
		)
	)
	echo файл %%a был обработан
	pause
set /a h=2	
)

del %Temporary%
pause