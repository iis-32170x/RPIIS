![](https://komarev.com/ghpvc/?username=Kukrynitza)
## УСЛОВИЕ ЛР1(Вариант 19)
*Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит абсолютный путь к папке (как параметр пакетного файла). Если такой папки нет, то писать “Данной папки нет” и завершить выполнение программы. Если такая папка есть, то в ней и ее подкаталогах посчитать количество файлов с различными расширениями. Вывести в файл report.txt отчет в виде: doc - 15 txt - 10 exe - 1. В отчет писать в порядке убывания*
---
# Реальзация sh-файла:
### Код	&#128526;
```sh
#!/bin/bash
 folder_path="$1"

if [ ! -d "$folder_path" ]; then  echo "Данной папки нет" cd
  exit 1 
fi
echo $folder_path
find "$folder_path" -type f -name "*temp*" -exec head -n 5 {} \; > /home/ilja/.myskript/result
```
---
##Работа с sh-файлом:
===
 Запускаем sh-файл и проверяем, есть ли проверка на наличие папки
 ===
![image](https://github.com/iis-32170x/RPIIS/assets/144555463/972d9653-b743-48eb-8e52-af0f27f24f39)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/2d70db38-b09e-4a2f-a82f-57319935712c)


![image](https://github.com/iis-32170x/RPIIS/assets/144555463/99e4fe66-753d-40d3-b689-849ad699c3af)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/869d2a80-855c-4c7b-9a16-430c30de1afe)


![image](https://github.com/iis-32170x/RPIIS/assets/144555463/55c9a87a-1249-4405-aeaa-535483c62d59)
![image](https://github.com/iis-32170x/RPIIS/assets/144555463/32e09bbb-fdf1-4427-8acd-fccaad78a573)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/fa9f386c-7a08-462f-a926-e999931139d2)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/b99841ce-905b-4f9c-8f8f-74b70349e9ab)


![image](https://github.com/iis-32170x/RPIIS/assets/144555463/2d44f3e8-6916-4f8e-bfdd-644da8189616)
![image](https://github.com/iis-32170x/RPIIS/assets/144555463/39be641f-032c-4cb0-957d-367ddff94777)
---
<img src="https://readme-jokes.vercel.app/api" alt="Jokes Card" />
