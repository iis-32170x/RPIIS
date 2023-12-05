#!/bin/bash
touch Dev.txt
ip route >> Dev.txt
ip link >> Dev.txt
ip addr >> Dev.txt
ip -s link >> Dev.txt
mkdir 1
cp Dev.txt 1
mv /home/aaa/1/Dev.txt /home/aaa/1/Dev1.txt
echo "count of lines:"
wc -l < /home/aaa/1/Dev.txt
read -p "VSE"
rm Dev.txt
rm -R 1
exit
