#!/bin/bash

dir_name=$1
func=$2
counter=0

count_exec() {
    for i in "$dir_name"/*; do
        if [[ -x "$i" ]]; then
            ((counter++))
        fi
    done
    echo "Executable counter: $counter"
}

show_top() {
    ls -lt "$dir_name" | head
}

# Call the function passed as argument
if declare -f "$func" > /dev/null; then
    "$func"
else
    echo "Error: function '$func' not found"
    exit 1
fi