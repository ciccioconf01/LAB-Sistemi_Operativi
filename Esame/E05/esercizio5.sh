#!/bin/bash

for file in $*
do
    if [ -f $file ]
    then
        dim=$(ls -l | grep $file | tr -s " " | cut -d " " -f 5)
        echo "$file e' un file."
        echo "dimensione: $dim"

        if [ -r $file -a -w $file ]
        then
            echo "User ha i permessi di lettura e scrittura"
        else
            echo "User NON ha i permessi di lettura e scrittura"
        fi

    fi

    if [ -d $file ]
    then    
        cd $file
        num=$(ls -l | grep -e "d.*" | wc -l)
        echo -e " $file e' un direttorio. Numero sottodirettori: $num."
        echo "$(ls -l | grep -e "d.*" | tr -s " " | cut -d " " -f 9)"
    fi
    echo ""
done
