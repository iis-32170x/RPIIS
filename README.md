# Условие (2 вариант)

В рамках ЛР 1 необходимо создать исполняемый файл .sh и .bat, который выполняет следующее условие:

Создать файл sh и bat, который выполняет следующее:
На вход пакетному файлу приходит число (как параметр пакетного файла). Создать папку test, в ней создать количество файлов с расширением *.txt, равное входному параметру. Меняем расширение каждого третьего файла на *.doc. В остальные файлы записать текущее время в формате HH_MM_SS. Создать файл, в который записать имена файлов (каждое с новой строки), в которых найдена подстрока “07”.

# Реализация на bash
```
#!/bin/sh
mkdir test
cd test
count=0
read kolichestvo
for ((i=1; i<=kolichestvo; i++)); do
  echo $(date +"%H_%M_%S") > $i.txt
  count=$((count+1))
  if [ $count -eq 3 ]; then
    echo "" > $i.txt
    mv $i.txt $i.doc
    count=0
  fi
done
echo "" > kniga.txt
for file in *.txt; do
  if grep -q "24" "$file"; then
    echo "$file" >> kniga.txt
  fi
done
```
![image](https://github.com/iis-32170x/RPIIS/blob/%D0%91%D0%B5%D0%B4%D0%B0%D1%80%D0%B8%D0%BA_%D0%97/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-18%20222737.png)



![image](https://github.com/iis-32170x/RPIIS/blob/%D0%91%D0%B5%D0%B4%D0%B0%D1%80%D0%B8%D0%BA_%D0%97/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20(3).png)


## Переменные

- kolichestvo - введеное пользователем.
- count - счётчик для нахождения каждого 3-го файла.
- $file - файл выбранный в цикле for.
## примеры запуска

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%91%D0%B5%D0%B4%D0%B0%D1%80%D0%B8%D0%BA_%D0%97/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-18%20222737.png)



![image](https://github.com/iis-32170x/RPIIS/blob/%D0%91%D0%B5%D0%B4%D0%B0%D1%80%D0%B8%D0%BA_%D0%97/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20(3).png)
# Реализация на batch
```
@echo off
setlocal enabledelayedexpansion
chcp 65001
for /f "tokens=2 delims==" %%G in ('wmic OS Get localdatetime /value') do set "datetime=%%G" 
set "timestamp=%datetime:~8,2%_%datetime:~10,2%_%datetime:~12,2%"
MD test
cd test
set count = 0 
SET /P kolichestvo=
for /l %%i in (1,1,%kolichestvo%) do (
                   echo %timestamp% > %%i.txt
                   set /a count += 1
                   if !count! equ 3 (
                           echo .>"%%i.txt"
                           ren "%%i.txt" "%%~ni.doc"
                           set count=0
                           )
) 
echo. > hahhahaahahh.txt
for %%l in (*.txt) do (
    findstr /m "04" "%%l" > nul
    if not errorlevel 1 (
        echo %%~nxl >> hahhahaahahh.txt
    )
)
endlocal
pause
```
## Переменные 

- datetime,timestamp - переменные для записи времени в требуемом формате.
- kolichestvo- переменная введённая пользователем.
- count - переменная для отсчёта каждого 3-его файла.

## примеры запуска

Создадим две папки dir1 и dir2 и закинем в них несколько файлов разных размеров (файлы созданные для .bat файла такие же, что и для .sh файла, а значит содержимое result.txt в обоих случаях будет совпадать).

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%9C%D0%BE%D1%82%D0%BE%D0%BB%D1%8F%D0%BD%D0%B5%D1%86_%D0%9A/images/files3.png)

Запустим скрипт подав на вход две созданные папки.

Для проверки правильности работоспособности этот скрипт при запуске выводит имя и размер минимального файла первой папки, а также информацию о файлах второй папки. 

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%9C%D0%BE%D1%82%D0%BE%D0%BB%D1%8F%D0%BD%D0%B5%D1%86_%D0%9A/images/stat_bat_1.png)

После запуска скрипта, можно заметить, что файл с минимальным размером - f2 переместился во вторую папку.

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%9C%D0%BE%D1%82%D0%BE%D0%BB%D1%8F%D0%BD%D0%B5%D1%86_%D0%9A/images/files4.png)

Так же видно, что размеры файлов сравнились корректно.

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%9C%D0%BE%D1%82%D0%BE%D0%BB%D1%8F%D0%BD%D0%B5%D1%86_%D0%9A/images/result2.png)

# Вывод

В ходе выполнения данной лабораторной работы были приобретены навыки базовой работы с командной строкой, написанием скриптов на batch и bash, а так же работой с системой контроля версий git и веб-сервис для хостинга IT-проектов github.