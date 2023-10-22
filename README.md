<h1 align="center"> Лабораторная работа <a href="https://daniilshat.ru/" target="_blank">№2</a> 

<h3 align="center">Условие 1 лабораторной работы (вариант 19): Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит абсолютный путь к папке (как параметр пакетного файла). Если такой папки нет, то писать “Данной папки нет” и завершить выполнение программы. Если такая папка есть, то в ней и ее подкаталогах посчитать количество файлов с различными расширениями. Вывести в файл report.txt отчет в виде: doc - 15 txt - 10 exe - 1. В отчет писать в порядке убывания
</h3>
<h1 align="center">Пример запуска и выполнения программы ( .bat )</h1>
1) <h3 align>Создаем папку с файлами с различными расширениями</h3>
<img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/3.png"/>
2) <h3 align>Запускаем bat файл</h3>
<img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20(9).png"/>
3) <h3 align>Вводим путь к папке</h3>
<img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20(7).png"/>
4) <h3 align>Создается report файл с различными расширениями</h3>
<img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20(6).png"/>
<h1 align="center">Описание алгоритма ( .bat )</h1>
<h3 align>1)"> </a> 
<h1 align="center">Пример запуска и выполнения программы ( .sh )</h1>
1) <h3 align>Создаем папку с файлами с различными расширениями</h3>
  <img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/3.png"/>
2) <h3 align>Запускаем sh файл</h3>
  <img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20(8).png"/>
3) <h3 align>Вводим путь к папке</h3>
  <img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/photo_2023-10-19_09-34-09.jpg"/>
4) <h3 align>Создается report файл с различными расширениями</h3>
  <img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/3.png"/>
<h1 align="center">Описание алгоритма ( .sh )</h1>
<h3 align>1) В этой переменной содержится абсолюный путь к папке с текстовыми файлами.<a href="https://daniilshat.ru/" target="_blank"> - folder</a> 
<h3 align>2) Этой переменной присваивается значение "report.txt"<a href="https://daniilshat.ru/" target="_blank"> - report</a> 
<h3 align>3) В эту переменную сохраняется расширение файла, а также принимает значения ключей массива count<a href="https://daniilshat.ru/" target="_blank"> - ext</a> 
