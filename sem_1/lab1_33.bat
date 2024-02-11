@chcp 1251
echo enter directory
set /p a=
cd %a%
dir %a% 
goto exist%errorlevel%
:exist1
echo the directory not exist
pause
exit
:exist0
echo the directory exist
echo enter filename
set /p b=
dir %a%  /o:-s /s  >%b%
