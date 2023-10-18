# Лабораторная работа №1

## В рамках ЛР 1 необходимо создать исполняемый файл в соответствии с заданным вариантом, в моём случае - 16.
> Создать файл sh и bat, который выполняет следующее:

На вход пакетному файлу приходит относительный путь к папке (как параметр пакетного файла). В данной папке найти все файлы, в названии которых есть буква s (большая или маленькая). Вывести в файл result.txt последнюю строку всех найденных файлов

## Файл .bat

```Batchfile

@echo off
setlocal enabledelayedexpansion

if "%~1"=="" (
  echo Usage: %0 ^<directory^>
  exit 1
)

set "directory=%~1"
set "output_file=result.txt"

del "%output_file%" 2>nul

for /r "%directory%" %%f in (*s*) do (
  set "last_line="
  for /f %%a in ('type "%%f"') do set "last_line=%%a"
  if defined last_line (
    echo !last_line!>>"%output_file%"
  )
)

echo Last lines of files containing 's' saved in %output_file%'
```

### Пример выполнения bat файла:

![Содержимое папки, относительный путь к которой приходит на вход пакетному файлу](/pages/folder.png)
![Содержимое файлов, в названии которых есть буква s (большая или маленькая)](/pages/ghs.png,/pages/hgSfjh.png,/pages/njkbhskh.png,/pages/sgkgu.png)
![Запуск пакетного файла с комнадной строки(в данном случае PowerShell)](/pages/cmd.png)
![Результат выполнения пакетного файла](/pages/result.png)

## Файл .sh

```Shell
#!/bin/bash
echo "Введите относительный путь"
read rput
# Ищем в указанной папке файлы с буквой "s" в названии
find "$rput" -type f -iname "*s*" | while read -r file; do
#Выводим последнюю строку каждого найденного файла
tail -n 1 "$file"
done > result.txt
echo "Выполнено! Результаты сохранены в файл result.txt"
```
### Пример выполнения sh файла:

![Содержимое папки, относительный путь к которой приходит на вход пакетному файлу](/pages/folder.jpeg)
![Содержимое файлов, в названии которых есть буква s (большая или маленькая)](/pages/_s.jpeg,/pages/_s_(2).jpeg,/pages/s_.jpeg,/pages/_S_.jpeg)
![Запуск пакетного файла с комнадной строки](/pages/consol.jpeg)
![Результат выполнения пакетного файла](/pages/result.jpeg)