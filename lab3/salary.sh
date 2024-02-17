echo "Enter Salary : "
read sry

if [ $sry -le 5000 ] 
then
	echo "5% bonus: "
	bonus=`expr $sry \* 5 / 100`
	echo $bonus
elif [ $sry -gt 5000 -a $sry -lt 10000 ]
then
	echo "10% bonus: "
	bonus=`expr $sry \* 10 / 100`
	echo $bonus
elif [ $sry -ge 10000 -a $sry -lt 15000 ]
then
	echo "15% bonus: "
	bonus=`expr $sry \* 15 / 100`
	echo $bonus
elif [ $sry -ge 15000 ]
then
	bonus=`expr $sry \* 20 / 100`
	echo $bonus
else
	echo "Something went wrong!"

fi

