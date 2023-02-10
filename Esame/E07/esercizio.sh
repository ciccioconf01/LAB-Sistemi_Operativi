#!/bin/bash

if [ $# -ne 6 ]
then
    echo -n "errore nel numero di parametri"
fi

conta=0

while [ $conta -ne $4 ]
do
    echo -n "$5"
    let conta=conta+1
done >> $6

while read row
do
    echo -n " "
    for word in $row
    do
        if [ $word = $2 ]
        then
            echo -n "$3 "
        else
            echo -n "$word "
        fi
    done 
done < $1 >> $6

conta=0

while [ $conta -ne $4 ]
do
    echo -n "$5" >> $6
    let conta=conta+1
done >> $6
