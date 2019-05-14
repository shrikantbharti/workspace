c=0
while [ $c -eq 0 ]

do 
	echo "Enter first no: "
	read num1
	echo "Enter second no: "
	read num2
	echo "1 Addition"
	echo "2 Subtraction"
	echo "3 Multiplication"
	echo "4 Division"
	
	echo "Enter choice: "
	read choice
	
	case $choice in 
	1) sum=`echo $num1 + $num2 | bc`
  	 echo "sum of $num1 and $num2 is: "$sum 
  	 ;;
	2) sub=`echo $num1 - $num2 | bc`
  	 echo "difference of $num1 and $num2 is: "$sub 
  	 ;;
  	3) mul=`echo $num1 \* $num2 | bc`
  	 echo "product of $num1 and $num2 is: "$mul
  	 ;;
	4) div=`echo "scale=2; $num1 / $num2" | bc`
  	 echo "quotient of $num1 and $num2 is: "$div 
  	 ;;
	
	*) echo "Wrong choice!!!"
  	 ;;
	esac
	echo "Do you want to continue with same inputs(Y=0/N=1)???"
	read c
	echo "--------------------"
done
	

