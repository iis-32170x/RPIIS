@echo off
echo "Ку, напиши любое число" 
set /p num=
if %num% EQU 0
 ( echo "Число %num% четное, создаю папки циклически"
  setlocal enabledelayedexpansion
  for /l %%i in (1, 1, %num%) do 

   (md folder%%i\folder%%{i+1}\folder%%{i+2}
    set filename=%time:~0,2%_%time:~3,2%_%time:~6,2%
    copy nul folder%%i\folder%%{i+1}\folder%%{i+2}\!filename!.txt )
) else (
  echo "Число %num% нечетное."
  echo "Произвольное число %RANDOM%" >> numbers.txt
)
