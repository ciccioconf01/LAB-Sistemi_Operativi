#!/bin/bash

listaNomi=$(ps -e | tr -s " " | cut -d " " -f 5 )
max=0

for nome in $listaNomi
do
    i=${#nome}
    if [ $i -gt $max ]
    then
        max=$i
        nomeS=$nome
    fi
done

echo "Il processo piu' lungo e': $nomeS"
