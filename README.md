<<<<<<< HEAD
# ПОИИС
 Репозиторий дисциплины Представление и обработка информации в интеллектуальных системах 
 (Representation and processing of information in intelligent systems) для групп потока 32170х.
 С условиями лабораторных работ можно ознакомиться в папке соответствующего семестра.
=======
# BSUIR ЛР1 
В рамках ЛР 1 необходимо создать файл с разрешением *bat.* и *sh.* в соответствии с заданным вариантом.
Цель данной лаборотоной работы - ознакомится с командными строками операционных систем *Windows* и *Linux*.
## Условие ЛР1 (75 вариант)
![image](https://github.com/iis-32170x/RPIIS/assets/48830085/7d0592c8-0f6e-45d4-b263-16bb1d2ee418)
)
# Описание алгоритма, пример запуска и выполнения программы (.bat)
![image](https://github.com/iis-32170x/RPIIS/assets/48830085/a78a54e0-72ca-4e19-bfef-1656b30c940b)

## Алгоритм программы
1. Отключиаем вывод команд на экран.
2. Задаем переменные, которые будет являться абсолютным путем к файлам.
3. Перебираем все строки в каждом файле, количество строк в первом файле записываем в переменную NumStr1, во втором NumStr2
4. Задаем переменную количества с начальным значением 0.
5. Сравниваем количество строк в двух файлах
6. Если в каждом файле одинаковое количество строк, то выводим "Количество строк равное"
7. Если в каждом файле разное  количество строк, то выводим "Количество строк разное"
7.1. Перебираем все слова в каждом файле, количество слов в первом файле записываем в переменную n1, во втором n2
7.2 Если в каждом файле одинаковое количество слов , то выводим "Количество слов равное"
7.3 Если в каждом файле одинаковое количество строк, то выводим "Количество слов разное"
8. Закрываем программу через 7 секунд
### Переменные
- d1,d2: Содержит абсолютный путь к папке.
- NumStr1, NumStr2: Содержит значение количества строк в файле1 и файле2
- n1, n2: Содержит значение количества строк в файле1 и файле2

 ## Разбор кода

1. Команда "chcp 65001 > nul" изменяет активную кодовую страницу на UTF-8 для поддержки символов Unicode.
2. Команды "set /p d1=%1" и "set /p d2=%2" запрашивают у пользователя ввести имена файлов.
3. Циклы "for /f" используются для подсчета количества строк в каждом файле с помощью команды "find /c /v ""^<" ". Результат сохраняется в переменных NumStr1 и NumStr2.
4. Две переменные n1 и n2 инициализируются значением 0.
5. Если количество строк в обоих файлах равно, выводится сообщение "Количество строк равное". В противном случае выводится сообщение "Количество строк разное".
6. Два вложенных цикла "for /f" используются для подсчета количества слов в каждом файле. Переменная n1 увеличивается для каждого слова в файле d1, а n2 - для каждого слова в файле d2.
7. Если количество слов в обоих файлах равно, выводится сообщение "Количество слов равное". Если нет, выводится сообщение "Количество слов разное".
8. Команда "timeout 7" приостанавливает выполнение скрипта на 7 секунд перед выходом.
## Пример и алгоритм работы:
 запуск командой строки

 
 ![image](https://github.com/iis-32170x/RPIIS/assets/148707516/9f44d34e-31a9-4944-b426-2a64e1b785bc)

 Открытие .bat файла:



 Папка до запуска программы:
 
 ![image](https://github.com/iis-32170x/RPIIS/assets/48830085/a97965bd-4206-4ef4-bedc-492b89aa7091)


 Содержимое файла 1.txt:
 
![image](https://github.com/iis-32170x/RPIIS/assets/48830085/cfe18458-24b5-4810-b0ed-20b0b64ab5e7)

 Содержимое файла 2.txt:
 
![image](https://github.com/iis-32170x/RPIIS/assets/48830085/923f9daf-c068-4baf-a7ac-7d86c79f4901)

 Bat файл работает исправно.
 
![image](https://github.com/iis-32170x/RPIIS/assets/48830085/116a53b9-388b-40e2-9694-0fc4c4735017)

 # Описание лагоритма, пример запуска и выполнения программы (.sh)
 
 ![image](https://github.com/iis-32170x/RPIIS/assets/148707516/4bfb2b37-ad2a-4117-9da7-25c8c6765bdb)

 ## Алгоритм программы
 1. Устанавливается переменная directory с путем к каталогу "D:/PZH/pivas".
 2. Проверяется, существует ли указанный каталог. Если каталог не существует, выводится сообщение "Papka not found", и программа завершается.
 3. Устанавливается переменная count со значением 0.
 4. Ищутся все файлы внутри каталога directory и его подкаталогов.
 5. При каждом найденном файле значение переменной count увеличивается на 1.
 6. Вычисляется результат умножения значения переменной count на количество доступных процессоров.
 7. Задается переменная fileName, которая содержит текущее время в формате "HH_MM_SS".
 8. Значение переменной result записывается в текстовый файл с именем $fileName.txt внутри каталога directory.
 ### Переменные
 - directory: Содержит абсолютный путь к папке.
 - count: Содержит значение количества найденных файлов в абсолютном пути к папке.
 - result: Содержит значение результата умножения переменной count на количество процессов (nproc).
 ## Разбор кода
 1. Задается переменная directory со значением пути к каталогу "D:/PZH/pivas".
 2. if if [ ! -d "$directory" ]]; then: Это выражение которое проверяет, является ли "$directory" несуществующим каталогом (-d проверяет, является ли путь каталогом, а ! отрицает результат проверки).
 3. echo "Papka not found" - Эта команда выводит сообщение "Papka not found", если из п.2 было определено, является ли "$directory$" несуществующим каталогом.
 4. exit 1 - Эта команда завершает выполнение программы с кодом 1, что указывает на ошибку в выполнении программы.
 5. while read -r -d '' file; do: Эта строка начинает цикл while и считывает строки из ввода и сохраняет их в переменную file. Опции -r сохраняют строки без интерпретации экранированных символов, а -d '' указывает, что строки разделяются пустыми символами.
 6. ((count++)) - После того, как будет найден каждый файл значение переменной будет увеличиваться на 1. done - Это конец цикла while.
 7. < <(find "$directory" -type f -print0): Данная команда выполняется, чтобы найти все файлы в указанном каталоге "$directory" и его подкаталогах. -type f указывает, что нужны только файлы, а -print0 выводит результаты в формате с нулевыми символами в качестве разделителей. Все найденные файлы передаются в цикл while в качестве ввода.
 8. result=$((count * $(nproc))): Это выражение, которое умножает значение переменной count на количество доступных процессоров и результат записывает в переменную result.
 9. fileName=$(date +"%S_%M_%H"): Задаем значение переменной fileName, команда date, которая задает текущее время, с помощью  +"%S_%M_%H" указываем формат вывода времени в секундах_минутах_часах.
 10. echo "$result" > "$directory/$fileName.txt": Выводим значение переменной "$result$" и перенаправляем ее в файл с названием "filename".
## Пример и алгоритм работы:
 Запуск sh и файла:
 
 Открываем gitbash:
 
 ![image](https://github.com/iis-32170x/RPIIS/assets/148707516/37b8b821-ef15-42ae-88eb-33a4677435cf)

 Переход к каталогу с файлом - cd /путь/к/папке
 Запуск файла ./название файла.sh

 
 ![image](https://github.com/iis-32170x/RPIIS/assets/148707516/92e545cb-6c67-4210-8359-ab881aec401a)

 Содержимое папки до запуска программы:
 
 ![image](https://github.com/iis-32170x/RPIIS/assets/148707516/499229c8-6b07-4c08-afc4-9339028c2cc7)

 Содержимое папки после запуска программы:
 
 ![image](https://github.com/iis-32170x/RPIIS/assets/148707516/0b26a3ec-b297-4c3d-91ae-067da67ef165)

 Содержимое файла .txt:
 
 ![image](https://github.com/iis-32170x/RPIIS/assets/148707516/360a6ed5-cad9-4d54-84f9-5bdf71c1a927)

 Sh файл работает исправно.

 # Вывод
 Приобрела навыки работы с командной строкой. Разработала программы, выполняющие соответсвующее задание.
>>>>>>> 4b57f6c (README.md)
