# Лабораторная работа №1

## Вариант 35
На вход пакетному файлу приходит путь к каталогу (как параметр пакетного файла). Если такой папки нет, то писать “Данной папки нет” и завершить выполнение программы. Если такая папка есть, то найти в заданном каталоге и всех его подкаталогах все файлы заданного размера и принадлежащие определенному пользователю. Диапазон (min - max) размеров файлов задаётся пользователем в качестве второго и третьего параметра пакетного файла. Имя владельца задается пользователем в качестве четвертого параметра пакетного файла. Скрипт выводит результаты поиска в файл в виде "полный путь, имя файла, его размер", в конец файла выводится общее число просмотренных файлов

## Параметры запуска
- Путь к папке, с которой будет вестись работа
- Минимально допустимый размер файла в папке
- Максимально допустимый размер файла в папке
- Какой должен быть у файла владелец

## Словесное описание алгоритма
1. Пользователь одновременно с запуском скрипта вводит 4 указанных выше параметра.
2. Проверка на существование папки, указанной в первом параметре.\
2.1 Если папка не существует, программа завершает свою работу.
3. Проход по циклу
4. Вывод полного и краткого имени, а также размера файлов, удовлетворяющих условиям:\
4.1 Размер находится в диапазоне, заданном во втором и третьем параметрах;\
4.2 Владелец файла равен указанному в четвёртом параметре.

## Пример запуска
Дана следующая папка:

![Изображение папки](test_folder.png)
![Изображение подпапки](test_subfolder.png)

Запуск команды с путём к этой папке в качестве параметра:

![Изображение команды (bat)](test_command_bat.png)

![Изображение команды (sh)](test_command_sh.png)
