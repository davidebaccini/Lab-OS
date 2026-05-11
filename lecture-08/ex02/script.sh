#!/bin/bash

dir_name=$1
reg_file=0
sh_count=0
dir_count=0

for i in "$(ls)"; do
    if [[ -f $i ]]; then
       reg_count=$(( $reg_count + 1 ))
    fi

    if [[ $i == *.sh ]]; then
       sh_count=$(( $sh_count + 1 ))
    fi
done

for i in "$(ls -d)"; do
    dir_count_count=$(( $dir_count + 1 ))
done

echo "Number of regular files: $reg_count"
echo "Number of DIRs: $dir_count"
echo "Number of .sh files: $sh_count"