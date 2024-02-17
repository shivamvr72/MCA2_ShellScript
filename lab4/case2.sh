#case esac with wild cards

echo "enter any single character "
read ch
case $ch in 
[a-z]) echo "Lower case " ;;
[A-Z]) echo "Upper case " ;;
[0-9]) echo "Digit " ;;
*) echo "Special Symbol"
esac 
