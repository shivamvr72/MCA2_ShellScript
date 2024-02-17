#if no argument passed
if [ $# -eq 0 ]
	then
	echo "please provide atleast one argument "
	exit 1
fi
#number input to search	
echo "Enter Number to check number presence "
read n
for i in "$@"
	do
		if [ "$i" -eq "$n" ]
			then
			found=1
			break
		fi
	done
#result 
if [ $found -eq 1 ];then 
	echo "$n is present in args"
else
	echo "$n is not present in args"
fi
