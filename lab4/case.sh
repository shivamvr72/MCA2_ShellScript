echo "Menu " 
echo "1 : listing files "
echo "2 : process of user "
echo "3 : uers of the system"
echo "4 : quit"

echo "Enter Your choice: "
read ch

case $ch in
1) ls -l ;;
2) ps ;;
3) who ;;
4) exit ;;
*) echo "invalid" 
esac
