
if [ $# -ne 1 ]
then 
	echo "Enter file name "
	read fname
	echo "Total words in file : $fname "
	wc -w $fname

else
	echo "total words "
	wc -w $1
fi
