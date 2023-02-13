#!/bin/bash

i=0
max=0

while read row
do
    for word in $row
    do
        i=$(echo $word | wc -m)
        
        if [ $i -gt $max ]
        then
            max=$i
            parola=$word
        fi
    done
done < $1

echo "la parola di lunghezza massima e' $parola ed ha lunghezza: $max."