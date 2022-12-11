#!/bin/bash

echo "Inserisci nome direttorio"
read $direttorio

if [ $? -ne 0 ]
then
    echo "errore nella read"
fi

if [ ! -d $direttorio ]
then 
    echo "direttorio non esistente"
fi

for x in $(find $direttorio -mindepth 2)
do 
    c=$(echo $x | tr [A-Z] [a-z])
    mv $x $c

done
