#!/bin/bash
# Michael McRoskey
# November 22 2016

make generate_map

printf "| N             | Elapsed Time  | Memory Usage   |\n"
printf "|---------------|---------------|----------------|\n"

for size in 10 20 50 100 200 500 1000
do
	sizestring="$size"
	
kernel="2.6.39"
distro="xyz"
cat >test.txt <<EOL
line 1, ${kernel} ${distro}
line 2, 
line 3, ${distro}
line 4 line
EOL
	
#cat >test.txt <<EOL
#6
#f 3
#g 1
#G 2
#h 4
#m 7
#r 5
#${sizestring} ${sizestring}
#${./generate_map -n $size}
#0 0
#${sizestring} ${sizestring}
#EOL
	
	TIME=1.00
	MEMORY=1.00
	
	printf "| \t %6s | %13s | %14s |\n" $size $TIME $MEMORY
done

#cat test.txt
#kernel="2.6.39"
#distro="xyz"
#cat >test.txt <<EOL
#line 1, ${kernel} ${distro}
#line 2, 
#line 3, ${distro}
#line 4 line
#EOL

cat test.txt
