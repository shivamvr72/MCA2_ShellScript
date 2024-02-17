echo "Enter Number : "
read n
echo "Revese.."
while [ $n -ge 0 ]
do
	echo $n
	n=`expr $n - 1`
done
