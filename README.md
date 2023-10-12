![](https://komarev.com/ghpvc/?username=Kukrynitza)
## УСЛОВИЕ ЛР1(Вариант 19)
*Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит абсолютный путь к папке (как параметр пакетного файла). Если такой папки нет, то писать “Данной папки нет” и завершить выполнение программы. Если такая папка есть, то в ней и ее подкаталогах посчитать количество файлов с различными расширениями. Вывести в файл report.txt отчет в виде: doc - 15 txt - 10 exe - 1. В отчет писать в порядке убывания*
---
# Реальзация sh-файла:
### Код чтобы можно было скопировать	&#128526;
```
#!/bin/bash
 folder_path="$1"

if [ ! -d "$folder_path" ]; then  echo "Данной папки нет" cd
  exit 1 
fi
echo $folder_path
find "$folder_path" -type f -name "*temp*" -exec head -n 5 {} \; > /home/ilja/.myskript/result
```
---
### Код для красоты:)
<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=Cambria&pause=1000&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&separator=%3C&lines=%23!%2Fbin%2Fbash+%3C+folder_path%3D%22%241%22%3Cif+%5B+!+-d+%22%24folder_path%22+%5D;+%3Cthen++echo+%22%D0%94%D0%B0%D0%BD%D0%BD%D0%BE%D0%B9+%D0%BF%D0%B0%D0%BF%D0%BA%D0%B8+%D0%BD%D0%B5%D1%82%22+cd%3Cexit+1+%3Cfi%3Cecho+%24folder_path%3Cfind+%22%24folder_path%22+-type+f+-name+%22*temp*%22+-exec+head+-n+5+%7B%7D+%5C;+%3C+%3E+%2Fhome%2Filja%2F.myskript%2Fresult" alt="Typing SVG" /></a>
---
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
