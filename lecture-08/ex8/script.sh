#!/bin/bash

func=$1
dir_name=$2
file_count=0
dir_count=0
largest_size=0

stats() {
    for i in $dir_name/*; do
        if [[ -f $i ]]; then
            ((file_count++))
        elif [[ -d $i ]]; then
            ((dir_count++))
        else
            echo "None"
        fi
    done

    echo -e "File count: $file_count\nDirectory count: $dir_count"
}

largest() {
    for i in $dir_name/*; do
        if [[ -f $i ]]; then
            current_size=$(stat -c '%s' $i)
            if [[ $current_size -gt $largest_size ]]; then
                largest_file=$i
                largest_size=$(stat -c '%s' $largest_file)
            fi
        else
            echo "Directory skipped"
        fi
    done
    
    echo -e "Largest file is: $largest_file"
}

help() {
    echo "Usage of"
}

case $func in
    stats)
        stats
    ;;

    largest)
        largest
    ;;

    help)
        help
    ;;

    *)
        echo "Unknown command"
    ;;
esac