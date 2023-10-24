# Условие (2 вариант)

В рамках ЛР 1 необходимо создать исполняемый файл .sh и .bat, который выполняет следующее условие:

Создать файл sh и bat, который выполняет следующее:
На вход пакетному файлу приходит число (как параметр пакетного файла). Создать папку test, в ней создать количество файлов с расширением *.txt, равное входному параметру. Меняем расширение каждого третьего файла на *.doc. В остальные файлы записать текущее время в формате HH_MM_SS. Создать файл, в который записать имена файлов (каждое с новой строки), в которых найдена подстрока “07”.

# Реализация на bash
```
#!/bin/bash

read -p "Введите абсолютный путь к каталогу: " directory

read -p "Введите атрибут прав доступа к файлу: " permissions

read -p "Введите символ: " symbol

cd "$directory"
ls
echo $permissions

for file in *$symbol*; do
    chmod -v $permissions $file
	
	echo $file
done

echo "Права доступа ко всем файлам, содержащим символ $symbol в названии, изменены на $permissions"
read -p "Нажмите любую клавишу для продолжения..."
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
![image](https://github.com/iis-32170x/RPIIS/blob/%D0%91%D0%B5%D0%B4%D0%B0%D1%80%D0%B8%D0%BA_%D0%97/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-18%20224335.png)

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%91%D0%B5%D0%B4%D0%B0%D1%80%D0%B8%D0%BA_%D0%97/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20(4).png)
# Вывод

В ходе выполнения данной лабораторной работы были приобретены навыки работы с командной строкой, написанием скриптов на batch и bash.
