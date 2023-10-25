@echo off
set /a date1 = %date:~0,1%
set /a date2 = %date:~1,1%
set /a date3 = %date:~2,1%
set /a date4 = %date:~3,1%
set /a date5 = %date:~4,1%
set /a date6 = %date:~5,1%
set /a date7 = %date:~6,1%
set /a date8 = %date:~7,1%
if %date1% geq %date1% if %date1% geq %date2% if %date1% geq %date3% if %date1% geq %date4% if %date1% geq %date5% if %date1% geq %date6% if %date1% geq %date7% if %date1% geq %date8% set /a a=%date1%
if %date2% geq %date1% if %date2% geq %date2% if %date2% geq %date3% if %date2% geq %date4% if %date2% geq %date5% if %date2% geq %date6% if %date2% geq %date7% if %date2% geq %date8% set /a a=%date2%
if %date3% geq %date1% if %date3% geq %date2% if %date3% geq %date3% if %date3% geq %date4% if %date3% geq %date5% if %date3% geq %date6% if %date3% geq %date7% if %date3% geq %date8% set /a a=%date3%
if %date4% geq %date1% if %date4% geq %date2% if %date4% geq %date3% if %date4% geq %date4% if %date4% geq %date5% if %date4% geq %date6% if %date4% geq %date7% if %date4% geq %date8% set /a a=%date4%
if %date5% geq %date1% if %date5% geq %date2% if %date5% geq %date3% if %date5% geq %date4% if %date5% geq %date5% if %date5% geq %date6% if %date5% geq %date7% if %date5% geq %date8% set /a a=%date5%
if %date6% geq %date1% if %date6% geq %date2% if %date6% geq %date3% if %date6% geq %date4% if %date6% geq %date5% if %date6% geq %date6% if %date6% geq %date7% if %date6% geq %date8% set /a a=%date6%
if %date7% geq %date1% if %date7% geq %date2% if %date7% geq %date3% if %date7% geq %date4% if %date7% geq %date5% if %date7% geq %date6% if %date7% geq %date7% if %date7% geq %date8% set /a a=%date7%
if %date8% geq %date1% if %date8% geq %date2% if %date8% geq %date3% if %date8% geq %date4% if %date8% geq %date5% if %date8% geq %date6% if %date8% geq %date7% if %date8% geq %date8% set /a a=%date8%
set /a b=%a%/2*2
if %a%==%b% ( echo > d:%a% ) else ( echo Hello )
pause
