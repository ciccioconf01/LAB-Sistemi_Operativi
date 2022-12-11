#!/bin/bash
file=$1
if [ $# -ne 1 ]
then
    echo "Nome file non presente"
    echo "digita nome file"
    read file
    if [ $? -ne 0 ]
    then
        echo "errore nella read"
    fi

    if [ ! -f $file ]
    then
        echo "nessun file inserito"
    fi
fi

declare -A vet

for stringa in $(cat $file)
do
    vet["$stringa"]=0
done

for stringa in $(cat $file)
do
    if [ ${vet["$stringa"]} -eq 0 ]
    then
        vet["$stringa"]=1
    else
        let "vet["$stringa"]=${vet["$stringa"]}+1"
    fi
done
 

for i in ${!vet[*]}
do
    echo "$i = ${vet[$i]}"
done
