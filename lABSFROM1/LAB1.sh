echo "Set way to folder"
read ppk
cd $ppk
for a in `grep -l "txt" *`
do
	stat --format='%w' $a >> nn.txt && echo $a >> nn.txt
done
awk '{print $1}' nn.txt > result.txt
rm nn.txt
nv result.txt /home/gkarp/Desktop