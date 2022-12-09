#!/bin/bash

if [ $# -ne 1 ]
then
    echo "numero di parametri errato"
fi

if [ ! -f $1 ]
then
    echo "Parametro errato"
fi

numeroRighe=0
massimo=0
x=0
while read row
do
    let "numeroRighe=numeroRighe+1"
    x=${#row}
    if [ "$x" -gt "$massimo" ]
    then
        massimo=$x
    fi
done < $1

echo "il numero di righe e' $numeroRighe"
echo "la riga con piu' caratteri e' lunga: $massimo"
