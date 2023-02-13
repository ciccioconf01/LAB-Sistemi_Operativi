#!/bin/bash

if [ $# -ne 1 ]
then
    echo "errore nel numero di parametri"
fi

file="./passwd"

#dir=$(echo $file | grep "^$1:" | cut -f 6 -d ":")
#rm -r $dir

rigaDaCancellare=$(cat $file | grep -ve "^$1:")

cat $file | grep -v "^$1:" > "tmp"
mv tmp $file