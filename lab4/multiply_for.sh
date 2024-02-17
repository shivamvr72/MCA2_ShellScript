mul=1
for i in $@
	do 
		mul=`expr $mul \* $i` 
	done
	echo "Multiplication = $mul"
