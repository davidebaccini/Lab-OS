#!/bin/bash

func=$1
dir_name=$2
file_count=0
dir_count=0

stats() {
    for i in "$dir_name"/*; do
        if [[ -f "$i" ]]; then
            ((file_count++))
        elif [[ -d "$i" ]]; then
            ((dir_count++))
        else
            echo "None"
        fi
    done

    echo -e "File count: $file_count\nDirectory count: $dir_count"
}

largest() {
    echo "largest"
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