#!/bin/bash

# Functions
init_file() {
    flags=("INFO" "WARNING" "ERROR")

    for i in {0..7}; do
        random_index=$((RANDOM % ${#flags[@]}))
        echo "$(date '+%Y-%m-%d %H:%M:%S') ${flags[$random_index]}" >> $logfile
    done
}

# Main execution
logfile=$1
info_counter=0
warning_counter=0
error_counter=0

if [[ -f $logfile ]]; then
    echo "File passed: $logfile"
else
    logfile=eb1-logfile.txt
    rm $logfile
    echo -e "No file passed.\nCreating a new one from scratch."
    touch $logfile
    init_file
fi

# Regex to find only that string
while read -r line; do
    if [[ $line =~ "INFO" ]]; then
        ((info_counter++))
    elif [[ $line =~ "WARNING" ]]; then
        ((warning_counter++))
    elif [[ $line =~ "ERROR" ]]; then
        ((error_counter++))
    else
        echo "No pattern found in this line: $line"
    fi
done < $logfile

echo -e "INFOS: $info_counter\nWARNINGS: $warning_counter\nERRORS: $error_counter"