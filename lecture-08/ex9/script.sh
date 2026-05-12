#!/bin/bash

# Functions
init_file() {
    echo "$(date '+%Y-%m-%d %H:%M:%S')" >> $logfile
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
    echo -e "No file passed.\nCreating new one from scratch."
    touch $logfile
    init_file
fi

while read -r $line; do
    echo $line
done < $logfile