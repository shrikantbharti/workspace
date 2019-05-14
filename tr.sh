utl()
{
VAR1=BASHSHELLSCRIPTING
echo $VAR1 | tr A-Z a-z
}
ltu()
{
VAR1=bashshellscripting
echo $VAR1 | tr a-z A-Z
}
ftu()
{
VAR1=bashshell
VAR2=${VAR1^}
echo $VAR2
}
cspc()
{
VAR1=bashsheldl
VAR2=${VAR1^^[ade]}
echo $VAR2
}
ftl()
{
VAR1=SURENDRAKUMAR
VAR2=${VAR1,}
echo $VAR2

}
cspc2()
{
VAR1=BASHSHELLSCRIPDTING
VAR2=${VAR1,,[ADE]}
echo $VAR2
}

c=0
while [ $c -eq 0 ]

do
	echo "1 :uppercase to lowercase"
	echo "2 :lowercase to upper"
	echo "3 :firstcase to uppercase"
	echo "4 :convert specific character to uppercase"
	echo "5 :firstcase to lowercase"
	echo "6 :convert specific character to lowercase"
	
	echo "Enter choice:"
	read choice
	
	case $choice in
	1)
	utl
	;;
	2)
	ltu
	;;
	3)
	ftu
	;;
	4)
	cspc
	;;
	5)
	ftl
	;;
	6)
	cspc2
	;;
	
	*)echo "Wrong choice!!"
	;;
	esac 
	echo "Do you wnt to continue with same inputs (Y=0/N=1)???"
	read c
	echo "----------------------"
done
	
	
