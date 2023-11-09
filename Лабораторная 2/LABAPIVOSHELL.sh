#! /bin/bash
touch text.txt
ps>text.txt
echo Введите PID процесса
read pid
var=0
t=1
x=0
if [ $(grep -ic $pid text.txt) -eq $t ]; then
	var=1
fi
rm text.txt

if [ "$var" = "$x" ]; then
	echo Такого процесса нет
	sleep 5
	exit 0
fi

ps -fp [$pid]
echo Хотите закончить процесс [y/n]
read sim

while [ "$sim" != "y" ] && [ "$sim" != "n" ]; do
	echo Хотите закончить процесс [y/n]
	read sim
	done
if [ "$sim" == "y" ]; then
	echo Процесс будет завершен
	sleep 5
	kill $pid
	exit 0
fi
if [ "$sim" == "n" ]; then
	echo Процесс не будет завершен
	sleep 5
	exit 0
fi
