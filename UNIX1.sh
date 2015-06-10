#!/bin/sh

#!/bin/bash

echo "Enter the path you want to search: "
read PATH_NAME

find $PATH_NAME -type f -regex ".*\.\(jpg\|gif\|png\|jpeg\)" -exec identify -format ' %f %d %e %b %G \n' {} >> test.html \; 

echo "Choose how you want to sort the result: "
echo "1. By Name"
echo "2. By Directory"
echo "3. By Format"
echo "4. By Size"
echo "5. By Resolution"
echo "Please enter your choice: "
read i

case "$i" in
	1) find $PATH_NAME -type f -regex ".*\.\(jpg\|gif\|png\|jpeg\)" -exec identify -format ' %f %d %e %b %G \n' {} \; | sort -k 1 >> test.html
	;;
	2) find $PATH_NAME -type f -regex ".*\.\(jpg\|gif\|png\|jpeg\)" -exec identify -format ' %f %d %e %b %G \n' {} \; | sort -k 2 >> test.html 
	;;
	3) find $PATH_NAME -type f -regex ".*\.\(jpg\|gif\|png\|jpeg\)" -exec identify -format ' %f %d %e %b %G \n' {} \; | sort -k 3 >> test.html 
	;;
	4) find $PATH_NAME -type f -regex ".*\.\(jpg\|gif\|png\|jpeg\)" -exec identify -format ' %f %d %e %b %G \n' {} \; | sort -k 4 >> test.html 
	;;
	5) find $PATH_NAME -type f -regex ".*\.\(jpg\|gif\|png\|jpeg\)" -exec identify -format ' %f %d %e %b %G \n' {} \; | sort -k 5 >> test.html 
	;;
	*) echo "Wrong choice!"
	;;
esac



exit 0
