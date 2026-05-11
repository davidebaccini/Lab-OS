#!/bin/bash

dir_name=$1

for i in $(ls $dir_name); do
    if [[ $i == *.txt ]]; then
        echo "mv $i $i.bak"
        mv $dir_name/$i $dir_name/$i.bak
    fi
done