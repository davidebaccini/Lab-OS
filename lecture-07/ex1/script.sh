#!/bin/bash
if [[ $# -eq 1 ]]; then
    echo "Usage: $0 path"
    exit 0
fi

NAME=$1

if [[ -f "$NAME" ]]; then
    echo "$NAME is a file"
elif [[ -d "$NAME" ]]; then
    echo "$NAME is a directory"
elif [[ -L "$NAME" ]]; then
    echo "$NAME is a symbolic link"
else
    echo "Strange file type"
fi

ls -ld $NAME