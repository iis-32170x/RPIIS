file1=File1.txt
if [ ! -f "$file1" ]; then
    touch File1.txt
fi
file2=File2.txt
if [ ! -f "$file2" ]; then
    touch File2.txt
fi
chattr -h File2.txt
log=log.txt
if [ -f "$log" ]; then
    rm log.txt
fi
touch log.txt
echo Введите путь к первому файлу: 
read f1
start $f1
sleep 10
echo Введите путь ко второму файлу: 
read f2
start $f2
sleep 10
diff -i File1.txt File2.txt>>log.txt
r=$?
if [ "$r" == 0 ]; then
    echo Файлы совпадают, их содержимое:
    echo Файлы совпали>>log.txt
	cat File1.txt | iconv -f Windows-1251
    echo Выводим содержимое первого файла в консоль>>log.txt
else
    echo Файлы не совпали
    echo Файлы не совпали>>log.txt
	echo Удаляем первый файл>>log.txt
	rm File1.txt
	echo Делаем второй файл скрытым>>log.txt
	chattr +h File2.txt
fi	
sleep 100