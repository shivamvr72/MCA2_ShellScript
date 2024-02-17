echo "Enter file/directory"
read fidir

if [ -d $fidir ]
then
	echo "directory type"
elif [ -e $fidir ]
then
	echo "file type"
fi
