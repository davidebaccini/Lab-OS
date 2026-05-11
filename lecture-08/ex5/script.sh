#!/bin/bash

file=$1
counter=0

until [[ -f $file ]] || [[ $counter -gt 4 ]]; do
    echo "Waiting for $file"
    $counter=$(( counter++ ))
    sleep 1
done

if [[ counter -gt 4 ]]; then
    echo "Timeout reached"
else
    echo "File found"
fi