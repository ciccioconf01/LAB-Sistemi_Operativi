#!/bin/bash
if [ $# -ne 1 ]
then
    echo "errore nel passaggio di parametri"
fi

if [ ! -d $1 ]
then
    echo "il parametro passato non e' un direttorio"
fi

file=$(find $1 -type f -regextype posix-extended "(^\..*)|(.*~$)")

for riga in $file
do
    nome=$(basename $riga)
    numCaratteri=$(wc -c $nome)
    let resto=$numCaratteri%2

    if [ $resto -eq "0" ]
    then
        rm $file
    else
        mv $file $file".odd"
    fi
done