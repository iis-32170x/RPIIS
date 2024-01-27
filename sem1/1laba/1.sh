#!/bin/bash
echo "vvedite chislo menshee 100: "
read N
mkdir testshell
cd testshell 
if [ $N -ge 100 ] 
then 
echo "NEVERNYE DANNYE"
read N
fi
if [ $N -le 0 ]
then 
echo "NEVERNYE DANNYE"
read N
fi
let "a=$N/10"
b=$(($N%10))
if [ $a -gt $b ]
then
     for (( i=1; i <= $a; i++ ))
do
        touch $i.txt
done
     for ((i=2; i<=$a;i=i+2 ))
do
         mv $i.txt $i.doc
		 date > $i.doc
done
else 
     for (( i=1; i <= $b; i++ ))
do
         touch $i.txt
done
     for ((i=2; i<=$b;i=i+2 ))
do
         mv $i.txt $i.doc
		 date > $i.doc
done
fi 
sleep 1m
