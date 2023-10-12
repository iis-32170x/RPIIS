#!/bin/bash

if [ -z "$1" ]
then    echo vvedi chislo

exit 1

fi

ps -eo pid | grep $1 > pid1.txt
echo OKE
