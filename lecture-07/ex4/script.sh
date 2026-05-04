#!/bin/bash
cat /etc/passwd | wc -l
echo ""

grep "/bin/bash" /etc/passwd
echo ""

if [[ -r /etc/passwd ]]; then
    echo "File is readable"
else
    echo "File is NOT readable"
fi