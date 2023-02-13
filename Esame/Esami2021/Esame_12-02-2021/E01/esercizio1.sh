#!/bin/bash

elem=$(find home -name ".*.c$")

for file in $elem
do
    nome=$(basename $file)
    cat $file | grep -e "$nome"
    if [ $? -eq 0 ]
    then
        mv $file $file"_new"
    fi

done

