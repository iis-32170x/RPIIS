# Лосик Ярослав, 321701, Вариант 12

Создать файл sh и bat, который выполняет следующее:
Создает файл first.txt, в него записывает произвольное количество произвольных чисел (три числа на одну строку),
находит все строки, в которых есть подстрока “23” и записать их в файл second.txt в порядке убывания (по строкам). 

## Реализация на cmd

```
@echo off
cd Desktop
start first.txt
start second.txt
taskkill /im notepad.exe
set /a _rand = (%random%*100/32767)+1
set /a i=0
:loop
if %i%==%_rand% goto end
set /a r = 100+(999-100+1)*%random%/32768
echo %r% >> C:\Users\yaroslave\Desktop\first.txt
set /a i=i+1
goto loop
:end
findstr /r /c:"23" first.txt >> second.txt
cd Desktop
sort /r second.txt /o second.txt
start second.txt
start first.txt 
pause
```

## Фотоотчет

![](//github.com/iis-32170x/RPIIS/blob/%D0%9B%D0%BE%D1%81%D0%B8%D0%BA_%D0%AF/1.png)

![](//github.com/iis-32170x/RPIIS/blob/%D0%9B%D0%BE%D1%81%D0%B8%D0%BA_%D0%AF/2.png)

![](//github.com/iis-32170x/RPIIS/blob/%D0%9B%D0%BE%D1%81%D0%B8%D0%BA_%D0%AF/cmd.png)

## Реализация на bash

```
touch {first.txt,second.txt}
i=0
while [ $i -le $(( RANDOM )) ]
do
echo $[ $RANDOM % 899 + 100 ]>> first.txt
((i++))
done
grep -i "23" first.txt >> second.txt
sort -r second.txt
start first.txt
start second.txt
```

## Фотоотчет

![](//github.com/iis-32170x/RPIIS/blob/%D0%9B%D0%BE%D1%81%D0%B8%D0%BA_%D0%AF/1sh.png)

![](//github.com/iis-32170x/RPIIS/blob/%D0%9B%D0%BE%D1%81%D0%B8%D0%BA_%D0%AF/2sh.png)

## Как работает

- Создает файлы first.txt и second.txt
- Записывает с помощью цикла числа в диапазоне от 100 до 999 в first.txt
- Находит строки, имеющие подстроку "23" в first.txt
- Сортирует числа в порядке убывания
- Результат сортировки записывается в second.txt
- Для показа результата открываются first.txt & second.txt

## Вывод

При выполнении данной работы были приобретены навыки работы с коммандной строкой, написания скриптов на bash и cmd, а также работы с CSV git.
