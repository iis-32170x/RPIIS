# BSUIR_cmd-bash


Данная лабораторная работа была предназначена для ознакомления с командной строкой операционных систем Windows и Linux. В рамках ЛР 1 необходимо создать исполняемый файл .bat и .sh в соответствии с заданным вариантом.

## Условие ЛР 1 (60 вариант)
Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит относительный путь к папке (как параметр пакетного файла). Если такой папки нет, то писать “Данной папки нет” и завершить выполнение программы. Если такая папка есть, то в ней создайте текстовый файл result.txt, содержащий список процессов, использовавших процессор более 10 минут. Список должен быть отсортирован по времени (от большего к меньшему)

## Описание алгоритма, пример запуска и выполнения программы

![image](https://github.com/iis-32170x/RPIIS/assets/144939284/e18d5c7a-51f0-4f8f-ad12-c07d2bced28b)

#### Переменные:
- _folder_path_ - хранит в себе относительный путь к файлу



#### Последовательность действий:
1. Ввод переменной _folder_path_ 

2. Проверка на наличие папки, и если папки нет то программа завершается с выводом сообщения "Папка не найдена"
3. Если папка есть , то создаем в ней текстовый файл result и записываем в него данные по условию


#### Используемые команды
1. _tasklist_ - отвечает за вывод процессов используемых прецессором
2. _awk_ -фильтрует процессы по времени (больше 10 мин)


#### Пример запуска:
Запускаем командную строку:
<img width="889" alt="image" src="https://github.com/iis-32170x/RPIIS/assets/144939284/0c10bd5f-42b6-4a19-870d-493002a3727f">

 
Запуск .bat файла : "Путь к файлу"
<img width="1103" alt="image" src="https://github.com/iis-32170x/RPIIS/assets/144939284/8829fcc5-1f38-421b-a201-f94f5ab2719b">


Ввод относительного пути к папке

Запись процессов в текстовый файл
<img width="1127" alt="image" src="https://github.com/iis-32170x/RPIIS/assets/144939284/72788176-2dbd-47d0-96df-4caed43e4511">

Программа успешно заканчивает работу, после чего переходим в папку, где хранится .bat файл и замечаем новый файл соответствующий “result” .txt

<img width="1277" alt="image" src="https://github.com/iis-32170x/RPIIS/assets/144939284/9e4b668d-afb8-4a73-ab04-28470e16e63a">

Давайте откроем этот файл

<img width="1202" alt="image" src="https://github.com/iis-32170x/RPIIS/assets/144939284/2ef3793a-c251-4fa0-a74d-433cd4c64594">

Работа .bat файла окончена.






