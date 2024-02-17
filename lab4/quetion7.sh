#multiple type
echo "Menu"
echo "1 : Date "
echo "2 : newfile in current working dir"
echo "3 : longest length of any file"
echo "4 : rename file "
echo "5 : move file to its parent dir"
echo "6 : display current working dir"
echo "7 : exit "
read ch
case $ch in
1) echo $(date + "%A %d %B %Y");;	
2) touch newfile;;
3) echo -n "Enter file name:"
	read filename
	if [ -f $filename ]; then
		echo "The length of the longest line in $filenanme is:" $(wc -L < $filename)
	else
		echo "$filename is not a valid file"
	fi;;
4) echo -n "Enter old file name"
	read file1
	if [ -f $filename ]; then 
		mv $file "new$file1"
	else
		echo "$filename is not a valid file"
	fi;;
5) echo -n "enter file name: "
	read filename
	if [ -f $filename ]; then
		mv $filename ../
	else
		echo "$filename is not a valid"
	fi;;
6) echo "Current working directory: $(pwd)"
   echo "Home direcrtoy : $HOME " ;;
7) exit;;
*) echo "Invalid choice ";;
esac
