@echo off
chcp 65001
echo Введите число не превышающее 100:
set /p a=N=
if %a% gtr 100 (echo НЕВЕРНЫЕ ДАННЫЕ )
if %a% lss 0 (echo НЕВЕРНЫЕ ДАННЫЕ )
set /a ending=%a%%%10
set /a starting=%a%/10
set datetemp=%date:~-10%
cd C:\Users\devert\Documents\LABY\PIVO
md test
cd C:\Users\devert\Documents\LABY\PIVO\test
if %ending% gtr %starting% ( for /l %%i in (1,1,%ending%) do ( echo %datetemp% > %%i.txt )
                                   for /l %%i in (2,2,%ending%) do ( ren %%i.txt %%i.doc ) 
                                             for /l %%i in (1,2,%ending%) do ( del %%i.txt
                                                                     echo тут няма ничога > %%i.txt )
) else ( 
          for /l %%i in (1,1,%starting%) do ( echo %datetemp% > %%i.txt ) 
             for /l %%i in (2,2,%starting%) do ( ren %%i.txt %%i.doc )
                   for /l %%i in (1,2,%starting%) do ( del %%i.txt
                                                         echo тут няма ничога > %%i.txt ) )
pause