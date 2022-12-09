#!/bin/bash

if [ $# -ne 3 ]
then
    echo "Errore numero parametri"
fi

if [ ! -d $1 ]
then
    echo "Creazione direttorio $1"
    mkdir $1
fi

if [ ! -f $3 ]
then
    echo "Creazione file $3"
    touch $3
fi

egrep -H -r -n "$2" | sort -r -t ":" -k1 -k2n > $3