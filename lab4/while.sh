#while loop testing
echo "enter number for table " 
read n
fp=1 
while [ $fp -le 10 ]
	do 
	echo "$n x $fp =`expr $fp \* $n`"
	fp=`expr $fp + 1`
done
	
	
