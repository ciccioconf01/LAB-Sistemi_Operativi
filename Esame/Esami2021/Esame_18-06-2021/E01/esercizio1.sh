#!/bin/bash

cat file.txt | head -n 50 | tail -n 1

find /home/foo -name ".*\.h" | -exec grep -e "(include)|(define)" \{} \ >> list.txt

cat bar.txt | sort | uniq | cut -d " " -f 2 >> "/home/tmp/list.txt"