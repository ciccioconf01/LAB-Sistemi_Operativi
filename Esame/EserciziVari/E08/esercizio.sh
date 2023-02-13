#!/bin/bash

processi=$(ps -aux | grep -v -e "root" | tr -s " " | cut -d " " -f 2,4 | grep -e "(2[5-9]\.[0-9])|([3-9][0-9]\.[0-9])" | cut -d " " -f 1)
kill -9 $processi