#! /bin/bash
ListOfFile () {

val="Shell Program Search Images"
file=output.html
cat <<EOF1 > $file
<html> 
<head>
<title>Shell Program Search Images</title>
</head>
<body>
<h1>$val</h1>
EOF1
echo '<table border="1">' >> $file
echo '<th>File Name</th>' >> $file
echo '<th>Extension</th>' >> $file
echo '<th>Resolution</th>' >> $file
echo '<th>Size</th>' >> $file
echo '<th>Location of the file</th>' >> $file
sudo find $PATH_NAME -type f \( -iname \*.png -o -iname \*.jpg -o -iname \*.bmp \) | xargs identify |  awk '{ print $1 "\t" $2 "\t" $3 "\t" $7 "\t "$1}'  | awk '{gsub(/\/.*\//,"",$1); print "<tr>" "<td>" $1 "</td>" "<td>" $2 "</td>" "<td>"$3 "</td>" "<td>"$4"</td>" "<td>"$5"</td>" "</tr>"}' >> $file
echo '</table>' >> $file
cat <<EOF2 >> $file
</body>
</html>
EOF2
	echo "List of media files"
    sudo find $PATH_NAME -type f \( -iname \*.png -o -iname \*.jpg -o -iname \*.bmp \) | xargs identify | awk '{ print $1 "\t" $2 "\t" $3 "\t" $7 "\t "$1}' | awk '{gsub(/\/.*\//,"",$1); print}' | column -t
}


SortByName () {
	echo "Sort by apha"
    sudo find $PATH_NAME -type f \( -iname \*.png -o -iname \*.jpg -o -iname \*.bmp \) | xargs identify | awk '{ print $1 "\t" $2 "\t" $3 "\t" $7 "\t "$1}'| awk '{gsub(/\/.*\//,"",$1); print }'  | sort -k1,1 | column -t 
}

SortByFormat () {
	echo "Sort by extension"
    sudo find $PATH_NAME -type f \( -iname \*.png -o -iname \*.jpg -o -iname \*.bmp \) | xargs identify | awk '{ print $1 "\t" $2 "\t" $3 "\t" $7 "\t "$1}'  | awk '{gsub(/\/.*\//,"",$1); print}'  | sort -k2,2 | column -t 
}

SortBySize () {
	echo "Sort by size"
    sudo find $PATH_NAME -type f \( -iname \*.png -o -iname \*.jpg -o -iname \*.bmp \) | xargs identify |  awk '{ print $1 "\t" $2 "\t" $3 "\t" $7 "\t "$1}'  |  awk '{gsub(/\/.*\//,"",$1); print}' | sort -n -k4 | column -t 
}

SortByResolution(){
	echo "Sort by size"
    sudo find $PATH_NAME -type f \( -iname \*.png -o -iname \*.jpg -o -iname \*.bmp \) | xargs identify |  awk '{ print $1 "\t" $2 "\t" $3 "\t" $7 "\t "$1}'  |  awk '{gsub(/\/.*\//,"",$1); print}' | sort -n -k3 | column -t 
}


ListOfDuplicate () {
	echo  "highlight of the duplicate files(if any): "
    sudo find $PATH_NAME -type f \( -iname \*.png -o -iname \*.jpg -o -iname \*.bmp \) -printf "%f  " -exec ls -l --block-size=K {} \; | awk '{if (x[$1]) { x_count[$1]++;  print "\033[1;31m" $1 "\t" $6 "\t" $10 "\033[0m "; if (x_count[$1] == 1) { print x[$1] } } x[$1] = "\033[1;31m" $1 "\t" $6 "\t" $10 "\033[0m "}'| column -t | sort -k1,1
}

echo "Please input path: "
read PATH_NAME

MENU="
Program Part 1 Topic 2
1. List of Images
2. Sort by Name
3. Sort by Size
4. Sort by Format
5. Sort by Resolution
6. Find Duplicate File (if any)
7. Quit
"
MenuFunction () {
	while true; do
  clear
  echo "$MENU"
  echo -n "Please make your choice: "
  read INPUT 
 
  case $INPUT in
    1)
    ListOfFile
    echo press ENTER to continue
    read
    ;;
    2)
    SortByName
    echo press ENTER to continue
    read
    ;;
    3)
    SortBySize
    echo press ENTER to continue
    read
    ;;
    4)
    SortByFormat
    echo press ENTER to continue
    read
    ;;
    5)
    SortByResolution
    echo press ENTER to continue
    read
    ;;
    6)
    ListOfDuplicate
    echo press ENTER to continue
    read
    ;;
    7|q|Q) 
    exit 0
    ;;
    *) # All other user input results in an usage message
    clear
    echo Please choose again
    sleep 1
    ;;
  esac
 
done
}

MenuFunction
