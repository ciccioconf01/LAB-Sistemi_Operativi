#!/bin/bash

echo "Inserisci il nome di un processo"
read processo

echo "inserisci tempo"
read tempo

conta=0

while conta -ne 5
do
    
    stato=$(ps -el | grep $processo | cut -d " " -f 9)
    
    if [ $stato -eq "Z" ]
    then
        let conta=$conta+1
    else
        conta=0
    fi
    
    sleep($tempo)
done

pid=$(ps -el | grep $processo | cut -d " " -f 2)
kill -9 pid
