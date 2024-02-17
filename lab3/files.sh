#echo "Enter file name " 
#read fname

if [ ! -e $1 ]
then
	echo "file is not exist"
else
	echo "attribute of file $1 is "
	ls -l $1
	echo "total line of in file " 
	wc -l $1
	cp -v $1 svr
fi	
