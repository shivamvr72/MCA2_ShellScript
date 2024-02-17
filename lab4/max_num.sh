#finding maximum number from termincal arguments
max=0;
for i in $@
	do
	if [ $i -gt $max ]
	then
		max=$i
	fi	
	done
echo "Max Num : $max"
