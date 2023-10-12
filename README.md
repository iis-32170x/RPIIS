![](https://komarev.com/ghpvc/?username=Kukrynitza)
## [![Typing SVG](https://readme-typing-svg.herokuapp.com?font=italic&size=24&pause=1000&color=FF10D1&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&lines=%D0%A3%D0%A1%D0%9B%D0%9E%D0%92%D0%98%D0%95+%D0%9B%D0%A01(%D0%92%D0%B0%D1%80%D0%B8%D0%B0%D0%BD%D1%82+17))](https://git.io/typing-svg)
*Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит относительный путь к папке (как параметр пакетного файла). Если такой папки нет, то писать “Данной папки нет” и завершить выполнение программы. Если такая папка есть, то найти в ней и в ее подкаталогах файлы, в названии которых есть подстрока “temp”. Вывести первые пять строк найденных файлов в файл result.txt.*
---
## <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=italic&pause=1000&color=641C6F&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&lines=%D0%A0%D0%95%D0%90%D0%9B%D0%98%D0%97%D0%90%D0%A6%D0%98%D0%AF+SH-%D0%A4%D0%90%D0%99%D0%9B%D0%90" alt="Typing SVG" /></a>
Код	&#128526;
```sh
#!/bin/bash
 folder_path="$1"

if [ ! -d "$folder_path" ]; then  echo "Данной папки нет" cd
  exit 1 
fi
echo $folder_path
find "$folder_path" -type f -name "*temp*" -exec head -n 5 {} \; > /home/ilja/.myskript/result
```
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=italic&size=24&pause=1000&color=733789&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&lines=%D0%9F%D0%B5%D1%80%D0%B5%D0%BC%D0%B5%D0%BD%D0%BD%D1%8B%D0%B5%3A)](https://git.io/typing-svg)

folder_pass - путь к папке, в которой будет происходить поиск всех текстовых файлов в названии которых есть подстрока “temp”

Получается одна переменная 	&#129325;<br>
<br>

**<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=italic&size=24&pause=1000&color=733789&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&lines=%D0%A0%D0%B0%D0%B1%D0%BE%D1%82%D0%B0+%D1%81+sh-%D1%84%D0%B0%D0%B9%D0%BB%D0%BE%D0%BC%3A" alt="Typing SVG" /></a>**

Запускаем sh-файл и проверяем, есть ли проверка на наличие папки &#128564;
 
![image](https://github.com/iis-32170x/RPIIS/assets/144555463/972d9653-b743-48eb-8e52-af0f27f24f39)

Видим что записалось в result 	&#128527;

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/485f0748-5013-470f-a2ef-d7368a73fa5f)

Что мы имели изначально(чтобы можно было бы убедиться что всё работает) &#128554;

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/fa9f386c-7a08-462f-a926-e999931139d2)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/869d2a80-855c-4c7b-9a16-430c30de1afe)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/55c9a87a-1249-4405-aeaa-535483c62d59)


![image](https://github.com/iis-32170x/RPIIS/assets/144555463/b99841ce-905b-4f9c-8f8f-74b70349e9ab)


![image](https://github.com/iis-32170x/RPIIS/assets/144555463/2d44f3e8-6916-4f8e-bfdd-644da8189616)
![image](https://github.com/iis-32170x/RPIIS/assets/144555463/39be641f-032c-4cb0-957d-367ddff94777)
---
## <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=italic&pause=1000&color=65164B&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&lines=%D0%A0%D0%95%D0%90%D0%9B%D0%98%D0%97%D0%90%D0%A6%D0%98%D0%AF+BAT-%D0%A4%D0%90%D0%99%D0%9B%D0%90" alt="Typing SVG" /></a>

Код	&#128525;
```bat
@echo off
setlocal EnableDelayedExpansion
chcp 65001
if "%1"=="" (echo Параметр не задан)
echo. >D:/labaPi1/result.txt
if not exist D:/labaPi1/%1 (echo Данной папки нет)
echo. >D:/labaPi1/result.txt
for /R D:/labaPi1/%1 %%t in (*temp*) do (
set fileName= %%t
set /A counter=0
for /F %%s in (!fileName!) do (
if !counter! lss 5 (
echo %%s >>D:/labaPi1/result.txt
set /A counter+=1
)
)
echo. >>D:/labaPi1/result.txt
)
endlocal
```
## <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=italic&size=24&pause=1000&color=65164B&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&lines=%D0%9F%D0%B5%D1%80%D0%B5%D0%BC%D0%B5%D0%BD%D0%BD%D1%8B%D0%B5%3A" alt="Typing SVG" /></a>

fileName - переменная, в которой хранится расположение обрабатываеммого файла;

counter - переменная-счетчик, которая отсчитывает колличество строк;

<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=italic&size=24&pause=1000&color=65164B&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&lines=%D0%A0%D0%B0%D0%B1%D0%BE%D1%82%D0%B0+%D1%81+bat-%D1%84%D0%B0%D0%B9%D0%BB%D0%BE%D0%BC%3A" alt="Typing SVG" /></a>

Запускаем bat-файл и проверяем, есть ли проверка на наличие папки &#128529;

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/82d66767-8856-42c7-a101-4b691036e92b)

Видим что записалось в result 	&#128527;

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/47c99b0b-4ca2-45c6-a3b2-3ae6542f3504)

Что мы имели изначально(чтобы можно было бы убедиться что всё работает) &#128554;

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/49f4d770-0105-453e-a2b7-e2204b2a4364)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/8b29d31f-1c5f-44dd-8d23-6e38076a947a)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/fca92d79-e1fd-4e9a-a0eb-9e70ca644336)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/03c86686-a3c1-426d-9bfa-b2bdcc55bc94)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/12a7e76d-56ae-438a-8073-f4cf7051faff)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/45a6e5c4-71ab-49a5-a4ea-b7427325fd5b)
---


<img src="https://readme-jokes.vercel.app/api" alt="Jokes Card" />
