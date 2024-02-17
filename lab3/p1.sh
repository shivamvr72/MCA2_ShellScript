if [ $# -ne 1 ]
	then
		echo "enter file name "
		read fname 
		cat $fname
	else
		cat $1
fi	
