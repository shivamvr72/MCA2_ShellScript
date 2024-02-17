echo "enter number"
read n

while [ $n -gt 0 ]
	do
	echo $n
	n=`expr $n - 1`
done
