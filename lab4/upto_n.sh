echo "Enter Number : "
read n

st=1
while [ $st -le $n ]
do
	echo $st
	st=`expr $st + 1`
done
