#!/bin/shell
echo "Enter directory"
read -r A
echo " Your directory " $A
cd $A
sleep 3
if ! [ -d $A ]; 
then
echo "The directory does not exist"
sleep 3
else 
echo "The directory exist"
sleep 1
echo "Enter filename"
read -r B
ls -S -R -all $A 
ls -S -R -all $A >$B
sleep 2
fi
sleep 5
