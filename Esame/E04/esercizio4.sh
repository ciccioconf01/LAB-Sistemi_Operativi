#!/bin/bash

r=0
c=0
lunghezza=0

while read row
do
    c=0

    for word in $row
    do
        if [ $r -eq $c ]
        then
            i=${#word}
            let lunghezza=lunghezza+i
        fi
    let c=c+1
    done

    let r=r+1
done < $1

echo "La lunghezza delle parole della diagonale e': $lunghezza"
