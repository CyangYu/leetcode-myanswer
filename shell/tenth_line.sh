#!/usr/bin/sh

# Read from the file file.txt and output the tenth line to stdout.
count=0

cat file.txt | while read line
do
    count=$[ $count + 1 ]
    if [ $count -eq 10 ]; then
        echo $line
    fi
done