@echo off
setlocal enabledelayedexpansion

set "weekday=%1"
set "current_date=%date%"

for /F "tokens=1-3 delims=. " %%x in ("%current_date%") do (
  set "current_day=%%x"
  set "current_month=%%y"
  set "current_year=%%z"
)

for /L %%m in (%current_month%, 1, 10) do (
  for /L %%d in (%current_day%, 1, 31) do (
    set "date_to_check=!current_year!-%%m-%%d"
    for /F "tokens=1-3 delims=-" %%x in ("!date_to_check!") do (
      set /A "weekday_num=((%%x %% 100 + 2) * 365 + (%%y + 17) %% 12 * 30 + (%%z + 100) %% 100 + 2) %% 7 + 1"
    )
    if !weekday_num! equ %weekday% (
      echo !date_to_check! >> result.txt
    )
  )
)

for /L %%m in (11, 1, 12) do (
  for /L %%d in (1, 1, 30) do (
    set "date_to_check=!current_year!-%%m-%%d"
    for /F "tokens=1-3 delims=-" %%x in ("!date_to_check!") do (
      set /A "weekday_num=((%%x %% 100 + 3) * 365 + (%%y + 17) %% 12 * 30 + (%%z + 100) %% 100 + 2) %% 7 + 1"
    )
    if !weekday_num! equ %weekday% (
      echo !date_to_check! >> result.txt
    )
  )
)

endlocal
