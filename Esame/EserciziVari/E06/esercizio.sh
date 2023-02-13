#!/bin/bash

if [ $# -ne 1 ]
then
    echo "numero di parametri errato"
fi

while read row
do
    parole=$(echo $row | wc -w)
    let resto=$parole%2

    if [ $resto -eq 0 ]
    then
        riga=$(echo $row | tr [a-z] [A-Z])
        echo "$riga"
    else
        riga=$(echo $row | tr [A-Z] [a-z])
        echo "$riga"
    fi
done < $1