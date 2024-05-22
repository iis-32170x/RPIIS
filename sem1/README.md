# Условие (8 вариант)

В рамках ЛР 1 необходимо создать исполняемый файл .sh и .bat, который выполняет следующее условие:

Создать файл sh и bat, который выполняет следующее:
На вход файлу подается абсолютный путь к каталогу, атрибут прав доступа к файлу и символ (как параметр пакетного файла). Для текущего каталога поменять права доступа ко всем файлам, имеющим в названии заданный символ.


# Реализация на bash
``` sh
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


## Переменные

- directory - абсолютный путь к каталогу.
- permissions - атрибут прав доступа к файлу.
- symbol - символ для поиска в названиях файлов.
- $file - файл выбранный в цикле for.
## примеры запуска

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D0%BE%D0%B2%D0%B0%D0%BB%D1%8C%D1%87%D1%83%D0%BA_%D0%92/images/1.png)



![image](https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D0%BE%D0%B2%D0%B0%D0%BB%D1%8C%D1%87%D1%83%D0%BA_%D0%92/images/2.png)



![image](https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D0%BE%D0%B2%D0%B0%D0%BB%D1%8C%D1%87%D1%83%D0%BA_%D0%92/images/3.png)
# Реализация на batch
``` bat
@echo off
chcp 65001 > NUL

set /p "target_directory=Введите абсолютный путь к каталогу: " 

set /p "search_symbol=Введите символ для поиска в названиях файлов: "

set /p "file_attribute=Введите атрибуты прав доступа(например, +R): "

cd /d "%target_directory%"

for %%f in (*%search_symbol%*) do (
  echo Изменения прав доступа для файла: %%f
  attrib %file_attribute% %%f
)

echo Все файлы с символом"%search_symbol%" в имени изменены

pause
```
## Переменные 

- target_directory - абсолютный путь к каталогу.
- search_symbol- символ для поиска в названиях файлов.
- file_attribute - атрибуты прав доступа.

## примеры запуска
![image](https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D0%BE%D0%B2%D0%B0%D0%BB%D1%8C%D1%87%D1%83%D0%BA_%D0%92/images/bat1.png)

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D0%BE%D0%B2%D0%B0%D0%BB%D1%8C%D1%87%D1%83%D0%BA_%D0%92/images/bat2.png)

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D0%BE%D0%B2%D0%B0%D0%BB%D1%8C%D1%87%D1%83%D0%BA_%D0%92/images/bat3.png)

# Вывод

В ходе выполнения данной лабораторной работы были приобретены навыки работы с командной строкой, написанием скриптов на batch и bash.
