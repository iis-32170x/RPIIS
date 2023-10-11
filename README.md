# Условие (21 вариант)
21. Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит путь к каталогу, дата (формат DD.MM.YYYY) и второй каталог. Найти файл в указанном каталоге, созданный не позднее указанной даты, скопировать его в другой указанный каталог и добавить в имя файла дату его создания (filename_DD.MM.YYYY.txt).
# Реализация на batch
 ```batch 
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
```
## Пример запуска
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/85ef2bbe-e176-429b-98a8-7c958f0a65a6)
## Переменные :sweat_smile:
- source_directory-путь к каталогу,в котором будет осуществляться поиск файла
- date-хранит дату,относительно которой осуществляется отбор файла в формате ДД.ММ.ГГГГ
- destination_directory-путь к каталогу,в который будет сохранен найденный файл
- day-хранить день из переменной date
- month-хранить месяц из переменной date
- year-хранить год из переменной date
- found_file-путь к файлу
- file_date-дату создания файла
- fday-хранить день из переменной аdate
- fmonth-хранить месяц из переменной аdate
- fyear-хранить год из переменной аdate
- fdate-дата создания файла в формате ГГГГММДД
- Date-дата из переменной date,но в формате ГГГГММДД
- filename-имя файла
- extension-расширение файла
- fname-имя файла с расширением
- new_filename-имя файла,но уже с датой,когда его создали(в формате имяфайла_ДД.ММ.ГГГГ.расширение)

# Реализация на bash

 ``` bash
#!/bin/bash
sdirectory=$1
date=$2
directory=$3
day=$(echo $date | cut -d '.' -f 1)
echo $day
month=$(echo $date | cut -d '.' -f 2)
echo $month
year=$(echo $date | cut -d '.' -f 3)
echo $year
fdate=$year$month$day
for oldfile in "$sdirectory"/*
do
    if [ -f "$oldfile" ]; then
        oldname=$(basename "$oldfile")
        createdate=$(stat -c %w "$oldfile")
        echo $createdate
        fday=$(echo $createdate | cut -d '-' -f 3 | cut -d ' ' -f 1)
        fmonth=$(echo $createdate | cut -d '-' -f 2)
        fyear=$(echo $createdate | cut -d '-' -f 1)
        filedate=$fyear$fmonth$fday

        if [ "$filedate" -le "$fdate" ]; then
            newname="${oldname%.*}_$fday.$fmonth.$fyear.${oldname##*.}"
            newfile="$directory/$newname"
            cp "$oldfile" "$newfile"
           fi
        else "file not found"
    fi
done
```
## Пример запуска

![image](https://github.com/iis-32170x/RPIIS/assets/144935038/493f71f5-6cb9-4aba-9080-c5bb0532ca5d)
## Переменные :sweat_smile:
- sdirectory-путь к каталогу,в котором будет осуществляться поиск файла
- date-хранит дату,относительно которой осуществляется отбор файла в формате ДД.ММ.ГГГГ
- directory-путь к каталогу,в который будет сохранен найденный файл
- day-хранить день из переменной date
- month-хранить месяц из переменной date
- year-хранить год из переменной date
- oldfile-путь к файлу
- createdate-датa создания файла
- fday-хранить день из переменной аdate
- fmonth-хранить месяц из переменной аdate
- fyear-хранить год из переменной аdate
- filedate-дата создания файла в формате ГГГГММДД
- fdate-дата из переменной date,но в формате ГГГГММДД
- oldname-имя файла
- newname-имя файла,но уже с датой,когда его создали(в формате имяфайла_ДД.ММ.ГГГГ.расширение)
- newfile-путь к файлу в конечном каталоге
  ### Спасибо за внимание :white_heart:


