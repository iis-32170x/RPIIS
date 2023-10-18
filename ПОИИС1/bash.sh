#!/bin/bash
if [ -d C:/PiOIvIS ]; then 
echo "1)Atribut ra:">> result.txt
ls >> result.txt
echo "2)Atribut ha:" >> result.txt
ls -a | grep "^\." >> result.txt
echo "3)Atribut a:" >> result.txt
ls -a >> result.txt
else 
echo "Dannoi papki net"
fi