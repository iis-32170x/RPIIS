@echo off
setlocal

set "source_directory=%~1"
set "date=%~2"
set "destination_directory=%~3"

for /F "tokens=1-3 delims=." %%a in ("%date%") do (
    set "day=%%a"
    set "month=%%b"
    set "year=%%c"
)
for /R "%source_directory%" %%F in (*.*) do (
    set "found_file=%%F"
    :S
    for /F "skip=5 tokens=1" %%i in ('dir "%%F" /T:C') do (
        set "file_date=%%i"
        goto :out
    )
)
:out
for /F "tokens=1-3 delims=." %%a in ("%file_date%") do (
    set "fday=%%a"
    set "fmonth=%%b"
    set "fyear=%%c"
)

set "Date=%year%%month%%day%"
set "fdate=%fyear%%fmonth%%fday%"
if "%fdate%" LEQ "%Date%" (
    goto :w
) else (
    goto :S
)

:w
echo found_file=%found_file%
for %%I in ("%found_file%") do (
    set "filename=%%~nI"
    set "extension=%%~xI"
)
set "fname=%filename%%extension%"
echo fname:%fname%

set "new_filename=%filename%_%file_date%%extension%"
echo new filename:%new_filename%
robocopy "%source_directory%" "%destination_directory%" "%fname%"


RENAME "%destination_directory%\%fname%" "%new_filename%"

endlocal