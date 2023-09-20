# ПОИИС
Репозиторий дисциплины Представление и обработка информации в интеллектуальных системах 
(Representation and processing of information in intelligent systems) для групп потока 32170х.
С условиями лабораторных работ можно ознакомиться в папке соответствующего семестра.

# Цель лабораторной работы №1:
* Ознакомиться с командной строкой операционных систем *Windows* и *Linux*.
* Создать исполняемые файлы *.bat* и *.sh* в соответствии с заданными правилами.

# Условие Лабораторной работы №1. Вариант 56.
   
![image](https://github.com/iis-32170x/RPIIS/assets/144939580/378b14c4-8add-4505-9698-10d222d17196)


# Описание алгоритма и переменных. Пример запуска и выполнения программы.([_.bat_]() файл)

   ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/a0389e26-c3d4-4366-a224-6dd8f28b6418)   

## Последовательность действий алгоритма:
* ***Ввод относительного или абсолютного пути к папке.***
* ***Проверка существования папки.***
* ***Папка существует:***
  >* Начинаем осуществлять поиск по папке и её подкаталогах.
  >* Находим все файлы с расширением *.txt.
  >* В каждом файлов находим слова, которые начинаются с буквы v или V.
  >* Записываем все эти слова в файл result.txt.

* ***Папка не существует:***
  > Информируем о том, что данной папки нет. Заершаем программу.

### Переменные 
* *input* - переменная, в которую сохраняется путь, введенный пользователем.
* *fas* - переменная, в которой хранится путь к папке.

## Методы и комманды
```
@echo off
chcp 1251
setlocal enabledelayedexpansion
set /p input=Введите путь к папке:
set "fas=%input%"
}
```
 * Запускает командной оболочки в режиме "отключить вывод команд на экран" с помощью команды ```@echo off```.
 * Устанавливка кодировки ```chcp 1251```.
 * Включение режима отложенного разрешения переменных ```setlocal enabledelayedexpansion ```.
 * Ввести путь к папке ```set /p input=Введите путь к папке:```.
 * Введенное значение сохраняется в переменной ```%input%```.
 * С помощью команды ```set "fas=%input%"``` значение переменной ```%input%``` присваивается переменной ```%fas%```.


    
```
IF not EXIST "%fas%" (
  echo Данной папки нет
  exit /b
)
```

* Цикл ```IF not EXIST "%fas%"``` проверяет, существует ли папка, указанная в переменной ```%fas%```.

    
```
(for /r "%fas%" %%F in (*.txt) do (
    for /f "tokens=*" %%A in ('findstr /i "\<[vV][a-zA-Z]*[^ ]*" "%%F"') do (
        for %%W in (%%A) do (
            set "word=%%W"
            set "word=!word:~0,1!"
            if /i "!word!"=="v" (
                set "found="
                echo %%W>>result.txt
            )
        )
    )
))
```
 * Обходит все файлы с расширением ```.txt``` в указанной папке и её подпапках с помощью цикла ```for /r "%fas%" %%F in (*.txt) do```.
 * В каждом файле ищет строки, содержащие слова, начинающиеся на ```"v"``` или ```"V"```, с помощью команды ```findstr /i "\<[vV][a-zA-Z]*[^ ]*" "%%F"```.
 * Цикл for %%W in (%%A) перебирает значения переменной %%A. Каждое значение сохраняется в переменную %%W.
 * Внутри цикла происходят следующие действия:
   >- Команда ```set "word=%%W"``` сохраняет текущее значение переменной ```%%W``` в переменную ```word```.
   >- Команда ```set "word=!word:~0,1!"``` сохраняет первый символ значения переменной ```word``` в переменную ```word```.
   >- Команда ```if /i "!word!"=="v"``` проверяет, является ли значение переменной word равным ```"v"``` (без учета регистра).
    > - Если условие выполняется, то команда ```set "found="``` очищает значение переменной found.
     >- Команда ```echo %%W>>result.txt``` записывает значение переменной ```%%W``` в файл ```"result.txt"```.

      
## Пример запуска
Запускаем командную строку ```(Win + R)```. Для открытия папки с .bat файлом вводим     
```cd путь_к_файлу```.  

   
![image](https://github.com/iis-32170x/RPIIS/assets/144939580/dfd0e4e2-5457-435f-b657-15a708374b8c)

   Чтобы запустить наш .bat файл используем    
   ```start название_файла.bat```.


   ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/50e9d300-9a28-4dc0-bab2-0f51ed4be315)   

  Файл запущен.    


  ## Пример работы программы:

  Создадим папку с подпапками и текстовыми файлами. Запишем в них различные слова.  

  
  ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/efac49cc-2e7b-4877-bee4-bd9a20773757)


  Во входной программе, соответствующей условию, задается число и путь.

  ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/4468f9f0-cdee-43c4-ae66-4e793457a871)


  Запускаем. 


  ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/1aa96c77-9fc8-42fc-b52a-9d4368a1548c)



  Программа успешно завершает работу. Появился новый файл *result.txt*, откроем его.

  ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/c63b9804-de3b-41dd-b398-de5a45f71ee4)



  В результате программы было записано несколько слов, начинающихся с большой или маленькой V. На этом побробное описание работы *.bat* файла заканчивается. Приступим к рассмотрению файла *.sh*. 




  






